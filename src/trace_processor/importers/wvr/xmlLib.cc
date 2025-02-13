#include "xmlLib.h"
#include <iostream>
#include <map>
#include "tinyxml2.h"
#include "v764smpdefXML.h"
#include "v732smpdefXML.h"

namespace xmllib {
using namespace std;
using namespace tinyxml2;

std::map<std::uint32_t, std::map<std::int16_t, EventDescription>> allEventMap;
bool isInitialized = false;

std::string vx764xmls[26] = {v7_64_smp_apexlib_xml,
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

std::string vx732xmls[26] = {v7_32_smp_apexlib_xml,
                                v7_32_smp_dprintf_xml,
                                v7_32_smp_edr_xml,
                                v7_32_smp_ioLib_xml,
                                v7_32_smp_isrlib_xml,
                                v7_32_smp_memlib_xml,
                                v7_32_smp_netdlib_xml,
                                v7_32_smp_objlib_xml,
                                v7_32_smp_pidia_xml,
                                v7_32_smp_powerMng_xml,
                                v7_32_smp_rtplib_xml,
                                v7_32_smp_rtpSignals_xml,
                                v7_32_smp_salLib_xml,
                                v7_32_smp_scopetools_xml,
                                v7_32_smp_sdLib_xml,
                                v7_32_smp_sensorpoint_xml,
                                v7_32_smp_syscalls_syn_xml_part1,
                                v7_32_smp_syscalls_syn_xml_part2,
                                v7_32_smp_syscalls_xml,
                                v7_32_smp_tipclib_xml,
                                v7_32_smp_usbHost_xml,
                                v7_32_smp_usbPeripheral_xml,
                                v7_32_smp_user_xml,
                                v7_32_smp_vxdcom_xml,
                                v7_32_smp_vxworks_xml,
                                v7_32_smp_wrsvCoreEvents_xml};

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
    // initial xml definition for vxworks7 64bit.
    uint32_t v764smpRevId = 0xB1C2C000;
    uint32_t v764RevId = 0xB1C24000;
    std::map<int16_t, EventDescription> v764EventMap;

    for (const auto& xml : vx764xmls) {
      std::map<int16_t, EventDescription> eventMap = parseXml(xml);
      for (const auto& pair : eventMap) {
        v764EventMap[pair.first] = pair.second;
      }
    }

    allEventMap[v764smpRevId] = v764EventMap;
    allEventMap[v764RevId] = v764EventMap;

    // initial xml definition for vxworks7 32bit.
    uint32_t v732smpRevId = 0xB1C28000;
    uint32_t v732RevId = 0xB1C20000;
    std::map<int16_t, EventDescription> v732EventMap;

    for (const auto& xml : vx732xmls) {
      std::map<int16_t, EventDescription> eventMap = parseXml(xml);
      for (const auto& pair : eventMap) {
        v732EventMap[pair.first] = pair.second;
      }
    }

    allEventMap[v732smpRevId] = v732EventMap;
    allEventMap[v732RevId] = v732EventMap;

    isInitialized = true;
  }
  return allEventMap[revisionId];
}

}  // namespace xmllib