//
// Created by nir on 27/11/17.
//
#include <gtest/gtest.h>
#include "../reversiFiles/Board.h"
#include "../reversiFiles/GameFlow.h"
#include "../reversiFiles/StandardLogic.h"
#include "../reversiFiles/GameLogic.h"

// Board test ->

TEST(Board, BoardCheckNumber1) {

    Board bard(8);

// case that check if the board assign signals correctly
/**********************************/
    bard.putSign(2, 3, 'X');
    bard.putSign(6, 6, 'O');
    bard.putSign(6, 5, 'O');
    ASSERT_EQ(bard.getSign(4, 4), 'O');
    EXPECT_EQ(bard.getSign(6, 5), 'O');
    EXPECT_EQ(bard.getSign(2, 3), 'X');
/*********************************/

// check if the board counting the 'X' and 'O' correct
/***********************************/
    EXPECT_EQ(bard.getNumberOfX(), 3);
    EXPECT_EQ(bard.getNumberOfO(), 4);
/***********************************/

// check if the board return the size correct
/***************************/
    EXPECT_EQ(bard.getSize(), 8);
/***************************/

// check if the board recognize that the table is/isn't full
/********************************************/
    ASSERT_FALSE(bard.checkIfTableFull());
    for (int i = 0; i < bard.getSize(); i++) {
        for (int j = 0; j < bard.getSize(); j++) {
            bard.putSign(i, j, 'X');
        }
    }
    ASSERT_TRUE(bard.checkIfTableFull());
/********************************************/

}

TEST(Board, BoardCheckNumber2) {
    Board board;

    // check if the default value in constructor works
    /**************************/
     EXPECT_EQ(board.getSize(), 8);
    /**************************/

    // check if recognize number of X + if recongize space
    /*****************************/
    board.putSign(0, 2, 'X');
    board.putSign(5, 6, 'O');
    board.putSign(7, 4, 'X');
    EXPECT_EQ(board.getNumberOfX(), 4);
    EXPECT_EQ(board.getSign(1, 6), ' ');
    /*****************************/

    //check if recongnize table is/isnt full
    /****************************************/
   int counter = 0;
   for (int s = 0; s < board.getSize(); s++) {
       for (int k = 0; k < board.getSize(); k++) {
           if (counter == 63) {
               continue;
           }
           board.putSign(s, k, 'X');
           counter++;
       }
   }
    EXPECT_FALSE(board.checkIfTableFull());
    board.putSign(7, 7, 'O');
     EXPECT_TRUE(board.checkIfTableFull());
    /****************************************/
}
