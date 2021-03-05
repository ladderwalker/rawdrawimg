#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
//#define STB_IMAGE_WRITE_IMPLEMENTATION
//#include "stb_image/stb_image_write.h"
#define CNFG_IMPLEMENTATION
#include "rawdraw/CNFG.h"
#include "rawdraw/os_generic.h"
#define CNFGOGL
#define HAS_XSHAPE
#define HAS_XINERAMA


void HandleKey( int keycode, int bDown ) { }
void HandleButton( int x, int y, int button, int bDown ) { }
void HandleMotion( int x, int y, int mask ) { }
void HandleDestroy() { }


int main(void)
{
	// Load image
	int width, height, channels;
	unsigned char *img = stbi_load("resources/calcbut.png", &width, &height, &channels, 0);
	if(img == NULL)
	{
		printf("You ain't got no pict-shuh\n");
		exit(1);
	}

	for(int i = 0; i < 48; i++)
    {
    	printf("%u\n", img[i]);
   	}

	CNFGSetup( "Example App", 1440, 768 );
	while(1)
	{
		CNFGBGColor = 0x000080ff; //Dark Blue Background

		short w, h;
		CNFGClearFrame();
		CNFGHandleInput();
		CNFGGetDimensions( &w, &h );

		//Change color to white.
		//CNFGColor( 0xffffffff );

		//CNFGPenX = 1;
		//CNFGPenY = 1;

		//CNFGDrawText( "Hello, World", 2 );

		CNFGBlitImage((unsigned int*)img, 10, 10, width, height);

		CNFGSwapBuffers();
	}


	stbi_image_free(img);

 	return 0;

}
