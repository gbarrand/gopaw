/*
 * Signature must be on one line starting with "function" in C comment. 
 * Argument left parenthesis must stick the function name.
 */

#include <math.h>

/* ENERGY is a VECTOR
   [] assumes that the vector already exists. 
   [n] check that a vector ENERGY exists :
         if the existing VECTOR is not of dim n, we have an error.
         if the existing VECTOR is of dime n, it is ok and it is used.
       if a vector ENERGY does not exist, it is created with dimension n.
*/

/*function*/ double airclas(double x,double ENERGY[1]) {      
      double np1,np2,ng;
      double E0,dE,E,dnsurdE,denom;
      E0=19.1;
      E0=16.7;
      E0=ENERGY[0];
      dE=0.5;
      E=x;
      np1=1+1e-3*98.49/(pow(E0,2)-pow(E,2));
      E=x+dE;
      np2=1+1e-3*98.49/(pow(E0,2)-pow(E,2));
      dnsurdE=(np2-np1)/dE;
      denom=1-x*dnsurdE/np1;
      ng=np1/denom;
      return (ng-1)*1000;
/*    return (np1-1)*1000; */
}
