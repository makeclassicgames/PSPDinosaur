BUILD_PRX = 1
TARGET = raylib
OBJS =  resource.o sprite.o input.o player.o main.o
INCDIR = inc/
CFLAGS = -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =
LIBS=   -lraylib -lpng -lz  -lglut -lGLU -lGL -lpspvfpu 

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Dinosaur

BUILD_PRX=1

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak


