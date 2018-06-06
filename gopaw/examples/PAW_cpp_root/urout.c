#include <hbook.h>

/*#include <stdio.h>*/

/*function*/ void urout(int NEV,hbook* a_hbook,void* a_tag) {
  int i;
  int id_100 = 100;
  int id_110 = 110;
  float X;
  float Y = 0;
  float W = 1;
  /*printf("debug : urout : %d\n",NEV);*/
  for(i=0;i<NEV;i++) {
    X = a_hbook->m_hrndm1(a_tag,id_100);
    a_hbook->m_hfill(a_tag,id_110,X,Y,W);
  }
}
