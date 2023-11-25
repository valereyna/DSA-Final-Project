#ifndef TREEH
#define TREEH

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TreeNode {
public:
    Movie data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const Movie& m) : data(m), left(nullptr), right(nullptr) {}
};

#endif