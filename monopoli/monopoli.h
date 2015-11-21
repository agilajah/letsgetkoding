#ifndef MONOPOLI_H
#define MONOPOLI_H
#define Nil NULL

/*
	Header
*/
#include <math.h>
#include "../mesinkata/mesinkata.h"

/*
	Struktur Data Monopoly
*/
typedef struct {
	/*
	 Ket : - Harga 0 adalah harga tanah
	 * 	   - Harga 1 adalah harga upgrade bangunan level 1
	 * 	   - Harga 2 adalah harga upgrade bangunan level 2
	 * 	   - Harga 3 adalah harga upgrade bangunan level 3
	 * Hargasewa = harga;
	 */
	int id;
	int levelPetak; //maksimum 3
	Kata namaKota; //$DIUBAH
	char pemilik; //assign '#' di awal jika tidak ada pemilik
	char blok; // blok bangunan
	boolean statusBangunan[3]; //$DIUBAH
		/*
			statusBangunan[0]: sedang dijual
			statusBangunan[1]: mati Lampu
			statusBangunan[2]: host piala dunia
		*/
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
	int posisiSekarang;
	boolean statusDipenjara; // 1 jika sedang di penjara
	boolean statusMain;
	boolean sudahUpgrade;
	long uang;
	int kartu[4]; //awal diassign 0
	/* Keterangan
	 * Kartu[0] = free me(bebas penjara)
	 * Kartu[1] = free tax
	 * Kartu[2] = Kartu mati lampu
	 * Kartu[3] = Kartu perlindungan
	 */
} infoPemain;

/*
	Selektor
*/
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

/*
	Variabel Publik
*/
boolean PUBLIC_gameOver;
infoPemain PUBLIC_pemain[4];
char PUBLIC_inputTerakhir[NMax];
int PUBLIC_giliranPemain;
List PUBLIC_petak;
int PUBLIC_banyakPemain; // menunjuk banyak pemain yang sedang bermain saat ini, bisa 2-4 orang

/*
	Fungsi Tambahan
*/
int banyakKata(Kata k);
Kata ambilKataKe(Kata k, int n);
Address CARI_ALAMAT_PETAK(int id);
int CARI_ID_PEMAIN(char pemilik);
boolean BOOL_PEMILIK_PETAK(char idC, int idI);
int NAMA_KOTA_KE_ID(Kata namaKota);

/*
	Kak Ayunda
*/
void LOAD(const char *namaFile);
void SAVE(const char *namaFile);
void INISIALISASI();

/*
	Evita
*/
void BONUS();
void CHANCE(int id);
void INFO(int id);
void TAX();
void KATA_PEMBUKA();
/*
	Febi
*/
dadu ROLL_DICE();
//void jalan(int PUBLIC_giliranPemain, int *PUBLIC_pemain[PUBLIC_giliranPemain]); //susah dibaca
void jalan(int PUBLIC_giliranPemain, infoPemain *posisipemainsekarang); //lebih enak dibaca
int ROLLER(int min_num, int max_num);
void SHOW_OFFERED(List *PUBLIC_petak);
void BUY_OFFERED(List *PUBLIC_petak, boolean *berhasil);
void CEK_KONDISI_PETAK(int id, infoPemain *pemainsekarang);

/*
	Hasna
*/
void BOARD();

/*
	Jason
*/
void UPGRADE();
void SELL(int id);
void SELL_BANK(int id);
boolean GAME_OVER();

/*
	Rio
*/
void BUY();
void END_TURN();
void HOST(int id);
void LEADERBOARD();
void TRAVEL(int id);
void OLAH();

#endif
