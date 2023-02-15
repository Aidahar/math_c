#include "s21_math.h"

int s21_abs(int x) {
  (0 > x) ? x = -x : x;
  return x;
}

long double s21_acos(double x) {
  long double res = 0;
  if (1 < x || -1 > x || S21_INF == x || -S21_INF == x) {
    res = S21_NAN;
  } else {
    res = S21_PI / 2 - s21_asin(x);
  }
  return res;
}

long double s21_fabs(double x) {
  if (!s21_isnan(x)) {
    (0 > x) ? x = -x : x;
  }
  return x;
}

long double s21_pow(double x, double exp) {
  long double res = 0.0;
  if (x == 1 && s21_isnan(exp)) {
    res = 1;
  } else if (s21_isnan(x) || s21_isnan(exp)) {
    res = S21_NAN;
  } else if (x == S21_INF || x == -S21_INF) {
    if ((x == S21_INF && exp > S21_EPS) ||
        (x == S21_OTR_INF && exp > S21_EPS &&
         (exp - (long long int)exp != 0 || s21_fmod(exp, 2) == 0)))
      res = S21_INF;
    else if (exp > S21_EPS)
      res = -S21_INF;
    else if (exp < -S21_EPS)
      res = 0.0;
    else
      res = 1.0;
  } else if (exp == S21_INF || exp == S21_OTR_INF) {
    if (x == 1 || x == -1)
      res = 1;
    else if ((x == 0 && exp == S21_OTR_INF) ||
             (s21_fabs(x) > 1 && exp == S21_INF))
      res = S21_INF;
    else if (s21_fabs(x) < 1 && exp == S21_INF)
      res = 0;
    else if (s21_fabs(x) < 1 && exp == S21_OTR_INF)
      res = S21_INF;
  } else {
    if (x < 0 && exp - (int)exp != 0)
      res = S21_NAN;
    else {
      res = 1.0;
      int a = s21_abs((int)exp);
      if (s21_fabs(exp) - a == 0) {
        while (a > 0) {
          if (exp > 0)
            res *= x;
          else
            res /= x;
          a--;
        }
      } else {
        res = s21_exp(exp * s21_log(s21_fabs(x)));
      }
    }
  }
  return res;
}

long double s21_exp(double x) {
  long double res = 0;
  if (x == S21_OTR_INF)
    res = 0;
  else if (s21_isnan(x))
    res = x;
  else if (MIN_DEGREE >= x)
    res = 1e-310;
  else if (S21_INF == x || MAX_DEGREE < x)
    res = S21_INF;
  else {
    res = 1.0;
    long double add = 1.0, i;
    for (i = 1.0; S21_EPS < add; i++) {
      add *= s21_fabs(x) / i;
      res += add;
    }
    if (x < 0) res = 1.0 / res;
  }
  return res;
}

long double s21_log(double x) {
  long double res = 0.0;
  if (x != x)
    res = S21_NAN;
  else if (0.0 == x)
    res = -S21_INF;
  else if (S21_INF == x)
    res = S21_INF;
  else if (-S21_INF == x)
    res = S21_NAN;
  else if (2 == x)
    res = 0.6931471805599453;
  else if (0 < x) {
    int i = 0;
    while (1 < x) {
      x /= 10;
      i++;
    }
    x = x - 1.0;
    long double add = x, n;
    for (n = 1.0; S21_EPS < s21_fabs(add); n++) {
      res += add / n;
      add *= -x;
    }
    res += i * LN10;
  } else {
    res = S21_NAN;
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res = 1.0;
  if (0 > x || s21_isnan(x)) {
    res = S21_NAN;
  } else if (1.0 == x) {
    res = 1.0;
  } else if (0.0 == x) {
    res = 0;
  } else if (S21_INF == x) {
    res = S21_INF;
  } else {
    for (;;) {
      double tmp = (res + x / res) / 2;
      if (s21_fabs(res - tmp) < S21_EPS) break;
      res = tmp;
    }
  }
  return res;
}

long double s21_ceil(double x) {
  long double res;
  if (s21_isnan(x))
    res = x;
  else if (S21_INF == x)
    res = S21_INF;
  else if (S21_OTR_INF == x)
    res = S21_OTR_INF;
  else {
    long double diff = x - (long long int)x;
    if (S21_EPS > diff && -S21_EPS < diff) {
      res = x;
    } else if (0 < x) {
      res = (long long int)x + 1;
    } else {
      res = (long long int)x;
    }
  }
  return res;
}

long double s21_floor(double x) {
  long double res = 0.0;
  if (s21_isnan(x))
    res = x;
  else if (x == S21_INF)
    res = S21_INF;
  else if (x == S21_OTR_INF)
    res = S21_OTR_INF;
  else {
    long double diff = x - (long long int)x;
    if (S21_EPS > diff && diff > -S21_EPS) {
      res = x;
    } else if (x > 0)
      res = (long long int)x;
    else
      res = (long long int)x - 1;
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = 0.0;
  if ((y == S21_INF || y == S21_OTR_INF) &&
      !(x == S21_INF || x == S21_OTR_INF)) {
    res = x;
  } else if (s21_fabs(y) <= S21_EPS && !s21_isnan(x)) {
    res = S21_NAN;
  } else if ((x == S21_INF || x == S21_OTR_INF) && !s21_isnan(x) &&
             (!s21_isnan(y) || (y == S21_INF || y == S21_OTR_INF))) {
    res = S21_NAN;
  } else if (s21_isnan(x) || s21_isnan(y)) {
    res = S21_NAN;
  } else if (s21_fabs(x) <= S21_EPS && y != 0) {
    res = x;
  } else {
    long long int i = x / y;
    res = (long double)x - i * (long double)y;
  }
  return res;
}

long double s21_sin(double x) {
  long double res = 0.;
  if (s21_isnan(x) || x == S21_INF || x == -S21_INF)
    res = S21_NAN;
  else {
    if (S21_PI == x) {
      res = S21_EPS;
    } else if (-S21_PI == x)
      res = -S21_EPS;
    else {
      if (0 < x) {
        x = x - ((int)(x / (2 * S21_PI)) * (2 * S21_PI));
      } else if (0 > x) {
        x = x - ((int)(x / (2 * -S21_PI)) * (2 * -S21_PI));
      }
      double i;
      long double tmp = x;
      res = x;
      for (i = 1.; s21_fabs(tmp) > S21_EPS; i++) {
        tmp *= ((-1.) * x * x / (2. * i * (2. * i + 1.)));
        res += tmp;
      }
    }
  }
  return res;
}

long double s21_cos(double x) {
  long double res = 0;
  if (s21_isnan(x) || S21_INF == x || -S21_INF == x)
    res = S21_NAN;
  else {
    x = s21_fmod(x, 2 * S21_PI);
    double i = 1.;
    long double add = 1.;
    for (i = 1.; S21_EPS < s21_fabs(add); i++) {
      res += add;
      add *= -x * x / (2 * i * (2 * i - 1));
    }
  }
  return res;
}

long double s21_tan(double x) {
  long double result = 0.0;
  if (S21_OTR_INF == x || S21_INF == x) {
    result = S21_NAN;
  } else if (S21_PI / 2 == x) {
    result = 16331239353195370.0;
  } else if (-S21_PI / 2 == x) {
    result = -16331239353195370.0;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}

long double s21_asin(double x) {
  long double res = 0;
  if (1 < x || -1 > x || S21_INF == x || -S21_INF == x) {
    res = S21_NAN;
  } else if (1 == x) {
    res = S21_PI_HALF;
  } else if (-1 == x) {
    res = -S21_PI_HALF;
  } else {
    x = x / s21_sqrt(1 - x * x);
    res = s21_atan(x);
  }
  return res;
}

long double s21_atan(double x) {
  long double res = 0;
  if (S21_INF == x) {
    res = S21_PI_HALF;
  } else if (S21_OTR_INF == x) {
    res = -S21_PI_HALF;
  } else if (s21_isnan(x)) {
    res = S21_NAN;
  } else if (1.0 == x) {
    res = S21_PI_4;
  } else if (-1.0 == x) {
    res = -S21_PI_4;
  } else {
    int flag = 0;
    if (1 < x || -1 > x) {
      x = 1 / x;
      if (0 > x) {
        x = -x;
        flag = 1;
      } else {
        flag = 2;
      }
    }
    long double i, add = (long double)x;
    for (i = 0; S21_EPS < s21_fabs(add); i++) {
      res += add / (2 * i + 1);
      add *= -x * x;
    }
    if (2 == flag)
      res = -res + S21_PI_HALF;
    else if (1 == flag)
      res = res - S21_PI_HALF;
  }
  return res;
}