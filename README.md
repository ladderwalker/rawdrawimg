# rawdrawimg

## display a png image with cnlohr's rawdraw
-----------------------------------------------
### How to
--------------
* Export a png in 8bpc RGBA pixelformat and take note of the size
* use 'xxd -i calcbut.png > calcbut.h' and include calcbut.h
* make a pointer to the array in calcbut.h
    'unsigned char *img2 = calcbut_png;'
* ram that pointer into CNFGBlitImage type casted as an unsigned int, the first 2 parameters   are x,y coordinates of where you want the o,o pixel of your image to appear on the screen, the second 2 are the width and height of your image (you took notes for this in the first step)
'CNFGBlitImage((unsigned int*)img2, 10, 200, 300, 88);'
