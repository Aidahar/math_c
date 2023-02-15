#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(s21_abs_my) {
  int x = -10;
  ck_assert_int_eq(s21_abs(x), abs(x));
  x = -10;
  ck_assert_int_eq(s21_abs(x), abs(x));
  ck_assert_int_eq(s21_abs((int)S21_INF), abs((int)S21_INF));
  ck_assert_int_eq(s21_abs((int)-S21_INF), abs((int)-S21_INF));
  ck_assert_int_eq(s21_abs((int)S21_NAN), abs((int)S21_NAN));
}
END_TEST

START_TEST(s21_fabs_my) {
  double x = 0.0;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = -0.0;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = 3.0;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = -3.0;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = S21_INF;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_fabs(x));
}
END_TEST

START_TEST(s21_sqrt_my) {
  double x = 4;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
  x = -0.0;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
  x = 5;
  ck_assert_ldouble_eq(1 + s21_sqrt(x) / 2, 1 + sqrt(x) / 2);
  x = 0.0;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
  x = 2;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
  x = 100;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
  x = -100;
  ck_assert_ldouble_nan(s21_sqrt(x));
  x = -1.0;
  ck_assert_ldouble_nan(s21_sqrt(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_sqrt(x));
  x = S21_INF;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

START_TEST(s21_pow_my) {
  double x = 0, y = -1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 1, y = S21_NAN;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 12, y = S21_NAN;
  ck_assert_ldouble_nan(s21_pow(x, y));
  x = -12, y = S21_NAN;
  ck_assert_ldouble_nan(s21_pow(x, y));
  x = S21_NAN, y = 1;
  ck_assert_ldouble_nan(s21_pow(x, y));
  x = S21_NAN, y = S21_NAN;
  ck_assert_ldouble_nan(s21_pow(x, y));
  x = S21_NAN, y = -1;
  ck_assert_ldouble_nan(s21_pow(x, y));
  x = S21_NAN, y = 0;
  ck_assert_ldouble_nan(s21_pow(x, y));
  x = S21_INF, y = 1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_INF, y = -1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_INF, y = 0;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_OTR_INF, y = 0;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_INF, y = 0.1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_OTR_INF, y = 0.1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_INF, y = -0.1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_OTR_INF, y = -0.1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_INF, y = 12;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_OTR_INF, y = 12;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_INF, y = -1.1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_INF, y = -0.0000000000001;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_INF, y = 0.0000000000001;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_OTR_INF, y = -1.1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_OTR_INF, y = -0.0000000000001;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_OTR_INF, y = 0.0000000000001;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_OTR_INF, y = -1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = S21_OTR_INF, y = 1;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = -1, y = S21_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = -1, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = -11.05, y = S21_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 11.05, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 1, y = S21_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 1, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 0, y = S21_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 0, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 15, y = S21_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = -15, y = S21_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 15, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 0.5, y = S21_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 0.5, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = -15, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 15, y = 0;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = -0.12, y = 2;
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 0.0000001);
  x = -0.12, y = 0;
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 0.0000001);
  x = -0.12, y = 2.2;
  ck_assert_ldouble_nan(s21_pow(x, y));
  x = -0.12, y = -2.2;
  ck_assert_ldouble_nan(s21_pow(x, y));
  x = 0.12, y = -2.2;
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 0.0000001);
  x = 0.12, y = 2.2;
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 0.0000001);
  x = -0.12, y = -2;
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 0.0000001);
  x = 15, y = 2.5;
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_my) {
  double x = 5.1, y = 3.0;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = -5.1, y = 3.0;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = 5.1, y = -3.0;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = -5.1, y = -3.0;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = S21_EPS - 0.0000001, y = 3.0;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = S21_EPS + 0.0000001, y = -3.0;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = 130000000000, y = 15.2;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
  x = 0.0, y = 1.0;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = -0.0, y = 1.0;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = 0.0, y = -1.0;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = -0.0, y = -1.0;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = S21_INF, y = 5.1;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = 5.1;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_INF, y = -5.1;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = -5.1;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 5.1, y = S21_INF;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = 5.1, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = -5.1, y = S21_INF;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = -5.1, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = 0.000000001, y = S21_INF;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = 0.000000001, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = -0.000000001, y = S21_INF;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = -0.000000001, y = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
  x = 5.1, y = 0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = -5.1, y = 0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_NAN, y = 5.4;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_NAN, y = S21_INF;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_NAN, y = S21_OTR_INF;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_INF, y = S21_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_INF, y = S21_INF;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_INF, y = S21_OTR_INF;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_INF, y = -5.4;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_INF, y = 5.4;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_INF, y = 0.0000000000001;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_INF, y = -0.0000000000001;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = S21_INF;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_INF, y = -0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = S21_OTR_INF;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = S21_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = -5.1;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = 0.0000000000001;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = -0.0000000000001;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = 5.4;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_OTR_INF, y = -5.4;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 5.4, y = S21_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_exp_my) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 0.000001);
  x = 0.03;
  ck_assert_ldouble_eq_tol(100 * s21_exp(x), 100 * exp(x), 0.000001);
  x = -0.03;
  ck_assert_ldouble_eq_tol(100 * s21_exp(x), 100 * exp(x), 0.000001);
  x = MIN_DEGREE;
  ck_assert_ldouble_eq_tol(100 * s21_exp(x), 100 * exp(x), 0.000001);
  x = -1;
  ck_assert_ldouble_eq_tol(100 * s21_exp(x), 100 * exp(x), 0.000001);
  x = 0.0;
  ck_assert_ldouble_eq(s21_exp(x), exp(x));
  x = -0.0;
  ck_assert_ldouble_eq(s21_exp(x), exp(x));
  x = 710;
  ck_assert_ldouble_eq(s21_exp(x), exp(x));
  x = -710;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 0.0000001);
  x = S21_INF;
  ck_assert_ldouble_eq(s21_exp(x), exp(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_exp(x), exp(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_exp(x));
}
END_TEST

START_TEST(s21_log_my) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 0.000001);
  x = 2;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 0.000001);
  x = -2;
  ck_assert_ldouble_nan(s21_log(x));
  x = 125;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 0.0000001);
  x = S21_INF;
  ck_assert_ldouble_eq(s21_log(x), log(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_nan(s21_log(x));
  x = 0;
  ck_assert_ldouble_eq(s21_log(x), log(x));
  x = -0;
  ck_assert_ldouble_eq(s21_log(x), log(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_log(x));
  ck_assert_ldouble_nan(log(x));
}
END_TEST

START_TEST(s21_ceil_my) {
  double x = 2.4;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), 0.000001);
  x = -2.4;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), 0.000001);
  x = S21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  x = -0;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  x = 0;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  x = 1;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  x = -1;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_ceil(x));
}
END_TEST

START_TEST(s21_atan_my) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 0.000001);
  x = S21_OTR_INF;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 0.000001);
  x = S21_INF;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 0.000001);
  x = 0.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 0.000001);
  x = 1.5;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 0.000001);
  x = -1.5;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 0.000001);
  x = -1.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 0.000001);
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_atan(x));
  x = -0.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 0.000001);
}
END_TEST

START_TEST(s21_tan_my) {
  double x = M_PI / 4;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
  x = 3 * M_PI / 4;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
  x = -3 * M_PI / 4;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
  x = M_PI / 2;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
  x = -M_PI / 2;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
  x = 5 * M_PI / 4;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
  x = 7 * M_PI / 4;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
  x = S21_INF;
  ck_assert_ldouble_nan(s21_tan(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_tan(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_nan(s21_tan(x));
  x = -0.0;
  ck_assert_ldouble_eq(s21_tan(x), tan(x));
  x = -0.0;
  ck_assert_ldouble_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(s21_cos_my) {
  double x = M_PI / 3;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 0.000001);
  x = -3 * M_PI / 2;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 0.000001);
  x = S21_INF;
  ck_assert_ldouble_nan(s21_cos(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_cos(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_nan(s21_cos(x));
  x = -0.0;
  ck_assert_ldouble_eq(s21_cos(x), cos(x));
  x = 0.0;
  ck_assert_ldouble_eq(s21_cos(x), cos(x));
}
END_TEST

START_TEST(s21_acos_my) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 0.000001);
  x = 0.0;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 0.000001);
  x = -0.0;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 0.000001);
  x = S21_INF;
  ck_assert_ldouble_nan(s21_acos(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_nan(s21_acos(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_acos(x));
  x = 0.5;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 0.000001);
  x = -0.5;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 0.000001);
  x = 1.1;
  ck_assert_ldouble_nan(s21_acos(x));
  x = -1.1;
  ck_assert_ldouble_nan(s21_acos(x));
}
END_TEST

START_TEST(s21_sin_my) {
  double x = M_PI / 6;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.000001);
  x = M_PI;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.000001);
  x = -M_PI;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.000001);
  x = M_PI / 2;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.000001);
  x = -M_PI / 2;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.000001);
  x = -3 * M_PI / 4;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.000001);
  x = S21_INF;
  ck_assert_ldouble_nan(s21_sin(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_nan(s21_sin(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_sin(x));
  x = -0.0;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.0000001);
  x = 0.0;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.0000001);
  x = -0.05;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.0000001);
  x = 0.05;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.0000001);
  x = -11.05;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.0000001);
  x = 11.05;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 0.0000001);
}
END_TEST

START_TEST(s21_asin_my) {
  double x = 0.000000005;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), 0.000001);
  x = -0.000000005;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), 0.000001);
  x = S21_INF;
  ck_assert_ldouble_nan(s21_asin(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_nan(s21_asin(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_asin(x));
  x = -12.1;
  ck_assert_ldouble_nan(s21_asin(x));
  x = 12.1;
  ck_assert_ldouble_nan(s21_asin(x));
  x = 2.1;
  ck_assert_ldouble_nan(s21_asin(x));
  x = 1.0;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), 0.000001);
  x = -1.0;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), 0.000001);
  x = S21_PI / 2;
  ck_assert_ldouble_nan(s21_asin(x));
  x = S21_PI / 2;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(s21_floor_my) {
  double x = 1.0;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = 125;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = -125;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = 47e16;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = 37e2;
  ck_assert_ldouble_eq(s21_floor((long long int)x), floor((long long int)x));
  x = -47e16;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = -47e2;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = S21_OTR_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = 1.523;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = -0.123;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_floor(x));
}
END_TEST

Suite *s21_math_suit(void) {
  Suite *s;
  s = suite_create("Math functions");

  TCase *tc_abs;
  TCase *tc_ceil;
  TCase *tc_exp;
  TCase *tc_fabs;
  TCase *tc_floor;
  TCase *tc_fmod;
  TCase *tc_log;
  TCase *tc_pow;
  TCase *tc_sqrt;
  TCase *tc_tan;
  TCase *tc_atan;
  TCase *tc_cos;
  TCase *tc_acos;
  TCase *tc_sin;
  TCase *tc_asin;

  tc_abs = tcase_create("abs");
  suite_add_tcase(s, tc_abs);
  tcase_add_test(tc_abs, s21_abs_my);

  tc_ceil = tcase_create("ceil");
  suite_add_tcase(s, tc_ceil);
  tcase_add_test(tc_ceil, s21_ceil_my);

  tc_exp = tcase_create("exp");
  suite_add_tcase(s, tc_exp);
  tcase_add_test(tc_exp, s21_exp_my);

  tc_fabs = tcase_create("fabs");
  suite_add_tcase(s, tc_fabs);
  tcase_add_test(tc_fabs, s21_fabs_my);

  tc_floor = tcase_create("floor");
  suite_add_tcase(s, tc_floor);
  tcase_add_test(tc_floor, s21_floor_my);

  tc_fmod = tcase_create("fmod");
  suite_add_tcase(s, tc_fmod);
  tcase_add_test(tc_fmod, s21_fmod_my);

  tc_log = tcase_create("log");
  suite_add_tcase(s, tc_log);
  tcase_add_test(tc_log, s21_log_my);

  tc_pow = tcase_create("pow");
  suite_add_tcase(s, tc_pow);
  tcase_add_test(tc_pow, s21_pow_my);

  tc_sqrt = tcase_create("sqrt");
  suite_add_tcase(s, tc_sqrt);
  tcase_add_test(tc_sqrt, s21_sqrt_my);

  tc_tan = tcase_create("tan");
  suite_add_tcase(s, tc_tan);
  tcase_add_test(tc_tan, s21_tan_my);

  tc_atan = tcase_create("atan");
  suite_add_tcase(s, tc_atan);
  tcase_add_test(tc_atan, s21_atan_my);

  tc_cos = tcase_create("cos");
  suite_add_tcase(s, tc_cos);
  tcase_add_test(tc_cos, s21_cos_my);

  tc_acos = tcase_create("acos");
  suite_add_tcase(s, tc_acos);
  tcase_add_test(tc_acos, s21_acos_my);

  tc_sin = tcase_create("sin");
  suite_add_tcase(s, tc_sin);
  tcase_add_test(tc_sin, s21_sin_my);

  tc_asin = tcase_create("asin");
  suite_add_tcase(s, tc_asin);
  tcase_add_test(tc_asin, s21_asin_my);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_math_suit();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (0 == number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}
