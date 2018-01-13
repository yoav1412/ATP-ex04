//
// Created by Yoav on 08-Jan-18.
//

#include "PuzzlePiece.h"
#include "Groups.h"
#include <iostream>


//TODO: groupPuzzlePieces function (    auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());)
//TODO: get should get a {} of constraints
// finish operator <<

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
    std::cout <<"DONE 2D\n";

    int _edges1[6] = {1,2,1,3,-5,1}; Puzzle3dPiece<5> _p1(_edges1);
    int _edges2[6] = {4,-1,3,5,-1,1}; Puzzle3dPiece<5> _p2(_edges2);
    int _edges3[6] = {1,1,4,-2,-5,5}; Puzzle3dPiece<5> _p3(_edges3);
    int _edges4[6] = {1,3,2,-5,-5,4}; Puzzle3dPiece<5> _p4(_edges4);

    std::vector< Puzzle3dPiece<5> > _vec;
    _vec.push_back(_p1); _vec.push_back(_p2);_vec.push_back(_p3); _vec.push_back(_p4);

    Groups< Puzzle3dPiece<5> > _grps(_vec.begin(), _vec.end());

    int _filter[6] = {1,NO_CONSTRAINT,NO_CONSTRAINT,NO_CONSTRAINT,-5,NO_CONSTRAINT};
    Puzzle3dPiece<5> _filter_piece(_filter);

    auto _filtered = _grps.get(_filter_piece);
    std::cout <<"DONE 3D\n";

    //---First example main:------//
    std::list<Puzzle2dPiece<5>> pieces = {{0, 3, 2, -5}, {0, -2, 2, -5}};
//    auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
//    // note that there is no & on the auto below (was in previous version)
//    auto some_pieces = groups.get({0, std::numeric_limits<int>::min(), 2, -5});
    for(auto piece_ptr : pieces) {//for(auto piece_ptr : some_pieces) {
        std::cout << piece_ptr << std::endl; // will print both pieces! //WAS *piece_ptr
    }
    //----Second example main:-----//
    std::list<Puzzle3dPiece<1>> pieces3 = {{0, 1, 1, 1, -1, -1}, {0, -1, 1, 1, 1, 1}};
//    auto groups = groupPuzzlePieces(pieces3.begin(), pieces3.end());
    // note that there is no & on the auto below (was in previous version)
//    auto some_pieces3 = groups.get({0, 1, 1, 1, 1, 1});
    for(auto piece_ptr : pieces3) {
        std::cout << piece_ptr << std::endl; // will print nothing! //WAS *piece_ptr
    }


    return 0;

}