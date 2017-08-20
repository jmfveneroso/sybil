CC=g++

OS := $(shell uname)
$(info $(OS))
ifeq ($(OS), Linux)
  INC=-I/usr/local/include
  LIBS=-L/usr/X11/lib -L/usr/local/lib -lglfw3 -lGL -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread -lGLEW -lpng
else
  LIBS=-L/usr/X11/lib -L/usr/local/lib -lglfw -lglew -lpng -framework OpenGL -framework GLUT
endif



_DEPS = src/alternative_render.h src/visual_engine.h src/vector.h src/vertex.h src/bitmap.h src/objloader.h

build/main: src/main.cpp $(_DEPS)
	$(CC) -o $@ $< $(LIBS) $(C_FLAGS) $(INC) -g -O3
