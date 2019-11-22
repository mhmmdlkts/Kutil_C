default: programm

programm: programm.c teil.c utility.c
	cc -o programm programm.c teil.c utility.c