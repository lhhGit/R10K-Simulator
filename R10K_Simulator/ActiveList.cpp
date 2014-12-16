//
//  ActiveList.cpp
//  R10K_Simulator
//
//  Created by lhh on 12/14/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#include "ActiveList.h"

Instruction* ActiveList::removeHead(){
    Instruction* instr = this->myqueue.front();
    myqueue.pop();
    return instr;
}

void ActiveList::append(Instruction *instr){
    myqueue.push(instr);
}