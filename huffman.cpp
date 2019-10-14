//
//  huffman.cpp
//  jpeg
//
//  Created by Blake Johnson on 9/16/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#include "huffman.hpp"
#include <math.h>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

void Huffman::compress(std::string data, int bits)
{
    //Create a hashtable to count occurences of symbols and store string into object's string
    map count;
    rawData = data;
    std::string token = "";
    float size = 0.0;    //number of total occurences of symbols
    //int numOfSymbols = 0; //number of unique symbols
    bool done = false;
    std::istringstream str (rawData);
    
    //If the string is a binary, parse groups of bits into symbols and store into the obect's string
    if(bits) parseBits(bits);
    
    //Now parse the string and count the occurences of the symbols
    
    while(!done){
        str >> token;
        if(token.size() == 0 ) done = true;
        else{
            //val = std::stoi(token);
            count[token]++;
            token.clear(); //clear so we can eventually set done
            size++;
       }
    }
   
    
    huffNode node;
    
    //for every item in the hash table, create a huffNode and add it to a minHeap
    for(auto iter = count.begin(); iter != count.end(); iter++){
       // std::cout << iter -> first << " : " << iter -> second << "\n";
        numOfSymbols++;
        node.symbol = std::stoi(iter -> first);
        node.prob = (iter -> second) / size;
        
        //important for placing of subtrees. ie 0.03999 vs 0.041111 should both be 0.04
        node.prob = std::round(node.prob * 1000) / 1000;
        
        BinaryTree<huffNode> *tree = new BinaryTree<huffNode>;
        tree -> insert(node);
        minHeap.push(tree);
        //delete tree;
    }
    
    //Now create a huffman tree using the values in the heap
    createTree();
    //traverse the tree to create the codes
    generateCodes(huffmanTree.getRoot(), "");
    //Now encode the raw data
    encodeString();
    
    
    
    /*
    //Debuging
    while(minHeap.size()){
        //std::cout << minHeap.top().symbol << " " <<  minHeap.top().prob << "\n" ;
        std::cout << minHeap.top()->getRoot()->data.symbol << " " << minHeap.top()->getRoot()->data.symbol << "\n";
        minHeap.pop();
    }
    */
    
}

void Huffman::parseBits(int bits)
{
    
}


void Huffman::createTree(){
    
  //  BinaryTree<huffNode> tree1, tree2;
   // huffNode huff1, huff2, huff3;
    
    BinaryTree<huffNode> * tree1, *tree2, * tree;
    huffNode newNode;
    
    
    //while(minHeap.size()){
    for(int i = 0; i < numOfSymbols -1; i++){
        // std::cout << huff.symbol << " " <<  huff.prob << "\n" ;
        //Grab the top two nodes from the min heap and pop them off. this is used to create the tree
       /*
        huff1 = minHeap.top();
        tree1.insert(huff1);
        minHeap.pop();
        
        huff2 = minHeap.top();
        tree2.insert(huff2);
        minHeap.pop();
        
        huff3.prob = huff1.prob + huff2.prob;
        
        huffmanTree.makeTree(huff3, tree1, tree2);
        huffmanTree.levelOrder(huffmanTree.getRoot());
        std::cout << "\n";
        
        minHeap.push(huff3);
        */
        tree1 = minHeap.top();
        minHeap.pop();
        
        tree2 = minHeap.top();
        minHeap.pop();
        
        newNode.prob = (tree1 -> getRoot() -> data.prob) + (tree2 -> getRoot() -> data.prob);
        
        tree = new BinaryTree<huffNode>;
        
        if(tree1 -> getRoot() ->data.prob <= tree2 -> getRoot() ->data.prob){
            
            tree -> makeTree(newNode, *tree1, *tree2);
            
        }
        else {
            tree -> makeTree(newNode, *tree2, *tree1);
        }
        /*
    
        
        else{
            if(tree1 -> getTreeSize() <= tree2 -> getTreeSize())
                tree -> makeTree(newNode, *tree1, *tree2);
            else
                tree -> makeTree(newNode, *tree2, *tree1);
                
        }
       */
            //debug
            tree -> levelOrder(tree -> getRoot());
            std::cout << "\n";
        
        minHeap.push(tree);
        delete tree1;
        delete tree2;
        //if(newNode.prob == 1){
        if(i == numOfSymbols -2){
            huffmanTree = *tree;
            huffmanTree.levelOrder(huffmanTree.getRoot());
            std::cout << "\n";
            postOrder(huffmanTree.getRoot());
            std::cout << "\n";
            break;
        }
    }
}

//The idea I am going for here is to do a pre order traversal of the huffman tree
//Each time a node is entered, its code is updated
//when traveling to Left child, multiply by 10 for a zero
//when traveling to right child, multiply by 10 and add 1 for a 1
bool Huffman::generateCodes(BinaryTreeNode<huffNode> * node, std::string code){
   /* if(node != NULL){
        node -> data.code = code;
        int newCode = code * 10;
        generateCodes(node -> left, newCode);
        generateCodes(node -> right, newCode + 1);
    }
    */
    if(node != NULL){
        bool leaf = false;
        
        node -> data.code = code;
        //std::string newCode = code;
        
        leaf = generateCodes(node -> left, code + "1");
        leaf = generateCodes(node -> right, code + "0");
        
        if(leaf) {
            dictionary[node -> data.symbol] = node -> data.code;
            std::cout << node -> data.symbol << " " << node -> data.code << "\n";
        }
        return false;
    }
    else return true;
}


void Huffman::encodeString(){
    
    bool done = false;
    int symbol = 0;
    std::istringstream uncoded (rawData);
    std::ostringstream encoded;
    std::string token = "";
    std::cout << rawData << "\n";
    while(!done){
        uncoded >> token;
        if(token.size() == 0 ) done = true;
        else{
            symbol = std::stoi(token);
            encoded << dictionary[symbol] << " ";
            token.clear(); //clear so we can eventually set done
        }
    }
    
    
    encodedData = encoded.str();
    std::cout << "\n"<<encodedData << "\n";
    
}

