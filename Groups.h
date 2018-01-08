//
// Created by Yoav on 08-Jan-18.
//

#ifndef ATP_EX04_GROUPS_H
#define ATP_EX04_GROUPS_H

#define NO_CONSTRAINT std::numeric_limits<int>::min()

#include <map>
#include <list>
#include "PuzzlePiece.h"
#include "BooleanMasks.h"
#include <sstream>
#include <limits>

enum Rotate {NO = 0, DEG90 = 90, DEG180 = 180, DEG270 = 270};


template<typename _puzzlePiece>
class Groups{
private:
    typedef std::string key_t;

    std::map<key_t, std::vector<_puzzlePiece*>> _table;
    Groups();


    /*
     * insert pointer to piece p with all fitting keys in table.
    */
    void insertPiece(_puzzlePiece *p){
        key_t key;
        auto booleanMasks =  BooleanMasks::getBooleanMasks(2*(p->getDim()));
        for (auto booleanMask : booleanMasks){
            std::stringstream strm;
            for (int i=0; i < 2*(p->getDim()); i++ ){ //TODO: when we can colon-iterate over piece, would be nicer to use it here.
                int edge = p->getEdges()[i];
                if (booleanMask[i]) { strm << edge; }
                else { strm << NO_CONSTRAINT; }
            }
            key = strm.str();
            if (_table.find(key) == _table.end()) { // key doesn't exist in map yet, so create an empty set
                _table[key] = std::vector<_puzzlePiece*>();
            }
            _table[key].push_back(p); //TODO: currently no support for rotations, add later. (can copy from puzzle constaintsTable)
        }
    };

    key_t pieceToKey(_puzzlePiece &p){
        std::stringstream strm;
        for (int i=0; i < 2*p.getDim(); i++) {//TODO: when we can colon-iterate over piece, would be nicer to use it here.
            int edge = p.getEdges()[i];
            strm << edge;
        }
        return strm.str();
    };




public:
    std::vector<_puzzlePiece*> get(_puzzlePiece p){
        key_t key = pieceToKey(p);
        if (_table.find(key) == _table.end() ){
            return std::vector<_puzzlePiece*>(); // no piece matches constraint -> return empty vector.
        }
        return _table[key];
    };




    template <typename Iter> Groups(Iter b, Iter e){//TODO: really need this template?...
        for (; b != e; b++ ){
            insertPiece(&(*b));
        }
    };
};


#endif //ATP_EX04_GROUPS_H
