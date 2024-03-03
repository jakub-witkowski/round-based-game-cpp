CC=g++
CXXFLAGS=-g -Wall
CFLAGS=-std=c++17
srcdir = ../sources
SOURCES=$(srcdir)/player1.cpp $(srcdir)/TArcher.cpp $(srcdir)/TBase.cpp $(srcdir)/TCatapult.cpp $(srcdir)/TKnight.cpp $(srcdir)/TMap.cpp $(srcdir)/TPikeman.cpp $(srcdir)/TPlayer.cpp $(srcdir)/TRound.cpp $(srcdir)/TSwordsman.cpp $(srcdir)/TUnit.cpp

all: compile run

compile: $(SOURCES)
	$(CC) $(CXXFLAGS) $(SOURCES) -o player $(CFLAGS)
#	$(CC) $(SOURCES) -o plot $(CFLAGS)
run:
	./player ../map.txt ../status.txt ../orders.txt