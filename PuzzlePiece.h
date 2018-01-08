//
// Created by Yoav on 08-Jan-18.
//

#ifndef ATP_EX04_PUZZLEPIECE_H
#define ATP_EX04_PUZZLEPIECE_H

#define NUM_2D_CONSTRAINTS 4
#define NUM_3D_CONSTRAINTS 6
#define ROTATION_LIMIT_2D 3
#define ROTATION_LIMIT_3D 0 //TODO: change from 0 when adding support for 3d rotates


//TODO: create c'tors so that a piece can be created from something like this: {1,0,-1,1}



template <int K>
class PuzzlePiece{

    //TODO:
    // 1. needed code for for loop to work. after implementing, can use in Groups::insertPiece(PuzzlePiece *p) to make it less ugly.
    // 2. << operator
    // 3. inherit code to 2d and 3d classes..

public:
    virtual int getDim() = 0;
    virtual int* getEdges() = 0;
};

template<int K>
class Puzzle2dPiece : public PuzzlePiece<K>{
    int _edges[NUM_2D_CONSTRAINTS];
    int _dim = 2;




public:
    Puzzle2dPiece(int edges[NUM_2D_CONSTRAINTS]){
        for (int i=0; i<NUM_2D_CONSTRAINTS; i++){
            _edges[i] = edges[i];
        }
    };

    int getDim(){ return _dim; };
    int* getEdges(){return _edges;};

    int getRotationsLimit(){ return ROTATION_LIMIT_2D; }

    /*
    * return the value of the constraint of the piece at the given edge, with optional rotation.
    */
    int getConstraint(int edge, int timesRotated){
        int offset = ( (int)edge - (timesRotated) )%4;
        offset = offset >= 0 ? offset : 4 + offset; //note offset is negative in second case.
        return  this->_edges[offset];
    }

};


template<int K>
class Puzzle3dPiece: public PuzzlePiece<K>{
    int _edges[NUM_3D_CONSTRAINTS];
    int _dim = 3;
public:
    Puzzle3dPiece(int edges[NUM_3D_CONSTRAINTS]){
        for (int i=0; i<NUM_3D_CONSTRAINTS; i++){
            _edges[i] = edges[i];
        }
    };
    int getDim(){ return _dim; };
    int* getEdges(){ return _edges; }; // TODO: returning address of local variable here?
    int getRotationsLimit(){ return ROTATION_LIMIT_3D; }
    int getConstraint(int edge, int timesRotated){
        return _edges[edge]; //TODO: for now, no support of rotations. when added, change rotation paramenter to be of an appropriate type
    };

};


#endif //ATP_EX04_PUZZLEPIECE_H
