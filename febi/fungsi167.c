
dadu ROLL_DICE() {
/* fungsi ROLL_DICE mengembalikan sebuah tuple dengan dua nilai bertype data integer, 
   nilai pertama adalah hasil acak dari dadu pertama. Nilai kedua adalah hasil acak dari dadu ke dua. Digunakan dua dadu pada permainan ini. */

/* KAMUS */
	int a,b;
	dadu hasil;
/* ALGORITMA */
	a = roller(1, 6);
	b = roller(6, 1); /* Random dadu mulai dari angka 1 sampai 6*/
	hasil.x = a;
	hasil.y = b;
	
	return hasil;
}
/* fungsi seeder random number */
int roller(int min_num, int max_num) {
	int result =0, low_num=0, hi_num=0;
	if(min_num<max_num)
            {
                low_num=min_num;
                hi_num=max_num+1; // this is done to include max_num in output.
            }else{
                low_num=max_num+1;// this is done to include max_num in output.
                hi_num=min_num;
            }
            srand(time(NULL));
            result = (rand()%(hi_num-low_num))+low_num;
            return result;
        }
}

void SHOW_OFFERED(List *PUBLIC_petak) {
/* Procedure menampilkan semua list offered */
/* Deskripsi */
	/* menampilkan list yang offered. Nanti akan ada sebuah struktur data yang akan menampung property apa saja
	   yang bisa dibeli. struktur data ini dapat diupdate setiap saat, setiap user ingin menambahkan property miliknya ke
	   struktur data ini, artinya property tersebut sekarang berstatus 'dijual'. Semua property dengan status tersebut
	   dapat dilihat di prosedur ini. Prosedur ini dapat diakses oleh pemain yang sedang dalam gilirannya. Pemain lain tidak
	   bisa mengakses prosedur ini jika bukan giliran mainnya.

	   prosedur ini dapat diakses kapanpun dan berulang kali. ketika seorang pemain mendapatkan gilirannya, ia mendapatkan
	   beberapa pilihan: roll the dice, dan sebagainya. termasuk prosedur ini*/
/* KAMUS */
	Address P;
	int pilihan;
	boolean berhasil =false;
	boolean benar = false;
/* ALGORITMA */
	
	 printf("---------------------------------------------------------------\n");
	 printf("				List Petak yang sedang ditawarkan				\n");
	 printf("---------------------------------------------------------------\n");
	 printf("\n");
	 P = First(PUBLIC_petak);
	 printf("PEMILIK  |  NAMA KOTA  |  HARGA | ID \n");
	 while (P != Nil) {
	 	if (infoPetak.statusSedangDijual == 1) {
	 		printf("%d   %s   %d   %d\n", Info(P).pemilik, Info(P).namakota, Info(P).hargasewa, Info(P).id);
	 	}
	 }
	printf("1. Beli\n");
	printf("2. Keluar\n";
	printf("\n");
	printf("Pilihan Anda : ");
	scanf("%d", &pilihan);
	if (pilihan!=1 || pilihan!=2) {		//mengecek input user sesuai format
	   			printf("Ulangi masukan.\n");
	   			while (!benar) {
	   				scanf("%d", &pilihan);
	   				if (pilihan==1 || pilihan ==2) {
	   					benar =true;
	   				}
	   			}
	}
	printf("\n");
	printf("\n");
	printf("---------------------------------------------------------------\n");

	switch(pilihan) {
		case 1 : {
			while (!berhasil) {  //selama pembelian tidak berhasil, maka akan terus diulangi. Atau user membatalkan pembelian
				BUY_OFFERED(PUBLIC_petak, &berhasil);
			}
			break;
		}
		case 2 : {
			break;
		}
	}
}

void BUY_OFFERED(List *PUBLIC_petak, boolean *berhasil) {
/* Procedure untuk membeli property. Procedure ini dapat diakses saat user mengakses SHOW_OFFERED
   sehingga ketika user melihat list offered, ia dapat membelinya dengan menggunakan procedure ini */

/* Deskripsi /*
/* ketika menampilkan semua property dengan status 'dijual', akan muncul sebuah opsi 'exit' atau 'buy'
	   Jika user memilih buy, maka ia dapt membeli satu atau lebih property, disesuaikan dengan budget yang ia miliki.
	   Jika user membeli property tertentu, sang pemilik lama akan mendapatkan uang, dan semua 'surat kepemilikan' diberikan
	   kepada pemilik baru. Pemilik baru akan kehilangan uangnya, namun mendapatkan property yang ia inginkan.

	   pemain yang sedang mendapatkan giliran dapat mengakses fungsi ini berulang-ulang sampai ia menginput opsi 'selesai' atau
	   sejenisnya. */
/* KAMUS */
	   char namaPetak[100];
	   Address alamat;
	   int aidi, i,j;
	   int beli;
	   infoPemain *pemain = PUBLIC_pemain[PUBLIC_giliranPemain];
	   boolean benar=false;
/* ALGORITMA */
	   printf("\n");
	   printf("Petak mana yang ingin Anda beli?\n");
	   printf("Input ID : ");
	   scanf("%d", &aidi);
	   printf("Tunggu sebentar");
	   alamat = CARI_ALAMAT_PETAK(aidi);
	   for (i=0; i<5; i++) {
	   		for (j=0; j<25; j++) {
	   			printf("");
	   		} //delay
	   	 printf(".");
	   }
	   printf("\n");
	   printf("\n");
	   if (alamat==Nil) {
	   		printf("Tidak ada kota dengan ID tersebut, silahkan ulangi masukan...");
	   		*berhasil = false;
	   } else
	   {
	   		printf("Kota ditemukan!");
	   		printf("PEMILIK  |  NAMA KOTA  |  HARGA | ID \n");
	   		printf("%d   %s   %d   %d\n", Info(P).pemilik, Info(P).namakota, Info(P).hargasewa, Info(P).id);
	   		printf("\n");
	   		printf("Ingin meneruskan pembelian?\n");
	   		printf("1. Ya\n");
	   		printf("2. Batal\n");
	   		scanf("%d", &beli);
	   		if (beli!=1 || beli!=2) {		//mengecek input user sesuai format
	   			printf("Ulangi masukan.\n");
	   			while (!benar) {
	   				scanf("%d", &beli);
	   				if (beli==1 || beli ==2) {
	   					benar =true;
	   				}
	   			}
	   		}
	   		switch(beli) {
	   			case 1 : {
	   				*pemilikPetak = CARI_ID_PEMAIN((Info(alamat).pemilik));
					if (*pemain.uang > (2 * (Info(alamat).harga[Info(alamat.levelPetak)])))  {

						Info(alamat).pemilik = (*pemain).id;
						(*pemain).uang -= 2 * (Info(alamat).harga[Info(alamat.levelPetak)]);
						(*pemilikPetak).uang += 2 * (Info(alamat).harga[Info(alamat.levelPetak)]);

						printf("Selamat, kota %s kini menjadi milikmu!\n", Info(alamat).namaKota);
						printf("Level bangunan %d\n", Info(alamat).levelPetak);
						printf("Sisa uangmu: %ld\n", (*pemain).uang);
						printf("Player %c mendapatkan hasil penjualan sebesar %ld\n", (*pemilikPetak).id, 2 * ((*petakSekarang).harga[(*petakSekarang).levelPetak]));
						*berhasil = true; //transaksi berhasil
					}else{
						printf("Uangmu tidak cukup untuk membeli kota ini\n");
						*berhasil = true; //transaksi gagal, tapi karena uang tidak cukup maka tidak dimungkingkan untuk membeli sementara waktu
					}
					break;
	   			}
	   			case 2 :{
	   					*berhasil = true; //kegiatan transaksi dihentikan karena player tidak ingin melanjutkannya
	   					break;
	   			}
	   		}

	   }
}

void jalan(int PUBLIC_giliranPemain, infoPemain *pemainsekarang) {
/*Deskripsi*/
	/* *pemainsekarang sebenarnya adalah PUBLIC_Pemain[PUBLIC_GiliranPemain]
	/* Sebuah prosedur untuk mengatur jalannya pemain */
	/* BELUM MENANGANI KASUS DADU SAMA BEBERAPA KALI */
/*KAMUS*/
	int idpetak;
	int jumlahlangkah,i;

	dadu langkah;

/*ALGORITMA*/
	idpetak = *pemainsekarang.posisiSekarang;
	langkah = ROLL_DICE();
	jumlahlangkah = langkah.x + langkah.y;
	i = jumlahlangkah;
	while (i>0) {
		idpetak++;
		if (idpetak > 31) {
			idpetak =0; //ubah ke start;
		}
	}
	*pemainsekarang.posisiSekarang = idpetak;
	CEK_KONDISI_PETAK(idpetak, *pemainsekarang); //cek kondisi petak yang sedang diinjak sekarang
}

void CEK_KONDISI_PETAK(int id, *pemainsekarang) {
/*Deskripsi*/
	/* Sebuah prosedur untuk mengecek kondisi petak yang diinjak setelah giliran selesai.
	   Jika petak yang diinjak adalah petak milik pemain lain, maka pemain yang sedang ada dalam giliran
	   harus membayar sejumlah uang. Jika petak adalah kesempatan, maka ia mendapatkan kartu kesempatan.
	 */
/* KAMUS */
	   Address alamatsekarang;
	   int i;
/* ALGORITMA */
	   alamatsekarang = CARI_ALAMAT_PETAK(id);
	   /* 
	   switch(Info(alamatsekarang).id) {
			case X : { Berapa ID untuk petak kesempatan? masih bingung
	   				CHANCE(*pemainsekarang.id);
	   				break;
			}
			case X : {Berapa ID untuk petak penjara? masih bingung
					break;
			}
			case X : { Berapa ID untuk petak tax? bingung juga
					TAX();
					break;
			}
			case X : { ID buat petak2 lain?
					break;
			}
			default : { antara menginjak lahan orang atau free.
				   break;
			}

	   }

}
