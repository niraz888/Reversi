#include <gtest/gtest.h>
#include "../reversiFiles/Board.h"
#include "../reversiFiles/StandardLogic.h"
#include "../reversiFiles/GameLogic.h"

TEST(checkStandardLogic, checkBasicMoves) {
    Board board(8);
    StandardLogic log = StandardLogic();

    // basic case which check if all possible points are found by function
    /******************************************/
    log.possiblePoints(board, 'X');
    Point pnt1(3, 4);
    Point pnt2(4, 3);
    Point pnt3(6, 5);
    Point pnt4(5, 6);

    EXPECT_TRUE(log.checkForPointInGame(pnt1));
    EXPECT_TRUE(log.checkForPointInGame(pnt2));
    EXPECT_TRUE(log.checkForPointInGame(pnt3));
    EXPECT_TRUE(log.checkForPointInGame(pnt4));
    /*******************************************/

    //case which check if the function recognize a possible point after sequnce
    /*********************************************/
    board.putSign(3, 3, 'O');
    board.putSign(2, 3, 'O');
    board.putSign(1, 3, 'O');
    log.possiblePoints(board, 'X');
    Point pnt5(1, 4);
    EXPECT_TRUE(log.checkForPointInGame(pnt5));
    /*********************************************/

    //case which check if recognize an option with double flip
    /*****************************************/
    board.putSign(5, 5, 'O');
    board.putSign(4, 5, 'X');
    log.possiblePoints(board, 'O');
    Point pnt6(4, 6);
    EXPECT_TRUE(log.checkForPointInGame(pnt6));
    /********************************************/

    // case that check if the Standardlogic recognize that there isnt possible points to play
    /***************************************************/
    board.putSign(4, 3, 'O');
    board.putSign(3, 4, 'O');
    Point pnt7(5,6);
    log.applyMoveWithGivenPoint(board, pnt7, 'O');
    vector<Point> vec = log.possiblePoints(board, 'O');
    EXPECT_TRUE(vec.empty());
    /******************************************************/

}
