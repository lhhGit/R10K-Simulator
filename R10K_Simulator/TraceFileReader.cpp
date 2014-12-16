//
//  TraceFileReader.cpp
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#include "TraceFileReader.h"
#include "Instruction.h"

int TraceFileReader::read(int count, Instruction** buf){
    int i = read_ptr;
    while (i < instrs.size() && i - read_ptr < count) {
        buf[i-read_ptr] = instrs[i];
        i++;
    }
    int true_count = i - read_ptr;
    read_ptr = i;
    return true_count;
}

void TraceFileReader::load(char* filename) {
    dummyLoad();
}

void TraceFileReader::dummyLoad(){
    int count = 5;
    for (int i=0; i<count; i++) {
        Instruction* instr = new Instruction();
        instr->intr_type = 'M';
        for (int j = 0; j<OPERAND_COUNT; j++) 
            instr->logicalIdx[j] = 1;
        instrs.push_back(instr);
    }
}

