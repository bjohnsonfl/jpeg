//
//  main.cpp
//  jpeg
//
//  Created by Blake Johnson on 9/16/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#include <iostream>
#include <string>

#include "jpeg.hpp"

#include "dct.hpp"
int main(int argc, const char * argv[]) {

    Jpeg jpeg("mandelBrot.ppm");
  
    

    
   
    double *** colors = new double ** [1];
   
        colors[0] = new double * [8];
        for( int j = 0; j<8; j++){
            colors[0][j] = new double [8];
        }
    
     double color [1][8][8]  = {
        {
            {52, 55, 61, 66, 70, 61, 64, 73},
            {63, 59, 55, 90,109, 85, 69, 72},
            {62, 59, 68,113,144,104, 66, 73},
            {63, 58, 71,122,154,106, 70, 69},
            {67, 61, 68,104,126, 88, 68, 70},
            {79, 65, 60, 70, 77, 68, 58, 75},
            {85, 71, 64, 59, 55, 61, 65, 83},
            {87, 79, 69, 68, 65, 76, 78, 94}
        }
    };
    
    for (int y = 0; y < 8; y++){
        for(int x = 0; x < 8; x++){
            colors[0][y][x] = color[0][y][x];
        }
    }
    
    DCT d;
    
    d.fdct(0, 0, 0, colors);
    

   
    
    return 0;
}
