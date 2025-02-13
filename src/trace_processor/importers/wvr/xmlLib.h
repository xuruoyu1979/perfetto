#ifndef XML_LIB_H
#define XML_LIB_H

#include <map>
#include "EventDescription.h"
#include "EventParam.h"

namespace xmllib {

std::map<std::int16_t, EventDescription> getEventMap(std::uint32_t revisionId);
}  // namespace xmllib

#endif  // XML_LIB_H