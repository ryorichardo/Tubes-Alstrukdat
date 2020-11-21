/*** Array Willy Wangky ***/

#include <stdio.h>
#include "array.h"
#include "jam.h"
#include "mesinkata.h"
#include "point.h" 

/**** KONSTRUKTOR ****/

TabAction GetAction (char namafile[])
/* Prosedur menginisialasi suatu array berisi daftar aksi dan durasi yang dibutuhkan dari file eksternal */
{
   TabAction TA;
   //BacaFileAction(namafile, &TA)
   return TA;    
}

TabWahana GetTabWahana (char namafile[])
/* Prosedur menginisialasi suatu array berisi daftar wahana dan spesifikasinya dari file eksternal */
{
   TabWahana TW;
   BacaFileWahana(namafile, &TW);
   int panjang = NbElmtTabWahana(TW);
   TW.TW[panjang].Nama = Empty; //Make MARK
   TW.TW[panjang].Harga = 0;
   TW.TW[panjang].Kapasitas = 0;
   TW.TW[panjang].Durasi = 0;
   TW.TW[panjang].HargaBuild = 0;
   TW.TW[panjang].DurasiBuild = 0;
   TW.TW[panjang].Mat[0] = 0;
   TW.TW[panjang].Mat[1] = 0;
   TW.TW[panjang].Mat[2] = 0;
   TW.TW[panjang].Deskripsi = Empty;
   TW.TW[panjang].Point = PointUndef;
   TW.TW[panjang].Rusak = true;
   return TW;
}

TabMaterial GetTabMaterial(char namafile[])
{
   TabMaterial TM;
   //BacaFileMaterial(namafile, &TM);
   return TM;
}

TabLaporan MakeTabLaporan(TabWahana TW)
/* Fungsi untuk inisialisasi array laporan wahana */
{
   TabLaporan TL;
   int i=0;
   while(!isWahanaEmpty(TW.TW[i])){
      TL.TL[i].Nama = TW.TW[i].Nama;
      TL.TL[i].Penggunaan = 0;
      TL.TL[i].PenghasilanTotal = 0;
      TL.TL[i].PenggunaanHari = 0;
      TL.TL[i].PenghasilanHari = 0;
      i++;
   }
   TL.TL[i].Nama = Empty;
   TL.TL[i].Penggunaan = 0;
   TL.TL[i].PenghasilanTotal = 0;
   TL.TL[i].PenggunaanHari = 0;
   TL.TL[i].PenghasilanHari = 0;
   return TL;
}


Wahana MakeWahana (Kata Nama, int Harga, int Kapasitas, int Durasi, int HargaBuild, int DurasiBuild, int Mat[3], Kata Deskripsi, POINT Point, boolean Rusak)
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
boolean isWahanaEmpty(Wahana W){
   return IsKataSama(W.Nama, Empty) && W.Harga==0 && W.Kapasitas==0 && W.Durasi==0 && IsKataSama(W.Deskripsi, Empty);
}

boolean isLaporanEmpty(Laporan L){
   return IsKataSama(L.Nama, Empty) && L.Penggunaan==0 && L.PenghasilanTotal==0 && L.PenggunaanHari==0 && L.PenghasilanHari==0;
}

boolean isMaterialEmpty(Material M){
   return IsKataSama(M.Nama, Empty) && M.Harga==0;
}

/**** OPERASI ****/
int NbElmtTabWahana(TabWahana TW)
{
   int i =0;
   while(!isWahanaEmpty(TW.TW[i])){
      i++;
   }
   return i;
}

int NbElmtTabLaporan(TabLaporan TL)
{
   int i =0;
   while(!isLaporanEmpty(TL.TL[i])){
      i++;
   }
   return i;
}

int NbElmtTabMaterial (TabMaterial TM){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    int i = IdxMin;
    while (!isMaterialEmpty(TM.TM[i])){
        i++;
    }
    return (i);
}

void AddWahana(TabWahana *TW, Wahana W)
/* Prosedur menambahkan suatu wahana beserta spesifikasinya ke daftar wahana */
{
   int panjang = NbElmtTabWahana(*TW);
   TW->TW[panjang] = W;
   // Make MARK
}

void RefreshLaporan (TabLaporan *TL)
/* I.S. TL tidak kosong */
/* Prosedur untuk "refresh" laporan ketika memulai hari baru */
{
   int length = sizeof TL / sizeof TL[0];
   for (int i=0; i<length; i++){
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
   // Make MARK
}

boolean SearchWahana(TabWahana TW, Kata Nama)
/* Fungsi untuk mencari apakah suatu wahana ada di daftar wahana */
{
   int i=0;
   while(!isWahanaEmpty(TW.TW[i])){
      if(IsKataSama(TW.TW[i].Nama, Nama)){
         return true;
      }
   }
   return false;
}

int SearchMaterial (TabMaterial T, Kata X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
    if (NbElmtTabMaterial(T) == 0){
        return (IdxUndef);
    }
    else{
        int i = IdxMin;
        boolean found = false;
        while ((found == false) && (i < NbElmtTabMaterial(T))){
            if (IsKataSama(T.TM[i].Nama, X)){
                found = true;
                return (i);
            }
            i++;
        }
        if (found == false){
            return (IdxUndef);
        }
    }
}

void PrintListWahana(TabWahana TW)
/* Prosedur untuk menampilkan daftar wahana yang tersedia */
{
   int i=0;
   while(!isWahanaEmpty(TW.TW[i])){
      printf("%d. %s\n", i+1, TW.TW[i].Nama); //ini nanti diganti sama print kata;
      i++;
   }
}

void PrintDetailWahana(TabWahana TW, Kata Nama)
/* Prosedur untuk menampilkan detail dari suatu wahana */
{
   int i=0;
   while(!isWahanaEmpty(TW.TW[i])){
      if(IsKataSama(TW.TW[i].Nama, Nama)){
         printf("Nama Wahana : %s\n", Nama); //Ini nanti diganti sama printkata
         printf("Harga Tiket : %d\n", TW.TW[i].Harga);
         printf("Kapasitas Wahana : %d\n", TW.TW[i].Kapasitas);
         printf("Durasi Wahana : %d\n", TW.TW[i].Durasi);
         printf("Deskripsi Wahana : ", TW.TW[i].Deskripsi); //Ini nanti diganti sama printkata
      }
      i++;
   }
}

void PrintLaporanWahana(TabLaporan TL, Kata Nama)
/* Prosedur untuk menampilkan laporan wahana */
{
   int i=0;
   while(!isLaporanEmpty(TL.TL[i])){
      if(IsKataSama(TL.TL[i].Nama, Nama)){
         printf("Nama Wahana : %s\n", Nama);
         printf("Penggunaan Total : %d\n", TL.TL[i].Penggunaan);
         printf("Penghasilan Total : %d\n", TL.TL[i].PenghasilanTotal);
         printf("Penggunaan Harian : %d\n", TL.TL[i].PenggunaanHari);
         printf("Penghasilan Harian : %d\n", TL.TL[i].PenghasilanHari);
      }
      i++;
   }
}
