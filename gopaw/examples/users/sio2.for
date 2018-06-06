      function sio2(x)
      real np1,np2,ng
c x est l'energie en eV
      b1=0.6961663
      b2=0.4079426
      b3=0.8974794
      E1=18.13
      E2=10.67
      E3=0.125
      dE=0.1
      E=x
      np1=sqrt(b1/(1-(E/E1)**2)+b2/(1-(E/E2)**2)+b3/(1-(E/E3)**2)+1)
      E=x+dE
      np2=sqrt(b1/(1-(E/E1)**2)+b2/(1-(E/E2)**2)+b3/(1-(E/E3)**2)+1)
      dnsurdE=(np2-np1)/dE
      denom=1-x*dnsurdE/np1
      ng=np1/denom
c      ng=np1*(1+x*dnsurdE/np1)
      sio2=ng-1
c      sio2=np1-1
      end
