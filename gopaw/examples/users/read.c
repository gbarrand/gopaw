/*
 * Signature must be on one line starting with "function" in C comment. 
 * Argument left parenthesis must stick the function name.
 */

#include <stdio.h>

/* RUN,ACT,EACT are VECTORs
   [] assumes that the vector already exists. 
   [n] check that a vector TYP exists :
         if the existing VECTOR is not of dim n, we have an error.
         if the existing VECTOR is of dime n, it is ok and it is used.
       if a vector TYP does not exist, it is created with dimension n.
*/

/*function*/ double read(int K,double RUN[],double ACT[],double EACT[]) {      
      int I,J,IRU;
      float AC,EAC;
      FILE* file;

/*
      printf("debug : read : K %d\n",K);
*/

      file = fopen("activite_radon_gas_trace_info","rb");
      if(file==NULL) {
        printf("Can't open activite_radon_gas_trace_info\n");
        return 0;
      }
 
      I = 0;

    /*J = 0;*/
      J = -1;
      while(!feof(file)) {
        if(fscanf(file,"%d %g %g\n",&IRU,&AC,&EAC)!=3) {
          printf("Erreur de lecture de activite_radon_gas_trace_info\n");
          fclose(file);
          return 0;
        }
/*
        printf(" Lecture : IRU %d AC %g EAC %g\n",IRU,AC,EAC);
*/
        J = J + 1;
        if( (IRU>=(3580+(K-1)*200)) && (IRU<(3580+K*200)) ) {
          RUN[J] = (double)IRU;
          ACT[J] = AC;
          EACT[J] = EAC;
        }
/*
        printf(" J %d RUN(J) %g ACT(J) %g EACT(J) %g\n",
          J,RUN[J],ACT[J],EACT[J]);
*/
      }

      fclose(file);

      return 0;
}
