//
// Created by Yoav on 08-Jan-18.
//

#ifndef ATP_EX04_PUZZLEPIECE_H
#define ATP_EX04_PUZZLEPIECE_H

#include <iostream>
#include <vector>


#define NUM_2D_CONSTRAINTS 4
#define NUM_3D_CONSTRAINTS 6
#define ROTATION_LIMIT_2D 3
#define ROTATION_LIMIT_3D 0 //TODO: change from 0 when adding support for 3d rotates


//TODO: create c'tors so that a piece can be created from something like this: {1,0,-1,1}



//template <int K>
class PuzzlePiece{

    //TODO:
    // 1. needed code for for loop to work. after implementing, can use in Groups::insertPiece(PuzzlePiece *p) to make it less ugly.
    // 2. << operator
    // 3. inherit code to 2d and 3d classes..
    // 4. why does this need to be templated? tami
protected:
    std::vector<int> _edges;
    int _dim;
public:
    typedef int* iterator;
    typedef const int* const_iter;

    virtual int getDim() = 0;
    virtual std::vector<int>& getEdges(){ return _edges;};
    friend std::ostream &operator << (std::ostream &os, PuzzlePiece& piece);
    typename PuzzlePiece::iterator begin(){ return &(_edges[0]);};
    typename PuzzlePiece::iterator end(){return &(_edges[_dim * 2]);};
    typename PuzzlePiece::const_iter begin() const{ return &(_edges[0]);};
    typename PuzzlePiece::const_iter end() const{return &(_edges[_dim * 2]);};

};

template<int K>
class Puzzle2dPiece : public PuzzlePiece{
public:
    //---Ctor:---///
    Puzzle2dPiece(int edges[NUM_2D_CONSTRAINTS]){
        _edges.resize(NUM_2D_CONSTRAINTS);
        _dim = 2;
        for (int i=0; i<NUM_2D_CONSTRAINTS; i++){
            _edges[i] = edges[i];
        }
    };
    Puzzle2dPiece(std::initializer_list<int> il){
        _edges = il;
        _edges.resize(NUM_2D_CONSTRAINTS);
        _dim = 2;
    }

    //-----function:----/
    int getDim(){ return _dim; };
    //int* getEdges(){return _edges;}; // TODO!!!

    int getRotationsLimit(){ return ROTATION_LIMIT_2D; }

    /*
    * return the value of the constraint of the piece at the given edge, with optional rotation.
    */
    int getConstraint(int edge, int timesRotated){
        int offset = ( (int)edge - (timesRotated) )%4;
        offset = offset >= 0 ? offset : 4 + offset; //note offset is negative in second case.
        return  this->_edges[offset];
    }
    //For foreach loop:
    //TODO: how to move this to PuzzlePiece?

    void print() const;

};


template<int K>
class Puzzle3dPiece: public PuzzlePiece{

public:
    //-----------Ctor:-------------//
    Puzzle3dPiece(int edges[NUM_3D_CONSTRAINTS]){
        _edges.resize(NUM_3D_CONSTRAINTS);
        _dim = 3;
        for (int i=0; i<NUM_3D_CONSTRAINTS; i++){
            _edges[i] = edges[i];
        }
    };

    Puzzle3dPiece(std::initializer_list<int> il){
        _edges = il;
        _edges.resize(NUM_3D_CONSTRAINTS);
        _dim = 3;
    }

    //---------function:---------//
    int getDim(){ return _dim; };
    int getRotationsLimit(){ return ROTATION_LIMIT_3D; }
    int getConstraint(int edge, int timesRotated){
        return _edges[edge]; //TODO: for now, no support of rotations. when added, change rotation paramenter to be of an appropriate type
    };
    //For foreach loop:
    typename PuzzlePiece::iterator begin(){ return &(_edges[0]);};
    typename PuzzlePiece::iterator end(){return &(_edges[NUM_3D_CONSTRAINTS]);};
    typename PuzzlePiece::const_iter begin() const{ return &(_edges[0]);};
    typename PuzzlePiece::const_iter end() const{return &(_edges[NUM_3D_CONSTRAINTS]);};
    //TODO: how to move this to PuzzlePiece?

    void print() const;
};

//TODO: implement

#endif //ATP_EX04_PUZZLEPIECE_H
