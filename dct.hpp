//
//  dct.hpp
//  jpeg
//
//  Created by Blake Johnson on 10/23/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#ifndef dct_hpp
#define dct_hpp

#include <stdio.h>

#include "jpeg.hpp"

//This header file handles the Discrete Cosine Transform and Quantization of N x N blocks from the jpeg object

#define Pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062


//DCT is a friend class of class Jpeg. the dct is calculated on Jpeg color 3-d array for each channel.
class DCT {
    
private:
    int x;
    int y;
public:
    DCT(){};
    
    //forward discrete cosine transform
    void fdct(int x, int y);
    
    
    
};







#endif /* dct_hpp */
