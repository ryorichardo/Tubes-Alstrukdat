/* Nama : Dzaki Muhammad */
/* NIM : 13519049 */
/* Tanggal : 1 September 2020 */
/* File : jam.c */
/* Body ADT Jam */
#include <stdio.h>
#include "jam.h"
/* -----------konstruktor Jam--------- */
JAM MakeJAM(int H, int M)
/* Membentuk Jam dari H, M yg valid */
{ /* Kamus Lokal */
	JAM J1;
	/* Algoritma */
	Hour(J1) = H;
	Minute(J1) = M;
	return J1;
}


/*------------Baca & Tulis jam-----------*/
void TulisJAM(JAM J)
/* I.S. : J sembarang*/
/* F.S. : J ditulis ke layar dengan format HH:MM */
/* Proses : Menulis ke layar */
{ /* Kamus lokal */
	/* Algoritma */
	if (Hour(J) < 10){
		if (Minute(J) < 10){
			printf("0%d:0%d", Hour(J), Minute(J));
		}
		else{
			printf("0%d:%d", Hour(J), Minute(J));
		}
	}
	else{
		if (Minute(J) < 10){
			printf("%d:0%d", Hour(J), Minute(J));
		}
		else{
			printf("%d:%d", Hour(J), Minute(J));
		}
	}
}

long JAMToMenit(JAM J)
/* Konversi Jam menjadi menit */
{ /* Kamus Lokal */
	/* Algoritma */
	return(60 * Hour(J) + Minute(J));
}

JAM MenitToJAM(long N)
/* Konversi menit ke Jam */
{ /* Kamus Lokal */
	int sisa;
	JAM JOut;
	/* Algoritma */
	N = N % 1440; // harus ditambah ini agar valid
	Hour(JOut) = N / 60;
	sisa = N % 60;
	Minute(JOut) = sisa;
	return JOut;
}

/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */

boolean JLE (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
	return(JAMToMenit(J1)<=JAMToMenit(J2));
}

boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
	return(JAMToMenit(J1)>JAMToMenit(J2));
}

/* *** Operator aritmatika JAM *** */

JAM NextNMenit (JAM J, int N)
/* Mengirim N menit setelah J dalam bentuk JAM */
{
	return(MenitToJAM((JAMToMenit(J)+N)));
}

JAM UpdateJam(JAM CurrentJam, JAM Durasi)
/* Update Jam setelah wahana berjalan */
{
	return(MenitToJAM((JAMToMenit(CurrentJam)+JAMToMenit(Durasi))));
}

/* *** Kelompok Operator Aritmetika *** */
long SelisihJam (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm menit, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
	if (JGT(JAw, JAkh)){
		return(JAMToMenit(JAkh)+86400-JAMToMenit(JAw));
	}
	else{
		return(JAMToMenit(JAkh)- JAMToMenit(JAw));
	}
}