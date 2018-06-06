      function sio2clas(x)
      real np1,np2,ng
      E0=17.3
      E0=10.6
      dE=0.001
      E=x
      A=81.05/(E0**2-E**2)
      np1=sqrt((1+2*A)/(1-A))
      E=x+dE
      A=81.05/(E0**2-E**2)
      np2=sqrt((1+2*A)/(1-A))
      dnsurdE=(np2-np1)/dE
      denom=1-x*dnsurdE/np1
      ng=np1/denom
      sio2clas=ng-1
c      sio2clas=np1-1
      end
