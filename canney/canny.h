//
//  canny.h
//  canney
//
//  Created by Charles-Alexandre Gagnon on 2013-06-26.
//  Copyright (c) 2013 ETS. All rights reserved.
//

#ifndef canney_canny_h
#define canney_canny_h

#define RED_BIAS 0.3
#define BLUE_BIAS 0.11
#define GREEN_BIAS 0.59

#include "IOBitmap.h"

typedef struct
{
    SBitMapInfo bmp_info;
    unsigned char ** grayscale_image;
}T_canny;


// fonction pour faire la conversion de couleur vers noir et blanc
// il retourne l'addresse du tableau de pixels gris
int grayscale_convert(T_canny * info);

// fonction pour faire l'alouage dynamique de mémoire en 2D
unsigned char ** allocate_memory(int width, int height);

//fonction pour retourner les pixels en RGB
void convert_to_RGB(SBitMapInfo * destination, unsigned char ** source);


#endif
