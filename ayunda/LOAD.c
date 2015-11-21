#include <math.h>

void LOAD(const char *namaFile){
	/* KAMUS */
	FILE *f;
	int i, j, k, n, a, d;
	char c;
	Address P;
	int b[1000];
	long duit;
		
	/* ALGORITMA */
	f = fopen(namaFile, "r");
	if(f == Nil){
	    	printf("Gagal Membuka File!");
		exit(EXIT_FAILURE);
	}
	n = PUBLIC_banyakPemain;
	for(i = 1; i <= n; i++){
		c = fgetc(f);
		while(c != 'n' && c != EOF){
			PUBLIC_pemain[i].id = c;
			c = fgetc(f);
			PUBLIC_pemain[i].posisiSekarang = c - '0';
			c = fgetc(f);
			PUBLIC_pemain[i].statusDipenjara = c - '0';
			c = fgetc(f);
			PUBLIC_pemain[i].statusMain = c - '0';
			c = fgetc(f);
			a = 0;
			while(c != 'y' && c != EOF){
				c = fgetc(f);
				b[a] = c - '0';
				a++;
			}
			duit = 0;
			d = a;
			for(k = 0; k <= a; k++){
				duit = duit + (b[k] * pow(10, d));
				d--;
			}
			PUBLIC_pemain[i].uang = duit;
			for(j = 0; j <= 3; j++){
				c = fgetc(f);
				PUBLIC_pemain[i].kartu[j] = c - '0';
			}			
		}
	}
	c = fgetc(f);
	while(c != 'A' && c != EOF){
		c = fgetc(f);
	}
	
	P = First(PUBLIC_petak);
	while(c != 'B' && c != EOF){
		c = fgetc(f);
		while(c != 'm' && c != EOF){
			if(Info(P).id != (c - '0')){
				P = Next(P);
			}
			else {
				c = fgetc(f);
				Info(P).levelPetak = c - '0';
				c = fgetc(f);
				Info(P).pemilik = c - '0';
				c = fgetc(f);
				Info(P).host = c - '0';
				c = fgetc(f);
				Info(P).statusSedangDijual = c - '0';
			}
		}
		P = First(PUBLIC_petak);
	}
	c = fgetc(f);
	PUBLIC_giliranPemain = c - '0';
	c = fgetc(f);
	PUBLIC_gameOver = c = '0';
	if(PUBLIC_gameOver = 0)
		printf("Permainan telah Game Over");
	
	fclose(f);	
}
