//
//  main.cpp
//  gtest
//
//  Created by Selvaraj Palaniyappan on 17/07/22.
//
#include <gtest/gtest.h>
#include <iostream>

int main(int ac, char* av[]) {
    // insert code here...
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
    
}
