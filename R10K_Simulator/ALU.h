//
//  ALU.h
//  R10K_Simulator
//
//  Created by lhh on 12/15/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#ifndef __R10K_Simulator__ALU__
#define __R10K_Simulator__ALU__
#include <iostream>
#include "InstructionQueue.h"
#include "Logger.h"
#include "RegisterManager.h"

enum ALUType {
    ADD, MULTIPLY
};

class ALU {
protected:
    InstructionQueue* upstream_queue;
    Logger* logger;
    RegisterManager* reg_mgr;
    ALUType type;
public:
    virtual void execute()=0;
    ALU(Logger* logger, InstructionQueue* instr_queue,
               RegisterManager* reg_mgr) {
        this->logger = logger;
        this->upstream_queue = instr_queue;
        this->reg_mgr = reg_mgr;
    }
};
#endif /* defined(__R10K_Simulator__ALU__) */
