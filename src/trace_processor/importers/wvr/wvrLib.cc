#include "wvrLib.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>

namespace wvrlib {

using namespace std;

WVRFileReader::WVRFileReader(int32_t start, int64_t total, bool isLEndian) {
  pos = start;
  totalSize = total;
  isLittleEndian = isLEndian;
}

vector<uint8_t> WVRFileReader::readPayload(const char* input, EVENT_TYPE type) {
  vector<uint8_t> payload;
  switch (type) {
    case EVENT_TYPE::EVENT_UINT8: {
      uint8_t value[1];
      memcpy(value, input + pos, sizeof(value));
      pos += sizeof(value);
      payload.push_back(value[0]);
      break;
    }
    case EVENT_TYPE::EVENT_UINT16: {
      uint8_t value[2];
      memcpy(value, input + pos, sizeof(value));
      pos += sizeof(value);
      for (int i = 0; i < 2; ++i) {
        payload.push_back(value[i]);
      }
      break;
    }
    case EVENT_TYPE::EVENT_UINT32: {
      uint8_t value[4];
      memcpy(value, input + pos, sizeof(value));
      pos += sizeof(value);
      for (int i = 0; i < 4; ++i) {
        payload.push_back(value[i]);
      }
      break;
    }
    case EVENT_TYPE::EVENT_UINT64: {
      uint8_t value[8];
      memcpy(value, input + pos, sizeof(value));
      pos += sizeof(value);
      for (int i = 0; i < 8; ++i) {
        payload.push_back(value[i]);
      }
      break;
    }
    case EVENT_TYPE::EVENT_BLOB: {
      uint8_t buffer[4];
      memcpy(buffer, input + pos, sizeof(buffer));
      pos += sizeof(buffer);
      const int32_t length = readUINT32(buffer);
      const int32_t len = length & 0x1fffffff;
      const int32_t padding = length >> 29 & 0x7;
      const int32_t fixedlen = padding + len;
      uint8_t* value =
          static_cast<uint8_t*>(malloc(static_cast<size_t>(fixedlen)));
      memcpy(value, input + pos, fixedlen);
      pos += fixedlen;
      for (int i = 0; i < fixedlen; ++i) {
        payload.push_back(value[i]);
      }
      break;
    }
    default:
      std::cerr << "Unsupported EVENT_TYPE:" << type << std::endl;
      break;
  }
  return payload;
}

int16_t WVRFileReader::readUINT16(uint8_t bytes[2]) {
  if (isLittleEndian) {
    return static_cast<int16_t>((bytes[1] << 8) | bytes[0]);
  } else {
    return static_cast<int16_t>((bytes[0] << 8) | bytes[1]);
  }
}

int32_t WVRFileReader::readUINT32(uint8_t bytes[4]) {
  if (isLittleEndian) {
    return static_cast<int32_t>((bytes[3] << 24) | (bytes[2] << 16) |
                                (bytes[1] << 8) | bytes[0]);
  } else {
    return static_cast<int32_t>((bytes[0] << 24) | (bytes[1] << 16) |
                                (bytes[2] << 8) | bytes[3]);
  }
}

int64_t WVRFileReader::readUINT64(uint8_t bytes[8]) {
  if (isLittleEndian) {
    return ((uint64_t)bytes[7] << 56) | ((uint64_t)bytes[6] << 48) |
           ((uint64_t)bytes[5] << 40) | ((uint64_t)bytes[4] << 32) |
           ((uint64_t)bytes[3] << 24) | ((uint64_t)bytes[2] << 16) |
           ((uint64_t)bytes[1] << 8) | (uint64_t)bytes[0];
  } else {
    return ((uint64_t)bytes[0] << 56) | ((uint64_t)bytes[1] << 48) |
           ((uint64_t)bytes[2] << 40) | ((uint64_t)bytes[3] << 32) |
           ((uint64_t)bytes[4] << 24) | ((uint64_t)bytes[5] << 16) |
           ((uint64_t)bytes[6] << 8) | (uint64_t)bytes[7];
  }
}

bool WVRFileReader::parseEvent(const char* input) {
  if (pos == totalSize) {
    return false;
  }

  // 获取id
  uint8_t idBuffer[2];
  memcpy(idBuffer, input + pos, sizeof(idBuffer));
  pos += sizeof(idBuffer);
  const int16_t id = readID(idBuffer);
  auto it = eventDescMap.find(id);
  if (it == eventDescMap.end()) {
    cout << "找不到event id:" << id << "的定义" << std::endl;
    return false;
  }

  // 获取ticks
  int32_t ticks = 0;
  if (it->second.getHasTimeStamp()) {
    uint8_t tickBuffer[4];
    memcpy(tickBuffer, input + pos, sizeof(tickBuffer));
    pos += sizeof(tickBuffer);
    ticks = readTimeStamp(tickBuffer);
  }

  vector<Param> params = vector<Param>();
  for (const auto& paramDesc : it->second.getParams()) {
    vector<uint8_t> payload = readPayload(input, paramDesc.getType());

    Param param = Param(paramDesc.getName(), paramDesc.getType(), payload);
    params.push_back(param);
  }

  currentEvent = Event(it->second.getName(), id, ticks, params);
  return true;
}
}  // namespace wvrlib
