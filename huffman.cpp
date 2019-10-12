//
//  huffman.cpp
//  jpeg
//
//  Created by Blake Johnson on 9/16/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#include "huffman.hpp"
#include <queue>
#include <sstream>
#include <vector>

void Huffman::compress(std::string data, int bits)
{
    //Create a hashtable to count occurences of symbols and store string into object's string
    map count;
    rawData = data;
    std::string token = "";
    float size = 0.0;    //number of total occurences of symbols
    int numOfSymbols; //number of unique symbols
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
        node.symbol = std::stoi(iter -> first);
        node.prob = (iter -> second) / size;
        
        minHeap.push(node);
    }
    
    //Now create a huffman tree using the values in the heap
    createTree();
    
    /*
    //Debuging
    while(minHeap.size()){
        std::cout << minHeap.top().symbol << " " <<  minHeap.top().prob << "\n" ;
        minHeap.pop();
    }
    */
    
}

void Huffman::parseBits(int bits)
{
    
}


void Huffman::createTree(){
    
}
