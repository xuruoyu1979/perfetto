#ifndef WVR_LIB_H
#define WVR_LIB_H

#include <fstream>
#include <vector>
#include <map>
#include "xmlLib.h"
#include "EventDescription.h"
#include "EventParam.h"
#include "Event.h"

namespace wvrlib
{

    using namespace std;

    class WVRFileReader
    {
    private:
        std::map<std::int16_t, EventDescription> eventDescMap = xmllib::getEventMap();
        bool isLittleEndian = false;
        int32_t pos = 0;
        int64_t totalSize = 0;
        // int64_t currentTimestamp = 0;
        Event currentEvent = Event("",0,0,vector<Param>());

        vector<uint8_t> readPayload(const char* input, EVENT_TYPE type);
        int16_t readID(uint8_t buffer[2]){
            return readUINT16(buffer);
        }
        int32_t readTimeStamp(uint8_t buffer[4]){
            return readUINT32(buffer);
        }
        
        char hexDigit(uint8_t value)
        {
            if (value < 10)
            {
                return '0' + value;
            }
            else
            {
                return 'A' + (value - 10);
            }
        }

    public:
        WVRFileReader(int32_t start, int64_t total, bool isLEndian);
        bool parseEvent(const char* buffer);
        Event getCurrentEvent() const { return currentEvent; }
        uint16_t readUINT16(uint8_t buffer[2]);
        uint32_t readUINT32(uint8_t buffer[4]);
        uint64_t readUINT64(uint8_t buffer[8]);
        string bytesToString(const vector<uint8_t> &bytes)
        {
            string result;
            for (size_t i = 0; i < bytes.size(); ++i)
            {
                uint8_t byte = bytes[i];
                uint8_t high = (byte >> 4) & 0x0F;
                uint8_t low = byte & 0x0F;

                result += hexDigit(high);
                result += hexDigit(low);
            }
            return result;
        }
    };
} // namespace wvrlib

#endif // WVR_LIB_H