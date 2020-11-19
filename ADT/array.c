/* Ryo Richardo 13519193 */
/* Pra praktikum 3 */

#include "boolean.h"
#include "array.h"
#include <stdio.h>

/*  Kamus Umum */
//#define IdxMax 99
/* Indeks maksimum array */
//#define IdxMin 0
/* Indeks minimum array */
//#define IdxUndef -999 
/* Indeks tak terdefinisi*/
//#define ValUndef -1
/* Nilai elemen tak terdefinisi*/

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabMaterial T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    int i = IdxMin;
    while (Harga(Elmt(T, i)) != 0){
        i++;
    }
    return (i);
}

IdxType GetLastIdx (TabMaterial T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    if (NbElmt(T) == 0){
        return(IdxMin);
    }
    else{
        return (NbElmt(T)-1);
    }
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiTab (TabMaterial T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
	if (NbElmt != 0){
		int i;
		for (i = IdxMin; i <= GetLastIdx(T); i++){
			printf("%d,", Elmt(T, i));
		}
	}
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search (TabMaterial T, Kata X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
    if (NbElmt(T) == 0){
        return (IdxUndef);
    }
    else{
        int i = IdxMin;
        boolean found = false;
        while ((found == false) && (i < NbElmt(T))){
            if (IsKataSama(Nama(Elmt(T, i)), X)){
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

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabMaterial * T, Material X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    Elmt(*T, NbElmt(*T)) = X;
}