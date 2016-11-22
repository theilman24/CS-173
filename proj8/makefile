all: image

image: image.o Complex.o
	g++ -o image image.o Complex.o

image.o: image.cpp Complex.h
	g++ -c image.cpp

Complex.o: Complex.cc Complex.h
	g++ -c Complex.cc
    