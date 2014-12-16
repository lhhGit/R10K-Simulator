//
//  main.cpp
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#include <iostream>
#include "TraceFileReader.h"
#include "Decoder.h"
#include "FPALU.h"
int main(int argc, const char * argv[])
{
    TraceFileReader reader;
    ActiveList aclist;
    RegisterManager reg_mgr;
    InstructionQueue fp_queue(&aclist, &reg_mgr);
    InstructionQueue integer_queue(&aclist, &reg_mgr);
    InstructionQueue addr_queue(&aclist, &reg_mgr);
    Logger logger;
    Decoder decoder(&logger, &reader, &fp_queue, &addr_queue, &integer_queue);
    FPALU fp_add(&logger, &fp_queue, &reg_mgr);
    FPALU fp_mul(&logger, &fp_queue, &reg_mgr);
    
    char* filename = "testFile.trace";
    reader.load(filename);
    for (int i=0; i<10; i++) {
        fp_add.execute();
        fp_mul.execute();
        decoder.decode();
        logger.increment();
    }
    logger.print();
    return 0;
}

