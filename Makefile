CFLAGS=-O3
PROGRAMS=programm
default: $(PROGRAMS)
programm: programm.o teil.o utility.o
clean:
	-rm -f *.o $(PROGRAMS)
