//
//  ALUQueue.cpp
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#include "InstructionQueue.h"

bool InstructionQueue::isInstructionReady(Instruction *instr) {
    for (int i = 0; i < 2; i++) {
        if (this->regmgr->isBusy[instr->logicalIdx[i]]) {
            return false;
        }
    }
    return true;
}

void InstructionQueue::commitInstruction(Instruction* instr) {
    instr->isDone = true;
    if (aclist->getHead() == instr) {
        aclist->removeHead();
    }
    //some register should be put back to the freelist
}

Instruction* InstructionQueue::deliverInstruction() {
    for (auto instr : this->instrs) {
        if (isInstructionReady(instr)) {
            this->instrs.erase(instr);
            return instr;
        }
    }
    return NULL;
}

