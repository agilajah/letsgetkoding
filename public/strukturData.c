#ifndef MONOPOLI_H
#define MONOPOLI_H
#define Nil NULL

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

//Konstanta


typedef struct {
	/*
	  Ket : - Harga 0 adalah harga tanah
	  * 	- Harga 1 adalah harga upgrade bangunan level 1
	  * 	- Harga 2 adalah harga upgrade bangunan level 2
	  * 	- Harga 3 adalah harga upgrade bangunan level 3
	  * Hargasewa = harga;
	 */
	int id;
	int levelPetak; //maksimum 3
	char namaKota[255];
	char pemilik; //assign '#' di awal jika tidak ada pemilik
	boolean host; //sebagai host piala dunia
	boolean statusSedangDijual; //awalnya diassign 0
	long harga[4];
	long hargaSewa[4];
} infoPetak;

typedef struct TElmtList *Address;

typedef struct TElmtList {
	infoPetak 	info;
	Address 	next;
} ElmtList;

typedef struct {
	Address		first;
} List;

typedef struct {
	int x;
	int y;
} dadu;


typedef struct {
	char id;
	int posisiSekarang;  //posisi di petak
	boolean statusDipenjara; // 1 jika sedang di penjara
	boolean statusMain;
	long uang;
	int kartu[4]; //awal diassign 0
	/* Keterangan
	 * Kartu[0] = free me(bebas penjara)
	 * Kartu[1] = free tax
	 * Kartu[2] = Kartu mati lampu
	 * Kartu[3] = Kartu perlindungan
	 */
} infoPemain;

#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

#endif
