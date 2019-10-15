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


int main(int argc, const char * argv[]) {

    Jpeg jpeg("mandelBrot.ppm");
  
    
    int var = 5;
    
    int * arr = new int [var];
    arr[2] = 5;
    std::cout << "hold" << arr[2];
    
    return 0;
}
