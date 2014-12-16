//
//  RegisterManager.h
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//
//  Maintains the logical and physical register mapping
//  Maintains the busy table
//  Maintains the free list

#ifndef __R10K_Simulator__RegisterManager__
#define __R10K_Simulator__RegisterManager__

#define PHYSICAL_COUNT 64
#define LOGICAL_COUNT 32
#include <iostream>
#include <queue>
class RegisterManager {
public:
    int physicalReg[LOGICAL_COUNT]; //mapping from logical register to physical, 32 entries
    float regValue[PHYSICAL_COUNT]; //the values in 64 registers
    bool isBusy[LOGICAL_COUNT]; //Indicator whether each physical register contains a valid value
    std::queue<int> freelist; //maintains a free list of available physical registers.
    RegisterManager() {
        for (int i=0; i<PHYSICAL_COUNT; i++)
            freelist.push(i);
        for (int i=0; i<LOGICAL_COUNT; i++)
            isBusy[i] = false;
    }
};
#endif /* defined(__R10K_Simulator__RegisterManager__) */
