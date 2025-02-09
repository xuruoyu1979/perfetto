#include <iostream>
#include <vector>
#include "EventParam.h"

#ifndef EVENT_DESCRIPTION
#define EVENT_DESCRIPTION

class EventDescription
{
private:
    std::string id;
    bool hasTimeStamp = true;
    std::string name;
    std::vector<EventParam> params;

public:
    // 构造函数、getter和setter方法
    void setId(std::string i) { id = i; }
    std::string getId() const { return id; }
    void setHasTimeStamp(bool b) { hasTimeStamp = b; }
    bool getHasTimeStamp() { return hasTimeStamp; }
    void setName(std::string n) { name = n; }
    std::string getName() const { return name; }
    void addParam(EventParam p) { params.push_back(p); }
    const std::vector<EventParam> &getParams() const { return params; }
};

#endif