void BUY(){
	/* KAMUS */
	Pemain pemilikPetak;

	/* ALGORITMA */
	if(petak[nomorPetakSekarang].pemilik == Nil){
		if(pemain[giliranSekarang].balance > petak[nomorPetakSekarang].hargaAwal){
			petak[nomorPetakSekarang].pemilik = pemain[giliranSekarang].id;
			pemain[giliranSekarang].balance -= petak[nomorPetakSekarang].hargaAwal;

			printf("Selamat, kota %s kini menjadi milikmu!\n", petak[nomorPetakSekarang].namaKota);
			printf("Level bangunan %d\n", petak[nomorPetakSekarang].level);
			printf("Sisa uangmu: %s\n", tulisUang(pemain[giliranSekarang].balance));
		}else{
			printf("Uangmu tidak cukup untuk membeli kota ini\n");
		}
	}else{
		pemilikPetak = kePemain(petak[nomorPetakSekarang].id);
		if(pemain[giliranSekarang].balance > petak[nomorPetakSekarang].hargaSekarang){
			petak[nomorPetakSekarang].pemilik = pemain[giliranSekarang].id;
			pemain[giliranSekarang].balance -= petak[nomorPetakSekarang].hargaSekarang;

			printf("Selamat, kota %s kini menjadi milikmu!\n", petak[nomorPetakSekarang].namaKota);
			printf("Level bangunan %d\n", petak[nomorPetakSekarang].level);
			printf("Sisa uangmu: \n", tulisUang(pemain[giliranSekarang].balance));
			printf("Player %c mendapatkan hasil penjualan sebesar %s\n", tulisUang(petak[nomorPetakSekarang].hargaSekarang));
		}else{
			printf("Uangmu tidak cukup untuk membeli kota ini\n");
		}
	}
}

void LEADERBOARD(){
	/* KAMUS */
	int i;

	/* ALGORITMA */
	for(i = 0; i < maxPemain; i++){
		printf("Player %c %s\n", pemainMax[i].id, tulisUang(pemainMax[i].balance));
	}
}

void HOST(){
	/* ALGORITMA */
	publicHost = pemain[giliranSekarang].id;
	printf("%s menjadi host World Cup. Uang sewa di %s menjadi %s\n", petak[nomorPetakSekarang].namaKota, petak[nomorPetakSekarang].namaKota, tulisUang(2 * petak[nomorPetakSekarang].hargaSekarang));
}

void TRAVEL(){
	/* KAMUS */

	
	/* ALGORITMA */

}

void END_TURN(){
	/* KAMUS */


	/* ALGORITMA */

}
