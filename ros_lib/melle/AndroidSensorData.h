#ifndef _ROS_melle_AndroidSensorData_h
#define _ROS_melle_AndroidSensorData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace melle
{

  class AndroidSensorData : public ros::Msg
  {
    public:
      float latitude;
      float longitude;
      float azimuth;
      float roll;
      float pitch;

    AndroidSensorData():
      latitude(0),
      longitude(0),
      azimuth(0),
      roll(0),
      pitch(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->azimuth);
      offset += serializeAvrFloat64(outbuffer + offset, this->roll);
      offset += serializeAvrFloat64(outbuffer + offset, this->pitch);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->azimuth));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->roll));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pitch));
     return offset;
    }

    const char * getType(){ return "melle/AndroidSensorData"; };
    const char * getMD5(){ return "372a806ca71ccc42a8e0620fd67a7fcf"; };

  };

}
#endif