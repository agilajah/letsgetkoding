void END_TURN(){
	/* KAMUS */
	int giliranSebelumnya;

	/* ALGORITMA */
	giliranSebelumnya = PUBLIC_giliranPemain;
	PUBLIC_giliranPemain++;
	PUBLIC_giliranPemain = PUBLIC_giliranPemain % PUBLIC_banyakPemain;
	printf("Player %c mengakhiri giliran. Giliran player %c!\n", PUBLIC_pemain[giliranSebelumnya].id, PUBLIC_pemain[PUBLIC_giliranPemain].id);
}
