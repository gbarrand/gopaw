
import math

def cone(X,Y):

#  CONE
#
#  Y = A * X + B
#      
#  X = 0 ---> HEIGHT+GROUND
#  X = R ---> GROUND

  GROUND = 1.0
  RADIUS = 10.0
  HEIGHT = 10.0e4
      
  R = math.sqrt(X*X+Y*Y)
  if R>RADIUS :
    CONE = GROUND
  else:
    CONE = -HEIGHT/RADIUS * R + GROUND+HEIGHT
    
  return CONE
