//
//  Instruction.h
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#ifndef __R10K_Simulator__Instruction__
#define __R10K_Simulator__Instruction__

#include <iostream>
#define OPERAND_COUNT 3
enum Type {ADDR, FLOAT, INTEGER};

class Instruction {
public:
    //the logical, physical register index
    int*  logicalIdx;
    int*  physicalIdx;
    int  ALTag;
    //instruction type
    char intr_type;
    bool isDone;
    void commit();
    Instruction() {
        logicalIdx = new int[OPERAND_COUNT];
        physicalIdx = new int[OPERAND_COUNT];
        ALTag = -1;
    }
    
    Type getType() {
        switch (this->intr_type) {
            case 'M':
            case 'A':
                return FLOAT;
            case 'L':
            case 'S':
                return ADDR;
            case 'I':
                return INTEGER;
        }
        return INTEGER;
    }
    
};


#endif /* defined(__R10K_Simulator__Instruction__) */
