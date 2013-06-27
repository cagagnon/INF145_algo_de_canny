

/*********************************************************************************/
/*																				                                       */
/* IOBitmap.h																	                                   */
/*																				                                       */
/* Cette librarie offre une m�thode pour lire un bitmap et l'obtenir comme un    */
/* tableau de char. Il offre aussi une structure permettant d'obtenir des        */
/* informations sur le fichier bitmap.                                           */
/*                                                                               */
/* Le tableau de char �nonce chaque pixel comme 3 char successif repr�sentant    */
/* les couleurs dans l'ordre suivant : Rouge, Bleu, Vert. Comme il s'agit de     */
/* byte, chaque couleur de base peut varier de 0 � 255 (0x00 � 0xFF).            */
/*                                                                               */
/* Le premier pixel est celui situ� en bas � gauche.                             */
/*                                                                               */
/* Si vous ouvrez un fichier, vous devez absolument le r��crire avant d'en       */
/* ouvrir un autre. Vous pouvez par contre l'�crire sous un nom diff�rent.       */
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
/* Cette fonction permet d'obtenir une chaine de char repr�sentant */
/* le fichier bitmap qui vient d'�tre lu.                          */
/*                                                                 */
/* Input - filename : nom du fichier � lire                        */
/* Output - BitMapInfo : l'adresse d'une struct SBitMapInfo        */
/* Retour - 1 si l'ouverture du fichier � bien fonctionn�, 0 sinon.*/
/*                                                                 */
/*******************************************************************/
int LoadBitmap(const char *filename, SBitMapInfo* BitMapInfo);


/*******************************************************************/
/* Sauvegarde d'un bitmap                                          */
/*                                                                 */
/* Cette fonction permet de sauvegarder un bitmap repr�sent� par   */
/* une structure de type "SBitMapInfo" dans un fichier bitmap.     */
/*                                                                 */
/* Input - filename : nom du fichier bitmap � cr�er (ou remplacer) */
/* Input - BitMap : L'adresse de la structure repr�sentant un      */
/*                  bitmap.                                        */
/* Retour - 1 si la sauvegarde du fichier � fonctionn�, 0 sinon.   */
/*                                                                 */
/*******************************************************************/
int SaveBitmap(const char *filename, SBitMapInfo* Bitmap);









































#endif