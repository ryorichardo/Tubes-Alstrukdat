/*** Array Willy Wangky ***/

#include <stdio.h>
#include "array.h"
#include "../Jam/jam.h"
#include "../Mesinkata/mesinkata.h"
#include "../Point/point.h"

void MakeKataEmpty(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'empty' */
{
   Kata->TabKata[0] = 'e';
   Kata->TabKata[1] = 'm';
   Kata->TabKata[2] = 'p';
   Kata->TabKata[3] = 't';
   Kata->TabKata[4] = 'y';
   Kata->Length = 5;
}

void MakeKataBuild(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'build' */
{
   Kata->TabKata[0] = 'b';
   Kata->TabKata[1] = 'u';
   Kata->TabKata[2] = 'i';
   Kata->TabKata[3] = 'l';
   Kata->TabKata[4] = 'd';
   Kata->Length = 5;
}

void MakeKataUpgrade(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'upgrade' */
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
/* Membuat Tipe Kata dengan isi 'buy' */
{
   Kata->TabKata[0] = 'b';
   Kata->TabKata[1] = 'u';
   Kata->TabKata[2] = 'y';
   Kata->Length = 3;
}

void MakeKataUndo(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'undo' */
{
   Kata->TabKata[0] = 'u';
   Kata->TabKata[1] = 'n';
   Kata->TabKata[2] = 'd';
   Kata->TabKata[3] = 'o';
   Kata->Length = 4;
}

void MakeKataExecute(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'execute' */
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
/* Membuat Tipe Kata dengan isi 'main' */
{
   Kata->TabKata[0] = 'm';
   Kata->TabKata[1] = 'a';
   Kata->TabKata[2] = 'i';
   Kata->TabKata[3] = 'n';
   Kata->Length = 4;
}

void MakeKataServe(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'serve' */
{
   Kata->TabKata[0] = 's';
   Kata->TabKata[1] = 'e';
   Kata->TabKata[2] = 'r';
   Kata->TabKata[3] = 'v';
   Kata->TabKata[4] = 'e';
   Kata->Length = 5;
}

void MakeKataRepair(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'repair' */
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
/* Membuat Tipe Kata dengan isi 'detail' */
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
/* Membuat Tipe Kata dengan isi 'office' */
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
/* Membuat Tipe Kata dengan isi 'prepare' */
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

void MakeKataExit(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'exit' */
{
   Kata->TabKata[0] = 'e';
   Kata->TabKata[1] = 'x';
   Kata->TabKata[2] = 'i';
   Kata->TabKata[3] = 't';
   Kata->Length = 4;
}

void MakeKataNew(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'new' */
{
   Kata->TabKata[0] = 'n';
   Kata->TabKata[1] = 'e';
   Kata->TabKata[2] = 'w';
   Kata->Length = 3;
}

void MakeKataLoad(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'load' */
{
   Kata->TabKata[0] = 'l';
   Kata->TabKata[1] = 'o';
   Kata->TabKata[2] = 'a';
   Kata->TabKata[3] = 'd';
   Kata->Length = 4;
}

void MakeKataSave(Kata *Kata)
/* Membuat Tipe Kata dengan isi 'load' */
{
   Kata->TabKata[0] = 's';
   Kata->TabKata[1] = 'a';
   Kata->TabKata[2] = 'v';
   Kata->TabKata[3] = 'e';
   Kata->Length = 4;
}

/**** KONSTRUKTOR ****/
void MakeTabWahanaEmpty(Wahana ListWahana[], int max)
/* Membuat array MARK bertipe wahana */
{
   int i;
   for (i = IdxMin; i < max; i++)
   {
      Kata Empty;
      MakeKataEmpty(&Empty);
      ListWahana[i].Nama = Empty; //Make MARK
      ListWahana[i].Harga = 0;
      ListWahana[i].Kapasitas = 0;
      ListWahana[i].Pemain = 0;
      ListWahana[i].Durasi = 0;
      ListWahana[i].HargaBuild = 0;
      ListWahana[i].DurasiBuild = 0;
      ListWahana[i].Mat[0] = 0;
      ListWahana[i].Mat[1] = 0;
      ListWahana[i].Mat[2] = 0;
      ListWahana[i].Deskripsi = Empty;
      ListWahana[i].Ukuran = MakePOINT(0, 0);
      ListWahana[i].Peta = 0;
      ListWahana[i].Point = MakePOINT(0, 0);
      ListWahana[i].Rusak = true;
   }
}

void MakeTabSaveEmpty(Save ListSave[3])
/* Membuat array MARK bertipe wahana */
{
   int i = 0;
   // for (i = 0; i < 3; i++)
   // {
   //    Kata Empty;
   //    MakeKataEmpty(&Empty);
   //    ListSave[i].Player = Empty; //Make MARK
   //    ListSave[i].Day = 0;
   //    ListSave[i].Money = 0;
   //    ListSave[i].Close = 0;
   //    ListSave[i].Banyak = 0;
   // }
   Kata Empty;
   MakeKataEmpty(&Empty);
   ListSave[i].Player = Empty; //Make MARK
   ListSave[i].Day = 0;
   ListSave[i].Money = 0;
   ListSave[i].Close = 0;
   ListSave[i].Banyak = 0;
   ListSave[i].Absis = 0;
   ListSave[i].Ordinat = 0;
}
void MakeTabMaterialEmpty(Material ListMaterial[3])
/* Membuat array MARK bertipe Material */
{
   int i;
   for (i = 0; i < 3; i++)
   {
      Kata Empty;
      MakeKataEmpty(&Empty);
      ListMaterial[i].Nama = Empty; //Make MARK
      ListMaterial[i].Harga = 0;
   }
}

void InitTabAction(Kata ListAksi[19])
/* Prosedur menginisialasi suatu array berisi daftar aksi dan durasi yang dibutuhkan dari file eksternal */
/* Cara inisialisasi di main : declare Kata ListAksi[16];
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
   Kata EXIT;
   Kata NEW;
   Kata LOAD;
   Kata SAVE;

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
   MakeKataExit(&EXIT);
   MakeKataNew(&NEW);
   MakeKataLoad(&LOAD);
   MakeKataSave(&SAVE);

   Kata W, A, S, D;
   W.TabKata[0] = 'w';
   W.Length = 1;
   A.TabKata[0] = 'a';
   A.Length = 1;
   S.TabKata[0] = 's';
   S.Length = 1;
   D.TabKata[0] = 'd';
   D.Length = 1;

   ListAksi[0] = BUILD;
   ListAksi[1] = UPGRADE;
   ListAksi[2] = BUY;
   ListAksi[3] = UNDO;
   ListAksi[4] = EXECUTE;
   ListAksi[5] = MAIN;
   ListAksi[6] = SERVE;
   ListAksi[7] = REPAIR;
   ListAksi[8] = DETAIL;
   ListAksi[9] = OFFICE;
   ListAksi[10] = PREPARE;
   ListAksi[11] = EXIT;
   ListAksi[12] = W;
   ListAksi[13] = A;
   ListAksi[14] = S;
   ListAksi[15] = D;
   ListAksi[16] = NEW;
   ListAksi[17] = LOAD;
   ListAksi[18] = SAVE;
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

void MakeTabLaporanEmpty(TabLaporan *TLap)
/* Fungsi untuk inisialisasi array laporan wahana yang berisi MARK untuk laporan */
{
   for (int i = 0; i < 100; i++)
   {
      Kata Empty;
      MakeKataEmpty(&Empty);
      TLap->TL[i].Nama = Empty;
      TLap->TL[i].Penggunaan = 0;
      TLap->TL[i].PenghasilanTotal = 0;
      TLap->TL[i].PenggunaanHari = 0;
      TLap->TL[i].PenghasilanHari = 0;
      i++;
   }
}

Wahana MakeWahana(Kata Nama, int Harga, int Kapasitas, int Pemain, int Durasi, int HargaBuild, int DurasiBuild, int Mat[3], Kata Deskripsi, POINT Ukuran, int Peta, POINT Point, boolean Rusak)
/* Fungsi untuk membentuk suatu tipe wahana */
{
   Wahana W;
   W.Nama = Nama;
   W.Harga = Harga;
   W.Kapasitas = Kapasitas;
   W.Pemain = Pemain;
   W.Durasi = Durasi;
   W.HargaBuild = HargaBuild;
   W.DurasiBuild = DurasiBuild;
   W.Mat[0] = Mat[0];
   W.Mat[1] = Mat[1];
   W.Mat[2] = Mat[2];
   W.Deskripsi = Deskripsi;
   W.Ukuran = Ukuran;
   W.Peta = 0;
   W.Point = Point;
   W.Rusak = Rusak;
   return W;
}

/**** EOP ****/
boolean isWahanaEmpty(Wahana W)
/* Mengirimkan true jika W = MARK untuk wahana */
{
   Kata Empty;
   MakeKataEmpty(&Empty);
   return IsKataSama(W.Nama, Empty) && W.Harga == 0 && W.Kapasitas == 0 && W.Durasi == 0 && IsKataSama(W.Deskripsi, Empty);
}

boolean isLaporanEmpty(Laporan L)
/* Mengirimkan true jika L = MARK untuk laporan */
{
   Kata Empty;
   MakeKataEmpty(&Empty);
   return IsKataSama(L.Nama, Empty) && L.Penggunaan == 0 && L.PenghasilanTotal == 0 && L.PenggunaanHari == 0 && L.PenghasilanHari == 0;
}

boolean isMaterialEmpty(Material M)
/* Mengirimkan true jika M = MARK untuk material */
{
   Kata Empty;
   MakeKataEmpty(&Empty);
   return IsKataSama(M.Nama, Empty) && M.Harga == 0;
}

/**** OPERASI ****/
int NbElmtTabWahana(Wahana ListWahana[10])
/* Mengirimkan banyaknya isi array Wahana */
/* Mengirimkan nol jika tabel kosong */
{
   int i = 0;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      i++;
   }
   return i;
}

int NbElmtTabLaporan(TabLaporan TLap)
/* Mengirimkan banyaknya isi array laporan */
/* Mengirimkan nol jika tabel kosong */
{
   int i = 0;
   while (!isLaporanEmpty(TLap.TL[i]) && i < 100)
   {
      i++;
   }
   return i;
}

int NbElmtTabMaterial(Material ListMaterial[3])
{
   /* Mengirimkan banyaknya elemen efektif tabel */
   /* Mengirimkan nol jika tabel kosong */
   int i = IdxMin;
   while (!isMaterialEmpty(ListMaterial[i]))
   {
      i++;
   }
   return (i);
}

void AddWahana(Wahana ListWahana[10], Wahana W)
/* Prosedur menambahkan suatu wahana beserta spesifikasinya ke daftar wahana */
{
   int panjang = NbElmtTabWahana(ListWahana);
   ListWahana[panjang] = W;
}

void DelWahana(Wahana ListWahana[10])
/* Prosedur menambahkan suatu wahana beserta spesifikasinya ke daftar wahana */
{
   int panjang = NbElmtTabWahana(ListWahana);
   int i = panjang - 1;
   Kata Empty;
   MakeKataEmpty(&Empty);
   ListWahana[i].Nama = Empty; //Make MARK
   ListWahana[i].Harga = 0;
   ListWahana[i].Kapasitas = 0;
   ListWahana[i].Pemain = 0;
   ListWahana[i].Durasi = 0;
   ListWahana[i].HargaBuild = 0;
   ListWahana[i].DurasiBuild = 0;
   ListWahana[i].Mat[0] = 0;
   ListWahana[i].Mat[1] = 0;
   ListWahana[i].Mat[2] = 0;
   ListWahana[i].Deskripsi = Empty;
   ListWahana[i].Ukuran = MakePOINT(0, 0);
   ListWahana[i].Peta = 0;
   ListWahana[i].Point = MakePOINT(0, 0);
   ListWahana[i].Rusak = true;
}
void RefreshLaporan(TabLaporan *TLap)
/* Prosedur untuk "refresh" laporan ketika memulai hari baru */
{
   int length = NbElmtTabLaporan(*TLap);
   for (int i = 0; i < length; i++)
   {
      TLap->TL[i].PenggunaanHari = 0;
      TLap->TL[i].PenghasilanHari = 0;
   }
}

void AddLaporan(TabLaporan *TLap, Wahana W)
/* Prosedur menambahkan laporan ke array laporan ketika wahana baru dibangun */
{
   int panjang = NbElmtTabLaporan(*TLap);
   TLap->TL[panjang].Nama = W.Nama;
   TLap->TL[panjang].Penggunaan = 0;
   TLap->TL[panjang].PenghasilanTotal = 0;
   TLap->TL[panjang].PenggunaanHari = 0;
   TLap->TL[panjang].PenghasilanHari = 0;
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
      i++;
   }
   return ListWahana[i];
}

Wahana SearchWahanaFromPoint(Wahana ListWahana[10], POINT Player, int IdxMap)
/* Fungsi untuk mencari apakah suatu wahana ada di sekitar pemain */
/* Mengembalikan Wahana kosong jika tidak ada */
{
   int i, count, Rect, utara, timur, selatan, barat;
   int RectAR, RectAL, RectAT, RectAB, RectBR, RectBL, RectBT, RectBB;
   count = 0;
   // atas
   i = 0;
   utara = -1;
   Rect = Absis(Player) - 1;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      RectAB = Absis(Point(ListWahana[i])) + LebarWahana(ListWahana[i]) - 1;
      if (RectAB == Rect && IndexPeta(ListWahana[i]) == IdxMap)
      {
         utara = i;
         count++;
         break;
      }
      i++;
   }
   //kanan
   i = 0;
   timur = -1;
   Rect = Ordinat(Player) + 1;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      RectAL = Ordinat(Point(ListWahana[i]));
      if (RectAL == Rect && IndexPeta(ListWahana[i]) == IdxMap)
      {
         timur = i;
         count++;
         break;
      }
      i++;
   }
   //bawah
   i = 0;
   selatan = -1;
   Rect = Absis(Player) + 1;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      RectAT = Absis(Point(ListWahana[i]));
      if (RectAT == Rect && IndexPeta(ListWahana[i]) == IdxMap)
      {
         selatan = i;
         count++;

         break;
      }
      i++;
   }
   //kiri
   i = 0;
   barat = -1;
   Rect = Ordinat(Player) - 1;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      RectAR = Ordinat(Point(ListWahana[i])) + PanjangWahana(ListWahana[i]) - 1;
      if (RectAR == Rect && IndexPeta(ListWahana[i]) == IdxMap)
      {
         barat = i;
         count++;

         break;
      }
      i++;
   }

   if (count == 0)
   {
      printf("Tidak ada wahana\n");
   }
   else
   {
      printf("Pilih wahana yang mana?\n");
      if (utara != -1)
      {
         PrintKata(Nama(ListWahana[utara]));
         printf("\n");
      }
      if (timur != -1)
      {
         PrintKata(Nama(ListWahana[timur]));
         printf("\n");
      }
      if (barat != -1)
      {
         PrintKata(Nama(ListWahana[barat]));
         printf("\n");
      }
      if (selatan != -1)
      {
         PrintKata(Nama(ListWahana[selatan]));
         printf("\n");
      }
      STARTKATA(stdin);
      if (IsKataSama(CKata, Nama(ListWahana[utara])))
      {
         i = utara;
      }
      else if (IsKataSama(CKata, Nama(ListWahana[timur])))
      {
         i = timur;
      }
      else if (IsKataSama(CKata, Nama(ListWahana[selatan])))
      {
         i = selatan;
      }
      else if (IsKataSama(CKata, Nama(ListWahana[barat])))
      {
         i = barat;
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
   int i = 0;
   while (!isMaterialEmpty(ListMaterial[i]))
   {
      if (IsKataSama(ListMaterial[i].Nama, X))
      {
         return i;
      }
      i++;
   }
   return IdxUndef;
}

void PrintListWahana(Wahana ListWahana[100])
/* Prosedur untuk menampilkan daftar wahana yang tersedia */
{
   int i = 0;
   while (!isWahanaEmpty(ListWahana[i]))
   {
      printf("%d. ", i + 1); //ini nanti diganti sama print kata;
      PrintKata(ListWahana[i].Nama), printf("\n");
      i++;
   }
}

void PrintDetailWahana(Wahana ArrayWahana[100], Kata NamaWahana)
/* Prosedur untuk menampilkan detail dari suatu wahana */
{
   int i = 0;
   boolean found = false;
   while (!isWahanaEmpty(ArrayWahana[i]) && !found)
   {
      if (IsKataSama(NamaWahana, ArrayWahana[i].Nama))
      {
         printf("\n\n#############################################\n");
         printf("Nama Wahana : ");
         PrintKata(NamaWahana);
         printf("\n");
         printf("Harga Tiket : %d\n", Harga(ArrayWahana[i]));
         printf("Kapasitas Wahana : %d\n", Kapasitas(ArrayWahana[i]));
         printf("Durasi Wahana : %d\n", Durasi(ArrayWahana[i]));
         printf("Deskripsi Wahana : ");
         PrintKata(ArrayWahana[i].Deskripsi);
         printf("\n");
         printf("\n#############################################\n\n");
         found = true;
      }
      i++;
   }
   if (!found)
   {
      printf("Wahana tersebut tidak ada");
   }
}

void PrintLaporanWahana(TabLaporan TLap, Kata Nama)
/* Prosedur untuk menampilkan laporan wahana */
{
   int i = 0;
   boolean found = false;
   while (!isLaporanEmpty(TLap.TL[i]) && !found)
   {
      if (IsKataSama(TLap.TL[i].Nama, Nama))
      {
         printf("\n\n#############################################\n");
         printf("Nama Wahana : ");
         PrintKata(Nama);
         printf("\n");
         printf("Penggunaan Total : %d\n", TLap.TL[i].Penggunaan);
         printf("Penghasilan Total : %d\n", TLap.TL[i].PenghasilanTotal);
         printf("Penggunaan Harian : %d\n", TLap.TL[i].PenggunaanHari);
         printf("Penghasilan Harian : %d\n", TLap.TL[i].PenghasilanHari);
         printf("\n#############################################\n\n");
         found = true;
      }
      i++;
   }

   if (!found)
   {
      printf("Wahana tersebut tidak ada");
   }
}
