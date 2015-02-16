TARGET=OpenGL
cache()
SOURCES+=src/*.cpp
HEADERS+=header/*.h

QMAKE_CXXFLAGS+=$$system(sdl2-config --cflags)
LIBS+=$$system(sdl2-config --libs)
LIBS += -lGL -lGLU -lglut

DEFINES +=NGL_DEBUG

LIBS +=  -L/$(HOME)/NGL/lib -l NGL
INCLUDEPATH += $$(HOME)/NGL/include/
