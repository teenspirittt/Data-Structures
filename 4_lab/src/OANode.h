#pragma once

#include <iostream>
#include <string>

using namespace std;

enum states {
    free_,
    busy_,
    deleted_
};

template<typename T>
struct OANode {
    string key;
    T value;
    states state;
};