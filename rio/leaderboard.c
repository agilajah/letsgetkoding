void LEADERBOARD(){
	/* KAMUS */
	int i, k[4], itemp;
	long max[4], ltemp;


	/* ALGORITMA */
	for(i = 0; i < 4; i++){
		max[i] = PUBLIC_pemain[i].uang;
		k[i] = i;
	}

	for(i = 0; i < 3; i++){
		for(j = i+1; j < 4; j++){
			if(max[j] > max[i]){
				ltemp = max[j];
				max[j] = max[i];
				max[i] = ltemp;
				itemp = k[i];
				k[i] = k[j];
				k[j] = itemp;
			}
		}
	}

	for(i = 0; i < 4; i++){
		printf("Player %c %ld\n", PUBLIC_pemain[k[i]].id, PUBLIC_pemain[k[i]].uang);
	}
}
