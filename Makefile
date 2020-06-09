CC=g++
CXXFLAGS=-g -lsfml-graphics\
	 -lsfml-window\
	 -lsfml-system

OBJ=main.o line.o ray.o particle.o
DEP=wall.h line.h main.h particle.h

EXECUTABLE=Raytracer

.phony:make clean all run

%.o: %.cpp $(DEP)
	$(CC) -c -o $@ $<

make: $(OBJ)
	$(CC) -o $(EXECUTABLE) $^ $(CXXFLAGS)

run: make
	./$(EXECUTABLE)

clean: run
	rm $(OBJ) $(EXECUTABLE)

all: make run clean
