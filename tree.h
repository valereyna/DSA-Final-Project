#ifndef TREEH
#define TREEH

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Class representing a node in the binary search tree
class TreeNode {
public:
    Movie data;
    TreeNode* left;
    TreeNode* right;

    //Constructor to initialize tree node with movie data
    TreeNode(const Movie& m) : data(m), left(nullptr), right(nullptr) {}
};

#endif
