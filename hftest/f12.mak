#
# makefile az F12 osztaly kiprobalasahoz.
# Bozi Roland Sa'ndor, EO7EGE reszere
# Datum: 2018-04-04 23:28:43
# Ez az allomany tetszes szerint modosithato, de nem celszeru
#

CC = g++
CXXFLAGS = -Wall 
HFT = /home/a/tutors/szebi/hftest2
HEADS = f12.h

f12: f12_main.o f12.o
	$(CC) -Wall -o f12 f12_main.o f12.o

f12.o: $(HEADS)

f12_main.o: $(HEADS)


submit: f12
	$(HFT) -12


