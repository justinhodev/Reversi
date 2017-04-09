OBJS = Reversi.cpp Board.o Human_player.o Computer_player.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

reversi : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o reversi

Board.o : Board.h Board.cpp Tile.h Direction.h
	$(CC) $(CFLAGS) Board.cpp

Human_player.o : Player.h Tile.h Human_player.h Human_player.cpp
	$(CC) $(CFLAGS) Human_player.cpp

Computer_player.o : Player.h Tile.h Computer_player.h Computer_player.cpp
	$(CC) $(CFLAGS) Computer_player.cpp

clean:
	\rm *.o *~ reversi