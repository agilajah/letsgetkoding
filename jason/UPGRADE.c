void UPGRADE(){
	/* KAMUS */
	infoPemain *pemain = PUBLIC_pemain[PUBLIC_giliranPemain];
	infoPetak *petakSekarang = Info(CARI_ALAMAT_PETAK(*pemain.posisiSekarang));

	/* ALGORITMA */
	if(((*petakSekarang).pemilik == '#') || ((*petakSekarang).pemilik != (*pemain).id)){
		printf("Kota %s bukan milikmu!\n", (*petakSekarang).namaKota);
	}else if ((*petakSekarang).levelPetak == 3){
		printf("Kota %s sudah level maksimum!\n", (*petakSekarang).namaKota);
	}else if ((*pemain).sudahUpgrade){
		printf("Anda sudah melakukan upgrade di giliran ini!\n");
	}else{
		if(*pemain.uang > (((*petakSekarang).harga[((*petakSekarang).levelPetak)+1]))){
			(*petakSekarang).levelPetak = (*petakSekarang).levelPetak + 1;
			(*pemain).uang -= (((*petakSekarang).harga[((*petakSekarang).levelPetak)+1]));

			printf("Selamat, bangunanmu di %s memiliki level %d!\n", (*petakSekarang).namaKota, (*petakSekarang).levelPetak);
			printf("Sisa uangmu: %ld\n", (*pemain).uang);
		}else{
			printf("Uangmu tidak cukup untuk melakukan upgrade bangunan\n");
		}
	}
}
