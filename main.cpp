//
// Created by Yoav on 08-Jan-18.
//

#include "PuzzlePiece.h"
#include "Groups.h"
#include <iostream>

int main(){


    int edges1[4] = {1,0,1,1};
    Puzzle2dPiece<1> p1(edges1);

    int edges2[4] = {0,-1,0,1};
    Puzzle2dPiece<1> p2(edges2);

    std::vector< Puzzle2dPiece<1> > vec;
    vec.push_back(p1); vec.push_back(p2);

    Groups< Puzzle2dPiece<1> > grps(vec.begin(), vec.end());
    std::cout <<"DONE\n";
    return 0;


}