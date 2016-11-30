#ifndef _ROS_melle_ArduinoSensorData_h
#define _ROS_melle_ArduinoSensorData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace melle
{

  class ArduinoSensorData : public ros::Msg
  {
    public:
      int8_t binFullness;
      int8_t batteryLevel;

    ArduinoSensorData():
      binFullness(0),
      batteryLevel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_binFullness;
      u_binFullness.real = this->binFullness;
      *(outbuffer + offset + 0) = (u_binFullness.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->binFullness);
      union {
        int8_t real;
        uint8_t base;
      } u_batteryLevel;
      u_batteryLevel.real = this->batteryLevel;
      *(outbuffer + offset + 0) = (u_batteryLevel.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->batteryLevel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_binFullness;
      u_binFullness.base = 0;
      u_binFullness.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->binFullness = u_binFullness.real;
      offset += sizeof(this->binFullness);
      union {
        int8_t real;
        uint8_t base;
      } u_batteryLevel;
      u_batteryLevel.base = 0;
      u_batteryLevel.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->batteryLevel = u_batteryLevel.real;
      offset += sizeof(this->batteryLevel);
     return offset;
    }

    const char * getType(){ return "melle/ArduinoSensorData"; };
    const char * getMD5(){ return "78ac0557f2be5bfe3f1764f8836b3aca"; };

  };

}
#endif