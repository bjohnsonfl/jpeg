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
    double prob;
    int code;
    //BinaryTree<int> tree = BinaryTree<int>();
    
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

//When creating the min heap, we use a priority queue with a comparison of each symbols probability
class comparator{
public:
    
    bool operator() (const huffNode& lhs, const huffNode& rhs) const
    {
        return lhs.prob > rhs.prob;
    }
    bool operator() ( BinaryTree<huffNode>& lhs,  BinaryTree<huffNode>& rhs) const
    {
       
        return (lhs.getRoot())->data.prob > (rhs.getRoot())->data.prob;
      
    }
    bool operator() ( BinaryTree<huffNode>* lhs,  BinaryTree<huffNode>* rhs) const
    {
        
        return (lhs->getRoot())->data.prob > (rhs->getRoot())->data.prob;
        
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
    int numOfSymbols;
    //std::priority_queue<huffNode, std::vector<huffNode>, comparator> minHeap;
    std::priority_queue<BinaryTree<huffNode> *, std::vector<BinaryTree<huffNode>* > , comparator> minHeap;
    BinaryTree<huffNode> huffmanTree;
    map dictionary;
    
public:
    Huffman(){numOfSymbols = 0;};
    //wrapper function to start compression of input string
    //counts occurences and calculates probabilities of symbols
    void compress (std::string data) {compress(data, 0);};
    void compress (std::string data, int bits);
    
    
    void parseBits (int bits);  //if the string is binary, parse the number of desired bits to create symbols
    void createTree();
    void generateCodes();
    void postOrder (BinaryTreeNode<huffNode> * node){
        if(node != NULL){
            postOrder(node -> left);
            postOrder(node -> right);
            std::cout << node -> data.prob << " ";
            
        }
    }
};

#endif /* huffman_hpp */
