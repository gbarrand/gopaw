
/*function*/ double mandel(double XP,double YP) {

  double X,Y,XX,YY,TT;
  int NMAX = 30;
  int N;

  X=XP;
  Y=YP;
  XX=0.;
  YY=0.;
  for(N=1;N<=NMAX;N++) {
    TT=XX*XX-YY*YY+X;
    YY=2.*XX*YY+Y;
    XX=TT;
    if(4.<(XX*XX+YY*YY)) break;
  }

  return ((float)N)/((float)NMAX);
}

