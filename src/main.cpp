#include <iostream>
#include "BTreeNode.h"

using std::cout;
using std::cin;
using std::endl;
using std::to_string;

int main() {
/* sudo code for how we are going to construct the BTree */
    map<string, float> inputData;
    inputData["apple"] = 4.5;
    inputData["banana"] = 4.0;
    inputData["cake"] = 4.2;
    inputData["candy"] = 2.6;
    inputData["donut"] = 1.1;
    inputData["radio"] = 4.9;
    inputData["chair"] = 4.5;
    inputData["desk"] = 6.2;    //test case for out of bounds upper
    inputData["headphones"] = -0.2; //test case for out of bounds lower
    inputData["nightstand"] = 3.9;
    inputData["gift"] = 2.8;
    inputData["glasses"] = 4.3;
    inputData["sweatpants"] = 5.0;
    inputData["notecards"] = 4.3;
    inputData["toner"] = 1.5;
    inputData["pen"] = 5.0; //bug here-- stores as one review instead of two
    inputData["pen"] = 4.0;
    inputData["canvas"] = 4.0;
    inputData["graphic_tee_shirt"] = 3.8;
    inputData["jeans"] = 4.8;
    inputData["old_headphones"] = 0.0;
    inputData["silver_necklace"] = 1.0;
    inputData["bracelet"] = -1.0;
    inputData["mousepad"] = 6.0;


    string prompt = "";
    float rating = 0.0;
    cout << "Please input the Product Name: "<<endl;
    cin >> prompt;
    cout<< "Please input the rating of the Product: " << endl;
    cin >> rating;
    
    bool flag = false;
    if(prompt == "" || rating < 0.0 || rating > 5.0) {
        flag = true;
        while(flag) {
            cout << "Please keep your rating 1-5: "<<endl;
            cin >> rating;
            cout << "and input a valid product name: "<<endl;
            cin >> prompt;
            if(prompt != "" && rating >= 0.0 && rating <= 5.0) {
                flag = false;
            }
        }
    }
    BTreeNode * temp = nullptr;
    BTreeNode * root = new BTreeNode(prompt, rating, false, temp);    //constructs root node with food name and rating to find 
    
    BTreeNode * nodeA = new BTreeNode("a", -1, false, root);
    root->setChild(nodeA);

    BTreeNode * nodeB = new BTreeNode("b", -1, false, root);
    root->setChild(nodeB);

    BTreeNode * nodeC = new BTreeNode("c", -1, false, root);
    root->setChild(nodeC);

    BTreeNode * nodeD = new BTreeNode("d", -1, false, root);
    root->setChild(nodeD);

    BTreeNode * nodeE = new BTreeNode("e", -1, false, root);
    root->setChild(nodeE);

    BTreeNode * nodeF = new BTreeNode("f", -1, false, root);
    root->setChild(nodeF);

    BTreeNode * nodeG = new BTreeNode("g", -1, false, root);
    root->setChild(nodeG);

    BTreeNode * nodeH = new BTreeNode("h", -1, false, root);
    root->setChild(nodeH);

    BTreeNode * nodeI = new BTreeNode("i", -1, false, root);
    root->setChild(nodeI);

    BTreeNode * nodeJ = new BTreeNode("j", -1, false, root);
    root->setChild(nodeJ);

    BTreeNode * nodeK = new BTreeNode("k", -1, false, root);
    root->setChild(nodeK);

    BTreeNode * nodeL = new BTreeNode("l", -1, false, root);
    root->setChild(nodeL);

    BTreeNode * nodeM = new BTreeNode("m", -1, false, root);
    root->setChild(nodeM);

    BTreeNode * nodeN = new BTreeNode("n", -1, false, root);
    root->setChild(nodeN);

    BTreeNode * nodeO = new BTreeNode("o", -1, false, root);
    root->setChild(nodeO);

    BTreeNode * nodeP = new BTreeNode("p", -1, false, root);
    root->setChild(nodeP);

    BTreeNode * nodeQ = new BTreeNode("q", -1, false, root);
    root->setChild(nodeQ);

    BTreeNode * nodeR = new BTreeNode("r", -1, false, root);
    root->setChild(nodeR);

    BTreeNode * nodeS = new BTreeNode("s", -1, false, root);
    root->setChild(nodeS);

    BTreeNode * nodeT = new BTreeNode("t", -1, false, root);
    root->setChild(nodeT);

    BTreeNode * nodeU = new BTreeNode("u", -1, false, root);
    root->setChild(nodeU);

    BTreeNode * nodeV = new BTreeNode("v", -1, false, root);
    root->setChild(nodeV);

    BTreeNode * nodeW = new BTreeNode("w", -1, false, root);
    root->setChild(nodeW);

    BTreeNode * nodeX = new BTreeNode("x", -1, false, root);
    root->setChild(nodeX);

    BTreeNode * nodeY = new BTreeNode("y", -1, false, root);
    root->setChild(nodeY);

    BTreeNode * nodeZ = new BTreeNode("z", -1, false, root);
    root->setChild(nodeZ);


    for(map<string, float>::iterator it = inputData.begin(); it != inputData.end(); it++) {
        char chr = it->first.at(0);

        switch(chr){
            case('a'):
                nodeA->insert(it->first, it->second);
                break;
            case('b'):
                nodeB->insert(it->first, it->second);
                break;
            case('c'):
                nodeC->insert(it->first, it->second);
                break;
            case('d'):
                nodeD->insert(it->first, it->second);
                break;
            case('e'):
                nodeE->insert(it->first, it->second);
                break;
            case('f'):
                nodeF->insert(it->first, it->second);
                break;
            case('g'):
                nodeG->insert(it->first, it->second);
                break;
            case('h'):
                nodeH->insert(it->first, it->second);
                break;
            case('i'):
                nodeI->insert(it->first, it->second);
                break;
            case('j'):
                nodeJ->insert(it->first, it->second);
                break;
            case('k'):
                nodeK->insert(it->first, it->second);
                break;
            case('l'):
                nodeL->insert(it->first, it->second);
                break;
            case('m'):
                nodeM->insert(it->first, it->second);
                break;
            case('n'):
                nodeN->insert(it->first, it->second);
                break;
            case('o'):
                nodeO->insert(it->first, it->second);
                break;
            case('p'):
                nodeP->insert(it->first, it->second);
                break;
            case('q'):
                nodeQ->insert(it->first, it->second);
                break;
            case('r'):
                nodeR->insert(it->first, it->second);
                break;
            case('s'):
                nodeS->insert(it->first, it->second);
                break;
            case('t'):
                nodeT->insert(it->first, it->second);
                break;
            case('u'):
                nodeU->insert(it->first, it->second);
                break;
            case('v'):
                nodeV->insert(it->first, it->second);
                break;
            case('w'):
                nodeW->insert(it->first, it->second);
                break;
            case('x'):
                nodeX->insert(it->first, it->second);
                break;
            case('y'):
                nodeY->insert(it->first, it->second);
                break;
            case('z'):
                nodeZ->insert(it->first, it->second);
                break;
            default: 
                break;
        }
    }

    //Tests for construction of entire BTree (should be alphabetized)   //passes (except for duplicate nodes)
    cout<<"Tests for construction of BTree: "<<endl;
    root->printTree();

    //Tests for =operator (basically a test for copy and clear)
    cout<<"Simple Test for =operator: "<<endl;  //passed
    BTreeNode* one = new BTreeNode("Shoes", 3.6, true, root);
    BTreeNode* two = one;
    cout<< one->getItemName()<< " "<<to_string(one->getItemRating())<<endl;
    cout<< two->getItemName()<< " "<<to_string(two->getItemRating())<<endl;

    cout<<"Medium Test for =operator:"<<endl;   //failed-- I think copy is wrong-- will have to fix this 
    one->setItemName("Sneakers");
    two->setItemRating(4.1);
    cout<< one->getItemName()<< " "<<to_string(one->getItemRating())<<endl;
    cout<< two->getItemName()<< " "<<to_string(two->getItemRating())<<endl;

    //Test for find method: should return the item with the best rating for that given item    //Fails. Nothing found for banana
    cout<<"Test for find Method: "<<endl;
    string name= "banana";
    BTreeNode* found = root->find(root, name);
    cout<<found->getItemName()<<to_string(found->getItemRating())<<endl;

    //Test for findAll method; should return item name and it's rating -> fails: prints empty vector the entire time 
    cout<<"Test for findAll Method: "<<endl;
    string name_find = "apple";
    float rating_find = 4.5;
    vector<BTreeNode*> findVector = root->findAll(root, name_find, rating_find);
    if(findVector.empty()) {cout<<"Vector is Empty"<<endl;}
    for(size_t vecCount = 0; vecCount < findVector.size(); vecCount++) {
        cout<< findVector[vecCount]->getItemName()<< " "<<to_string(findVector[vecCount]->getItemRating())<<endl;
    }

    //Test for Traversal Method -> FAILS: SEG FAULT
    // cout<<"Testing Traversal: "<<endl;
    // vector<BTreeNode*> traversalVector = root->traverse(root);
    // for(size_t vec2Count = 0; vec2Count < traversalVector.size(); vec2Count++) {
    //     cout<< findVector[vec2Count]->getItemName()<< " " <<to_string(findVector[vec2Count]->getItemRating())<<endl;
    // }


    return 0;
}