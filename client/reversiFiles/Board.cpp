/*
 * Board.cpp3
 *
 * Author: natan furer 204594428
 */

#include "Board.h"
#include <iostream>
using namespace std;


Board::Board(int boardSize) : size(boardSize) {
	if (boardSize < 6) {
		boardSize = 6;
	}
	numberOfX = 2;
	numberOfO = 2;
	board = new char*[size];
	for (int i = 0; i < size; i++) {
		board[i] = new char[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = ' ';
		}
	}
	board[(size / 2) -1][(size / 2) -1] = 'O';
	board[(size / 2)][(size / 2)] = 'O';
	board[(size / 2) - 1][size / 2] = 'X';
	board[size / 2][(size / 2) - 1] = 'X';

}
void Board::operator =(const Board &b) {
    numberOfX = b.getNumberOfX();
    numberOfO = b.getNumberOfO();
    size = b.getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = b.getSign(i, j);
        }
    }
}


void Board::print() const {
	cout << " |";
	for(int j = 0; j < size; j++) {
		cout << " " << j + 1 << " |";
	}
	cout << endl;
	cout << "--";
	for(int m = 0; m < size; m++) {
		cout << "----";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
        cout << i + 1 << "| ";
        for (int j = 0; j < size; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "--";
        for (int m = 0; m < size; m++) {
            cout << "----";
        }
        cout << endl;
    }
}

Board::~Board(){
	for (int i = 0; i < size; i++) {
		delete[] board[i];
	}
	delete[] board;
}

int Board::getSize() const {
	return size;
}

char Board::getSign(int i, int j) const {
	return board[i][j];

}

void Board::putSign(int i, int j, char s) {
    int countX = 0, countO = 0;
    board[i][j] = s;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(board[i][j] == 'X') {
                countX++;
            }
            if (board[i][j] == 'O') {
                countO ++;
            }
        }
    }
	numberOfX = countX;
    numberOfO = countO;
}

int Board::getNumberOfX() const {
    return numberOfX;
}

int Board::getNumberOfO() const {
	return numberOfO;
}

bool Board::checkIfTableFull() const {
	if ((size * size) == numberOfX + numberOfO) {
		return true;
	}
	return false;
}


