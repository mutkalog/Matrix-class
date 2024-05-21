CPPC=clang++
CPPFLAGS=-g -Wall -std=c++20 -fsanitize=address 
CPPOPT=#-O2

all:
	$(CPPC) $(CPPFLAGS) $(CPPOPT) -c src/source_files/matrix.cpp -I obj/ -o obj/matrix.o
	$(CPPC) $(CPPFLAGS) $(CPPOPT) -c src/main.cpp -I obj/ -o obj/main.o
	$(CPPC) $(CPPFLAGS) $(CPPOPT) -o bin/app ./obj/matrix.o ./obj/main.o

clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	cd ./bin; ./app;
