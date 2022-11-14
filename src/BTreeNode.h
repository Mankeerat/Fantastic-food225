#pragma once 

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using std::string;
using std::stack;
using std::vector;
using std::queue;
using std::map;

class BTreeNode {
    public:
        BTreeNode();
        BTreeNode(string itemName, float itemRating, bool is_leaff, BTreeNode * parent);
        ~BTreeNode();
        void setChild(BTreeNode* child);
        void printTree();
        void printTreeHelper(BTreeNode* root);
        BTreeNode & operator=(const BTreeNode & other);
        void clear(BTreeNode* subroot);
        BTreeNode* copy(const BTreeNode & subroot);

        BTreeNode* find(BTreeNode* root, string itemName, float ItemRating);
        vector<BTreeNode*> findAll(BTreeNode * root, string itemName, float itemRating);
        void findAllHelper(BTreeNode * subroot, vector<BTreeNode*> vec, string itemName, float itemRating);        
        void insert(string itemName, float itemRating);
        vector<BTreeNode*> traverse(BTreeNode* root);
        void traverse_(BTreeNode* subroot, vector<BTreeNode*> & vector);
        void split_child(BTreeNode* parent, int child_index);
    
    private:
        bool is_leaf;   //will have to update in split_child 
        string itemName_;
        float itemRating_;
        BTreeNode* parent_;
        unsigned int order_;
        vector<BTreeNode *> children_;
};