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

void HOST(int id){
	/*KAMUS */
	infoPetak *petak;
	Address p;

	/* ALGORITMA */
	p = CARI_ALAMAT_PETAK(id);
	if(p != Nil){
		(*petak) = Info(p);
		(*petak).host = BOOL_PEMILIK_PETAK(PUBLIC_pemain[PUBLIC_giliranPemain], (*petak).id);
		if((*petak).host){
			printf("%s menjadi host World Cup. Uang sewa di %s menjadi %ld\n", (*petak).namaKota, (*petak).namaKota, (*petak).hargaSewa[(*petak).levelPetak]);
		}else{
			printf("Kota %s tidak dapat dijadikan host World Cup, karena kota ini bukan milik Anda\n", (*petak).namaKota);
		}
	}else{
		printf("Kota tidak valid\n");
	}
}
