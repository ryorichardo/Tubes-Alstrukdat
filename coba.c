#include<stdio.h>
#include"matriks.h"

int main () {
  MATRIKS M;
  BacaMATRIKS(&M, 20, 40, "map1.txt");
  TulisMATRIKS(M);
  SimpanMATRIKS(M, "simpan.txt");
}
