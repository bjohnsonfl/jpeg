//
//  main.cpp
//  jpeg
//
//  Created by Blake Johnson on 9/16/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#include <iostream>
#include "binaryTree.hpp"

int main(int argc, const char * argv[]) {

    BinaryTree<int> tree;
    double* buff = new double [1000000];
    {
    BinaryTree<int> tree1;
    BinaryTree<int> tree2;
    tree1.insert(1);
    tree1.insert(2);
    tree1.insert(3);
        
       
    tree2.insert(4);
    tree2.insert(5);
    tree2.insert(6);
    
    //tree.makeTree(7, tree1, tree2);
    }
   
    //tree.levelOrder(tree.getRoot());
    //tree.postOrder(tree.getRoot());
    
    return 0;
}
