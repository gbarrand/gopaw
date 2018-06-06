#include <math.h>

/*
 * Signature must be on one line starting with "function" in C comment. 
 * Argument left parenthesis must stick the function name.
 */

/*function*/ double cone(double X,double Y) {

/*
      CONE

      Y = A * X + B
      
      X = 0 ---> HEIGHT+GROUND
      X = R ---> GROUND
*/
      double RADIUS,GROUND,HEIGHT,R,CONE;
      GROUND = 1;
      RADIUS = 10;
      HEIGHT = 10e4;
      
      R = sqrt(X*X+Y*Y);
      if(R>RADIUS) {
        CONE = GROUND;
      } else {
        CONE = -HEIGHT/RADIUS * R + GROUND+HEIGHT;
      }
      return CONE;
}
