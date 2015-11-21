void SELL(int id){
	/* KAMUS */
	Address P;
	
	/* ALGORITMA */
	P = CARI_ALAMAT_PETAK(id);
	if((P != Nil) && ((Info(P).pemilik == PUBLIC_player[PUBLIC_giliranPemain].id))){
		/* Petak ditemukan dan milik pemain yang menjual */
		Info(P).statusSedangDijual = true;
		printf("%s dimasukkan ke dalam list penjualan.", Info(P).namaPetak); 
		printf("Jika %s terjual, kamu akan mendapatkan uang hasil penjualan.\n", Info(P).namaPetak);
	}
	else if(P == Nil){ 
		/* Petak tidak ditemukan */
		printf("Masukan bukan merupakan nama kota yang valid.\n");
	}
	else{ 
		/* Petak bukan merupakan milik penjual */
		printf("%s bukan properti milikmu.\n", Info(P).namaPetak);
	}
}
