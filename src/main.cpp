#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "BTreeNode.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
/* sudo code for how we are going to construct the BTree 

    string prompt = "";
    float rating = 0.0;
    cout << "Please input the Product Name: "
    cin << prompt <<endl;;
    cout<< "Please input the rating of the Product: "
    cin << rating << endl;
    bool flag = false;
    if(prompt == "" || rating < 0.0 || rating > 5.0) {
        flag = true;
        while(flag) {
            cout << "Please keep your rating 1-5: ";
            cin << rating << endl;
            cout << "and input a valid product name: ";
            cin << prompt << endl;
            if(prompt != "" && rating >= 0.0 && rating <= 5.0) {
                flag = false;
            }
        }
    }

    BTreeNode * root(prompt, rating, false, nullptr);    //constructs root node with food name and rating to find 
    BTreeNode * nodeA = ("a", -1, false, root);
    root->children[0] = nodeA;

    BTreeNode * nodeB = ("b", -1, false, root);
    root->children[1] = nodeB;

    BTreeNode * nodeC = ("c", -1, false, root);
    root->children[2] = nodeC;

    BTreeNode * nodeD = ("d", -1, false, root);
    root->children[3] = nodeD;

    BTreeNode * nodeE = ("e", -1, false, root);
    root->children[4] = nodeE;

    BTreeNode * nodeF = ("f", -1, false, root);
    root->children[5] = nodeF;

    BTreeNode * nodeG = ("g", -1, false, root);
    root->children[6] = nodeG;

    BTreeNode * nodeH = ("h", -1, false, root);
    root->children[7] = nodeH;

    BTreeNode * nodeI = ("i", -1, false, root);
    root->children[8] = nodeI;

    BTreeNode * nodeJ = ("j", -1, false, root);
    root->children[9] = nodeJ;

    BTreeNode * nodeK = ("k", -1, false, root);
    root->children[10] = nodeK;

    BTreeNode * nodeL = ("l", -1, false, root);
    root->children[11] = nodeL;

    BTreeNode * nodeM = ("m", -1, false, root);
    root->children[12] = nodeM;

    BTreeNode * nodeN = ("n", -1, false, root);
    root->children[13] = nodeN;

    BTreeNode * nodeO = ("o", -1, false, root);
    root->children[14] = nodeO;

    BTreeNode * nodeP = ("p", -1, false, root);
    root->children[15] = nodeP;

    BTreeNode * nodeQ = ("q", -1, false, root);
    root->children[16] = nodeR;

    BTreeNode * nodeR = ("r", -1, false, root);
    root->children[17] = nodeR;

    BTreeNode * nodeS = ("s", -1, false, root);
    root->children[18] = nodeS;

    BTreeNode * nodeT = ("t", -1, false, root);
    root->children[19] = nodeT;

    BTreeNode * nodeU = ("u", -1, false, root);
    root->children[20] = nodeU;

    BTreeNode * nodeV = ("v", -1, false, root);
    root->children[21] = nodeV;

    BTreeNode * nodeW = ("w", -1, false, root);
    root->children[22] = nodeW;

    BTreeNode * nodeX = ("x", -1, false, root);
    root->children[23] = nodeX;

    BTreeNode * nodeY = ("y", -1, false, root);
    root->children[24] = nodeY;

    BTreeNode * nodeZ = ("z", -1, false, root);
    root->children[25] = nodeZ;

    for(int i = 0; i < inputData.size(); i++) {
        char first = inputData[i.first[0]];

        switch(first){
            case('a'):
                nodeA->insert(inputData[i]->first, inputData[i]->second);
                break;
            case('b'):
                nodeB->insert(inputData[i]);
                break;
            case('c'):
                nodeC->insert(inputData[i]);
                break;
            case('d'):
                nodeD->insert(inputData[i]);
                break;
            case('e'):
                nodeE->insert(inputData[i]);
                break;
            case('f'):
                nodeF->insert(inputData[i]);
                break;
            case('g'):
                nodeG->insert(inputData[i]);
                break;
            case('h'):
                nodeH->insert(inputData[i]);
                break;
            case('i'):
                nodeI->insert(inputData[i]);
                break;
            case('j'):
                nodeJ->insert(inputData[i]);
                break;
            case('k'):
                nodeK->insert(inputData[i]);
                break;
            case('l'):
                nodeL->insert(inputData[i]);
                break;
            case('m'):
                nodeM->insert(inputData[i]);
                break;
            case('n'):
                nodeN->insert(inputData[i]);
                break;
            case('o'):
                nodeO->insert(inputData[i]);
                break;
            case('p'):
                nodeP->insert(inputData[i]);
                break;
            case('q'):
                nodeQ->insert(inputData[i]);
                break;
            case('r'):
                nodeR->insert(inputData[i]);
                break;
            case('s'):
                nodeS->insert(inputData[i]);
                break;
            case('t'):
                nodeT->insert(inputData[i]);
                break;
            case('u'):
                nodeU->insert(inputData[i]);
                break;
            case('v'):
                nodeV->insert(inputData[i]);
                break;
            case('w'):
                nodeW->insert(inputData[i]);
                break;
            case('x'):
                nodeX->insert(inputData[i]);
                break;
            case('y'):
                nodeY->insert(inputData[i]);
                break;
            case('z'):
                nodeZ->insert(inputData[i]);
                break;
            base: 
                break;
        }
            


    }

    */
    return 0;
}