//
//  dct.cpp
//  jpeg
//
//  Created by Blake Johnson on 10/23/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#include "dct.hpp"




void DCT::fdct(int xPix, int yPix, int chan, double *** colors){
    //configure internal object parameters
    i = xPix;
    j = yPix;
    channel = chan;
  
   
    levelShift(colors);
   
    
    
    int u = 0, v = 0, x = 0, y = 0;
    
    
}


//Shift all values around zero before doing the dct.
//if there are 8 bits per channel, than the mid point is 128, so subtract that

void DCT::levelShift(double *** colors){
    
    for (int y = i; y < n; y++){
        for(int x = j; x < m; x++){
            colors[channel][y][x] -= 128;
        }
    }
}




//DEBUG
void DCT::printBlock(double ***colors){
    for (int y = i; y < n; y++){
        for(int x = j; x < m; x++){
            std::cout << colors[channel][y][x] << " ";
        }
        std::cout << std::endl;
    }
}
