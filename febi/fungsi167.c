
tuple ROLL_DICE() {
/* fungsi ROLL_DICE mengembalikan sebuah tuple dengan dua nilai bertype data integer, 
   nilai pertama adalah hasil acak dari dadu pertama. Nilai kedua adalah hasil acak dari dadu ke dua. Digunakan dua dadu pada permainan ini. */

/* KAMUS */

/* ALGORITMA */
	/* Ada dua pilihan, pertama pake fungsi rand() yang ada di stdlib.h atau
	   buat fungsi sendiri (menggunakan fungsi roller). */
}

/* ini fungsi optional, masih belum tahu bakal dipakai atau tidak 
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
} */

void SHOW_OFFERED() {
/* Procedure menampilkan semua list offered */
/* KAMUS */

/* ALGORITMA */
	/* menampilkan list yang offered. Nanti akan ada sebuah struktur data yang akan menampung property apa saja
	   yang bisa dibeli. struktur data ini dapat diupdate setiap saat, setiap user ingin menambahkan property miliknya ke
	   struktur data ini, artinya property tersebut sekarang berstatus 'dijual'. Semua property dengan status tersebut
	   dapat dilihat di prosedur ini. Prosedur ini dapat diakses oleh pemain yang sedang dalam gilirannya. Pemain lain tidak
	   bisa mengakses prosedur ini jika bukan giliran mainnya.

	   prosedur ini dapat diakses kapanpun dan berulang kali. ketika seorang pemain mendapatkan gilirannya, ia mendapatkan
	   beberapa pilihan: roll the dice, dan sebagainya. termasuk prosedur ini*/

}

void BUY_OFFERED() {
/* Procedure untuk membeli property. Procedure ini dapat diakses saat user mengakses SHOW_OFFERED
   sehingga ketika user melihat list offered, ia dapat membelinya dengan menggunakan procedure ini */
/* KAMUS */

/* ALGORITMA */
	/* ketika menampilkan semua property dengan status 'dijual', akan muncul sebuah opsi 'exit' atau 'buy'
	   Jika user memilih buy, maka ia dapt membeli satu atau lebih property, disesuaikan dengan budget yang ia miliki.
	   Jika user membeli property tertentu, sang pemilik lama akan mendapatkan uang, dan semua 'surat kepemilikan' diberikan
	   kepada pemilik baru. Pemilik baru akan kehilangan uangnya, namun mendapatkan property yang ia inginkan.

	   pemain yang sedang mendapatkan giliran dapat mengakses fungsi ini berulang-ulang sampai ia menginput opsi 'selesai' atau
	   sejenisnya. */
}