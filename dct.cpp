//
//  dct.cpp
//  jpeg
//
//  Created by Blake Johnson on 10/23/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#include "dct.hpp"
#include <iomanip>



void DCT::fdct(int xPix, int yPix, int chan, double *** colors){
    //configure internal object parameters
    i = xPix;
    j = yPix;
    channel = chan;
  
   //orient every pixel value around zero
    printBlock(colors);
    levelShift(colors);
    printBlock(colors);
    /*
     Take the dct of every pixel in the nxn block. This requires
     iterating over every Suv value where u and v range from 0 to 8.
     u and v correlate to an X and Y pixel in the colors array. (xPix, yPix)
     is the top left pixel in the nxn block, essentially an offset. Add
     i + u and and j + v to get a coordinate for the colors array. Because of
     the repeating nature of the dct, a holding array to store the new Suv
     values will be needed as not to overwrite the old colors values.
     */
    
    
    //Initialize holding array
    double Suv [8][8];
    
    
    //fdctFunc(0, 0, Suv, colors);
    
   // printBlock(Suv);
    
    for (int v = 0; v < 8; v++){
        for (int u = 0; u < 8; u++){
            fdctFunc(u, v, Suv, colors);
            
        
        }
    }
    
    
    printBlock(Suv);
}


void DCT::fdctFunc(int u, int v, double Suv [8][8],  double *** colors){
    
    double S = 0, Cu = 1, Cv = 1, inner = 0, outer = 0, theta = 0, sum = 0;
    double coef [8][8];
    
    if(u == 0) Cu = Cuv;
    if(v == 0) Cv = Cuv;
    
    S = 0.25 * Cu * Cv;
    
    
    for (int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            theta = ((2 * x) + 1) * u * Pi;
           coef[y][x] = colors[channel][y + j][x + i] * std::cos(theta / 16);
            theta = ((2 * y) + 1) * v * Pi;
           coef[y][x] *= std::cos(theta / 16);
            sum += coef[y][x];
        }
    }
    
    S *= sum;
    
    Suv [v][u] = S;
    
    
    
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

void DCT::quantize(double ***colors)
{
    
    
}



//DEBUG
void DCT::printBlock(double ***colors){
    std::cout << "\n";
    for (int y = i; y < n; y++){
        for(int x = j; x < m; x++){
            std::cout << colors[channel][y][x] << " ";
        }
        std::cout << std::endl;
    }
}

//DEBUG
void DCT::printBlock(double colors [8][8]){
    std::cout <<std::setprecision(4) <<"\n";
    for (int y = i; y < n; y++){
        for(int x = j; x < m; x++){
            std::cout << colors[y][x] << " ";
        }
        std::cout << std::endl;
    }
}
