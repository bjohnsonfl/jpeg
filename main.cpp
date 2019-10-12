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

    std::string str = " 1 2 3 4  5 6 6 6 6 6 5 ";
    Huffman huff;
    
    huff.compress(str);
    return 0;
}
