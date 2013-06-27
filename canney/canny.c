#include <stdio.h>
#include "canny.h"
#include <stdlib.h>

unsigned char ** allocate_memory(int width, int height)
{
    unsigned char ** tableau;
    int i;
    
    tableau = (unsigned char **) malloc (height * sizeof(unsigned char));
    if (tableau == NULL)
        return NULL;
    
    for(i=0; i < height; i++)
    {
        tableau[i] = (unsigned char *) malloc(width * sizeof(unsigned char));
        if (tableau[i] == 0)
            return NULL;
        //FREE COMMAND NEEDED
    }
    
    return tableau;
}


int grayscale_convert(T_canny * info)
{
    int i,j,pos = 0;
    
    info->grayscale_image = allocate_memory(info->bmp_info.Length, info->bmp_info.Height);
    if (info->grayscale_image == NULL)
        return 0;
    
    for(i = 0; i < info->bmp_info.Height; i++)
    {
        for(j = 0; j < info->bmp_info.Length; j++)
        {
            info->grayscale_image[i][j] = (info->bmp_info.vecteur[pos] * RED_BIAS) + (info->bmp_info.vecteur[pos+1] * GREEN_BIAS) + (info->bmp_info.vecteur[pos+2] * BLUE_BIAS);
            pos += 3;
        }
    }
    
    return 1;
}


void convert_to_RGB(SBitMapInfo * destination, unsigned char ** source)
{
    int i,j,pos = 0;
    
    for(i = 0; i < destination->Height; i++)
    {
        for(j = 0; j < destination->Length; j++)
        {
            destination->vecteur[pos] = (source[i][j]);
            destination->vecteur[pos+1] = (source[i][j]);
            destination->vecteur[pos+2] = (source[i][j]);
            pos +=3;
        }
    }
}













