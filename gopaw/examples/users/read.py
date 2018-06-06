
# RUN,ACT,EACT are VECTORs
#   [] assumes that the vector already exists. 
#   [n] check that a vector TYP exists :
#       if the existing VECTOR is not of dim n, we have an error.
#       if the existing VECTOR is of dim n, it is ok and it is used.
#       if a vector TYP does not exist, it is created with dimension n.

# the Python signature contains at end, in a Python comment, the C signature to help declare VECTORs.

def read(K,RUN,ACT,EACT):  #/*function*/ double read(int K,double RUN[],double ACT[],double EACT[])
 #print 'debug : read.py : K ',K
  
  file = open("data_activite_radon_gas_trace.dat","rb")
 
  I = 0

 #J = 0
  J = -1
  for line in file:
    words = line.split()
    #print words
    IRU = int(words[0])    #   int() is important.
    AC  = float(words[1])  # float() is important.
    EAC = float(words[2])  # float() is important.
    
   #print ' Lecture : IRU ',IRU,' AC ',AC,' EAC ',EAC
   
    J = J + 1
    if (IRU>=(3580+(K-1)*200)) and (IRU<(3580+K*200)) :
      RUN[J]  = IRU
      ACT[J]  = AC
      EACT[J] = EAC
    
   #print ' J ',J,' RUN(J) ',RUN[J],' ACT(J) ',ACT[J],' EACT(J) ',EACT[J]

  file.close()
