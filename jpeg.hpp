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
 
 create a huffman tree for ac luminance, ac Yc + Yr, dc luminance, and dc Yc + Yr
 
 for each block use entropy encoding (use run length encoding optional but desired), create a zigzag pattern, encode using huffman trees created above
 
 for each block, populate the new jpeg file
 
 
 
 create a method to view the binary of a jpeg file for debugging
 
 */
//sequential 
//non interchange
//Abbreviated format for table-specification data 4.9.3

class DCT;
class Jpeg {
    
private:
    std::string sourceImage;
    //in ppm images, the first line says the type, the second line says height and width, the third line says the color size, fourth line starts data
   
    std::ifstream srcImg;
    
protected:
    int width;
    int height;
    double *** colors; //3 channels for rgb/YCbCr x height x width

public:
    Jpeg();
    Jpeg(std::string img) {
        generateJpeg(img);
    }
    ~Jpeg(){};
    
    void generateJpeg(std::string img);
    void parseDimensions();
    //extracts rgb data from the file and converts them to YCbCr and stores them into colors array
    void parseColors();
    void rgbToYCbCr ( double YcBcR []);
    //iterate over nxn blocks, call dct, and quantize
    void divideIntoBlocks();
    //creates 4 huffman trees to eventually encode each block
    void createHuffmanTrees();
    
    
    friend class DCT;
    
};




#endif /* jpeg_hpp */
