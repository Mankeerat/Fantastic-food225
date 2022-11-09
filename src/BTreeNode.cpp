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

BTreeNode::BTreeNode(vector<int> v, bool is_leaff) { 
    root_ = nullptr;
    is_leaf = is_leaff;
    order_ = 3;
    for(size_t i = 0; i < v.size(); i++) {
        elements_.push_back(v[i]);
    }
}

BTreeNode::~BTreeNode() {
    clear(this->root_);
}

BTreeNode & BTreeNode::operator=(const BTreeNode & other) {
    clear(this->root_);
    copy(other.root_);
    return (*this);
}

void BTreeNode::clear(BTreeNode* subroot) { 
    for(size_t i= 0; i < subroot->children_.size(); i++) {
        subroot->children_[i]->elements_.erase(elements_.begin(), elements_.end());
    }
    subroot->root_ = nullptr;
    subroot->is_leaf = false;
    subroot->order_ = 3;
}

BTreeNode* BTreeNode::copy(const BTreeNode* subroot) {  //work on this too-- will change with our implementation
    for(size_t i= 0; i < subroot->children_.size(); i++) {
        for(size_t j = 0; j < subroot->children_[i]->elements_.size(); j++) {
            this->children_[i]->elements_[j] = subroot->children_[i]->elements_[j];
        }
    }
    this->order_ = subroot->order_;
    this->is_leaf = subroot->is_leaf;
    this->root_ = subroot->root_;
    return (this);
}

BTreeNode* BTreeNode::find(BTreeNode* subroot, int key) {
    auto list = subroot->elements_;
    size_t i;
    for(i = 0; i < list.size() && key > list[i]; i++);
    if(i < list.size() && list[i] == key) {return subroot;}

    if(subroot->is_leaf) {return nullptr;}
    return find(subroot->children_[i], key);    
}

void BTreeNode::insert(BTreeNode* subroot, int key) {   //last function to finish-- must be able to insert a child or element
    if(subroot == nullptr) {subroot = new BTreeNode(true, order_);}
    //insert(subroot, DataPair(key, value))

    if(subroot->elements_.size() >= order_) {
        BTreeNode * newSubroot = new BTreeNode(false, order_);
        newSubroot->children_.push_back(subroot);
        split_child(newSubroot, 0);
        subroot = newSubroot;
    }

}

vector<int> BTreeNode::traverse(BTreeNode* root) {
    vector<int> v;
    traverse_(root, v);
    return v;
}

void BTreeNode::traverse_(BTreeNode* root, vector<int> & vector) {
    if(root == nullptr) {return;}

    for(size_t index = 0; index < root->elements_.size(); index++) {
        if(!root->is_leaf) {
            traverse_(root->children_[index], vector);
        }
        vector.push_back(root->elements_[index]);
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