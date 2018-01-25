//
// Created by Yoav on 08-Jan-18.
//

#include "BooleanMasks.h"

std::set<std::vector<bool>> BooleanMasks::getBooleanMasks(int n){
    std::set<std::vector<bool>> res;
    std::vector<bool> boolstr(n);
    _getBooleanMaskRec(n,boolstr,res);
    return res;
}


void BooleanMasks::_getBooleanMaskRec(int n, std::vector<bool> boolstr, std::set<std::vector<bool>>& res){
    if (n==0){
        res.insert(boolstr);
        return;
    }
    std::vector<bool> add_true = boolstr;
    add_true[n-1] = true;
    _getBooleanMaskRec(n-1, add_true, res);
    std::vector<bool> add_false = boolstr;
    add_true[n-1] = false;
    _getBooleanMaskRec(n-1, add_false, res);
}
