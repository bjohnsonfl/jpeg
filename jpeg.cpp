//
//  jpeg.cpp
//  jpeg
//
//  Created by Blake Johnson on 10/15/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#include "jpeg.hpp"


void Jpeg::generateJpeg(std::string img){
    
    sourceImage = img;
    srcImg.open(sourceImage); //for now no error checking will be conducted
    parseDimensions();
    parseColors();
    
    
    
    
    
    
    srcImg.close();
}

void Jpeg::parseDimensions(){
    std::istringstream str;
    std::string line = "";  //used to grab a line from the image
    
    std::getline(srcImg, line);  //grab the ppm type
    std::getline(srcImg, line);  //grab the dimensions line
    
    str.str(line);
    
    str >> width;
    str >> height;
}

void Jpeg::parseColors(){
    std::istringstream str;
    std::string line = "";  //used to grab a line from the image
    std::string token = ""; //used to grab elements from that line
    
    std::getline(srcImg, line);  //grab the ppm type
    std::getline(srcImg, line);  //grab the dimensions line
    std::getline(srcImg, line);  //grab the color size
    
    //initialize the colors 3 dimensional array: 3 channels x height x width
    
    colors = new int ** [3];
    
    for(int i = 0; i < 3; i++){
        colors[i] = new int * [height];
        for( int j = 0; j<height; j++){
            colors[i][j] = new int [width];
        }
    }
    
    
    //now parse the image into the three channels. These will be rgb values from the file, so convert them to YCbCr
    int rgb [3] = {0,0,0};
    
    for(int i = 0; i < height; i++){
        
    }
    
    
    
    
    
    
    
    
}



void Jpeg::rgbToYCbCr(int r, int g, int b, int YcBcR[]){
    /*
    |Y |    |_  _  _|   |r|
    |Cr|  = |_  _  _| * |g|
    |Cr|    |_  _  _|   |b|
     
     to convert rgb into YCbCr, use this matrix equation. credits to wikipedia, the equations with the "A" matrix values are already solved
     
     */
    YcBcR[0] = 0   + (0.299    * r) + (0.587    * g) + (0.114    * b);
    YcBcR[1] = 128 - (0.168736 * r) - (0.331264 * g) + (0.5      * b);
    YcBcR[2] = 128 + (0.5      * r) - (0.418688 * g) - (0.081312 * b);
}


