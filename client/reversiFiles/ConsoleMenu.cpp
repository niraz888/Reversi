//
// Created by natan furer 204594428
//

#include "ConsoleMenu.h"
using namespace std;

ConsoleMenu::ConsoleMenu() {

}

void ConsoleMenu::displayMenu() {
    cout << "welcome to Reversi" << endl;
    cout << "choose an opponent type:" << endl;
    cout << "1. a human local player" << endl << "2. an Ai player"
            << endl << "3. a remote player" << endl;
}


int  ConsoleMenu::getAndCheckPLayersChoice() {
    int choice;

    while(true) {
        //check for correct input
        while(!(cin >> choice)) {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "wrong input" << endl;
            cout << "choose an opponent type:" << endl;
            cout << "1. a human local player" << endl << "2. an Ai player"
                 << endl << "3. a remote player" << endl;
            continue;
        }
        if (choice == 1) {
            return 1;
        } if (choice == 2) {
            return 2;
        } if (choice == 3) {
            return 3;
        }
        cout << "choose an opponent type:" << endl;
        cout << "1. a human local player" << endl << "2. an Ai player"
             << endl << "3. a remote player" << endl;
        cin.ignore(80, '\n');

    }

}
