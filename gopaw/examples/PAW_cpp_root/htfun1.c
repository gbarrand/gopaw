#include <math.h>

/*
 * Signature must be on one line starting with "function" in C comment. 
 * Argument left parenthesis must stick the function name.
 *   See below for examples.
 */

/*function*/ double htfun1(double X) {
  const double C1 = 1.;
  const double C2 = 0.5;
  const double XM1 = 0.3;
  const double XM2 = 0.7;
  const double XS1 = 0.07;
  const double XS2 = 0.12;
  double A1,A2,X1,X2;

  A1=-0.5 * pow((X-XM1)/XS1,2);
  A2=-0.5 * pow((X-XM2)/XS2,2);
  X1=C1;
  X2=C2;
  if(fabs(A1)>0.0001) X1 = C1 * exp(A1);
  if(fabs(A2)>0.0001) X2 = C2 * exp(A2);
  return X1+X2;
}
/*function*/ double HTFUN2(double X,double Y) {
  return 100*htfun1(X)*htfun1(Y);
}
