/*
 * Signature must be on one line starting with "function" in C comment. 
 * Argument left parenthesis must stick the function name.
 */

#include <math.h>

/* TYP is a VECTOR
   [] assumes that the vector already exists. 
   [n] check that a vector TYP exists :
         if the existing VECTOR is not of dim n, we have an error.
         if the existing VECTOR is of dime n, it is ok and it is used.
       if a vector TYP does not exist, it is created with dimension n.
*/

/*function*/ double oblique(double x,double TYP[]) {      
      double k,indice;
      double f;
      double ctetai,stetat,tetat,ctetat,reflechi,transmi,oblique;
      x=x*3.14/180.;
/* x est l'angle d'incidence en degres */
      indice=sqrt(44./29.);
      f=1000.;
      k=6.28*f/340.;
      ctetai=cos(x);
      stetat=sin(x)/indice;
      tetat=asin(stetat);
      tetat=tetat*180./3.14;
      ctetat=sqrt(1.-pow(stetat,2));
      reflechi=(indice*ctetai-ctetat)/(indice*ctetai+ctetat);
      transmi=2.*indice*ctetai/(indice*ctetai+ctetat);
      oblique = 0;
      if(TYP[0]==1.){
         oblique=reflechi;
      }
      if(TYP[0]==2.){
         oblique=transmi;
      }
      if(TYP[0]==3.){
         oblique=tetat;
      }
      if(TYP[0]==4.){
         indice=1./indice;
         oblique=tetat;
      }
      return oblique;     
}
