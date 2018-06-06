      function airclas(x)
      real np1,np2,ng
      vector energy(1)
      E0=19.1
      E0=16.7
      E0=energy(1)
      dE=0.5
      E=x
      np1=1+1e-3*98.49/(E0**2-E**2)
      E=x+dE
      np2=1+1e-3*98.49/(E0**2-E**2)
      dnsurdE=(np2-np1)/dE
      denom=1-x*dnsurdE/np1
      ng=np1/denom
      airclas=(ng-1)*1000
c      airclas=(np1-1)*1000
      end
