//
//  Decoder.h
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//
using namespace std;

#ifndef __R10K_Simulator__Decoder__
#define __R10K_Simulator__Decoder__
#include <iostream>
#include <vector>
#include <unordered_set>
#include "Instruction.h"
#include "TraceFileReader.h"
#include "InstructionQueue.h"
#include "Logger.h"
#define MAX_COUNT 1
//In fact, it should be called issuer
class Decoder {
private:
    Logger* logger;
    TraceFileReader* reader;
    //store the instructions that could not be decoded in the previous cycle
    Instruction** remainder[MAX_COUNT];
    bool isFree[MAX_COUNT];
    int remainderCount;
    
    unordered_set<Instruction*> pendingIntrs;
    InstructionQueue* fp_queue;
    InstructionQueue* addr_queue;
    InstructionQueue* integer_queue;
    bool dispatch(Instruction* instr);
public:
    Decoder(Logger* logger,
            TraceFileReader* reader, InstructionQueue* fp_queue,
            InstructionQueue* addr_queue,
            InstructionQueue* integer_queue) {
        this->logger = logger;
        this->reader = reader;
        this->fp_queue = fp_queue;
        this->addr_queue = addr_queue;
        this->integer_queue = integer_queue;
    }
    int decode();
};
#endif /* defined(__R10K_Simulator__Decoder__) */
