//
// Created by natan furer 204594428
//

#include "AIPlayer.h"
#include <map>
#include <algorithm>


AIPlayer::AIPlayer(GameLogic* gameLogic, char sign): Player(sign) {
    logic = gameLogic;
}

Point AIPlayer::playerMove(vector<Point> &v, Board &b) {
    int score, enemyHighestScore = 0;
    map<int , Point> enemyHighScores;
    Board copyBoard(b.getSize()), enemyBoard(b.getSize());
    vector<int> scores;
    vector<Point> enemyPossibleMoves;
    //play AI move with each point in the vector.
    for (vector<Point>::iterator it = v.begin(); it != v.end(); it ++) {
        //copy the current board.
        copyBoard = b;
        //play AI move with point
        logic->applyMoveWithGivenPoint(copyBoard,*it, getSign());
        enemyPossibleMoves = logic->possiblePoints(copyBoard, 'X');
        //sum the competitor score for his possible moves.
        for (vector<Point>::iterator iter = enemyPossibleMoves.begin();
             iter != enemyPossibleMoves.end(); iter ++) {
            enemyBoard = copyBoard;
            logic->applyMoveWithGivenPoint(enemyBoard,*iter, 'X');
            score = (enemyBoard).getNumberOfX() - (enemyBoard).getNumberOfO();
            if (score > enemyHighestScore) {
                //keep the highest score.
                enemyHighestScore = score;
            }
        }
        scores.push_back(enemyHighestScore);
        enemyHighScores[enemyHighestScore] = *it;
    }
    //sort scores.
    sort(scores.begin(), scores.end());
    //return the point that would lead to the competitor lowest score.
    return enemyHighScores[*(scores.begin())];


}


