# Mini-Projet-C-Lecture-de-trame-GPS-GPGGA



##### Membres du groupe :

* DULUC Soren
* SAURY Guillaume



##### Objectif :

L'objectif de cette application est d'interpréter une trame GPS suivant la norme NMEA 0183, et d'afficher la date de réception de la trame ainsi que la latitude et la longitude que fournit celle-ci.



##### Documentation :

###### verifierTrame :

* Description : Renvoie true si la chaine de caractères est une trame GPS suivant la norme NMEA 0183, et false sinon.
* Entrée : chaine de caractères (char\[])
* Sortie : booléen (bool)



###### extraireChamps :

* Description : Extrait les différents champs de la trame GPS dans un struct TrameGPS.
* Entrée : chaine de caractères (char\[])
* Sortie : struct TrameGPS (TrameGPS)



###### convertirLongEtLat :

* Description : Convertie la longitude et la latitude pour qu'elles soient lisibles et les range dans un struct TrameGPS qui est renvoyé.
* Entrée : struct TrameGPS (TrameGPS)
* Sortie : struct TrameGPS (TrameGPS)



###### affichageLongEtLat :

* Description : Affiche la longitude et la latitude de la TrameGPS donnée en paramètre.
* Entrée : struct TrameGPS (TrameGPS)
* Sortie : rien (void)



###### formaterHeure :

* Description : Formate l'heure pour qu'elle soit lisible et la range dans un struct TrameGPS qui est renvoyé.
* Entrée : struct TrameGPS (TrameGPS)
* Sortie : struct TrameGPS (TrameGPS)



###### affichageHeure :

* Description : Affiche l'heure de la TrameGPS donnée en paramètre.
* Entrée : struct TrameGPS (TrameGPS)
* Sortie : rien (void)



