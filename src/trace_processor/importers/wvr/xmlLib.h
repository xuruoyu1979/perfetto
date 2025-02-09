#ifndef XML_LIB_H
#define XML_LIB_H

#include <map>
#include "EventParam.h"
#include "EventDescription.h"

namespace xmllib
{

    std::map<std::int16_t, EventDescription> getEventMap();

} // namespace xmllib

#endif // XML_LIB_H