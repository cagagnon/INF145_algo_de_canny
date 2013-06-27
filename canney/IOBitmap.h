

/*********************************************************************************/
/*																				                                       */
/* IOBitmap.h																	                                   */
/*																				                                       */
/* Cette librarie offre une méthode pour lire un bitmap et l'obtenir comme un    */
/* tableau de char. Il offre aussi une structure permettant d'obtenir des        */
/* informations sur le fichier bitmap.                                           */
/*                                                                               */
/* Le tableau de char énonce chaque pixel comme 3 char successif représentant    */
/* les couleurs dans l'ordre suivant : Rouge, Bleu, Vert. Comme il s'agit de     */
/* byte, chaque couleur de base peut varier de 0 à 255 (0x00 à 0xFF).            */
/*                                                                               */
/* Le premier pixel est celui situé en bas à gauche.                             */
/*                                                                               */
/* Si vous ouvrez un fichier, vous devez absolument le réécrire avant d'en       */
/* ouvrir un autre. Vous pouvez par contre l'écrire sous un nom différent.       */
/*                                                                               */
/* NOTE - Vous ne pouvez pas changer la taille du bitmap                         */
/*                                                                               */
/*********************************************************************************/

#ifndef IOBitmap_H
#define IOBitmap_H

/*Structure d'information sur le bitmap*/
typedef struct
{ unsigned char* vecteur;     //le vecteur des valeurs RGB de chaque pixel
	int Length;                 //largeur du Bitmap
	int Height;                 //hauteur du Bitmap
	int NbOfPixel;              //nombre total de pixels 
	int Padding;                //octets de remplissage (s'il y a lieu)
}SBitMapInfo;

/*******************************************************************/
/* Lecture d'un bitmap                                             */
/*                                                                 */
/* Cette fonction permet d'obtenir une chaine de char représentant */
/* le fichier bitmap qui vient d'être lu.                          */
/*                                                                 */
/* Input - filename : nom du fichier à lire                        */
/* Output - BitMapInfo : l'adresse d'une struct SBitMapInfo        */
/* Retour - 1 si l'ouverture du fichier à bien fonctionné, 0 sinon.*/
/*                                                                 */
/*******************************************************************/
int LoadBitmap(const char *filename, SBitMapInfo* BitMapInfo);


/*******************************************************************/
/* Sauvegarde d'un bitmap                                          */
/*                                                                 */
/* Cette fonction permet de sauvegarder un bitmap représenté par   */
/* une structure de type "SBitMapInfo" dans un fichier bitmap.     */
/*                                                                 */
/* Input - filename : nom du fichier bitmap à créer (ou remplacer) */
/* Input - BitMap : L'adresse de la structure représentant un      */
/*                  bitmap.                                        */
/* Retour - 1 si la sauvegarde du fichier à fonctionné, 0 sinon.   */
/*                                                                 */
/*******************************************************************/
int SaveBitmap(const char *filename, SBitMapInfo* Bitmap);









































#endif