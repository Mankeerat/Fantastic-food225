#pragma once 

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using std::string;
using std::stack;
using std::vector;
using std::queue;

class BTreeNode {
    public:
        BTreeNode();
        BTreeNode(unsigned int order);
        BTreeNode(bool is_leaff, unsigned int order);
        BTreeNode(vector<int> v);
        ~BTreeNode();
        void clear(BTreeNode* subroot);
        BTreeNode* copy(const BTreeNode* subroot);
        BTreeNode* find(BTreeNode* subroot, int key);
        void insert(BTreeNode* subroot, int key);
        void traverse(BTreeNode* root, vector<int> & v);
        void split_child(BTreeNode* parent, int child_index);
    private:
        bool is_leaf;
        BTreeNode* root_;
        unsigned int order_;
        vector<int> elements_;
        vector<BTreeNode *> children_;
};