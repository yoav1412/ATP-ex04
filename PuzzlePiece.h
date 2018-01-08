//
// Created by Yoav on 08-Jan-18.
//

#ifndef ATP_EX04_PUZZLEPIECE_H
#define ATP_EX04_PUZZLEPIECE_H

#define NUM_2D_CONSTRAINTS 4
#define NUM_3D_CONSTRAINTS 6

#include "Constraints.h"

template <int K>
class PuzzlePiece{

    //TODO:
    // 1. needed code for for loop to work. after implementing, can use in Groups::insertPiece(PuzzlePiece *p) to make it less ugly.
    // 2. << operator
    // 3. inherit code to 2d and 3d classes..

public:
    virtual int getDim();
    virtual int* getEdges();
};

template<int K>
class Puzzle2dPiece{ // todo: inherit from super
    int _edges[NUM_2D_CONSTRAINTS];


public:
    Puzzle2dPiece(int edges[4]){
        for (int i=0; i<NUM_2D_CONSTRAINTS; i++){
            _edges[i] = edges[i];
        }
    };


    int getDim(){ return 2; };
    int* getEdges(){ return _edges; };

};


template<int K>
class Puzzle3dPiece: public PuzzlePiece<K>{
    int _edges[NUM_3D_CONSTRAINTS];
};


#endif //ATP_EX04_PUZZLEPIECE_H
