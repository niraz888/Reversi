/*
 * StandardLogic.h
 *
 *  natan furer 204594428
 */

#ifndef STANDARDLOGIC_H_
#define STANDARDLOGIC_H_
#include "GameLogic.h"
using namespace std;

class StandardLogic : public GameLogic {
public:

	/**
     * checkForPointInGame function - check if the given point is
     * possible point.
     *
     * @param p the point.
     * @return true if yes, false if not.
     */
	bool checkForPointInGame(Point &p);

	/**
	 * GameLogic function - creates a standard game logic object.
	 * handles the game logic.
	 *
	 */
	StandardLogic();

	virtual const vector<Point>& possiblePoints(Board &b, char s);
	virtual void applyMoveWithGivenPoint(Board &b, Point &p, char s);

	/**
	 * StandardLogic function - destructor.
	 *
	 */
	virtual ~StandardLogic();

private:
	vector<Point> pointPossible;

	/**
	 * checkSorrounding function - the function checks all 8 possible direction
	 * of the given indexes for its rival and puts the possible apply points
	 * in the vector using checkSequence, or using checkSequenceAndAplly
	 * to apply the points after the player move.
	 *
	 * @param s the player sign.
	 * @param b the game board.
	 * @param i the row index of with the sign.
	 * @param j the col index of with the sign.
	 * @param option - true for search and put, false for search and apply.
	 */
	void checkSorrounding(char s, Board &b, int i, int j, bool option);


	/**
	 * checkSequence function - the function checks around the given rival to
	 * add a possible point to move.the function runs to the given direction
	 * and search for an empty space.
	 *
	 * @param b the game board.
	 * @param rival - the rival sign.
	 * @param rowOperator - determine the check direction for the row index.
	 * @param colOperator - determine the check direction for the col index.
	 * @param i -  the roe index.
	 * @param j - the j col index.
	 */
	void checkSequence(const Board &b, char rival, int rowOperator,
			int colOperator, int i, int j);

	/**
	 * checkSequenceAndAplly function - the function checks around the given rival to
	 * given direction and apply the player sign instead of the rival disc.
	 * the function will "flip" rival disc only if it will find the player sign in the
	 * sequence.
	 *
	 * @param b the game board.
	 * @param rival - the rival sign.
	 * @param rowOperator - determine the check direction for the row index.
	 * @param colOperator - determine the check direction for the col index.
	 * @param i -  the roe index.
	 * @param j - the j col index.
	 */
	void checkSequenceAndAplly(Board &b, char rival, int rowOperator,
			int colOperator, int i, int j);

	/**
	 * getCompetitor function - returns the rival of the given player sign.
	 *
	 * @param s the player sign.
	 * @return the rival sign of the given player sign
	 */
	char getCompetitor(char s) const;
};

#endif /* STANDARDLOGIC_H_ */
