/******************************************************************************
*  ASR => partie R2.04 du S2.03                                               *
*******************************************************************************
*                                                                             *
*  N° du Sujet : 1                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé du sujet : Analyse de trame GPS                                   *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Groupe-Nom-prénom1 : DULUC Soren                                           *
*                                                                             *
*  Groupe-Nom-prénom2 : SAURY Guillaume                                       *
*                                                                             *
*  Sujet 3 -> Groupe-Nom-prénom3 :                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "analyse_de_trame.h"

int main(void)
{
	char trame[50];
	printf("Entrez un trame GPS GPGGA : ");
	scanf("%s", trame);
	
	if (!verifierTrame(trame))
	{
		printf("La trame %s est invalide, veuillez entrer une trame GPS suivant la norme NMEA 0183\n",trame);
		return -1;
	}
	
	TrameGPS trameStruct = extraireChamps(trame);
	
	trameStruct = formaterHeure(trameStruct);
	trameStruct = convertirLongEtLat(trameStruct);
	
	affichageHeure(trameStruct);
	affichageLongEtLat(trameStruct);
}

