//
//  main.cpp
//  jpeg
//
//  Created by Blake Johnson on 9/16/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#include <iostream>
#include <string>

#include "binaryTree.hpp"
#include "huffman.hpp"


int main(int argc, const char * argv[]) {

   // std::string str = " 1 2 3 4  5 6 6 6 6 6 5 1 1 3";
    std::string str = " 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2  2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 6 6 6 6 6 6 5 5 5 5";
    /*
     5 0.04
     6 0.06
     3 0.1
     4 0.1
     2 0.3
     1 0.4
     */
    Huffman huff;
    
    huff.compress(str);
    return 0;
}
