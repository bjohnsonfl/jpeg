//
//  jpeg.hpp
//  jpeg
//
//  Created by Blake Johnson on 10/15/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#ifndef jpeg_hpp
#define jpeg_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>

#include "huffman.hpp"


/*
 
 take in a ppm image
 
 divide the image into nxn blocks
 
 for each block, covert into YCbCr and also downsample (optional but desired)
 
 for each block, run it through a discrete cosine transform
 
 for each block, quantize
 
 for each block use entropy encoding (use run length encoding optional but desired)
 
 for each block create a huffman tree and encode the block with said tree
 
 for each block, populate the new jpeg file
 
 
 
 create a method to view the binary of a jpeg file for debugging
 
 */

class Jpeg {
    
private:
    std::string sourceImage;
    //in ppm images, the first line says the type, the second line says height and width, the third line says the color size, fourth line starts data
    int width;
    int height;
    
    std::ifstream srcImg;
    
    int *** colors; //3 channels for rgb/YCbCr x height x width
    
    
public:
    Jpeg();
    Jpeg(std::string img) {
        generateJpeg(img);
    }
    ~Jpeg(){};
    
    void generateJpeg(std::string img);
    void parseDimensions();
    void parseColors(); //extracts rgb data from the file and converts them to YCbCr and stores them into colors array
    void rgbToYCbCr (int r, int g, int b, int YcBcR []);
};


#endif /* jpeg_hpp */
