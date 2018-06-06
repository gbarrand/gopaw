	function fabry(x)

	real k,k0,num
	vector typ
	c=340.
c epais (d'une feuille) en microns
	epais=15
	f0=(1000.*c/3.14)/epais
	k=6.28*x/c
	a=typ(1)
c combien de secondaires pour 1.5ms dans Melissa ?
c	N=1+int(0.0015*c/(2.*a))
	N=int(0.0015*c/(2.*a))
	den=(1-(x/f0)**2)**2+(2*x/f0)**2
	t2r=(1.-(x/f0)**2)/den
	t2i=(-2*x/f0)/den
	r2r=-(x/f0)**2*t2r
	r2i=-(x/f0)**2*t2i
	phi=2*k*a
	rhor=r2r*cos(phi)+r2i*sin(phi)
	rhoi=r2i*cos(phi)-r2r*sin(phi)
	tempor=1
	tempoi=0
	do i=1,N
	   tempor=tempor*rhor-tempoi*rhoi
	   tempoi=tempoi*rhor+tempor*rhoi
	enddo
	fabry=t2r**2+t2i**2
	fabry=fabry*((1-tempor)**2+tempoi**2)
	fabry=fabry/((1-rhor)**2+rhoi**2)
	fabry=10.*alog10(fabry)
	end
