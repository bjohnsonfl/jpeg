//
//  dct.hpp
//  jpeg
//
//  Created by Blake Johnson on 10/23/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#ifndef dct_hpp
#define dct_hpp

#include <iostream>
#include <math.h>
#include <stdio.h>

#include "jpeg.hpp"

//This header file handles the Discrete Cosine Transform and Quantization of N x N blocks from the jpeg object

#define Pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062
#define Cuv 1 / pow(2, 0.5)


//DCT is a friend class of class Jpeg. the dct is calculated on Jpeg color 3-d array for each channel.
class DCT {
    
private:
    int i;
    int j;
    int n;
    int m;
    int channel;
   
public:
    DCT (){
        i = 0;
        j = 0;
        n = 8;   //assume nxn blocks
        m = 8;
        channel = 0; //assume channel is lumanince
    }
    DCT(int n, int m){
        this -> n = n;
        this -> m = m;
    };
    
    //forward discrete cosine transform
    void fdct(int x, int y, int chan ,Jpeg & image){
        fdct( x, y, chan, image.colors);
    }
    void fdct(int x, int y, int chan, double *** colors);
    
    
    //called from fdct to center all pixel values between -128 and 127
    void levelShift(double *** colors);
    
    void quantize();
    
    
    void printBlock(double *** colors);  //for debugging purposes
};







#endif /* dct_hpp */
