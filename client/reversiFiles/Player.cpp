/*
 * Player.cpp
 *
 * natan furer 204594428.
 */

#include "Player.h"
using namespace std;


Player::Player(char sign): sign(sign) {
}


char Player::getSign() const {
	return sign;
}


void Player::setLastPlayPoint(Point p){
	lastPlay.setX(p.getX());
	lastPlay.setY(p.getY());
}


Point Player::getLastPlayPoint() const {
	return lastPlay;
}

Player::~Player(){
}


