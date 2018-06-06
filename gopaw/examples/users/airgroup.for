      function airgroup(x)
      real k0,k1,k2,k3
      k0=238.0185
      k1=5792105
      k2=57.362
      k3=167917
      s=(x/1.24)**2
      airgroup=(k1*(k0+s)/(k0-s)**2+k3*(k2+s)/(k2-s)**2)/1e5      
      end
