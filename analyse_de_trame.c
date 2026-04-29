#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "analyse_de_trame.h"

bool verifierTrame(char trame[])
{
	//On vérifie si la trame a le bon nombre de champs (14 pour une trame GPGGA)
	int nbChamps = 0;
	for (int i=0; i < strlen(trame); i++)
	{
		if (trame[i] == ',') { nbChamps += 1;}
	}
	if (nbChamps != 14) return false;
	
	//On trouve l'indice de $
	char *e;
	e = strchr(trame, '$');
	if (e == NULL) return false;
	int index$ = (long)(e - trame);
	
	//On trouve l'indice de *
	e = strchr(trame, '*');
	if (e == NULL) return false;
	int indexAst = (long)(e - trame);
	
	//On calcule la checksum théorique de la trame
	int checkSum = 0;
	
	for (int i=index$ + 1; i < indexAst; i++)
	{
		checkSum ^= (int)trame[i];
	}
	
	//On obtient la checksum donnée dans la trame
	int checkSumLu;
	sscanf(e + 1, "%x", &checkSumLu);
	
	//On vérifie que les deux checksum sont similaires
	return checkSum == checkSumLu;
}

TrameGPS extraireChamps(char trame[])
{
	TrameGPS *t;
	
	sscanf(trame,"$GPGGA,%[^,],%[^,],%c,%[^,],%c,%d,%d,%f,%f,%c,%f,%c,%f,%[^*]*%s",
		t->heure,
		t->latitude,
		&t->N_ou_S,
		t->longitude,
		&t->E_ou_O,
		&t->fix,
		&t->nbrSatellites,
		&t->DOP,
		&t->altitude,
		&t->uniteHauteur,
		&t->correction,
		&t->uniteCorrection,
		&t->secDepuisMAJ,
		t->idStation,
		t->checkSum
	);
	printf("Heure : %s\n", t->heure);
	return *t;
}

