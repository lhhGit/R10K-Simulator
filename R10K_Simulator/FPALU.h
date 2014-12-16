//
//  ALU.h
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#ifndef __R10K_Simulator__FPALU__
#define __R10K_Simulator__FPALU__
using namespace std;
#include <iostream>
#include "ALU.h"

class FPALU : public ALU {
private:
    ALU* alu;
    Instruction* stage1_instr;
    Instruction* stage2_instr;
public:
    void execute();
    FPALU(Logger* logger, InstructionQueue* instr_queue,
          RegisterManager* reg_mgr) : ALU(logger, instr_queue, reg_mgr) {}
};
#endif /* defined(__R10K_Simulator__FPALU__) */
