/* File: jam.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#ifndef JAM_H
#define JAM_H

#include "../boolean.h"

/* *** Definisi TYPE JAM <HH:MM:SS> *** */
typedef struct
{
   int HH; /* integer [0..23] */
   int MM; /* integer [0..59] */
} JAM;

/* *** Notasi Akses: selektor JAM *** */
#define Hour(J) (J).HH
#define Minute(J) (J).MM

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM(int HH, int MM);
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM valid untuk membentuk JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */

void TulisJAM(JAM J);
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToMenit(JAM J);
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah menit dari pukul 0:0:0 */
/* Rumus : menit =  60*HH + MM */

JAM MenitToJAM(long N);
/* Mengirim  konversi Menit ke JAM */
/* Catatan: Jika N >= 1440, maka harus dikonversi dulu menjadi jumlah menit yang
   mewakili jumlah menit yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 1440, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JLE(JAM J1, JAM J2);
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT(JAM J1, JAM J2);
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
JAM NextNMenit(JAM J, int N);
/* Mengirim N menit setelah J dalam bentuk JAM */
JAM UpdateJam(JAM CurrentJam, JAM Durasi);
/* Update Jam setelah wahana berjalan */
/* *** Kelompok Operator Aritmetika *** */
long SelisihJam(JAM JAw, JAM JAkh);
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */

#endif