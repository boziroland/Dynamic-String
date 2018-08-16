#
# makefile az F8 feladat kiprobalasahoz.
# Bozi Roland Sa'ndor, EO7EGE reszere
# Datum: 2018-02-19 20:09:30
# Ez az allomany tetszes szerint modosithato, de nem celszeru
#

CXX = g++
CXXFLAGS = -Wall -pedantic -g
HFT = /home/a/tutors/szebi/hftest2
HEADS = f8.hpp

f8: f8_main.o 
	$(CXX) -Wall -pedantic -o f8 f8_main.o -g

f8_main.o: $(HEADS)

submit: f8
	$(HFT) -8


