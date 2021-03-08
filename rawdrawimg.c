#include <stdio.h>
#include <stdlib.h>

#include "calcbut.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

#define CNFG_IMPLEMENTATION
#include "rawdraw/CNFG.h"
#include "rawdraw/os_generic.h"

#define HAS_XSHAPE
#define HAS_XINERAMA

extern unsigned char _binary_calcbut_png_start[];
extern unsigned char _binary_calcbut_png_end[];
unsigned char *p = _binary_calcbut_png_start;

void HandleKey( int keycode, int bDown ) { }
void HandleButton( int x, int y, int button, int bDown ) { }
void HandleMotion( int x, int y, int mask ) { }
void HandleDestroy() { }


int main(void)
{
	//Load image from object
	printf( "address of start: %p\n", &_binary_calcbut_png_start);
    printf( "address of end: %p\n", &_binary_calcbut_png_end);

    /*for (unsigned char* p = _binary_calcbut_png_start; p != _binary_calcbut_png_end; ++p) {
        putchar( *p);
    }*/

	// Load image from png file with nothing/stb_image.h
	int width, height, channels;
	unsigned char *img = stbi_load("resources/calcbut.png", &width, &height, &channels, 0);
	if(img == NULL)
	{
		printf("You ain't got no pict-shuh\n");
		exit(1);
	}

    // pointer to array created by xxd
	unsigned char *img2 = calcbut_png;

	CNFGSetup( "Example App", 1440, 768 );
	while(1)
	{
		CNFGBGColor = 0x000080ff; //Dark Blue Background

		short w, h;
		CNFGClearFrame();
		CNFGHandleInput();
		CNFGGetDimensions( &w, &h );


		CNFGBlitImage((unsigned int*)img, 10, 10, width, height);
		CNFGBlitImage((unsigned int*)img2, 10, 200, 300, 88);
		CNFGBlitImage((unsigned int*)p, 10, 400, 300, 88);

		CNFGSwapBuffers();
	}


	stbi_image_free(img);

 	return 0;

}
