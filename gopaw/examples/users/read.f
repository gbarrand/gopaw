      SUBROUTINE READ(K)
      IMPLICIT NONE
      VECTOR RUN,ACT,EACT
      INTEGER I,J,K,IRU
      REAL AC,EAC

      OPEN(11,FILE='data_activite_radon_gas_trace.dat')
 
      I = 0

      J = 0
      DO WHILE (I.EQ.0)
        READ(11,*,ERR=98,END=99) IRU,AC,EAC
C        PRINT*,' Lecture : IRU ',IRU,' AC ',AC,' EAC ',EAC
        J = J + 1
        IF (IRU.GE.3580+(K-1)*200.AND.IRU.LT.3580+K*200) THEN
          RUN(J) = REAL(IRU)
          ACT(J) = AC
          EACT(J) = EAC
        ENDIF  
C        PRINT*,' J ',J,' RUN(J) ',RUN(J),' ACT(J) ',ACT(J),
C     &' EACT(J) ',EACT(J)
      ENDDO  
 98   PRINT*,'Erreur de lecture de data_activite_radon_gas_trace.dat'
      STOP

 99   CLOSE(11)

      END
