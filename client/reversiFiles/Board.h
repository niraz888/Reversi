/*
 * Board.h
 *
 * Author: natan furer 204594428
 */

#ifndef BOARD_H_
#define BOARD_H_
#define DEFAULT_SIZE 8


class Board {
public:

	/**
	 * Board function - creates the board.
	 * if size is not given, the default size will be 8x8.
	 * @param size - the board size (size x size).
	 *
	 */
	Board(int size = DEFAULT_SIZE);


	/**
     * copyBoard function - Copies the given board to the current one.
     * @param board a board
     *
     */
	void operator =(const Board &b);


	/**
	 * print function - prints the board.
	 *
	 */
	void print() const;


	/**
	 * destructor.
	 *
	 */
	~Board();

	/**
	 * getSize function - returns the size of the board(nxn).
	 *
	 * @return the size of the table.
	 *
	 */
	int getSize() const;

	/**
	 * getSign function - returns the sing at the given place.
	 *
	 * @param i- the row index
	 * @param j - the column index.
	 * @return the sing at the given place.
	 */
	char getSign(int i, int j) const;


	/**
	 * PutSign function - puts the given sign in the given place.
	 * then updates the number of disks for each sign.
	 *
	 * @param i- the row index
	 * @param j - the column index.
	 * @param s - the sign.
	 *
	 */
	void putSign(int i, int j, char s);

	/**
	 * getNumberOfX function - returns the number of X disks in the table.
	 *
	 * @return number of x discs.
	 */
	int getNumberOfX() const;

	/**
	 * getNumberOfO function - returns the number of O disks in the table.
	 *
	 * @return number of y discs.
	 *
	 */
	int getNumberOfO() const;

	/**
	 * checkIfTableFull function - returns true if the table is full,else false.
	 *
	 */
	bool checkIfTableFull() const;

private:
	char** board;
	int size;
	int numberOfX;
	int numberOfO;
};

#endif /* BOARD_H_ */
