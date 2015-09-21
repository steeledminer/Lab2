#
#This is the make file for craps.cpp
#
craps : craps.o
	g++ craps.o -o craps

craps.o :
	g++ -c craps.cpp

clean :
	rm craps.o craps
