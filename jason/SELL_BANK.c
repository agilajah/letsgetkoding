void SELL_BANK(char* input){
	/* KAMUS */
	Address P;
	
	/* ALGORITMA */
	P = CARI_ALAMAT_PETAK(id);
	if((P != Nil) && ((Info(P).pemilik == PUBLIC_player[PUBLIC_giliranPemain].id))){
		/* Petak ditemukan dan milik pemain yang menjual */
		Info(P).pemilik = '#'; /* Petak menjadi tidak ada yang punya */
		hargaJualPetak = 0.9 * Info(P).(harga[(Info(P).levelPetak)]); /* Harga petak 90% harga terakhir */
		Info(P).levelPetak = 0; /* Level direset */
		Info(P).statusSedangDijual = false; /* Apabila petak sedang di-offer, batalkan */
		PUBLIC_player[PUBLIC_giliranPemain].uang += hargaJualPetak; /* Tambahkan uang pemain */
		printf("%s dijual ke bank dengan harga %dM.\n", Info(P).namaPetak, hargaJualPetak);
		printf("Uangmu sekarang %dM.\n", PUBLIC_player[PUBLIC_giliranPemain].uang);
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
