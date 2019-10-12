//
//  huffman.cpp
//  jpeg
//
//  Created by Blake Johnson on 9/16/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#include "huffman.hpp"
#include <sstream>

void Huffman::compress(std::string data, int bits)
{
    //Create a hashtable to count occurences of symbols and store string into object's string
    map count;
    rawData = data;
    std::string token = "";
    int size = 0;    //number of total occurences of symbols
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
    numOfSymbols = count.size();
    
    
    
    
    
    
}

void Huffman::parseBits(int bits)
{
    
}
