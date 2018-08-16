#
# makefile az F14 feladat kiprobalasahoz.
# Bozi Roland Sa'ndor, EO7EGE reszere
# Datum: 2018-05-03 22:19:15
# Ez az allomany tetszes szerint modosithato, de nem celszeru
#

CC = g++
CXXFLAGS = -Wall -pedantic -g
HFT = /home/a/tutors/szebi/hftest2
HEADS = f14.hpp

f14: f14_main.o 
	$(CC) -Wall -o f14 f14_main.o 

f14_main.o: $(HEADS)

submit: f14
	$(HFT) -14


