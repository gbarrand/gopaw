      REAL FUNCTION CONE(X,Y)
C
C     CONE
C
C     Y = A * X + B
C     
C     X = 0 ---> HEIGHT+GROUND
C     X = R ---> GROUND
C
      REAL RADIUS,GROUND,HEIGHT,R
      GROUND = 1
      RADIUS = 10
      HEIGHT = 10e4
      
      R = SQRT(X*X+Y*Y)
      IF(R.GT.RADIUS) THEN
        CONE = GROUND
      ELSE
        CONE = -HEIGHT/RADIUS * R + GROUND+HEIGHT
      ENDIF
      RETURN
      END
