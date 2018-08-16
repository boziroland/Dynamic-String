#
# makefile az F10 osztaly kiprobalasahoz.
# Bozi Roland Sa'ndor, EO7EGE reszere
# Datum: 2018-03-08 22:23:21
# Ez az allomany tetszes szerint modosithato, de nem celszeru
#

CC = g++
CXXFLAGS = -Wall -g
HFT = /home/a/tutors/szebi/hftest2
HEADS = f10.h

f10: f10_main.o f10.o
	$(CC) -Wall -o f10 f10_main.o f10.o -g

f10.o: $(HEADS)

f10_main.o: $(HEADS)

submit: f10
	$(HFT) -10


