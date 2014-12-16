//
//  ALU.cpp
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#include "FPALU.h"
void FPALU::execute() {
    //pop out the instruction at the last stage,
    //only do that when the queue is full
    if (stage2_instr != NULL) {
        //update the register table
        float result = 0;
        switch (type) {
            case ADD:
                result = reg_mgr->regValue[stage2_instr->physicalIdx[0]] +
                reg_mgr->regValue[stage2_instr->physicalIdx[1]];
                break;
            case FLOAT:
                result = reg_mgr->regValue[stage2_instr->physicalIdx[0]] +
                reg_mgr->regValue[stage2_instr->physicalIdx[1]];
                break;
            default:
                break;
        }
        reg_mgr->regValue[stage2_instr->physicalIdx[2]] = result;
        reg_mgr->isBusy[stage2_instr->physicalIdx[2]] = false;
        logger->addLog(stage2_instr, 'W');
        this->upstream_queue->commitInstruction(stage2_instr);
    }
    stage2_instr = stage1_instr;
    //push in a new instruction
    stage1_instr = upstream_queue->deliverInstruction();
    if (stage1_instr!=NULL) {
        logger->addLog(stage1_instr, 'E');
    }
}