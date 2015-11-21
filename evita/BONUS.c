void BONUS(){
	/* KAMUS */


	/* ALGORITMA */
	    srand(time(NULL));
  	    int num;
     
	    num= 1+rand()%(3);
	     
	     switch (num){
	     	case 1: {
	     		printf("Selamat, kamu mendapatkan 10K!");
    			PUBLIC_player[PUBLIC_giliranPemain].uang += 10000;
  				printf("Uang kamu Sekarang %d\n", PUBLIC_player[PUBLIC_giliranPemain].uang);
            }break;
    case 2: {
            	printf("Selamat, kamu mendapatkan 20K!");
   				PUBLIC_player[PUBLIC_giliranPemain].uang += 20000;
    			printf("Uang kamu Sekarang %d\n", PUBLIC_player[PUBLIC_giliranPemain].uang);
            }break;
    case 3: {
           	 	printf("Selamat, kamu mendapatkan 30K!");
    			PUBLIC_player[PUBLIC_giliranPemain].uang += 30000;
    			printf("Uang kamu Sekarang %d\n", PUBLIC_player[PUBLIC_giliranPemain].uang);
            }break;
   		}
}
