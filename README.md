# Mini-Projet-C-Lecture-de-trame-GPS-GPGGA









$GPGGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx\*xx



hhmmss.ss= heure de la position

llll.ll  = Latitude = ll° ll' (.ll\*60/100)''

a        = N ou S

yyyyy.yy = Longitude= yy° yy' (.yy\*60/100)''

a        = E ou W/O

x        = fix Qualification (0=invalide; 1=Fix GPS; 2= fix DGPS)

xx       = Nombre de satellites en poursuite

x.x      = DOP (Dilution Horizontale)

x.x      = Altitude, en Mètres, au dessus du MSL (niveau moyen des Océans).

M        = Mètres  (Unité de hauteur de l'antenne)

x.x      = Correction de la hauteur de la géoïde en Mètres par rapport à l'ellipsoïde WGS84 (MSL).

M        = Mètres  (Unité de la séparation ellipsoïde)

x.x      = nombre de secondes écoulées depuis la dernière mise à jour DGPS.

xxxx     = Identification de la station DGPS.

\*xx      = somme de contrôle (XOR de tout les caractères entre $ et \* en ASCII)

