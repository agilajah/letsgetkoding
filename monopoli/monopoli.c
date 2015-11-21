#include "monopoli.h"

/*
	Fungsi Tambahan
*/


int banyakKata(Kata k){
	int i, n = 0;
	boolean kata = false;

	for(i = 0; i < k.Length - 1; i++){
		if(k.TabKata[i] != ' '){
			n += (!kata ? 1 : 0);
			kata = true;
		}else{
			kata = false;
		}
	}

	return n;
}

Kata ambilKataKe(Kata k, int n){
	int i = 0;
	int c = n;
	int j;
	boolean kata = false;
	char a[15];
	Kata b;

	while(true){
		if(k.TabKata[i] != ' ' && k.TabKata[i] != '\n' && !kata){
			c--;
			kata = true;
			if(c == 0){
				break;
			}
		}else if(k.TabKata[i] == ' '){
			kata = false;
		}

		i++;
	}

	j = 0;
	while((k.TabKata[i] != ' ') && (k.TabKata[i] != '\0')){
		a[j++] = k.TabKata[i];
		a[j] = '\0';
		i++;
	}

	resetKata(&b);

	initKata(&b, a);

	return b;
}

Address CARI_ALAMAT_PETAK(int id){
  	/* KAMUS */
	Address p = First(PUBLIC_petak);
	infoPetak X;
  
  	/* ALGORITMA */
	while(p != Nil){
		X = Info(p);
		if(X.id == id){
			return p;
		}
		
		p = Next(p);
	}

	return Nil;
}

int CARI_ID_PEMAIN(char pemilik){
	/* KAMUS */
	int i = 0;
	
	/* ALGORITMA */
	while(i < 4){
		if(pemilik == PUBLIC_pemain[i].id){
			return i;
		}
		i++;
	}

	return -1;
}

boolean BOOL_PEMILIK_PETAK(char idC, int idI){
	Address p;
	infoPetak petak;

	p = CARI_ALAMAT_PETAK(idI);
	if(p != Nil){
		petak = Info(p);
		return petak.pemilik == idC;
	}else{
		return false;
	}
}

int NAMA_KOTA_KE_ID(Kata namaKota){
	Address p;
	infoPetak petak;

	p = First(PUBLIC_petak);
	while(p != Nil){
		petak = Info(p);
		if(IsKataSama(namaKota, petak.namaKota)){
			return petak.id;
		}
	}

	return -1;
}

/*
	Kak Ayunda
*/
void LOAD(const char *namaFile){

}

void SAVE(const char *namaFile){

}

void INISIALISASI(){

}

/*
	Evita
*/
void BONUS(){

}

void CHANCE(int id){

}

void INFO(int id){

}

void TAX(){

}

void KATA_PEMBUKA(){

}

/*
	Febi
*/
dadu ROLL_DICE(){
	dadu D;

	return D;
}

int ROLLER(int min_num, int max_num){
	return 0;
}

void SHOW_OFFERED(List *PUBLIC_petak){

}

void BUY_OFFERED(List *PUBLIC_petak, boolean *berhasil) {

}

/*
	Hasna
*/
void BOARD(){

}

/*
	Jason
*/
void UPGRADE(){
	/* KAMUS */
	infoPemain *pemain;
	infoPetak *petakSekarang;

	*pemain = PUBLIC_pemain[PUBLIC_giliranPemain];
	*petakSekarang = Info(CARI_ALAMAT_PETAK((*pemain).posisiSekarang));

	/* ALGORITMA */
	if(((*petakSekarang).pemilik == '#') || ((*petakSekarang).pemilik != (*pemain).id)){
		printf("Kota %s bukan milikmu!\n", (*petakSekarang).namaKota.TabKata);
	}else if ((*petakSekarang).levelPetak == 3){
		printf("Kota %s sudah level maksimum!\n", (*petakSekarang).namaKota.TabKata);
	}else if ((*pemain).sudahUpgrade){
		printf("Anda sudah melakukan upgrade di giliran ini!\n");
	}else{
		if((*pemain).uang > (((*petakSekarang).harga[((*petakSekarang).levelPetak)+1]))){
			(*petakSekarang).levelPetak = (*petakSekarang).levelPetak + 1;
			(*pemain).uang -= (((*petakSekarang).harga[((*petakSekarang).levelPetak)+1]));

			printf("Selamat, bangunanmu di %s memiliki level %d!\n", (*petakSekarang).namaKota.TabKata, (*petakSekarang).levelPetak);
			printf("Sisa uangmu: %ld\n", (*pemain).uang);
		}else{
			printf("Uangmu tidak cukup untuk melakukan upgrade bangunan\n");
		}
	}
}

void SELL(int id){
	/* KAMUS */
	Address P;
	
	/* ALGORITMA */
	P = CARI_ALAMAT_PETAK(id);
	if((P != Nil) && ((Info(P).pemilik == PUBLIC_pemain[PUBLIC_giliranPemain].id))){
		/* Petak ditemukan dan milik pemain yang menjual */
		Info(P).statusBangunan[0] = true;
		printf("%s dimasukkan ke dalam list penjualan.", Info(P).namaKota.TabKata); 
		printf("Jika %s terjual, kamu akan mendapatkan uang hasil penjualan.\n", Info(P).namaKota.TabKata);
	}
	else if(P == Nil){ 
		/* Petak tidak ditemukan */
		printf("Masukan bukan merupakan nama kota yang valid.\n");
	}
	else{ 
		/* Petak bukan merupakan milik penjual */
		printf("%s bukan properti milikmu.\n", Info(P).namaKota.TabKata);
	}
}

void SELL_BANK(int id){
	/* KAMUS */
	Address P;
	long hargaJualPetak = 0;
	
	/* ALGORITMA */
	P = CARI_ALAMAT_PETAK(id);
	if((P != Nil) && ((Info(P).pemilik == PUBLIC_pemain[PUBLIC_giliranPemain].id))){
		/* Petak ditemukan dan milik pemain yang menjual */
		Info(P).pemilik = '#'; /* Petak menjadi tidak ada yang punya */
		hargaJualPetak = 0.9 * (Info(P)).harga[(Info(P).levelPetak)]; /* Harga petak 90% harga terakhir */
		Info(P).levelPetak = 0; /* Level direset */
		Info(P).statusBangunan[0] = false; /* Apabila petak sedang di-offer, batalkan */
		PUBLIC_pemain[PUBLIC_giliranPemain].uang += hargaJualPetak; /* Tambahkan uang pemain */
		printf("%s dijual ke bank dengan harga %liM.\n", Info(P).namaKota.TabKata, hargaJualPetak);
		printf("Uangmu sekarang %liM.\n", (PUBLIC_pemain[PUBLIC_giliranPemain]).uang);
	}
	else if(P == Nil){ 
		/* Petak tidak ditemukan */
		printf("Masukan bukan merupakan nama kota yang valid.\n");
	}
	else{ 
		/* Petak bukan merupakan milik penjual */
		printf("%s bukan properti milikmu.\n", Info(P).namaKota.TabKata);
	}
}

boolean GAME_OVER(){
	/* KAMUS */
	int jumlahStatusTidakMain = 0;
	int i = 0;
	
	/* ALGORITMA */
	while(i < 4){
		if((PUBLIC_pemain[i].statusDipenjara) && ((PUBLIC_pemain[i].uang) < (300)) && (PUBLIC_pemain[i].kartu[0] == 0)){
			jumlahStatusTidakMain = jumlahStatusTidakMain + 1;
		}
		if(!(PUBLIC_pemain[i].statusMain)){
			jumlahStatusTidakMain = jumlahStatusTidakMain + 1;
		}
		i++;
	}
	if (jumlahStatusTidakMain == 3){
		return true;
	}else{
		return false;
	}
}

/*
	Rio
*/
void BUY(){
	/* KAMUS */
	infoPemain *pemain;
	infoPemain *pemilikPetak;
	infoPetak *petakSekarang;

	*pemain = PUBLIC_pemain[PUBLIC_giliranPemain];
	*petakSekarang = Info(CARI_ALAMAT_PETAK((*pemain).posisiSekarang));

	/* ALGORITMA */
	if((*petakSekarang).pemilik == '#'){
		if((*pemain).uang > (*petakSekarang).harga[0]){
			(*petakSekarang).pemilik = (*pemain).id;
			(*pemain).uang -= (*petakSekarang).harga[0];

			printf("Selamat, kota %s kini menjadi milikmu!\n", (*petakSekarang).namaKota.TabKata);
			printf("Level bangunan %d\n", (*petakSekarang).levelPetak);
			printf("Sisa uangmu: %ld\n", (*pemain).uang);
		}else{
			printf("Uangmu tidak cukup untuk membeli kota ini\n");
		}
	}else{
		*pemilikPetak = PUBLIC_pemain[CARI_ID_PEMAIN((*petakSekarang).pemilik)];
		if((*pemain).uang > (2 * ((*petakSekarang).harga[(*petakSekarang).levelPetak]))){
			(*petakSekarang).pemilik = (*pemain).id;
			(*pemain).uang -= 2 * ((*petakSekarang).harga[(*petakSekarang).levelPetak]);
			(*pemilikPetak).uang += 2 * ((*petakSekarang).harga[(*petakSekarang).levelPetak]);

			printf("Selamat, kota %s kini menjadi milikmu!\n", (*petakSekarang).namaKota.TabKata);
			printf("Level bangunan %d\n", (*petakSekarang).levelPetak);
			printf("Sisa uangmu: %ld\n", (*pemain).uang);
			printf("Player %c mendapatkan hasil penjualan sebesar %ld\n", (*pemilikPetak).id, 2 * ((*petakSekarang).harga[(*petakSekarang).levelPetak]));
		}else{
			printf("Uangmu tidak cukup untuk membeli kota ini\n");
		}
	}
}

void END_TURN(){
	/* KAMUS */
	int giliranSebelumnya;

	/* ALGORITMA */
	giliranSebelumnya = PUBLIC_giliranPemain;
	PUBLIC_giliranPemain++;
	PUBLIC_giliranPemain = PUBLIC_giliranPemain % PUBLIC_banyakPemain;
	printf("Player %c mengakhiri giliran. Giliran player %c!\n", PUBLIC_pemain[giliranSebelumnya].id, PUBLIC_pemain[PUBLIC_giliranPemain].id);
}

void HOST(int id){
	/*KAMUS */
	infoPetak *petak;
	Address p;

	/* ALGORITMA */
	p = CARI_ALAMAT_PETAK(id);
	if(p != Nil){
		(*petak) = Info(p);
		(*petak).statusBangunan[2] = BOOL_PEMILIK_PETAK(PUBLIC_pemain[PUBLIC_giliranPemain].id, (*petak).id);
		if((*petak).statusBangunan[2]){
			printf("%s menjadi host World Cup. Uang sewa di %s menjadi %ld\n", (*petak).namaKota.TabKata, (*petak).namaKota.TabKata, (*petak).hargaSewa[(*petak).levelPetak]);
		}else{
			printf("Kota %s tidak dapat dijadikan host World Cup, karena kota ini bukan milik Anda\n", (*petak).namaKota.TabKata);
		}
	}else{
		printf("Kota tidak valid\n");
	}
}

void LEADERBOARD(){
	/* KAMUS */
	int i, j, k[4], itemp;
	long max[4], ltemp;

	/* ALGORITMA */
	for(i = 0; i < 4; i++){
		max[i] = PUBLIC_pemain[i].uang;
		k[i] = i;
	}

	for(i = 0; i < 3; i++){
		for(j = i+1; j < 4; j++){
			if(max[j] > max[i]){
				ltemp = max[j];
				max[j] = max[i];
				max[i] = ltemp;
				itemp = k[i];
				k[i] = k[j];
				k[j] = itemp;
			}
		}
	}

	for(i = 0; i < 4; i++){
		printf("Player %c %ld\n", PUBLIC_pemain[k[i]].id, PUBLIC_pemain[k[i]].uang);
	}
}

void TRAVEL(int id){
	/* KAMUS */
	infoPetak tujuan;

	/* ALGORITMA */
	tujuan = Info(CARI_ALAMAT_PETAK(id));
	PUBLIC_pemain[PUBLIC_giliranPemain].posisiSekarang = id;
	printf("Player %c sampai di %s\n", PUBLIC_pemain[PUBLIC_giliranPemain].id, tujuan.namaKota.TabKata);
}

void OLAH(char C[]){
	Kata a[100];
	Kata b, K, m;
	int temp;
	int i = 0;
	int j = 0;

	while(C[j] != '\0'){
		j++;
	}
	C[j - 1] = '\0';

	resetKata(&K);
	initKata(&K, C);

	/* 00 */ initKata(&a[i++], "roll");
	/* 01 */ initKata(&a[i++], "info"); //
	/* 02 */ initKata(&a[i++], "buy");
	/* 03 */ initKata(&a[i++], "sell"); //
	/* 04 */ initKata(&a[i++], "turn"); //
	/* 05 */ initKata(&a[i++], "show"); //
	/* 06 */ initKata(&a[i++], "buy");
	/* 07 */ initKata(&a[i++], "upgrade");
	/* 08 */ initKata(&a[i++], "board");
	/* 09 */ initKata(&a[i++], "leaderboard");
	/* 10 */ initKata(&a[i++], "host"); //
	/* 11 */ initKata(&a[i++], "travel"); //
	/* 12 */ initKata(&a[i++], "end");
	/* 13 */ initKata(&a[i++], "save"); //
	/* 14 */ initKata(&a[i++], "load"); //
	/* 15 */ initKata(&a[i++], "bank"); //
	/* 16 */ initKata(&a[i++], "offered"); //
	/* 17 */ initKata(&a[i++], "dice"); //
	/* 18 */ initKata(&a[i++], "free"); //
	/* 19 */ initKata(&a[i++], "me"); //
	/* 20 */ initKata(&a[i++], "tax"); //
	/* 21 */ initKata(&a[i++], "off"); //
	/* 22 */ initKata(&a[i++], "protect"); //

	if(banyakKata(K) == 1){
		resetKata(&b);
		b = ambilKataKe(K, 1);
		if(IsKataSama(b, a[2])){
			//BUY();
			printf("Test BUY()\n");
		}else if(IsKataSama(b, a[7])){
			//UPGRADE();
			printf("Test UPGRADE()\n");
		}else if(IsKataSama(b, a[8])){
			//BOARD();
			printf("Test BOARD()\n");
		}else if(IsKataSama(b, a[9])){
			//LEADERBOARD();
			printf("Test LEADERBOARD()\n");
		}else if(IsKataSama(b, a[0])){ // roll
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Mungkin maksud Anda \"roll dice\" \n");
		}else if(IsKataSama(b, a[16])){ // show
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Mungkin maksud Anda \"show offered\" \n");
		}else if(IsKataSama(b, a[12])){ // end
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Mungkin maksud Anda \"end turn\" \n");
		}else if(IsKataSama(b, a[1])){ // info
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Gunakan format input \"info <nama petak>\" \n");
		}else if(IsKataSama(b, a[3])){ // sell
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Gunakan format input \"sell <nama petak>\" atau \"sell bank <nama petak>\" \n");
		}else if(IsKataSama(b, a[10])){ // host
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Gunakan format input \"host <nama kota>\" \n");
		}else if(IsKataSama(b, a[11])){ // travel
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Gunakan format input \"travel <nama kota>\" \n");
		}else if(IsKataSama(b, a[13])){ // save
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Gunakan format input \"save <nama berkas>\" \n");
		}else if(IsKataSama(b, a[14])){ // load
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Gunakan format input \"load <nama berkas>\" \n");
		}else if(IsKataSama(b, a[18])){ // free
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Mungkin maksud Anda \"free me\" atau \"free tax\" \n");
		}else if(IsKataSama(b, a[21])){ // off
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Gunakan format input \"off <nama kota/tempat rekreasi>\" \n");
		}else if(IsKataSama(b, a[22])){ // protect
			printf("Error: Perintah Salah\n");	
			printf("  Petunjuk: Gunakan format input \"protect <nama kota/tempat rekreasi>\" \n");
		}else{
			printf("Error: Perintah Salah\n");			
		}				
	}else if(banyakKata(K) == 2){
		resetKata(&b);
		b = ambilKataKe(K, 1);
		if(IsKataSama(b, a[0])){ // roll dice
			resetKata(&b);
			b = ambilKataKe(K, 2);
			if(IsKataSama(b, a[17])){
				//ROLL_DICE();
				printf("Test ROLL_DICE()\n");
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Mungkin maksud Anda \"roll dice\" \n");
			}
		}else if(IsKataSama(b, a[5])){ // show offered
			resetKata(&b);
			b = ambilKataKe(K, 2);
			List L;
			if(IsKataSama(b, a[16])){
				//SHOW_OFFERED(L);
				printf("Test SHOW_OFFERED()\n");
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Mungkin maksud Anda \"show offered\" \n");
			}
		}else if(IsKataSama(b, a[12])){ // end turn
			resetKata(&b);
			b = ambilKataKe(K, 2);
			if(IsKataSama(b, a[4])){
				//END_TURN();
				printf("Test END_TURN()\n");
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Mungkin maksud Anda \"end turn\" \n");
			}
		}else if(IsKataSama(b, a[1])){ // info <np>
			resetKata(&b);
			b = ambilKataKe(K, 2);
			//temp = NAMA_KOTA_KE_ID(b);
			temp = 1;
			if(temp > -1){
				//INFO(temp);
				printf("Test INFO(%s)\n", b.TabKata);
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Gunakan format input \"info <nama petak>\" \n");
			}
		}else if(IsKataSama(b, a[3])){ // sell <np>
			resetKata(&b);
			b = ambilKataKe(K, 2);
			//temp = NAMA_KOTA_KE_ID(b);
			temp = 1;
			if(temp > -1){
				//SELL(temp);
				printf("Test SELL(%s)\n", b.TabKata);
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Gunakan format input \"sell <nama petak>\" \n");
			}
		}else if(IsKataSama(b, a[10])){ // host <np>
			resetKata(&b);
			b = ambilKataKe(K, 2);
			//temp = NAMA_KOTA_KE_ID(b);
			temp = 1;
			if(temp > -1){
				//HOST(temp);
				printf("Test HOST(%s)\n", b.TabKata);
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Gunakan format input \"host <nama kota>\" \n");
			}
		}else if(IsKataSama(b, a[11])){ // travel <np>
			resetKata(&b);
			b = ambilKataKe(K, 2);
			//temp = NAMA_KOTA_KE_ID(b);
			temp = 1;
			if(temp > -1){
				//TRAVEL(temp);
				printf("Test TRAVEL(%s)\n", b.TabKata);
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Gunakan format input \"travel <nama kota>\" \n");
			}
		}else if(IsKataSama(b, a[13])){ // save <nf>
			resetKata(&b);
			b = ambilKataKe(K, 2);
			SAVE(b.TabKata);
			printf("Test SAVE(%s)\n", b.TabKata);
			printf("  Petunjuk: Gunakan format input \"save <nama berkas>\" \n");
		}else if(IsKataSama(b, a[14])){ // load <nf>
			resetKata(&b);
			b = ambilKataKe(K, 2);
			LOAD(b.TabKata);
			printf("Test LOAD(%s)\n", b.TabKata);
			printf("  Petunjuk: Gunakan format input \"load <nama berkas>\" \n");
		}else if(IsKataSama(b, a[18])){ // load <nf>
			resetKata(&b);
			b = ambilKataKe(K, 2);
			if(IsKataSama(b, a[19])){ // free me
				printf("Test FREE_ME()\n");
			}else if(IsKataSama(b, a[20])){ // free tax
				printf("Test FREE_TAX()\n");
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Mungkin maksud Anda \"free me\" atau \"free tax\" \n");
			}
		}else if(IsKataSama(b, a[21])){ // off <np>
			resetKata(&b);
			b = ambilKataKe(K, 2);
			//temp = NAMA_KOTA_KE_ID(b);
			temp = 1;
			if(temp > -1){
				//TRAVEL(temp);
				printf("Test OFF(%s)\n", b.TabKata);
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Gunakan format input \"off <nama kota/tempat rekreasi>\" \n");
			}
		}else if(IsKataSama(b, a[22])){ // protect <np>
			resetKata(&b);
			b = ambilKataKe(K, 2);
			//temp = NAMA_KOTA_KE_ID(b);
			temp = 1;
			if(temp > -1){
				//TRAVEL(temp);
				printf("Test PROTECT(%s)\n", b.TabKata);
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Gunakan format input \"protect <nama kota/tempat rekreasi>\" \n");
			}
		}else{
			printf("Error: Perintah Salah\n");
		}
	}else if(banyakKata(K) == 3){
		resetKata(&b);
		b = ambilKataKe(K, 1);
		if(IsKataSama(b, a[3])){
			resetKata(&b);
			b = ambilKataKe(K, 2);
			if(IsKataSama(b, a[15])){ // sell bank <np>
				resetKata(&b);
				b = ambilKataKe(K, 3);
				//SELL_BANK();
				printf("Test SELL_BANK(%s)\n", b.TabKata);
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Gunakan format input   \n");
			}
		}else if(IsKataSama(b, a[6])){
			resetKata(&b);
			b = ambilKataKe(K, 2);
			if(IsKataSama(b, a[16])){ // buy offered <np>
				resetKata(&b);
				b = ambilKataKe(K, 3);
				//SELL_BANK();
				printf("Test BUY_OFFERED(%s)\n", b.TabKata);
			}else{
				printf("Error: Perintah Salah\n");
				printf("  Petunjuk: Gunakan format input \"buy offered <nama petak>\" \n");
			}
		}else{
			printf("Error: Perintah Salah\n");
		}
	}else{
		printf("Error: Perintah Salah\n");
	}
}
