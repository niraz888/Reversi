/*
 * ConsoleDisplay.cpp
 *
 *  natan furer 204594428
 */

#include "ConsoleDisplay.h"

ConsoleDisplay::ConsoleDisplay() {
}

void ConsoleDisplay::displayGame(Board &b, vector<Point> v, Player *player,
		Player *lastTurn) {
	cout << "current board:" << endl << endl;
	b.print();
	//prints the message after at least on move.
	if (!firstTurn) {
		cout << lastTurn->getSign() << " played " << lastTurn->getLastPlayPoint() << endl
				<< endl;
	} else {
		firstTurn = false;
	}
	cout << player->getSign() << ": it's your move" << endl;
	printPlayerOption(v);
}

void ConsoleDisplay::printPlayerOption(vector<Point> &v) const {
	int i = 1;
	//no possible points
	if (v.empty()) {
		cout << "no possible moves. play passes back to the other player" << endl;
		return;
	}
	cout << "your possible moves: ";
	//print points from vector
	for (vector<Point>::iterator it = v.begin(); it!= v.end(); it++) {
		if((int)v.size() == i) {
			cout << *it;
		} else {
			cout << *it << ",";
		}
		i++;
	}
	cout << endl << endl;
	cout <<"please enter your move row col: " << endl;
}

ConsoleDisplay::~ConsoleDisplay() {
}


