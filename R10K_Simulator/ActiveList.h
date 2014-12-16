//
//  ActiveList.h
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#ifndef __R10K_Simulator__ActiveList__
#define __R10K_Simulator__ActiveList__

#include <iostream>
#include "Instruction.h"
#include <queue>
//In active list, the instructions are sorted in the ascending order of timestamp
class ActiveList {
private:
    std::queue<Instruction*> myqueue;
public:
    //only remove the head of queue when it is committed
    Instruction* removeHead();
    void append(Instruction* instr);
    Instruction* getHead() {return myqueue.front();}
};
#endif /* defined(__R10K_Simulator__ActiveList__) */
