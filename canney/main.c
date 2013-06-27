//
//  main.c
//  canney
//
//  Created by Charles-Alexandre Gagnon on 2013-06-26.
//  Copyright (c) 2013 ETS. All rights reserved.
//

//
// TestIO.cpp : Exemple d'utilisation de la librairie IOBitmap.h.
//

#include "IOBitmap.h"
#include <stdlib.h>
#include <stdio.h>
#include "canny.h"

int main()
{
    T_canny master_canny;
    char* input_file = "/Users/charlesalexandregagnon/image.bmp";
    char* output_file = "/Users/charlesalexandregagnon/image_final.bmp";
    
    if(LoadBitmap(input_file, &master_canny.bmp_info))
    {
        if(!grayscale_convert(&master_canny))
            printf("error: greyscale copy error");
        convert_to_RGB(&master_canny.bmp_info, master_canny.grayscale_image);
        
        if(!SaveBitmap(output_file, &master_canny.bmp_info))
            printf("export error");
    }
    
    else
        printf("error: file unreadable");
    
    
    
    

    
	return 0;
}
