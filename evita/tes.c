//Pajak,Bonus

procedure Tax()
{
	if (currentposition[playernum]==15)
	{
	 	printf(" Pajak Bumi dan Bangunan, uangmu berkurang 100K");
        accountmoney[playernum]-= 100000;
        printf("Sisa uang  %d",accountmoney[playernum]);
	}
}

procedure Bonus()
{
	printf("Selamat, kamu mendapatkan 150K!");
    accountmoney[playernum]-= 150000;
    printf("Uang kamu sekarang %d",accountmoney[playernum]);
}

