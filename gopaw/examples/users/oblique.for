      real function oblique(x)
      real k,indice
      vector typ
      x=x*3.14/180.
c x est l'angle d'incidence en degres
      indice=sqrt(44./29.)
      f=1000.
      k=6.28*f/340.
      ctetai=cos(x)
      stetat=sin(x)/indice
      tetat=asin(stetat)
      tetat=tetat*180./3.14
      ctetat=sqrt(1.-stetat**2)
      reflechi=(indice*ctetai-ctetat)/(indice*ctetai+ctetat)
      transmi=2.*indice*ctetai/(indice*ctetai+ctetat)
      if(typ(1).eq.1.)then
         oblique=reflechi
      endif
      if(typ(1).eq.2.)then
         oblique=transmi
      endif
      if(typ(1).eq.3.)then
         oblique=tetat
      endif
      if(typ(1).eq.4.)then
         indice=1./indice
         oblique=tetat
      endif
      end
      
