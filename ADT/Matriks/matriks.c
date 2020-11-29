/* NIM              : 13519065*/
/* Nama             : Faris Aziz*/
/* Tanggal          : 24 September 2020*/
/* Topik            : ADT Matriks */
/* Deskripsi        : Praktikum 5*/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "../boolean.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS(int NB, int NK, MATRIKS *M)
{
  /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
  /* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
  /* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
  /* KAMUS LOKAL */
  /* ALGORITMA */
  NBrsEff(*M) = NB;
  NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid(int i, int j)
{
  /* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return (i >= 0 && i <= 99) && (j >= 0 && j <= 99);
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs(MATRIKS M)
{
  /* Mengirimkan indeks baris terkecil M */
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return 0;
}
indeks GetFirstIdxKol(MATRIKS M)
{
  /* Mengirimkan indeks kolom terkecil M */
  return 0;
}
indeks GetLastIdxBrs(MATRIKS M)
{
  /* Mengirimkan indeks baris terbesar M */
  return NBrsEff(M) - 1;
}
indeks GetLastIdxKol(MATRIKS M)
{
  /* Mengirimkan indeks kolom terbesar M */
  return NKolEff(M) - 1;
}
boolean IsIdxEff(MATRIKS M, indeks i, indeks j)
{
  /* Mengirimkan true jika i, j adalah indeks efektif bagi M */
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return (i < NBrsEff(M) && i >= 0) && (j < NKolEff(M) && j >= 0);
}
ElType GetElmtDiagonal(MATRIKS M, indeks i)
{
  /* Mengirimkan elemen M(i,i) */
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS(MATRIKS MIn, MATRIKS *MHsl)
{
  /* Melakukan assignment MHsl  MIn */
  /* KAMUS LOKAL */
  indeks i, j;
  /* ALGORITMA */
  MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
  for (i = 0; i <= GetLastIdxBrs(MIn); i++)
  {
    for (j = 0; j <= GetLastIdxKol(MIn); j++)
    {
      Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
    }
  }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS(Graph *G, MATRIKS *M, int NB, int NK, char namafile[])
{
  /* I.S. IsIdxValid(NB,NK) */
  /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
  /* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
  /* Selanjutnya membaca nilai elemen per baris dan kolom */
  /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
  /* KAMUS LOKAL */
  indeks i, j;
  FILE *ptr;
  /* ALGORITMA */
  ptr = fopen(namafile, "r");
  if (ptr == NULL)
  {
    printf("Error! opening file\n");
    exit(1);
  }
  MakeMATRIKS(NB, NK, M);
  for (i = 0; i < NB; i++)
  {
    for (j = 0; j < NK; j++)
    {
      fscanf(ptr, "%c ", &Elmt(*M, i, j));
      if (Elmt(*M, i, j) == '^' || Elmt(*M, i, j) == 'v' || Elmt(*M, i, j) == '<' || Elmt(*M, i, j) == '>')
      {
        POINT P = MakePOINT(i, j);
        adrNode T;
        InsertNode(G, P, &T);
      }
    }
  }
  fclose(ptr);
}
void TulisMATRIKS(MATRIKS M)
{
  /* I.S. M terdefinisi */
  /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
  /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
  /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
  /* KAMUS LOKAL */
  indeks i, j;
  /* ALGORITMA */
  for (i = 0; i < NBrsEff(M); i++)
  {
    for (j = 0; j < NKolEff(M); j++)
    {
      printf("%c", Elmt(M, i, j));
    }
    printf("\n");
  }
  printf("\n");
}

void SimpanMATRIKS(MATRIKS M, char namafile[])
{
  /* I.S. M terdefinisi */
  /* F.S. Nilai M(i,j) ditulis ke file per baris per kolom*/
  /* Proses: Menulis nilai setiap elemen M ke file dengan traversal per baris dan per kolom */
  /* KAMUS LOKAL */
  indeks i, j;
  FILE *ptr;
  /* ALGORITMA */
  // ptr = fopen(namafile, "r");
  if ((ptr = fopen(namafile, "w")) == NULL)
  {
    printf("Error! opening file\n");
    exit(1);
  }

  for (i = 0; i < NBrsEff(M); i++)
  {
    for (j = 0; j < NKolEff(M); j++)
    {
      fprintf(ptr, "%c", Elmt(M, i, j));
    }
    fprintf(ptr, "\n");
  }
  fclose(ptr);
}
