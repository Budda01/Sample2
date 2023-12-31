#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 0.0;

  if (x <= MAX_LOG_VAL) {
    int check = 0;
    if (x < 0) {
      x = s21_fabs(x);
      check = 1;
    }
    int intPart = (int)x;
    double fracPart = x - (int)x;
    long double prod = 1.0;
    for (int i = 1; i <= intPart; i++) {
      prod *= EXP;
    }
    res = prod;
    if (fracPart != 0.0) {
      res *= expSeriesExpansion(fracPart);
    }
    if (check == 1) res = 1 / res;
  } else if (x > MAX_LOG_VAL) {
    res = INF_VAL;
  } else {
    res = NAN_VAL;
  }
  return res;
}
