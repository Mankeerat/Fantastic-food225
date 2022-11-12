#include <iostream>
#include "BTreeNode.h"

BTreeNode::BTreeNode() {
    is_leaf = true;
    itemName_ = "";
    itemRating_ = -1.0;
    parent_ = nullptr;
    order_ = 2;
}

BTreeNode::BTreeNode(string itemName, float itemRating, bool is_leaff, BTreeNode & parent) {
    is_leaf = is_leaff;
    itemName_ = itemName;
    itemRating_ = itemRating;
    *parent_ = parent;
    order_ = 2;
}

BTreeNode::~BTreeNode() {
    clear(this);
}

BTreeNode & BTreeNode::operator=(const BTreeNode & other) {
    clear(this);
    copy(other);
    return (*this);
}

void BTreeNode::clear(BTreeNode* subroot) { 
    subroot->children_.erase(subroot->children_.begin(), subroot->children_.end());
    subroot->parent_ = nullptr;
    subroot->is_leaf = false;
    subroot->order_ = 3;
}

BTreeNode* BTreeNode::copy(const BTreeNode & subroot) {  
    for(size_t i = 0; i < subroot.children_.size(); i++) {
        this->children_.at(i) = subroot.children_.at(i);
    }
    this->order_ = subroot.order_;
    this->is_leaf = subroot.is_leaf;
    this->parent_ = subroot.parent_;
    return (this);
}

BTreeNode* find(BTreeNode* root, string itemName, float ItemRating) {

}


void BTreeNode::insert(string itemName, float itemRating) {   //last function to finish-- must be able to insert a child or element
    if(itemName.empty() || itemRating > 5.0 || itemRating < 0.0) {return;}    //protects against invalid insertions

    if(this->children_.empty()) {
        BTreeNode * newNode = new BTreeNode(itemName, itemRating, true, *this);
        this->children_.push_back(newNode);
    } else {
        if(this->children_.at(0)->itemRating_ < itemRating) {
            if(this->children_.size() == 1) {   //This may not be right-- for a single node this works, but this will depend on the order of the BTree
                this->children_.at(0)->is_leaf = true;
            } 
            BTreeNode * newNode = new BTreeNode(itemName, itemRating, false, *this);
            this->children_.insert(this->children_.begin(), newNode);
            
        } else {
            BTreeNode * newNode = new BTreeNode(itemName, itemRating, true, *this);
            this->children_.push_back(newNode);
        }
    }

    // if(this->children_.size() >= order_) {   //this needs tons of work-- no clue how to handle this case
    //     BTreeNode * newSubroot = new BTreeNode(false, order_);
    //     newSubroot->children_.push_back(subroot);
    //     split_child(newSubroot, 0);
    //     subroot = newSubroot;
    // }

}

vector<BTreeNode*> BTreeNode::traverse(BTreeNode* root) {  //essentially depth first until item rating isn't -1 from root, then BFS from there
    vector<BTreeNode*> v;
    v.push_back(root);
    traverse_(root, v);
    return v;
}

void BTreeNode::traverse_(BTreeNode* subroot, vector<BTreeNode*> & vector) {
    if(subroot == nullptr) {return;}

    if(subroot->itemRating_ < 0.0) {
        vector.push_back(subroot);
        traverse_(subroot->children_[0], vector);
    }

    BTreeNode * temp = subroot->children_[0];
    unsigned int count = 0;
    while(temp != nullptr && count < subroot->order_) {
        vector.push_back(temp);
        count++;
        temp = subroot->children_[count];
    }
    traverse_(temp->children_[0], vector);
}

// void BTreeNode::split_child(BTreeNode* parent, int child_index) {    //THIS IS GOING TO BE THE HARDEST METHOD 
//     BTreeNode* child = parent->children_[child_index];
//     BTreeNode* newLeft = child;
//     BTreeNode* newRight = new BTreeNode(child->is_leaf, order_);

//     int mid_element = (child->elements_.size()-1) / 2;
//     int mid_child = child->children_.size() /2;

//     auto child_iterator = parent->children_.begin() + child_index + 1;
//     auto element_iterator = parent->elements_.begin() + child_index;
//     auto mid_element_iterator = child->elements_.begin() + mid_element;
//     auto mid_child_iterator = child->children_.begin() + mid_child;

//     parent->children_.insert(child_iterator, newRight);
//     parent->elements_.insert(element_iterator, child->elements_[mid_element]);
//     newRight->elements_.assign(mid_element_iterator + 1, child->elements_.end());
//     newRight->children_.assign(mid_child_iterator, child->children_.end());
//     newLeft->elements_.assign(child->elements_.begin(), mid_element_iterator);
//     newLeft->children_.assign(child->children_.begin(), mid_child_iterator);

// }   