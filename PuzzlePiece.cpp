//
// Created by Yoav on 08-Jan-18.
//


#include "PuzzlePiece.h"
#include <sstream>
#include <iterator>




std::ostream &operator << (std::ostream &os, PuzzlePiece& piece){
    std::stringstream result;
    std::copy(piece._edges.begin(), piece._edges.end(), std::ostream_iterator<int>(result, " "));
    os << result.str();
    return os;
}