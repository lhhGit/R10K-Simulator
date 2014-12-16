//
//  Decoder.cpp
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#include "Decoder.h"
int Decoder::decode() {
    Instruction** buf = new Instruction*[MAX_COUNT];
    //first try to dispatch the instructions left from the previous step.
    int decodedCount = 0;
    unordered_set<Instruction*> toRemove;
    //It is probably wrong, because it may not give preference to early instructions
    //Decoding stops if the active list or a queue becomes full ??
    //When multiple ready to decode, which ones should I choose?
    for (auto instr : pendingIntrs) {
        if (decodedCount == MAX_COUNT) {
            break;
        }
        if (dispatch(instr)) {
            decodedCount++;
            toRemove.insert(instr);
        }
    }
    
    for (auto instr : toRemove) {
        pendingIntrs.erase(instr);
    }
    
    int trueCount = this->reader->read(MAX_COUNT, buf);
    for (int j=0; j<trueCount; j++) {
        if (decodedCount == MAX_COUNT) break;
        if (dispatch(buf[j])) {
            decodedCount++;
        } else {
            pendingIntrs.insert(buf[j]);
        }
    }
    return decodedCount;
}

bool Decoder::dispatch(Instruction *instr) {
    // for each instruction, dispatch to according instruction queues according to their type
    switch (instr->getType()) {
        case FLOAT:
            if (fp_queue->isFull()) {
                return false;
            } else {
                fp_queue->addInstruction(instr);
            }
            break;
        case INTEGER:
            if (integer_queue->isFull()) {
                return false;
            } else {
                integer_queue->addInstruction(instr);
            }
            break;
        case ADDR:
            if (addr_queue->isFull()) {
                return false;
            } else {
                addr_queue->addInstruction(instr);
            }
    }
    logger->addLog(instr, 'I');
    return true;
}