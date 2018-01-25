//
// Created by Yoav on 08-Jan-18.
//

#include "ex4headers.h"


int main(){

    //---First example main:------//
    std::list<Puzzle2dPiece<5>> pieces = {{0, 3, 2, -5}, {0, -2, 2, -5}};
    auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
    // note that there is no & on the auto below (was in previous version)
    auto some_pieces = groups.get({0, std::numeric_limits<int>::min(), 2, -5});
    for(auto piece_ptr : some_pieces) {//for(auto piece_ptr : some_pieces) {
        std::cout << *piece_ptr << std::endl; // will print both pieces! //WAS *piece_ptr
    }
    std::cout <<"finished first, should have printed 2 pieces" << std::endl;

    //----Second example main:-----//
    std::list<Puzzle3dPiece<1>> pieces3 = {{0, 1, 1, 1, -1, -1}, {0, -1, 1, 1, 1, 1}};
    auto groups3 = groupPuzzlePieces(pieces3.begin(), pieces3.end());
//     note that there is no & on the auto below (was in previous version)
    auto some_pieces3 = groups3.get({0, 1, 1, 1, 1, 1});
    for(auto piece_ptr : some_pieces3) {
        std::cout << *piece_ptr << std::endl; // will print nothing! //WAS *piece_ptr
    }
    std::cout <<"finished second should have printed nothing" << std::endl;
    //--------third example:------//
    auto joker = std::numeric_limits<int>::min();
    std::list<Puzzle3dPiece<1>> pieces4 = {{0, 1, 1, 1, -1, -1}, {0, -1, 1, 1, 1, 1}};
    auto groups4 = groupPuzzlePieces(pieces4.begin(), pieces4.end());
    auto some_pieces4 = groups4.get({0, joker, 1, 1, joker, joker});
    for(auto piece_ptr : some_pieces4) {
        std::cout << *piece_ptr << std::endl; // will print two pieces!
    }
    std::cout <<"finished third should print two pieces" << std::endl;
    //-----------fourth example:-----//
    std::vector<Puzzle2dPiece<5>> pieces5 = {{0, 3, 2, -5}, {0, -2, 2, -5}};
    auto groups5 = groupPuzzlePieces(pieces5.begin(), pieces5.end());
    auto some_pieces5 = groups.get({0, 3, 2, std::numeric_limits<int>::min()});
    for(auto piece_ptr : some_pieces5) {
        std::cout << *piece_ptr << std::endl; // will print the first piece!
    }
    std::cout <<"finished fourth should print one piece" << std::endl;

    auto groupsR = groupPuzzlePiecesWithRotate(pieces5.begin(), pieces5.end());
    auto some_pieces6 = groupsR.get({2, joker, 0, joker});
    for(auto piece_ptr : some_pieces6) {
        std::cout << *piece_ptr << std::endl; // will print the first piece!
    }
    std::cout <<"finished rotation should print 2 pieces" << std::endl;
    auto some_pieces7 = groupsR.get({joker, joker, joker, 3});
    for(auto piece_ptr : some_pieces7) {
        std::cout << *piece_ptr << std::endl; // will print the first piece!
    }
    std::cout <<"finished rotation 2: should print 1 piece" << std::endl;
    //auto groupsR3 = groupPuzzlePiecesWithRotate(pieces4.begin(), pieces4.end());
    return 0;

}