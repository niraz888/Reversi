#include <gtest/gtest.h>
#include "../reversiFiles/AIPlayer.h"
#include "../reversiFiles/Player.h"
#include "../reversiFiles/Board.h"
#include "../reversiFiles/StandardLogic.h"
#include "../reversiFiles/GameLogic.h"

TEST(checkAI, checkAlogrithm) {
    Player* player;
    player = new AIPlayer();
    StandardLogic logic;
    Board board;
    // check if the first turn of AI player give the best option
    /************************************************/
    Point p(6,5);
    logic.applyMoveWithGivenPoint(board, p, 'X');
    vector<Point> vec = logic.possiblePoints(board, player->getSign());
    Point pnt = player->playerMove(vec, board);
    Point check(6, 6);
    EXPECT_EQ(pnt, check);
    logic.applyMoveWithGivenPoint(board, check, player->getSign());
    /***********************************************/

    //check if the second turn of AI player give the best option
    /************************************************/
    Point p2(4, 3);
    logic.applyMoveWithGivenPoint(board, p2, 'X');
    vector<Point> vec2 = logic.possiblePoints(board, player->getSign());
    Point pnt2 = player->playerMove(vec2, board);
    Point check2(3,3);
    EXPECT_EQ(pnt2, check2);
    logic.applyMoveWithGivenPoint(board, check2, player->getSign());
    /*****************************************************/

    //check if a middle turn of AI player give the best option
    /**************************************/
    Point p3(2, 3);
    logic.applyMoveWithGivenPoint(board, p3, 'X');
    Point p4(2, 2);
    logic.applyMoveWithGivenPoint(board, p4, player->getSign());
    Point p5(2,1);
    logic.applyMoveWithGivenPoint(board, p5, 'X');
    Point p6(1,1);
    logic.applyMoveWithGivenPoint(board, p6, player->getSign());
    Point p7(3,4);
    logic.applyMoveWithGivenPoint(board, p7, 'X');
    vector<Point> vec3 = logic.possiblePoints(board, player->getSign());
    Point pnt3 = player->playerMove(vec2, board);
    Point check3(3,1);
    EXPECT_EQ(pnt2, check2);
    logic.applyMoveWithGivenPoint(board, check2, player->getSign());
    /*****************************************************/
delete player;
}

