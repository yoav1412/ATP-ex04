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


template<typename _puzzlePiece>
class Groups{
private:
    typedef std::string key_t;

    std::map<key_t, std::vector<_puzzlePiece*>> _table;
    Groups();


    /*
     * insert pointer to piece p with all fitting keys in table.
    *///TODO: currently no support for rotations, add later. (can copy from puzzle constaintsTable)
    void insertPiece(_puzzlePiece *p, bool withRotation = false){
        int timesRotated = 0;
        key_t key;
        do {
            auto booleanMasks = BooleanMasks::getBooleanMasks(2 * (p->getDim()));
            for (auto booleanMask : booleanMasks) {
                std::stringstream strm;
                int i = 0;
                for (auto edge : *p) { //TODO: when we can colon-iterate over piece, would be nicer to use it here.
                    if (booleanMask[i]) { strm << edge; }
                    else { strm << NO_CONSTRAINT; }
                    i++;
                }
                key = strm.str();
                if (_table.find(key) == _table.end()) { // key doesn't exist in map yet, so create an empty set
                    _table[key] = std::vector<_puzzlePiece *>();
                }
                _table[key].push_back(p);
            }
            timesRotated++;
            if ( timesRotated > p->getRotationsLimit() ) { withRotation = false; }
        } while (withRotation);
    };

    key_t pieceToKey(_puzzlePiece &p, int timesRotated = 0){
        std::stringstream strm;
        for (int i=0; i < 2*p.getDim(); i++) {//TODO: when we can colon-iterate over piece, would be nicer to use it here.
            int edge = p.getConstraint(i, timesRotated);
            strm << edge;
        }
        return strm.str();
    };

    //TODO: change this together with the prev onoe using spinfa of sort?
    key_t constraintsToKey(std::initializer_list<int> constraints){
        std::stringstream strm;
        for (auto con:constraints){
            if (!((con>=-_puzzlePiece::Limit && con<= _puzzlePiece::Limit) || con == NO_CONSTRAINT)){
                std::cout <<"Constraints should have values with abs value under "<< _puzzlePiece::Limit<< "or min int value"<<std::endl;
                throw std::invalid_argument("Constraints illegal value");
            }
            strm << con;
        }
        return strm.str();
    }


public:
    std::vector<_puzzlePiece*> get(std::initializer_list<int> constraints){
        if (constraints.size() != 2*_puzzlePiece::Dimension){
            std::cout <<"Constraints should have 2*Dimension values, got size "<<constraints.size()<<" needed"<<2*_puzzlePiece::Dimension<<std::endl;
            throw std::invalid_argument("Constraints should have 2*Dimension values");
        }
        key_t key = constraintsToKey(constraints);
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
