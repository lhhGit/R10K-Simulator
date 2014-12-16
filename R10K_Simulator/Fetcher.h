//
//  Fetcher.h
//  R10K_Simulator
//
//  Created by lhh on 12/16/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#ifndef __R10K_Simulator__Fetcher__
#define __R10K_Simulator__Fetcher__

#include <iostream>
#include "TraceFileReader.h"
#include "Logger.h"
#include "Params.h"
class Fetcher {
private:
    TraceFileReader* reader;
    Logger* logger;
    Instruction* buf[FETCH_COUNT];
    int instr_count;

public:
    //called by decoder
    int pull(int count, Instruction** outbuf) {
        for (int i=0; i<instr_count; i++)
            outbuf[i] = buf[i];
        return instr_count;
    }
    
    //calc
    void fetch(int count) {
        instr_count = this->reader->read(FETCH_COUNT, buf);
    }
};
#endif /* defined(__R10K_Simulator__Fetcher__) */
