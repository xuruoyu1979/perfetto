#ifndef WVR_LIB_H
#define WVR_LIB_H

#include <fstream>
#include <map>
#include <vector>
#include "Event.h"
#include "EventDescription.h"
#include "EventParam.h"
#include "xmlLib.h"

namespace wvrlib {

using namespace std;

class WVRFileReader {
 private:
  std::map<std::int16_t, EventDescription> eventDescMap;
  bool isLittleEndian = false;
  int32_t pos = 0;
  int64_t totalSize = 0;
  int32_t currentEventSize = 0;
  Event currentEvent = Event("", 0, 0, vector<Param>());

  vector<uint8_t> readPayload(const char* input, EVENT_TYPE type);
  int16_t readID(uint8_t buffer[2]) { return readUINT16(buffer); }
  int32_t readTimeStamp(uint8_t buffer[4]) { return readUINT32(buffer); }

  char hexDigit(uint8_t value) {
    if (value < 10) {
      return '0' + value;
    } else {
      return 'A' + (value - 10);
    }
  }

 public:
  WVRFileReader(int32_t start,
                int64_t total,
                bool isLEndian,
                uint32_t revisionId);
  bool parseEvent(const char* buffer);
  Event getCurrentEvent() const { return currentEvent; }
  uint32_t getCurrentEventSize() const { return currentEventSize; }
  uint16_t readUINT16(uint8_t buffer[2]);
  uint32_t readUINT32(uint8_t buffer[4]);
  uint64_t readUINT64(uint8_t buffer[8]);
  uint64_t readUINT(Param param) {
    if (param.getType() == EVENT_UINT16) {
      uint8_t bytes[2];
      memcpy(bytes, param.getPayload().data(), 2);
      return readUINT16(bytes);
    } else if (param.getType() == EVENT_UINT32) {
      uint8_t bytes[4];
      memcpy(bytes, param.getPayload().data(), 4);
      return readUINT32(bytes);
    } else if (param.getType() == EVENT_UINT64) {
      uint8_t bytes[8];
      memcpy(bytes, param.getPayload().data(), 8);
      return readUINT64(bytes);
    }
    return 0;
  }
  string bytesToString(const vector<uint8_t>& bytes) {
    string result;
    for (size_t i = 0; i < bytes.size(); ++i) {
      uint8_t byte = bytes[i];
      uint8_t high = (byte >> 4) & 0x0F;
      uint8_t low = byte & 0x0F;

      result += hexDigit(high);
      result += hexDigit(low);
    }
    return result;
  }

  string toPrintableString(const std::vector<uint8_t>& buffer) {
    std::string result;
    for (size_t i = 0; i < buffer.size(); ++i) {
      unsigned char c = static_cast<unsigned char>(buffer[i]);
      if (!isprint(c)) {
        break;
      }
      result += static_cast<char>(c);
    }
    return result;
  }
};
}  // namespace wvrlib

#endif  // WVR_LIB_H