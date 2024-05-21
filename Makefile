CPPC=clang++
CPPFLAGS=-Wall -std=c++20 -g -fsanitize=address 
#CPPOPT=-O2 

all:
	$(CPPC) $(PPFLAGS) $(CPPOPT) -c src/source_files/matrix.cpp -I obj/ -o obj/matrix.o
	$(CPPC) $(PPFLAGS) $(CPPOPT) -c src/main.cpp -I obj/ -o obj/main.o
	$(CPPC) $(PPFLAGS) $(CPPOPT) -o bin/app ./obj/matrix.o ./obj/main.o

clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	cd ./bin; ./app;
