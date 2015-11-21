boolean GAME_OVER(){
	/* KAMUS */
	int jumlahStatusTidakMain = 0;
	int i = 0;
	
	/* ALGORITMA */
	while(i < 4){
		if((PUBLIC_pemain[i].statusDipenjara) && (PUBLIC_pemain[i].uang < hargaKeluarPenjara) && (PUBLIC_pemain[i].(kartu[0]) == 0)){
			jumlahStatusTidakMain = jumlahStatusTidakMain + 1;
		}
		if(!(PUBLIC_pemain[i].statusMain)){
			jumlahStatusTidakMain = jumlahStatusTidakMain + 1;
		}
		i++;
	}
	if (jumlahStatusTidakMain == 3){
		return true;
	}else{
		return false;
	}
}
