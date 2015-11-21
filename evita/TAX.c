void TAX(){
	/* KAMUS */
	

	/* ALGORITMA */
	printf(" Pajak Bumi dan Bangunan, uangmu berkurang %d", 10*(PUBLIC_player[PUBLIC_giliranPemain].asset)/100);
     	PUBLIC_player[PUBLIC_giliranPemain].uang -= 10*(PUBLIC_player[PUBLIC_giliranPemain].asset)/100;
     	printf("Sisa Uangmu %d\n", PUBLIC_player[PUBLIC_giliranPemain].uang);	
 }
}
