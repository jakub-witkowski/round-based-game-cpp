CC=g++
CXXFLAGS=-g -Wall
CFLAGS=-std=c++17
srcdir = ../sources
SOURCES1=$(srcdir)/player1.cpp $(srcdir)/TArcher.cpp $(srcdir)/TBase.cpp $(srcdir)/TCatapult.cpp $(srcdir)/TKnight.cpp $(srcdir)/TMap.cpp $(srcdir)/TPikeman.cpp $(srcdir)/TPlayer.cpp $(srcdir)/TRam.cpp $(srcdir)/TRound.cpp $(srcdir)/TSwordsman.cpp $(srcdir)/TUnit.cpp $(srcdir)/TWorker.cpp
SOURCES2=$(srcdir)/player2.cpp $(srcdir)/TArcher.cpp $(srcdir)/TBase.cpp $(srcdir)/TCatapult.cpp $(srcdir)/TKnight.cpp $(srcdir)/TMap.cpp $(srcdir)/TPikeman.cpp $(srcdir)/TPlayer.cpp $(srcdir)/TRam.cpp $(srcdir)/TRound.cpp $(srcdir)/TSwordsman.cpp $(srcdir)/TUnit.cpp $(srcdir)/TWorker.cpp
SOURCES3=$(srcdir)/TMediator.cpp $(srcdir)/TArcher.cpp $(srcdir)/TBase.cpp $(srcdir)/TCatapult.cpp $(srcdir)/TKnight.cpp $(srcdir)/TMap.cpp $(srcdir)/TPikeman.cpp $(srcdir)/TRam.cpp $(srcdir)/TSwordsman.cpp $(srcdir)/TUnit.cpp $(srcdir)/TWorker.cpp $(srcdir)/mediator.cpp

all: player1 player2 mediator run

player1: $(SOURCES1)
	$(CC) $(CXXFLAGS) $(SOURCES1) -o player1 $(CFLAGS)

player2: $(SOURCES2)
	$(CC) $(CXXFLAGS) $(SOURCES2) -o player2 $(CFLAGS)

mediator:  $(SOURCES3)
	$(CC) $(CXXFLAGS) $(SOURCES3) -o mediator $(CFLAGS)

run:
	./mediator