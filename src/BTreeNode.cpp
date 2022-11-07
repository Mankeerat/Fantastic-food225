#include <iostream>
#include "BTreeNode.h"

BTreeNode::BTreeNode() {
    root_ = nullptr;
    order_ = 3;
}

BTreeNode::BTreeNode(unsigned int order) {
    root_ = nullptr;
    order_ = order < 3 ? 3 : order; 
}

BTreeNode::BTreeNode(bool is_leaff, unsigned int order) {
    is_leaf = is_leaff;
    order_ = order;
}

BTreeNode::BTreeNode(vector<int> v) { 
    root_ = nullptr;
    order_ = 3;
    for(int i = 0; i < v.size(); i++) {
        elements_.push_back(v[i]);
    }
}

BTreeNode::~BTreeNode() {
    clear(this->root_);
}

void BTreeNode::clear(BTreeNode* subroot) { //need to finish this implementation--handle children
    root_ = nullptr;
    is_leaf = false;
    order_ = 3;
    for(int i = 0; i < elements_.size(); i++) {
        elements_.erase(elements_.begin() + i);
    }
}

BTreeNode* BTreeNode::copy(const BTreeNode* subroot) {  //work on this too-- will change with our implementation
    clear(this->root_);

}

BTreeNode* BTreeNode::find(BTreeNode* subroot, int key) {
    auto list = subroot->elements_;
    for(unsigned index = 0; index < list.size() && key > list[index]; index++);
    if(index < list.size() && list[index] == key) {return subroot;} //error here with [] operator

    if(subroot->is_leaf) {return nullptr;}
    return find(subroot->children_[index], key);    //error here again with []
}

void BTreeNode::insert(BTreeNode* subroot, int key) {   //this function needs some work too
    if(subroot = nullptr) {subroot = new BTreeNode(true, order_);}
    //insert(subroot, DataPair(key, value))

    if(subroot->elements_.size() >= order_) {
        BTreeNode * newSubroot = new BTreeNode(false, order_);
        newSubroot->children_.push_back(subroot);
        split_child(newSubroot, 0);
        subroot = newSubroot;
    }

}

void BTreeNode::traverse(BTreeNode* root, vector<int> & v) {
    if(root_ = nullptr) {return;}

    for(unsigned index = 0; index < root_->elements_.size(); index++) {
        if(!root->is_leaf) {
            traverse(root->children_[index], v);
        }
        v.push_back(root->elements_[index]);
    }
}

void BTreeNode::split_child(BTreeNode* parent, int child_index) {
    BTreeNode* child = parent->children_[child_index];
    BTreeNode* newLeft = child;
    BTreeNode* newRight = new BTreeNode(child->is_leaf, order_);

    int mid_element = (child->elements_.size()-1) / 2;
    int mid_child = child->children_.size() /2;

    auto child_iterator = parent->children_.begin() + child_index + 1;
    auto element_iterator = parent->elements_.begin() + child_index;
    auto mid_element_iterator = child->elements_.begin() + mid_element;
    auto mid_child_iterator = child->children_.begin() + mid_child;

    parent->children_.insert(child_iterator, newRight);
    parent->elements_.insert(element_iterator, child->elements_[mid_element]);
    newRight->elements_.assign(mid_element_iterator + 1, child->elements_.end());
    newRight->children_.assign(mid_child_iterator, child->children_.end());
    newLeft->elements_.assign(child->elements_.begin(), mid_element_iterator);
    newLeft->children_.assign(child->children_.begin(), mid_child_iterator);

}   