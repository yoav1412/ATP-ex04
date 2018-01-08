//
// Created by Yoav on 08-Jan-18.
//

#ifndef ATP_EX04_GROUPS_H
#define ATP_EX04_GROUPS_H

//#define NO_CONSTRAINT std::numeric_limits<int>::min()
#define NO_CONSTRAINT "N" //todo: reinstate std::numeric_limits<int>::min()

#include <map>
#include <set>
#include "PuzzlePiece.h"
#include "BooleanMasks.h"
#include <sstream>
#include <limits>

enum Rotate {NO = 0, DEG90 = 90, DEG180 = 180, DEG270 = 270};


template<typename _puzzlePiece>
class Groups{
    typedef std::pair<_puzzlePiece*, Rotate> PieceAndRotation;
    typedef std::string KEY;

    std::map<KEY, std::set<PieceAndRotation>> _table;
    Groups();

    KEY pieceToKey(_puzzlePiece *p);


    /*
     * insert pointer to piece p with all fitting keys in table.
    */
    void insertPiece(_puzzlePiece *p){
        KEY key;
        auto booleanMasks =  BooleanMasks::getBooleanMasks(2*(p->getDim()));
        for (auto booleanMask : booleanMasks){
            std::stringstream strm;
            for (int i=0; i < 2*(p->getDim()); i++ ){
                int edge = p->getEdges()[i];
                if (booleanMask[i]) { strm << edge; }
                else { strm << NO_CONSTRAINT; }
            }
            key = strm.str();
            if (_table.find(key) == _table.end()) { // key doesn't exist in map yet, so create an empty set
                _table[key] = std::set<PieceAndRotation>();
            }
            _table[key].insert({p, Rotate::NO}); //TODO: currently no support for rotations, add later. (can copy from puzzle constaintsTable)
        }
    };




public:
    //std::vector<PuzzlePiece> get(_puzzlePiece p);




    template <typename Iter> Groups(Iter b, Iter e){//TODO: really need this template?...
        for (; b != e; b++ ){
            insertPiece(&(*b));
        }
    };
};


#endif //ATP_EX04_GROUPS_H
