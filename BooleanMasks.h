//
// Created by Yoav on 08-Jan-18.
//

#ifndef ATPPUZZLESOLVER_BOOLEANMASKS_H
#define ATPPUZZLESOLVER_BOOLEANMASKS_H


class BooleanMasks {
public:
    /*
    * return a vector of all boolean strings of size n.
    */
    static std::set<std::vector<bool>> getBooleanMasks(int n) {};
private:
    void _getBooleanMaskRec(int n, std::vector<bool> boolstr, std::set<std::vector<bool>> &res) {};
};

#endif //ATPPUZZLESOLVER_BOOLEANMASKS_H
