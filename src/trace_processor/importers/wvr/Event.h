#include <iostream>
#include "EventParam.h"
#include <vector>
#include "Param.h"
#ifndef EVENT
#define EVENT

using namespace std;

class Event
{
private:
    string name;
    uint16_t id;
    int32_t ticks;
    vector<Param> params;

public:
    // 构造函数、getter和setter方法
    Event(string n, uint16_t i, int32_t t,  vector<Param> p) : name(n), id(i), ticks(t), params(p) {}
    string getName() const { return name; }
    uint16_t getId() const { return id; }
    int32_t getTicks() const { return ticks; }
    vector<Param> getParams() const { return params; }
};

#endif