#include <iostream>
#include "EventParam.h"
#include <vector>
#ifndef PARAM
#define PARAM

using namespace std;

class Param
{
private:
    string name;
    EVENT_TYPE type;
    vector<uint8_t> payload;

public:
    // 构造函数、getter和setter方法
    Param(std::string n, EVENT_TYPE t,  vector<uint8_t> p) : name(n), type(t), payload(p) {}
    string getName() const { return name; }
    EVENT_TYPE getType() const { return type; }
    vector<uint8_t> getPayload() const { return payload; }
};

#endif