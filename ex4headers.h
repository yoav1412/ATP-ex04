//
// Created by Tami on 25/01/2018.
//

#ifndef ATPPUZZLESOLVER_EX4HEADERS_H
#define ATPPUZZLESOLVER_EX4HEADERS_H
#include "PuzzlePiece.h"
#include "Groups.h"
#include <iostream>


template<typename Iter>

Groups<typename std::iterator_traits<Iter>::value_type> groupPuzzlePieces(Iter begin, Iter end){
    return Groups<typename  std::iterator_traits<Iter>::value_type>(begin, end);
};
template<typename Iter>
Groups<typename std::iterator_traits<Iter>::value_type> groupPuzzlePiecesWithRotate(Iter begin, Iter end){
    static_assert(std::iterator_traits<Iter>::value_type::Dimension == 2, "Error: only support 2d rotations.");
    return Groups<typename  std::iterator_traits<Iter>::value_type>(begin, end, true);
};
#endif //ATPPUZZLESOLVER_EX4HEADERS_H
