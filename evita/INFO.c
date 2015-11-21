//ADT TAMBAHAN
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

void INFO(int id){
	/* KAMUS */
	Address P;

	/* ALGORITMA */
	P = CARI_ALAMAT_PETAK(id);
	if (P!= Nil){
		if (Info(P).pemilik != '#'){
			printf("%s, belum ada pemilik, bangunan level 0.",Info(P).namaKota);
			printf("Harga Tanah : %ld.",Info(P).harga[0]);
		}
		else{
			printf("%s, pemilik properti %c, bangunan level %d.", Info(P).namaKota, Info(P).pemilik, Info(P).levelPetak);
			printf("Harga Sewa : %ld.",Info(P).hargaSewa[(Info(P).levelPetak)]);
			printf("Harga Ambil Alih : %ld.",(2*(Info(P).harga[(Info(P).levelPetak)])));
			if (Info(P).levelPetak != 3){
				printf("Harga Upgrade Bangunan : %ld.",Info(P).harga[((Info(P).levelPetak)+1)]);
			}
		}
	}
	else{
		/* Petak tidak ditemukan */
		printf("Masukan bukan merupakan nama kota yang valid.\n");
	}
}
	
