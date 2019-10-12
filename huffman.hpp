//
//  huffman.hpp
//  jpeg
//
//  Created by Blake Johnson on 9/16/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#ifndef huffman_hpp
#define huffman_hpp

#include <stdio.h>
#include <string>
#include <unordered_map>


#include "binaryTree.hpp"

typedef std::unordered_map<std::string,int> map;

struct huffNode{
    
    int symbol;
    float prob;
    int code;
    
    huffNode(){
        symbol = 0;
        prob = 0.0;
        code = 0;
    }
    
    huffNode(int symbol){
        this->symbol = symbol;
        prob = 0.0;
        code = 0;
    }
    
    huffNode(int symbol, int prob){
        this -> symbol = symbol;
        this -> prob = prob;
        code = 0;
    }
    
    huffNode(int symbol, float prob, int code){
        this -> symbol = symbol;
        this -> prob = prob;
        this -> code = code;
    }
    
};
/*
 take in a string.
 
 (optional) parse string into 8 bit values
 
 store values into a map and count the number of values
 
 create an array of structures that hold the symbol, the prob, and the code
 
 build the huffman tree
 
 traverse the huffman tree to the leafs to create the codes
 
 create a map of symobols to codes
 
 */

class Huffman{
    
private:
    std::string rawData;
    map dictionary;
    
    BinaryTree<huffNode> huffmanTree;
    
public:
    Huffman(){};
    //wrapper function to start compression of input string
    //counts occurences and calculates probabilities of symbols
    void compress (std::string data) {compress(data, 0);};
    void compress (std::string data, int bits);
    
    
    void parseBits (int bits);  //if the string is binary, parse the number of desired bits to create symbols
    
    
};

#endif /* huffman_hpp */
