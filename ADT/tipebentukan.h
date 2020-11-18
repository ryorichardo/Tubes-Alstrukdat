# ifndef tipebentukan_H
# define tipebentukan_H

typedef struct {
    char Nama[50];
    int Harga;
    int Kapasitas;
    //Jam Durasi;
    char Deskripsi[100];
} Wahana;

// Selektor
#define Nama(P) P.Nama 
#define Harga(P) P.Haraga 
#define Kapasitas(P) P.Kapasitas 
#define Deskripsi(P) P.Deskripsi 

typedef struct {
    char Nama[50];
    int Harga;
} Material;

// Selektor
#define Nama(P) P.Nama 
#define Harga(P) P.Harga 

# endif