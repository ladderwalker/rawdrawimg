# rawdrawimg

## display a png image with cnlohr's rawdraw 3 different ways
-----------------------------------------------
### How to
--------------
* Export a png in 8bpc RGBA pixelformat and take note of the size

* then you can either use [stb_image](https://github.com/nothings/stb) and include stb_image.h
  - `unsigned char *img = stbi_load("resources/calcbut.png", &width, &height, &channels, 0);`

* or use `xxd -i calcbut.png > calcbut.h` on the terminal and include calcbut.h
  - make a pointer to the array in calcbut.h
    `unsigned char *img2 = calcbut_png;`

* or use ld to link the png as a binary blob into the executable
  - `ld  -r -b binary -o calcbut.o calcbut.png` on the terminal

  - ```
    extern unsigned char _binary_calcbut_png_start[];
    extern unsigned char _binary_calcbut_png_end[];
    unsigned char *p = _binary_calcbut_png_start;
    ```

* ram those pointers into CNFGBlitImage type casted as an unsigned int, the first 2 parameters   are x,y coordinates of where you want the o,o pixel of your image to appear on the screen, the second 2 are the width and height of your image (you took notes for this in the first step)
  - ```
	CNFGBlitImage((unsigned int*)img, 10, 10, width, height);
	CNFGBlitImage((unsigned int*)img2, 10, 200, 300, 88);
	CNFGBlitImage((unsigned int*)p, 10, 400, 300, 88);
    ```
