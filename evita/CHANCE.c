void CHANCE(int id){
		/* KAMUS */
	Address P;

	/* ALGORITMA */
	    srand(time(NULL));
  	    int num;
     
	    num= 1+rand()%(5+1-1);
	     
	     switch (num){
	     	case 1: {
	     		printf("Anda mendapat Kartu Bebas Penjara\n");
            	PUBLIC_player[PUBLIC_giliranPemain].kartu[0] = 1;
            }break;
    case 2: {
            	printf("Anda mendapat Kartu Bebas Pajak\n");
            	PUBLIC_player[PUBLIC_giliranPemain].kartu[1] = 1;
            }break;
    case 3: {
           	 	printf("Anda mendapat Kartu Masuk Penjara\n");
            	PUBLIC_player[PUBLIC_giliranPemain].posisiSekarang = 14;
            	PUBLIC_player[PUBLIC_giliranPemain].statusDipenjara = 1;
            }break;
    case 4: {
           		printf("Anda mendapat Kartu Mati Lampu\n");
            	PUBLIC_player[PUBLIC_giliranPemain].kartu[2] = 1;     
            }break;
    case 5:{
            printf("Anda mendapat Kartu Perlindungan\n");
            	PUBLIC_player[PUBLIC_giliranPemain].kartu[3] = 1;
            }break;
	}
}
