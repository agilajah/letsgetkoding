void TRAVEL(int id){
	/* KAMUS */
	infoPetak tujuan;

	/* ALGORITMA */
	tujuan = Info(CARI_ALAMAT_PETAK(id));
	PUBLIC_pemain[PUBLIC_giliranPemain].posisiSekarang = id;
	printf("Player %c sampai di %s\n", PUBLIC_pemain[PUBLIC_giliranPemain].id, tujuan.namaKota);
}
