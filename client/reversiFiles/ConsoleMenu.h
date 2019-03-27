//
// Created by natan furer 204594428
//

#ifndef EX2_CONSOLEMENU_H
#define EX2_CONSOLEMENU_H

#include <iostream>

class ConsoleMenu {

public:

   /**
    * ConsoleDisplay function - creates ConsoleMenu object.
    *
	*/
    ConsoleMenu();

   /**
    * displayMenu function - prints the game menu.
    *
    */
    void displayMenu();

   /**
    * getAndCheckPLayersChoice function - gets the player input -
    * check if :
    * 1 - play vs AI player.
    * 0 - play vs human player.(or sequence of 0).
    * the function will check if the input is correct.
    *
    */
    int getAndCheckPLayersChoice();

};


#endif //EX2_CONSOLEMENU_H
