#include "monopoli/monopoli.h"

int main(){
	
	INISIALISASI(); // kak ayunda
	KATA_PEMBUKA(); // evita

	while(!GAME_OVER()){ // jason
		printf("> ");
		fgets(PUBLIC_inputTerakhir, sizeof PUBLIC_inputTerakhir, stdin);
		printf("> ");
		OLAH(PUBLIC_inputTerakhir);
	}

	return 0;
}
