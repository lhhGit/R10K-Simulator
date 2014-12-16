//
//  Logger.h
//  R10K_Simulator
//
//  Created by lhh on 12/15/14.
//  Copyright (c) 2014 UCSD. All rights reserved.
//

#ifndef __R10K_Simulator__Logger__
#define __R10K_Simulator__Logger__
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Instruction.h"

class ActionTimePair {
public:
    int cycle;
    char stage;
};

class Entry {
public:
    vector<ActionTimePair> pipeline_history;
    void addAction(int cycle, char stage) {
        ActionTimePair atPair;
        atPair.cycle = cycle;
        atPair.stage = stage;
        pipeline_history.push_back(atPair);
    }
};

class Logger {
private:
    unordered_map<Instruction*, Entry> instr_log;
    int currentCycle;
public:
    void addLog(Instruction* instr, char stage) {
        if (instr_log.find(instr) == instr_log.end()) {
            Entry entry;
            instr_log.insert({instr, entry});
        }
        instr_log[instr].addAction(currentCycle, stage);
    }
    void increment() {
        currentCycle++;
    }
    void print() {
        for (auto kv : instr_log) {
            for (auto at_pair : kv.second.pipeline_history) {
                cout<<at_pair.stage<<','<<at_pair.cycle<<' ';
            }
            cout<<endl;
        }
    }
};
#endif /* defined(__R10K_Simulator__Logger__) */
