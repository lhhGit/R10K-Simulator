//
//  IntALU.h
//  R10K_Simulator
//
//  Created by lhh on 12/15/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#ifndef __R10K_Simulator__IntALU__
#define __R10K_Simulator__IntALU__
#include "ALU.h"
#include <iostream>
class IntALU : public ALU {
public:
    void execute();
    IntALU(Logger* logger, InstructionQueue* instr_queue,
           RegisterManager* reg_mgr) : ALU(logger, instr_queue, reg_mgr) {}
};
#endif /* defined(__R10K_Simulator__IntALU__) */
