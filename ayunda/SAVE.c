/* Menyimpan info pemain, info petak, giliran pemain, status permainan */
void SAVE(const char *namaFile){
  
	/* KAMUS */
	FILE *f;
	int i, j, n;
	Address P;
		
	/* ALGORITMA */
	f = fopen(namaFile, "w");
	if(f == Nil){
	    printf("Gagal Menyimpan Permainan!");
		  exit(EXIT_FAILURE);
	}
	n = PUBLIC_banyakPemain;
	for(i = 1; i <= n; i++){
		fprintf(f, "%d", PUBLIC_pemain[i].id - '0');
		fprintf(f, "%d", PUBLIC_pemain[i].posisiSekarang);
		fprintf(f, "%d", PUBLIC_pemain[i].statusDipenjara);
		fprintf(f, "%d", PUBLIC_pemain[i].statusMain);
		fprintf(f, "x%ldy", PUBLIC_pemain[i].uang);
		for(j = 0; j <= 3; j++){
			fprintf(f, "%d", PUBLIC_pemain[i].kartu[j]);
		}
		fprintf(f, "n");
	}
	fprintf(f,"A");
	P = First(PUBLIC_petak);
	while(P != Nil){
		fprintf(f, "%d", Info(P).id);
		fprintf(f, "%d", Info(P).levelPetak);
		fprintf(f, "%d", Info(P).pemilik - '0');
		fprintf(f, "%d", Info(P).host);
		fprintf(f, "%d", Info(P).statusSedangDijual);
		fprintf(f, "m");
		P = Next(P);
	}
	fprintf(f,"B");
	fprintf(f, "%d", PUBLIC_giliranPemain);
	fprintf(f, "%d", PUBLIC_gameOver);
	fclose(f);
	printf("Permainan telah berhasil disimpan ke dalam file %s\n", namaFile);
}
