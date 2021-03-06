//Board.h

#ifndef BOARD_H_
#define BOARD_H_

#include "Tile.h"
#include "Direction.h"
#include <vector>

namespace reversi {

class Board {
	private:
		std::vector<std::vector<Tile>> board; //stores the reversi game board
		Direction dir;		

	public:
		Board(int size); //constructor

		~Board() { } //destructor

		int size() const; //length of board

		bool in_board(int row, int col) const; //test if tile is within board

		void set(int row, int col, const Tile& t); //sets the tile (row, col) to be t

		Tile get(int row, int col) const; //return the type of tile at (row, col)

		void print() const; //prints board to terminal

		std::vector<Direction> search_base(int row, int col, const Tile& target); //searches the adjacent 8 spaces around (row, col)

		void search_recur(Direction& dir, int start_row, int start_col, const Tile& target); //searchs for t

		void replace(Direction& dir, int start_row, int start_col, const Tile& main, const Tile& target); //replace all tiles in 1 direction with main

		int score(const Tile& color) const;

		bool check_avail_move(const Tile& main, const Tile& target); //check to see if player can make a valid move

}; //Board

} //reversi

#endif //BOARD_H_
