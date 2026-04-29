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
*  Nom du fichier : analyse_de_trame.h                                        *
*                                                                             *
******************************************************************************/

#include <stdbool.h>

bool verifierTrame(char trame[]);

struct trameGPS
{
	char heure[10];
	char latitude[32];
	char N_ou_S;
	char longitude[32];
	char E_ou_O;
	int fix;
	int nbrSatellites;
	float DOP;
	float altitude;
	char uniteHauteur;
	float correction;
	char uniteCorrection;
	float secDepuisMAJ;
	char idStation[5];
	char checkSum[3];
};

typedef struct trameGPS TrameGPS;

TrameGPS extraireChamps(char trame[]);
TrameGPS convertirLongEtLat(TrameGPS trame);
void affichageLongEtLat(TrameGPS trame);
TrameGPS formaterHeure(TrameGPS trame);
void affichageHeure(TrameGPS trame);
