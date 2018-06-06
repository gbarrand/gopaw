/*
 * Signature must be on one line starting with "function" in C comment. 
 * Argument left parenthesis must stick the function name.
 */

#include <math.h>

/*function*/ double airgroup(double x) {      
  double k0,k1,k2,k3,s;
  k0=238.0185;
  k1=5792105;
  k2=57.362;
  k3=167917;
  s=pow(x/1.24,2);
  return (k1*(k0+s)/pow(k0-s,2)+k3*(k2+s)/pow(k2-s,2))/1e5;
}
