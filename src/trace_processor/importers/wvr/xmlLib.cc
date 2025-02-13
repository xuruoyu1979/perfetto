#include "xmlLib.h"
#include <iostream>
#include <map>
#include "tinyxml2.h"
#include "v764smpdefXML.h"

namespace xmllib {
using namespace std;
using namespace tinyxml2;

std::map<std::uint32_t, std::map<std::int16_t, EventDescription>> allEventMap;
bool isInitialized = false;

std::string vx764smpxmls[26] = {v7_64_smp_apexlib_xml,
                                v7_64_smp_dprintf_xml,
                                v7_64_smp_edr_xml,
                                v7_64_smp_iolib_xml,
                                v7_64_smp_isrlib_xml,
                                v7_64_smp_memlib_xml,
                                v7_64_smp_netdlib_xml,
                                v7_64_smp_objlib_xml,
                                v7_64_smp_pidia_xml,
                                v7_64_smp_powerMng_xml,
                                v7_64_smp_rtplib_xml,
                                v7_64_smp_rtpSignals_xml,
                                v7_64_smp_salib_xml,
                                v7_64_smp_scopetools_xml,
                                v7_64_smp_sdlib_xml,
                                v7_64_smp_sensorpoint_xml,
                                v7_64_smp_syscallws_syn_xml_part1,
                                v7_64_smp_syscallws_syn_xml_part2,
                                v7_64_smp_syscalls_xml,
                                v7_64_smp_tipclib_xml,
                                v7_64_smp_usbHost_xml,
                                v7_64_smp_usbPeripheral_xml,
                                v7_64_smp_user_xml,
                                v7_64_smp_vxdcom_xml,
                                v7_64_smp_vxworks_xml,
                                v7_64_smp_wrsvCoreEvents_xml};

std::map<int16_t, EventDescription> parseXml(const std::string& xmlString) {
  std::map<int16_t, EventDescription> eventMap;
  // 初始化 XML 文档对象
  XMLDocument doc;

  // 加载 XML 数据
  XMLError error = doc.Parse(xmlString.c_str(), xmlString.size());
  if (error != XML_SUCCESS) {
    std::cout << "XML 解析失败!" << error << std::endl;
    return eventMap;
  }

  XMLElement* root = doc.RootElement();

  // 遍历 EventClass
  for (XMLElement* eventClass = root->FirstChildElement("EventClass");
       eventClass; eventClass = eventClass->NextSiblingElement()) {
    // std::cout << "EventClass 开始..." << std::endl;

    // 获取 EventDescription 元素
    for (XMLElement* eventDesc =
             eventClass->FirstChildElement("EventDescription");
         eventDesc; eventDesc = eventDesc->NextSiblingElement()) {
      std::string eventId = eventDesc->Attribute("id");
      uint16_t id = stol(eventId);

      EventDescription ed;
      ed.setId(eventId);
      ed.setName(eventDesc->Attribute("name"));
      if (eventDesc->Attribute("hasTimeStamp") &&
          std::string(eventDesc->Attribute("hasTimeStamp")) == "false") {
        ed.setHasTimeStamp(false);
      }

      // 遍历 EventParam 参数
      for (XMLElement* param = eventDesc->FirstChildElement("EventParam");
           param; param = param->NextSiblingElement()) {
        EVENT_TYPE type = EVENT_UINT8;
        std::string typeStr = param->Attribute("type");

        if (typeStr == "UINT8") {
          type = EVENT_UINT8;
        } else if (typeStr == "UINT16") {
          type = EVENT_UINT16;
        } else if (typeStr == "UINT32") {
          type = EVENT_UINT32;
        } else if (typeStr == "UINT64") {
          type = EVENT_UINT64;
        } else if (typeStr == "STRING") {
          type = EVENT_STRING;
        } else if (typeStr == "STRINGZ") {
          type = EVENT_STRINGZ;
        } else if (typeStr == "BLOB") {
          type = EVENT_BLOB;
        }
        EventParam ep(param->Attribute("name"), type);
        ed.addParam(ep);
      }

      eventMap[id] = ed;
    }
  }

  return eventMap;
}

std::map<int16_t, EventDescription> getEventMap(uint32_t revisionId) {
  if (!isInitialized) {
    uint32_t v764smpRevId = 0xB1C2C000;
    std::map<int16_t, EventDescription> v764smpEventMap;

    for (const auto& xml : vx764smpxmls) {
      std::map<int16_t, EventDescription> eventMap = parseXml(xml);
      for (const auto& pair : eventMap) {
        v764smpEventMap[pair.first] = pair.second;
      }
    }

    allEventMap[v764smpRevId] = v764smpEventMap;
    isInitialized = true;
  }
  return allEventMap[revisionId];
}

}  // namespace xmllib