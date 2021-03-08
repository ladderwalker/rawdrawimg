all : rawdrawimg

#for X11 consider:             xorg-dev
#for X11, you will need:       libx-dev
#for full screen you'll need:  libxinerama-dev libxext-dev
#for OGL You'll need:          mesa-common-dev libglu1-mesa-dev

#-DCNFGRASTERIZER
#  and
#-CNFGOGL
#  are incompatible.






rawdrawimg : rawdrawimg.c
	ld  -r -b binary -o calcbut.o calcbut.png \
	&& gcc -o $@ $^ calcbut.o -lX11 -lpthread -lXinerama -lXext -lGL -g -lm -ldl

clean :
	rm -rf *.o *~ rawdrawimg rawdrawimg_ogl
