/*
 * main.cpp
 *
 * Author: natan furer 204594428
 */

#include "GameFlow.h"
#include"Client.h"
#include<iostream>
#include<stdlib.h>


using namespace std;

int main() {
	Board b;
	GameFlow g(b);
	ConsoleMenu menu;
	g.initializeGame(menu);
	g.runGame();
	return 0;



}



