/*
 * StandardPlayer.cpp
 *
 *  natan furer 204594428
 */

#include "StandardPlayer.h"

StandardPlayer::StandardPlayer(char sign): Player(sign) {
}

Point StandardPlayer::playerMove(vector<Point> &v, Board &b) {
	int row,col;

	while(true) {
		//check for correct input
		while(!(cin >> row >> col)) {
			cin.clear();
			cin.ignore(80, '\n');
			cout << "wrong input, please enter your input using the next format - "
					<< "row col" << endl;
			continue;
		}
			Point p(row, col);
			//check if point is an option
			for (vector<Point>::iterator it = v.begin();
					it!= v.end(); it++) {
				if (p == *it) {
					return p;
				}
			}
			//no option.
			cout << "wrong input, please enter your input using the next format - "
					<< "row col" << endl;
			cin.ignore(80, '\n');
			continue;

	}
}

StandardPlayer::~StandardPlayer() {	}





