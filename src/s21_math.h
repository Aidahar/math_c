#ifndef SRC_s21_math_H_
#define SRC_s21_math_H_

#ifdef __APPLE__
#define _POSIX_C_SOURCE 200809L
#endif

#ifndef s21_isnan
#define s21_isnan(a) (a != a)
#endif

#define S21_PI 3.14159265358979323846
#define S21_PI_HALF 1.57079632679489661923
#define S21_PI_4 0.785398163397448309616
#define S21_EPS 1e-17
#define S21_NAN 0.0 / 0.0
#define S21_INF __builtin_huge_vall()
#define S21_OTR_INF -__builtin_huge_vall()
#define S21_LN10 2.30258509299404590109
#define S21_MAX_DOUBLE 1.7976931348623158e308
#define MIN_DEGREE -713
#define MAX_DEGREE 709.782712
#define LN10 2.30258509299404568401799145468436421

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_fmod(double x, double y);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);

#endif  // SRC_s21_math_H_
