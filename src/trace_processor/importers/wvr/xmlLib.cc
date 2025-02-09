#include <map>
#include <iostream>
#include "tinyxml2.h"
#include "xmlLib.h"
#include "defXML.h"

namespace xmllib
{
    using namespace tinyxml2;

    std::map<int16_t, EventDescription> eventMap;

    bool isInitialized = false;

    void parseXml(const std::string &xmlString)
    {
        // 初始化 XML 文档对象
        XMLDocument doc;

        // 加载 XML 数据
        XMLError error = doc.Parse(xmlString.c_str(), xmlString.size());
        if (error != XML_SUCCESS)
        {
            std::cout << "XML 解析失败!" << error << std::endl;
            return;
        }

        XMLElement *root = doc.RootElement();

        // 遍历 EventClass
        for (XMLElement *eventClass = root->FirstChildElement("EventClass"); eventClass; eventClass = eventClass->NextSiblingElement())
        {
            // std::cout << "EventClass 开始..." << std::endl;

            // 获取 EventDescription 元素
            for (XMLElement *eventDesc = eventClass->FirstChildElement("EventDescription"); eventDesc; eventDesc = eventDesc->NextSiblingElement())
            {
                std::string eventId = eventDesc->Attribute("id");
                uint16_t id = stol(eventId);

                EventDescription ed;
                ed.setId(eventId);
                ed.setName(eventDesc->Attribute("name"));
                if (eventDesc->Attribute("hasTimeStamp") && std::string(eventDesc->Attribute("hasTimeStamp")) == "false")
                {
                    ed.setHasTimeStamp(false);
                }

                // 遍历 EventParam 参数
                for (XMLElement *param = eventDesc->FirstChildElement("EventParam"); param; param = param->NextSiblingElement())
                {
                    EVENT_TYPE type = EVENT_UINT8;
                    std::string typeStr = param->Attribute("type");

                    if (typeStr == "UINT8")
                    {
                        type = EVENT_UINT8;
                    }
                    else if (typeStr == "UINT16")
                    {
                        type = EVENT_UINT16;
                    }
                    else if (typeStr == "UINT32")
                    {
                        type = EVENT_UINT32;
                    }
                    else if (typeStr == "UINT64")
                    {
                        type = EVENT_UINT64;
                    }
                    else if (typeStr == "STRING")
                    {
                        type = EVENT_STRING;
                    }
                    else if (typeStr == "STRINGZ")
                    {
                        type = EVENT_STRINGZ;
                    }
                    else if (typeStr == "BLOB")
                    {
                        type = EVENT_BLOB;
                    }
                    EventParam ep(param->Attribute("name"), type);
                    ed.addParam(ep);
                }

                eventMap[id] = ed;
            }
        }

        return;
    }

    std::map<int16_t, EventDescription> getEventMap()
    {
        if (!isInitialized)
        {
            parseXml(apexlib_xml);
            parseXml(dprintf_xml);
            parseXml(edr_xml);
            parseXml(iolib_xml);
            parseXml(isrlib_xml);
            parseXml(memlib_xml);
            parseXml(netdlib_xml);
            parseXml(objlib_xml);
            parseXml(pidia_xml);
            parseXml(powerMng_xml);
            parseXml(rtplib_xml);
            parseXml(rtpSignals_xml);
            parseXml(salib_xml);
            parseXml(scopetools_xml);
            parseXml(sdlib_xml);
            parseXml(sensorpoint_xml);
            parseXml(syscallws_syn_xml_part1);
            parseXml(syscallws_syn_xml_part2);
            parseXml(syscalls_xml);
            parseXml(tipclib_xml);
            parseXml(usbHost_xml);
            parseXml(usbPeripheral_xml);
            parseXml(user_xml);
            parseXml(vxdcom_xml);
            parseXml(vxworks_xml);
            parseXml(wrsvCoreEvents_xml);
            isInitialized = true;
        }
        return eventMap;
    }

}