#include <iostream>
#ifndef EVENT_PARAM
#define EVENT_PARAM

enum EVENT_TYPE
{
    EVENT_UINT8 = 0,
    EVENT_UINT16,
    EVENT_UINT32,
    EVENT_UINT64,
    EVENT_STRING,
    EVENT_STRINGZ,
    EVENT_BLOB,
    EVENT_UNKNOWN
};

class EventParam
{
private:
    std::string name;
    EVENT_TYPE type;

public:
    // 构造函数、getter和setter方法
    EventParam(std::string n, EVENT_TYPE t) : name(n), type(t) {}
    std::string getName() const { return name; }
    EVENT_TYPE getType() const { return type; }
};

#endif