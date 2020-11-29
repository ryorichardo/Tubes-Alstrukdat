#include <stdio.h>
#include "../Jam/jam.h"

int main()
{
  JAM J1, J2;
  /* ALGORITMA */
  J1 = MakeJAM(1, 20);
  printf("Jam sekarang: ");
  TulisJAM(J1);
  printf("\n");
  printf("Konversi menjadi menit: %ld\n", JAMToMenit(J1));
  J2 = MenitToJAM(200);
  printf("200 menit sama dengan jam : ");
  TulisJAM(J2);
  printf("\n");
  JAM J3 = UpdateJam(J1, J2);
  printf("Jam sekarang setelah 200 menit: ");
  TulisJAM(J3);
  printf("\n");
  int s = SelisihJam(J1, J3);
  printf("Selisih jam sekarang dengan jam lampau dalam menit adalah: %d", s);
  return 0;
}