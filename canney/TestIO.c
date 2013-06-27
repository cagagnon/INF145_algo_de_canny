//
// TestIO.cpp : Exemple d'utilisation de la librairie IOBitmap.h.
//

#include "IOBitmap.h"
#include <stdlib.h>
#include <stdio.h>

int testIO()
{
	SBitMapInfo BitMapInfo;
	char* FileName = "/Users/charlesalexandregagnon/fleurs.bmp";
  
	int LineIter = 0;
	int PixelIter = 0, PosPixel;

	/* lire l'image */
	if (LoadBitmap(FileName, &BitMapInfo)) {

		printf("Hauteur : %i\n", BitMapInfo.Height);
		printf("Largeur : %i\n", BitMapInfo.Length);

		/* Inverser couleurs de toute l'image */
    PosPixel = 0;
		for(LineIter = 0 ; LineIter < BitMapInfo.Height ; LineIter++)
		{
			for(PixelIter = 0; PixelIter < BitMapInfo.Length ; PixelIter++)
			{
				BitMapInfo.vecteur[PosPixel] = 0xFF - BitMapInfo.vecteur[PosPixel]; /*Rouge*/
				BitMapInfo.vecteur[PosPixel+1] = 0xFF - BitMapInfo.vecteur[PosPixel+1]; /*Vert*/
				BitMapInfo.vecteur[PosPixel+2] = 0xFF - BitMapInfo.vecteur[PosPixel+2]; /*Bleu*/

				PosPixel += 3;
			}
		}

		/* on sauvegarde l'image */
		SaveBitmap("/Users/charlesalexandregagnon/image4.bmp", &BitMapInfo);
  }

	return 0;
}
