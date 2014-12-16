//
//  ALUQueue.h
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#ifndef __R10K_Simulator__ALUQueue__
#define __R10K_Simulator__ALUQueue__
using namespace std;
#include <iostream>
#include <unordered_set>
#include "Instruction.h"
#include "ActiveList.h"
#include "RegisterManager.h"
#define CAPACITY 16
class InstructionQueue {
private:
    unordered_set<Instruction*> instrs;
    ActiveList* aclist;
    RegisterManager* regmgr;
    bool isInstructionReady(Instruction* instr);
public:
    InstructionQueue(ActiveList* aclist, RegisterManager* regmgr) {
        this->aclist = aclist;
        this->regmgr = regmgr;
    }
    bool isFull() { return instrs.size() == CAPACITY;}

    //for a decoded instruction, adding into the instruction queue and
    //active list, creates the mapping between logical and physical
    //registers
    void addInstruction(Instruction* instr) {
        instrs.insert(instr);
        //what happens when we run out of physical registers?
        for (int i=0; i<OPERAND_COUNT; i++) {
            instr->physicalIdx[i] = regmgr->freelist.front();
            regmgr->freelist.pop();
        }
        //aclist may be full
        aclist->append(instr);
    }
    
    //called by ALU when an instruction is finished
    //mark the corresponding entry in the active list as DONE
    //updates the busy tables
    void commitInstruction(Instruction* str);
    
    //called by ALU to execute a ready instruction
    //and remove it from instruction queue
    
    //If multiple ready, which one should I choose?
    Instruction* deliverInstruction();
};
#endif /* defined(__R10K_Simulator__ALUQueue__) */
