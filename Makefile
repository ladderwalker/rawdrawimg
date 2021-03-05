all : rawdrawimg rawdrawimg_ogl

#for X11 consider:             xorg-dev
#for X11, you will need:       libx-dev
#for full screen you'll need:  libxinerama-dev libxext-dev
#for OGL You'll need:          mesa-common-dev libglu1-mesa-dev

#-DCNFGRASTERIZER
#  and
#-CNFGOGL
#  are incompatible.






rawdrawimg : rawdrawimg.c
	gcc -o $@ $^ -lX11 -lpthread -lXinerama -lXext -lGL -g -lm -ldl

rawdrawimg_ogl : rawdrawimg.c
	gcc -o $@ $^ -lX11 -lpthread -lXinerama -lXext -lGL -g -DCNFGOGL -lm -ldl

clean :
	rm -rf *.o *~ rawdrawimg rawdrawimg_ogl
