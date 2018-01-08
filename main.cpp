//
// Created by Yoav on 08-Jan-18.
//

#include "PuzzlePiece.h"
#include "Groups.h"
#include <iostream>

int main(){


    int edges1[4] = {1,0,1,1}; Puzzle2dPiece<1> p1(edges1);
    int edges2[4] = {0,-1,0,1}; Puzzle2dPiece<1> p2(edges2);
    int edges3[4] = {1,1,1,1}; Puzzle2dPiece<1> p3(edges3);
    int edges4[4] = {1,0,0,0}; Puzzle2dPiece<1> p4(edges4);

    std::vector< Puzzle2dPiece<1> > vec;
    vec.push_back(p1); vec.push_back(p2);vec.push_back(p3); vec.push_back(p4);

    Groups< Puzzle2dPiece<1> > grps(vec.begin(), vec.end());

    int filter[4] = {NO_CONSTRAINT,NO_CONSTRAINT,NO_CONSTRAINT,1};
    Puzzle2dPiece<1> filter_piece(filter);

    auto filtered = grps.get(filter_piece);

    std::cout <<"DONE\n";
    return 0;


}