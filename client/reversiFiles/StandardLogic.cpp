/*
 * StandardLogic.cpp
 *
 *  natan furer 204594428
 */

#include "StandardLogic.h"

StandardLogic::StandardLogic() {
}

const vector<Point>& StandardLogic::possiblePoints(Board &b, char s){
	for(int i = 0; i < b.getSize();i++) {
		for(int j = 0; j < b.getSize();j++){
			//check for player sign in the table
			if(b.getSign(i, j) == s) {
				checkSorrounding(s, b, i, j, true);
			}
		}
	}
	return pointPossible;
}

void StandardLogic::checkSequence(const Board &b, char rival, int rowOperator,
		int colOperator, int i, int j) {
	while ((i > -1) && (j > -1) && (i < b.getSize()) && (j < b.getSize())) {
		if (b.getSign(i,j) == ' ') {
			Point point(i + 1, j + 1);
			if(!checkForPointInGame(point)) {
				pointPossible.push_back(point);
			}
			return;
		}
		//check for rival sequence
		if (b.getSign(i, j) == rival) {
			i = i + rowOperator;
			j = j + colOperator;
			continue;
		}
		return;
	}
}

bool StandardLogic::checkForPointInGame(Point &p) {
	for (vector<Point>::iterator it = pointPossible.begin();
			it!= pointPossible.end(); it++) {
		if (*it == p) {
			return true;
		}
	}
	return false;
}


void StandardLogic::checkSorrounding(char s,Board &b, int i, int j, bool option) {
	char rival = getCompetitor(s);
	//check for each 8 possible sides:
	if ((i - 2 > -1) && (j - 2 > -1) && (b.getSign(i - 1, j - 1) == rival)) {
		if(option) {
			checkSequence(b, rival, -1, -1, i - 2, j - 2);
		} else {
			checkSequenceAndAplly(b, rival, -1, -1, i - 2, j - 2);
		}
	}
	if ((i - 2 > -1)  && (b.getSign(i -1, j) == rival)) {
		if(option) {
			checkSequence(b, rival, -1, 0, i - 2, j);
		} else {
			checkSequenceAndAplly(b, rival, -1, 0, i - 2, j);
		}
	}
	if ((i - 2 > -1) && (j + 2 < b.getSize()) && (b.getSign(i - 1, j + 1) == rival)) {
		if(option) {
			checkSequence(b, rival, -1, 1, i - 2, j + 2);
		} else {
			checkSequenceAndAplly(b, rival, -1, 1, i - 2, j + 2);
		}
	}
	if ((j + 2 < b.getSize()) && (b.getSign(i, j + 1)== rival)) {
		if(option) {
			checkSequence(b, rival, 0, 1, i, j + 2);
		} else {
			checkSequenceAndAplly(b, rival, 0, 1, i, j + 2);
		}
	}
	if ((i + 2 < b.getSize()) && (j + 2 < b.getSize()) && (b.getSign(i + 1, j + 1) == rival)) {
		if(option) {
			checkSequence(b, rival, 1, 1, i + 2, j + 2);
		} else {
			checkSequenceAndAplly(b, rival, 1, 1, i + 2, j + 2);
		}
	}
	if ((i + 2 < b.getSize()) && (b.getSign(i + 1, j) == rival)) {
		if(option) {
			checkSequence(b, rival, 1, 0, i + 2, j);
		} else {
			checkSequenceAndAplly(b, rival, 1, 0, i + 2, j);
		}
	}
	if ((i + 2 < b.getSize()) && (j - 2 > -1) && (b.getSign(i + 1, j - 1) == rival)) {
		if(option) {
			checkSequence(b, rival, 1, -1, i + 2, j - 2);
		} else {
			checkSequenceAndAplly(b, rival, 1, -1, i + 2, j - 2);
		}
	}
	if ((j - 2 > -1) && (b.getSign(i, j - 1) == rival)) {
		if(option) {
			checkSequence(b, rival, 0, -1, i, j- 2);
		} else {
			checkSequenceAndAplly(b, rival, 0, -1, i, j- 2);
		}

	}
}


void StandardLogic::applyMoveWithGivenPoint(Board & b, Point &p, char s) {
	b.putSign(p.getX() - 1, p.getY() -1, s);
	//using apply function
	checkSorrounding(s, b, p.getX() - 1 , p.getY() - 1 , false);
	pointPossible.clear();
}

void StandardLogic::checkSequenceAndAplly(Board &b, char rival, int rowOperator,
	int colOperator, int i, int j) {
	while ((i > -1) && (j > -1) && (i < b.getSize()) && (j < b.getSize())) {
		if (b.getSign(i,j) == getCompetitor(rival)) {
			//go back to flip rivals
			i = i + (-1 * rowOperator);
			j = j + (-1 * colOperator);
			while(b.getSign(i,j) != getCompetitor(rival)) {
				//flip rival and go back
				b.putSign(i,j,
						getCompetitor(rival));
				i = i + (-1 * rowOperator);
				j = j + (-1 * colOperator);
			}
			return;
		}
		//rival sequence
		if (b.getSign(i, j) == rival) {
			i = i + rowOperator;
			j = j + colOperator;
			continue;
		}
		return;
	}
}

char StandardLogic::getCompetitor(char s) const {
	if(s == 'X') {
		return 'O';
	}
	return 'X';
}

StandardLogic::~StandardLogic() {
}



