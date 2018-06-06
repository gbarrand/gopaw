/*
 * Signature must be on one line starting with "function" in C comment. 
 * Argument left parenthesis must stick the function name.
 */

#include <math.h>

/*function*/ double sio2clas(double x) {      
      double np1,np2,ng;
      double E0,dE,E,A;
      double dnsurdE,denom;
      E0=17.3;
      E0=10.6;
      dE=0.001;
      E=x;
      A=81.05/(pow(E0,2)-pow(E,2));
      np1=sqrt((1+2*A)/(1-A));
      E=x+dE;
      A=81.05/(pow(E0,2)-pow(E,2));
      np2=sqrt((1+2*A)/(1-A));
      dnsurdE=(np2-np1)/dE;
      denom=1-x*dnsurdE/np1;
      ng=np1/denom;
      return ng-1;
/*       return np1-1; */
}
