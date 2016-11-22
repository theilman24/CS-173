//================================================================
// names of your group
// date of completion
// image.cpp
// description of this project
//================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "Complex.h"
using namespace std;

#define HEIGHT 500
#define WIDTH  500
#define X_START -1.5
#define X_END    0.5
#define Y_START -1.0
#define Y_END    1.0

/*================================================================
Function to write 2d arrays of RGB values into a bitmap image
pre-condition :	red, green, and blue are integer 2d arrays (of size HEIGHT x WIDTH) with colors for each pixel
post-condition: writes a file called img.bmp with the image in the array
Adapted from http://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
================================================================*/
void writeBMP(int red[HEIGHT][WIDTH], int green[HEIGHT][WIDTH], int blue[HEIGHT][WIDTH])
{
    int r, g, b, x, y, area = HEIGHT * WIDTH;
    FILE *f;
    unsigned char *img = NULL;
    int filesize = 54 + 3 * area;  
    if( img )
	free( img );
    img = (unsigned char *)malloc(3*area);
    memset(img, 0, 3*area * sizeof(unsigned char));
    
    for(int i = 0; i < WIDTH; i++)
    {
	for(int j = 0; j < HEIGHT; j++)
	{
	    x=i; y=(HEIGHT-1)-j;
	    r = red[i][j];
	    g = green[i][j];
	    b = blue[i][j];
	    if (r > 255) r=255;
	    if (g > 255) g=255;
	    if (b > 255) b=255;
	    img[(x+y*WIDTH)*3+2] = (unsigned char)(r);
	    img[(x+y*WIDTH)*3+1] = (unsigned char)(g);
	    img[(x+y*WIDTH)*3+0] = (unsigned char)(b);
	}
    }
    
    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
    unsigned char bmppad[3] = {0,0,0};
    
    bmpfileheader[ 2] = (unsigned char)(filesize    );
    bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);
    
    bmpinfoheader[ 4] = (unsigned char)(WIDTH    );
    bmpinfoheader[ 5] = (unsigned char)(WIDTH>> 8);
    bmpinfoheader[ 6] = (unsigned char)(WIDTH>>16);
    bmpinfoheader[ 7] = (unsigned char)(WIDTH>>24);
    bmpinfoheader[ 8] = (unsigned char)(HEIGHT   );
    bmpinfoheader[ 9] = (unsigned char)(HEIGHT>> 8);
    bmpinfoheader[10] = (unsigned char)(HEIGHT>>16);
    bmpinfoheader[11] = (unsigned char)(HEIGHT>>24);
    
    f = fopen("img.bmp","wb");
    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    for(int i=0; i<HEIGHT; i++)
    {
	fwrite(img+(WIDTH*(HEIGHT-i-1)*3),3,WIDTH,f);
	fwrite(bmppad,1,(4-(WIDTH*3)%4)%4,f);
    }
    fclose(f);
}

//================================================================
// 		Program
// The main program iterates through every pixel on the image
// and determines its RGB value based on the Complex class we
// created for the previous project. 
//================================================================


int main()
{
    int red[HEIGHT][WIDTH], green[HEIGHT][WIDTH], blue[HEIGHT][WIDTH];

 
	int redR[32];
	int greenG[32];
	int blueB[32];
	
	
	for ( int i = 0; i < 32; i++)									// creates an RGB value for every a
	{
		 redR[i] = 255 - (7 * i);
		 greenG[i] = 255;
		 blueB[i] = 255;
	}
  
    float b;

    
    for ( int i = 0; i < WIDTH; i++ )
    {
    
    	float w = ((float)i/WIDTH)*(X_END-X_START)+X_START; 		// determines the coordinating x-value
    																	// for the real number being calculated
    	for ( int j = 0; j < HEIGHT; j++)
    	{
    		float h = ((float) j/HEIGHT)*(Y_END-Y_START)+Y_START;	// determines the y value
    		int a = 0;
    		b = 0;
    		
    		Complex c(w,h), z;										// calls the Complex class
    		while ( (b < 2) and (a<32))
    		{
    			z = (z * z) + c;									
    			b = sqrt(z.real*z.real + z.imaginary*z.imaginary);
    			a++; 
    		}
    		
    		if ( a == 32 )
    		{
    			red[i][j] = 0;
    			green[i][j] = 230;
    			blue[i][j] = 255;
    		}
    		else 
    		{
				red[i][j] = redR[a];
    			green[i][j] = greenG[a];
    			blue[i][j] = blueB[a];
    		}
    		
    	}
    }
    
	writeBMP(red, green, blue);
    
    return 0;
}





