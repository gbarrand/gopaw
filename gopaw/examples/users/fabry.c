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

/*function*/ double fabry(double x,double TYP[]) {      
	double k,k0,num,c,epais,f0,a,N;
	double fabry;
	double r2r,r2i,rhor,rhoi,tempoi,t2r,t2i,tempor,empoi,phi,den;

	c=340.;
/* epais (d'une feuille) en microns */
	epais=15;
	f0=(1000.*c/3.14)/epais;
	k=6.28*x/c;
	a=TYP[0];
/* combien de secondaires pour 1.5ms dans Melissa ? */
/*	N=1+int(0.0015*c/(2.*a)) */
	N=(int)(0.0015*c/(2.*a));
	den=pow(1-pow(x/f0,2),2)+pow(2*x/f0,2);
	t2r=(1.-pow(x/f0,2))/den;
	t2i=(-2*x/f0)/den;
	r2r=-pow(x/f0,2)*t2r;
	r2i=-pow(x/f0,2)*t2i;
	phi=2*k*a;
	rhor=r2r*cos(phi)+r2i*sin(phi);
	rhoi=r2i*cos(phi)-r2r*sin(phi);
	tempor=1;
	tempoi=0;
       {int i;
	for(i=1;i<=N;i++) {
	   tempor=tempor*rhor-tempoi*rhoi;
	   tempoi=tempoi*rhor+tempor*rhoi;
	}}
	fabry=pow(t2r,2)+pow(t2i,2);
	fabry=fabry*(pow(1-tempor,2)+pow(tempoi,2));
	fabry=fabry/(pow(1-rhor,2)+pow(rhoi,2));
	fabry=10.*log10(fabry);
        return fabry;
}
