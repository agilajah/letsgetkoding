int CARI_ID_PEMAIN(char pemilik){
	/* KAMUS */
	int i = 0;
	
	/* ALGORITMA */
	while(i < 4){
		if(pemilik == PUBLIC_pemain[i].pemilik){
			return i;
		}
		i++;
	}

	return -1;
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

void BUY(){
	/* KAMUS */
	infoPemain *pemain = PUBLIC_pemain[PUBLIC_giliranPemain], *pemilikPetak;
	infoPetak *petakSekarang = Info(CARI_ALAMAT_PETAK(*pemain.posisiSekarang));

	/* ALGORITMA */
	if((*petakSekarang).pemilik == '#'){
		if((*pemain).uang > (*petakSekarang).harga[0]){
			(*petakSekarang).pemilik = (*pemain).id;
			(*pemain).uang -= (*petakSekarang).harga[0];

			printf("Selamat, kota %s kini menjadi milikmu!\n", (*petakSekarang).namaKota);
			printf("Level bangunan %d\n", (*petakSekarang).levelPetak);
			printf("Sisa uangmu: %ld\n", (*pemain).uang);
		}else{
			printf("Uangmu tidak cukup untuk membeli kota ini\n");
		}
	}else{
		*pemilikPetak = CARI_ID_PEMAIN((*petakSekarang).pemilik);
		if(*pemain.uang > (2 * ((*petakSekarang).harga[(*petakSekarang).levelPetak]))){
			(*petakSekarang).pemilik = (*pemain).id;
			(*pemain).uang -= 2 * ((*petakSekarang).harga[(*petakSekarang).levelPetak]);
			(*pemilikPetak).uang += 2 * ((*petakSekarang).harga[(*petakSekarang).levelPetak]);

			printf("Selamat, kota %s kini menjadi milikmu!\n", (*petakSekarang).namaKota);
			printf("Level bangunan %d\n", (*petakSekarang).levelPetak);
			printf("Sisa uangmu: %ld\n", (*pemain).uang);
			printf("Player %c mendapatkan hasil penjualan sebesar %ld\n", (*pemilikPetak).id, 2 * ((*petakSekarang).harga[(*petakSekarang).levelPetak]));
		}else{
			printf("Uangmu tidak cukup untuk membeli kota ini\n");
		}
	}
}
