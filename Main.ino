#include <ros.h>
#include "IRSensor.h"
#include "ros_lib/melle/ArduinoSensorData.h"

IRSensor irSensor(A0);

ros::NodeHandle  arduinoNode;

melle::ArduinoSensorData arduinoSensorData;

ros::Publisher arduinoSensorDataPublisher("ArduinoSensorData",&arduinoSensorData);

void setup() {

  Serial.begin(57600);

  arduinoNode.initNode();
  arduinoNode.advertise(arduinoSensorDataPublisher);
  
}

void loop() {

  int binFullness = irSensor.getBinFullness();
  Serial.print("Bin fullness = ");
  Serial.println(binFullness);

  int batteryLevel = 50;
  Serial.print("Battery Level = ");
  Serial.println(batteryLevel);
  
  arduinoSensorData.binFullness = binFullness;
  arduinoSensorData.batteryLevel = batteryLevel;
  
  arduinoSensorDataPublisher.publish(&arduinoSensorData);

  arduinoNode.spinOnce();

  delay(500);
}
