#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "analyse_de_trame.h"

int main(void)
{
	char trame[50];
	printf("Entrez un trame GPS GPGGA : ");
	scanf("%s", trame);
	
	verifierTrame("$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E");
	TrameGPS trameStruct = extraireChamps("$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E");
}

