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
*  Nom du fichier : analyse_de_trame.c                                        *
*                                                                             *
******************************************************************************/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "analyse_de_trame.h"

//Renvoie true si la trame est valide, false sinon
bool verifierTrame(char trame[])
{
	//On vérifie si la trame a le bon nombre de champs (15 pour une trame GPGGA, donc 14 virgules)
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
	
	//On calcule la checksum théorique de la trame (XOR des caractères entre $ et *)
	int checkSum = 0;
	
	for (int i=index$ + 1; i < indexAst; i++)
	{
		checkSum ^= (int)trame[i];
	}
	
	//On obtient la checksum donnée dans la trame (située après *)
	int checkSumLu;
	sscanf(e + 1, "%x", &checkSumLu);
	
	//On vérifie que les deux checksum sont similaires
	return checkSum == checkSumLu;
}

//Extrait les informations de la trame dans un struct TrameGPS
TrameGPS extraireChamps(char trame[])
{
	TrameGPS t;
	
	sscanf(trame,"$GPGGA,%[^,],%[^,],%c,%[^,],%c,%d,%d,%f,%f,%c,%f,%c,%f,%[^*]*%s",
		t.heure,
		t.latitude,
		&t.N_ou_S,
		t.longitude,
		&t.E_ou_O,
		&t.fix,
		&t.nbrSatellites,
		&t.DOP,
		&t.altitude,
		&t.uniteHauteur,
		&t.correction,
		&t.uniteCorrection,
		&t.secDepuisMAJ,
		t.idStation,
		t.checkSum
	);
	return t;
}

TrameGPS convertirLongEtLat(TrameGPS trame)
{
	//On transforme la trame en double
    double val = atof(trame.latitude);
	
	//On extrait les degrès
    int deg = (int)(val / 100);
    
    //On extrait les minutes
    double minutes = val - deg * 100;

	//On extrait les fractions de minutes et on les convertie en secondes
    int min = (int)minutes;
    double sec = (minutes - min) * 60;
	
	//On stock les degrès, minutes et secondes dans le struct TrameGPS
    snprintf(trame.latitude, sizeof(trame.latitude),
             "%02d°%02d'%05.2f''", deg, min, sec);

	//Même fonctionnement que pour la latitude, mais on a un caractère de plus pour les degrès
    val = atof(trame.longitude);

    deg = (int)(val / 100);
    minutes = val - deg * 100;

    min = (int)minutes;
    sec = (minutes - min) * 60;

    snprintf(trame.longitude, sizeof(trame.longitude),
             "%03d°%02d'%05.2f''", deg, min, sec);

    return trame;
}
	
void affichageLongEtLat(TrameGPS trame)
{
	printf("Les coordonnées de cette trame sont %s,%c et %s,%c\n", trame.latitude, trame.N_ou_S, trame.longitude, trame.E_ou_O);
}
	
TrameGPS formaterHeure(TrameGPS trame)
{
	char heure[16];
	//On extrait les heures
	strncpy(heure, trame.heure, 2);
	heure[2] = '\0';
	strcat(heure, "h");
	
	//On extrait les minutes
	strncat(heure, trame.heure + 2, 2);
	strcat(heure, "m");
	
	//On extrait les secondes
	strncat(heure, trame.heure + 4, 2);
	strcat(heure, "s");
	
	//On stocke l'heure formaté dans la struct TrameGPS et on la renvoie
	strcpy(trame.heure, heure);
	return trame;
}
	
void affichageHeure(TrameGPS trame)
{
	printf("La trame a été reçu a %s\n",trame.heure);
}

