//
//  TraceFileReader.h
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#ifndef __R10K_Simulator__TraceFileReader__
#define __R10K_Simulator__TraceFileReader__

#include <iostream>
#include "Instruction.h"
#include <vector>

class TraceFileReader {
public:
    int read(int count, Instruction** buf);
    void load(char* filename);
private:
    std::vector<Instruction*> instrs;
    int read_ptr;
    void dummyLoad();
};

#endif /* defined(__R10K_Simulator__TraceFileReader__) */
