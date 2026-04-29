#include <stdbool.h>

bool verifierTrame(char trame[]);

struct trameGPS
{
	char heure[10];
	char latitude[13];
	char N_ou_S;
	char longitude[13];
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
