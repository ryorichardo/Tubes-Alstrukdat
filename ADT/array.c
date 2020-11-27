/*** Array Willy Wangky ***/

#include <stdio.h>
#include "array.h"
#include "jam.h"
#include "mesinkata.h"
#include "point.h"

void MakeKataEmpty(Kata *Kata)
{
   Kata->TabKata[0] = 'e';
   Kata->TabKata[1] = 'm';
   Kata->TabKata[2] = 'p';
   Kata->TabKata[3] = 't';
   Kata->TabKata[4] = 'y';
   Kata->Length = 5;
}

void MakeKataBuild(Kata *Kata)
{
   Kata->TabKata[0] = 'b';
   Kata->TabKata[1] = 'u';
   Kata->TabKata[2] = 'i';
   Kata->TabKata[3] = 'l';
   Kata->TabKata[4] = 'd';
   Kata->Length = 5;
}

void MakeKataUpgrade(Kata *Kata)
{
   Kata->TabKata[0] = 'u';
   Kata->TabKata[1] = 'p';
   Kata->TabKata[2] = 'g';
   Kata->TabKata[3] = 'r';
   Kata->TabKata[4] = 'a';
   Kata->TabKata[5] = 'd';
   Kata->TabKata[6] = 'e';
   Kata->Length = 7;
}

void MakeKataBuy(Kata *Kata)
{
   Kata->TabKata[0] = 'b';
   Kata->TabKata[1] = 'u';
   Kata->TabKata[2] = 'y';
   Kata->Length = 3;
}

void MakeKataUndo(Kata *Kata)
{
   Kata->TabKata[0] = 'u';
   Kata->TabKata[1] = 'n';
   Kata->TabKata[2] = 'd';
   Kata->TabKata[3] = 'o';
   Kata->Length = 4;
}

void MakeKataExecute(Kata *Kata)
{
   Kata->TabKata[0] = 'e';
   Kata->TabKata[1] = 'x';
   Kata->TabKata[2] = 'e';
   Kata->TabKata[3] = 'c';
   Kata->TabKata[4] = 'u';
   Kata->TabKata[5] = 't';
   Kata->TabKata[6] = 'e';
   Kata->Length = 7;
}

void MakeKataMain(Kata *Kata)
{
   Kata->TabKata[0] = 'm';
   Kata->TabKata[1] = 'a';
   Kata->TabKata[2] = 'i';
   Kata->TabKata[3] = 'n';
   Kata->Length = 4;
}

void MakeKataServe(Kata *Kata)
{
   Kata->TabKata[0] = 's';
   Kata->TabKata[1] = 'e';
   Kata->TabKata[2] = 'r';
   Kata->TabKata[3] = 'v';
   Kata->TabKata[4] = 'e';
   Kata->Length = 5;
}

void MakeKataRepair(Kata *Kata)
{
   Kata->TabKata[0] = 'r';
   Kata->TabKata[1] = 'e';
   Kata->TabKata[2] = 'p';
   Kata->TabKata[3] = 'a';
   Kata->TabKata[4] = 'i';
   Kata->TabKata[5] = 'r';
   Kata->Length = 6;
}

void MakeKataDetail(Kata *Kata)
{
   Kata->TabKata[0] = 'd';
   Kata->TabKata[1] = 'e';
   Kata->TabKata[2] = 't';
   Kata->TabKata[3] = 'a';
   Kata->TabKata[4] = 'i';
   Kata->TabKata[5] = 'l';
   Kata->Length = 6;
}

void MakeKataOffice(Kata *Kata)
{
   Kata->TabKata[0] = 'o';
   Kata->TabKata[1] = 'f';
   Kata->TabKata[2] = 'f';
   Kata->TabKata[3] = 'i';
   Kata->TabKata[4] = 'c';
   Kata->TabKata[5] = 'e';
   Kata->Length = 6;
}

void MakeKataPrepare(Kata *Kata)
{
   Kata->TabKata[0] = 'p';
   Kata->TabKata[1] = 'r';
   Kata->TabKata[2] = 'e';
   Kata->TabKata[3] = 'p';
   Kata->TabKata[4] = 'a';
   Kata->TabKata[5] = 'r';
   Kata->TabKata[6] = 'e';
   Kata->Length = 7;
}

/**** KONSTRUKTOR ****/
<<<<<<< HEAD
void MakeTabWahanaEmpty(Wahana *ListWahana[10])
{
=======
void MakeTabWahanaEmpty (Wahana *ListWahana[10]){
>>>>>>> e49e88144924c6d024848cc4ce8e073547c6b2c3
   int i;
   for (i = IdxMin; i <= IdxMax; i++)
   {
      Kata Empty;
      MakeKataEmpty(&Empty);
      ListWahana[i]->Nama = Empty; //Make MARK
      ListWahana[i]->Harga = 0;
      ListWahana[i]->Kapasitas = 0;
      ListWahana[i]->Durasi = 0;
      ListWahana[i]->HargaBuild = 0;
      ListWahana[i]->DurasiBuild = 0;
      ListWahana[i]->Mat[0] = 0;
      ListWahana[i]->Mat[1] = 0;
      ListWahana[i]->Mat[2] = 0;
      ListWahana[i]->Deskripsi = Empty;
      ListWahana[i]->Rusak = true;
   }
}

void InitTabAction(Kata *ListAksi[11] )
/* Prosedur menginisialasi suatu array berisi daftar aksi dan durasi yang dibutuhkan dari file eksternal */
/* Cara inisialisasi di main : declare Kata ListAksi[11];
                              panggil prosedur InitTabAction(&ListAksi); */
{
   Kata BUILD;
   Kata UPGRADE;
   Kata BUY;
   Kata UNDO;
   Kata EXECUTE;
   Kata MAIN;
   Kata SERVE;
   Kata REPAIR;
   Kata DETAIL;
   Kata OFFICE;
   Kata PREPARE;

   MakeKataBuild(&BUILD);
   MakeKataUpgrade(&UPGRADE);
   MakeKataBuy(&BUY);
   MakeKataUndo(&UNDO);
   MakeKataExecute(&EXECUTE);
   MakeKataMain(&MAIN);
   MakeKataServe(&SERVE);
   MakeKataRepair(&REPAIR);
   MakeKataDetail(&DETAIL);
   MakeKataOffice(&OFFICE);
   MakeKataPrepare(&PREPARE);

   *ListAksi[0] = BUILD;
   *ListAksi[1] = UPGRADE;
   *ListAksi[2] = BUY;
   *ListAksi[3] = UNDO;
   *ListAksi[4] = EXECUTE;
   *ListAksi[5] = MAIN;
   *ListAksi[6] = SERVE;
   *ListAksi[7] = REPAIR;
   *ListAksi[8] = DETAIL;
   *ListAksi[9] = OFFICE;
   *ListAksi[10] = PREPARE;
}

// Wahana GetTabWahana (char namafile[])
/* Prosedur menginisialasi suatu array berisi daftar wahana dan spesifikasinya dari file eksternal */
/* {
   Wahana ListWahana[10];
   Wahana ListUpgrade[10];
   BacaFileWahana(namafile, &ListWahana, &ListUpgrade);
   int panjang = NbElmtTabWahana(ListWahana);
   Kata Empty;
   MakeKataEmpty(&Empty);
   ListWahana[panjang].Nama = Empty; //Make MARK  //Kayaknya nanti implementasinta ini gausah bikin mark tp harus makeempty dulu
   ListWahana[panjang].Harga = 0;
   ListWahana[panjang].Kapasitas = 0;
   ListWahana[panjang].Durasi = 0;
   ListWahana[panjang].HargaBuild = 0;
   ListWahana[panjang].DurasiBuild = 0;
   ListWahana[panjang].Mat[0] = 0;
   ListWahana[panjang].Mat[1] = 0;
   ListWahana[panjang].Mat[2] = 0;
   ListWahana[panjang].Deskripsi = Empty;
   ListWahana[panjang].Point = PointUndef;
   ListWahana[panjang].Rusak = true;
   return ListWahana; 
} */

//TabMaterial GetTabMaterial(char namafile[])
/* {
   TabMaterial TM;
   //BacaFileMaterial(namafile, &TM);
   return TM;
} */

TabLaporan MakeTabLaporan(Wahana ListWahana[10])
/* Fungsi untuk inisialisasi array laporan wahana */
{
   TabLaporan TL;
   int i = 0;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      TL.TL[i].Nama = ListWahana[i].Nama;
      TL.TL[i].Penggunaan = 0;
      TL.TL[i].PenghasilanTotal = 0;
      TL.TL[i].PenggunaanHari = 0;
      TL.TL[i].PenghasilanHari = 0;
      i++;
   }
   Kata Empty;
   MakeKataEmpty(&Empty);
   TL.TL[i].Nama = Empty;
   TL.TL[i].Penggunaan = 0;
   TL.TL[i].PenghasilanTotal = 0;
   TL.TL[i].PenggunaanHari = 0;
   TL.TL[i].PenghasilanHari = 0;
   return TL;
}

Wahana MakeWahana(Kata Nama, int Harga, int Kapasitas, int Durasi, int HargaBuild, int DurasiBuild, int Mat[3], Kata Deskripsi, POINT Point, boolean Rusak)
{
   Wahana W;
   W.Nama = Nama;
   W.Harga = Harga;
   W.Kapasitas = Kapasitas;
   W.Durasi = Durasi;
   W.HargaBuild = HargaBuild;
   W.DurasiBuild = DurasiBuild;
   W.Mat[0] = Mat[0];
   W.Mat[1] = Mat[1];
   W.Mat[2] = Mat[2];
   W.Deskripsi = Deskripsi;
   W.Point = Point;
   W.Rusak = Rusak;
   return W;
}

/**** EOP ****/
boolean isWahanaEmpty(Wahana W)
{
   Kata Empty;
   MakeKataEmpty(&Empty);
   return IsKataSama(W.Nama, Empty) && W.Harga == 0 && W.Kapasitas == 0 && W.Durasi == 0 && IsKataSama(W.Deskripsi, Empty);
}

boolean isLaporanEmpty(Laporan L)
{
   Kata Empty;
   MakeKataEmpty(&Empty);
   return IsKataSama(L.Nama, Empty) && L.Penggunaan == 0 && L.PenghasilanTotal == 0 && L.PenggunaanHari == 0 && L.PenghasilanHari == 0;
}

boolean isMaterialEmpty(Material M)
{
   Kata Empty;
   MakeKataEmpty(&Empty);
   return IsKataSama(M.Nama, Empty) && M.Harga == 0;
}

/**** OPERASI ****/
int NbElmtTabWahana(Wahana ListWahana[10])
{
   int i = 0;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      i++;
   }
   return i;
}

int NbElmtTabLaporan(TabLaporan TL)
{
   int i = 0;
   while (!isLaporanEmpty(TL.TL[i]))
   {
      i++;
   }
   return i;
}

int NbElmtTabMaterial(Material ListMaterial[3])
{
   /* Mengirimkan banyaknya elemen efektif tabel */
   /* Mengirimkan nol jika tabel kosong */
   /* *** Daya tampung container *** */
   int i = IdxMin;
   while (!isMaterialEmpty(ListMaterial[i]))
   {
      i++;
   }
   return (i);
}

void AddWahana(Wahana *ListWahana[10], Wahana W)
/* Prosedur menambahkan suatu wahana beserta spesifikasinya ke daftar wahana */
{
   int panjang = NbElmtTabWahana(*ListWahana);
   *ListWahana[panjang] = W;
}

void RefreshLaporan(TabLaporan *TL)
/* I.S. TL tidak kosong */
/* Prosedur untuk "refresh" laporan ketika memulai hari baru */
{
   int length = NbElmtTabLaporan(*TL);
   for (int i = 0; i < length; i++)
   {
      TL->TL[i].PenggunaanHari = 0;
      TL->TL[i].PenghasilanHari = 0;
   }
}

void AddLaporan(TabLaporan *TL, Wahana W)
/* Prosedur menambahkan laporan ke array laporan ketika wahana baru dibangun */
{
   int panjang = NbElmtTabLaporan(*TL);
   TL->TL[panjang].Nama = W.Nama;
   TL->TL[panjang].Penggunaan = 0;
   TL->TL[panjang].PenghasilanTotal = 0;
   TL->TL[panjang].PenggunaanHari = 0;
   TL->TL[panjang].PenghasilanHari = 0;
}

Wahana SearchWahana(Wahana ListWahana[10], Kata Nama)
/* Fungsi untuk mencari apakah suatu wahana ada di daftar wahana */
/* Mengembalikan Wahana kosong jika tidak ada */
{
   int i = 0;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      if (IsKataSama(ListWahana[i].Nama, Nama))
      {
         return ListWahana[i];
      }
   }
   return ListWahana[i];
}

Wahana SearchWahanaFromPoint(Wahana ListWahana[10], POINT posisi)
/* Fungsi untuk mencari apakah suatu wahana ada di sekitar pemain */
/* Mengembalikan Wahana kosong jika tidak ada */
{
   int i = 0;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      if (Panjang(ListWahana[i].Point, posisi) <= 1)
      {
         return ListWahana[i];
      }
   }
   return ListWahana[i];
}

int SearchMaterial(Material ListMaterial[3], Kata X)
{
   /* Search apakah ada elemen tabel T yang bernilai X */
   /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
   /* Jika tidak ada, mengirimkan IdxUndef */
   /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
   /* Skema Searching yang digunakan bebas */
   if (NbElmtTabMaterial(ListMaterial) == 0)
   {
      return (IdxUndef);
   }
   else
   {
      int i = IdxMin;
      boolean found = false;
      while ((found == false) && (i < NbElmtTabMaterial(ListMaterial)))
      {
         if (IsKataSama(ListMaterial[i].Nama, X))
         {
            found = true;
            return (i);
         }
         i++;
      }
      if (found == false)
      {
         return (IdxUndef);
      }
   }
}

void PrintListWahana(Wahana ListWahana[10])
/* Prosedur untuk menampilkan daftar wahana yang tersedia */
{
<<<<<<< HEAD
   int i = 0;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      printf("%d. %s\n", i + 1, ListWahana[i].Nama); //ini nanti diganti sama print kata;
      i++;
=======
   for(int i=0; i<10; i++){
      printf("%d. %s\n", i+1, ListWahana[i].Nama); //ini nanti diganti sama print kata;
>>>>>>> e49e88144924c6d024848cc4ce8e073547c6b2c3
   }
}

void PrintDetailWahana(Wahana ListWahana[10], Kata Nama)
/* Prosedur untuk menampilkan detail dari suatu wahana */
{
<<<<<<< HEAD
   int i = 0;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      if (IsKataSama(ListWahana[i].Nama, Nama))
      {
=======
   for(int i=0; i<10; i++){
      if(IsKataSama(ListWahana[i].Nama, Nama)){
>>>>>>> e49e88144924c6d024848cc4ce8e073547c6b2c3
         printf("Nama Wahana : %s\n", Nama); //Ini nanti diganti sama printkata
         printf("Harga Tiket : %d\n", ListWahana[i].Harga);
         printf("Kapasitas Wahana : %d\n", ListWahana[i].Kapasitas);
         printf("Durasi Wahana : %d\n", ListWahana[i].Durasi);
         printf("Deskripsi Wahana : ", ListWahana[i].Deskripsi); //Ini nanti diganti sama printkata
      }
      i++;
   }
}

void PrintLaporanWahana(TabLaporan TL, Kata Nama)
/* Prosedur untuk menampilkan laporan wahana */
{
   int i = 0;
   while (!isLaporanEmpty(TL.TL[i]))
   {
      if (IsKataSama(TL.TL[i].Nama, Nama))
      {
         printf("Nama Wahana : %s\n", Nama);
         printf("Penggunaan Total : %d\n", TL.TL[i].Penggunaan);
         printf("Penghasilan Total : %d\n", TL.TL[i].PenghasilanTotal);
         printf("Penggunaan Harian : %d\n", TL.TL[i].PenggunaanHari);
         printf("Penghasilan Harian : %d\n", TL.TL[i].PenghasilanHari);
      }
      i++;
   }
}
