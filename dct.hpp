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


const double quantLumin [8][8] = {
    {16, 11, 10, 16, 24, 40, 51, 61},
    {12, 12, 14, 19, 26, 58, 60, 55},
    {14, 13, 16, 24, 40, 57, 69, 56},
    {14, 17, 22, 29, 51, 87, 80, 62},
    {18, 22, 37, 56, 68,109,103, 77},
    {24, 36, 55, 64, 81,104,113, 92},
    {49, 64, 78, 87,103,121,120,101},
    {72, 92, 95, 98,112,100,103, 99}
    };

const double quantChrom [8][8] = {
    {17, 18, 24, 47, 99, 99, 99, 99},
    {18, 21, 26, 66, 99, 99, 99, 99},
    {24, 26, 56, 99, 99, 99, 99, 99},
    {47, 66, 99, 99, 99, 99, 99, 99},
    {99, 99, 99, 99, 99, 99, 99, 99},
    {99, 99, 99, 99, 99, 99, 99, 99},
    {99, 99, 99, 99, 99, 99, 99, 99},
    {99, 99, 99, 99, 99, 99, 99, 99}
    };

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
    
    void fdctFunc(int u, int v, double Suv[8][8],  double *** colors);
    
    
    
    //called from fdct to center all pixel values between -128 and 127
    void levelShift(double *** colors);
    
    void quantize(double *** colors);
    
    
    void printBlock(double *** colors);  //for debugging purposes
    void printBlock(double colors [8][8]);
};







#endif /* dct_hpp */
