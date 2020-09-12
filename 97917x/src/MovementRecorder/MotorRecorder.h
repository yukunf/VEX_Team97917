#ifndef motorrecorder

#define motorrecorder motorrecorder

#include "vex.h"

enum DataType {
  pct = (int)vex::velocityUnits::pct,
  rpm = (int)vex::velocityUnits::rpm,
  dps = (int)vex::velocityUnits::dps,
  mV = (int)vex::voltageUnits::mV,
  V = (int)vex::voltageUnits::volt
};

enum AdapterState { recording = 0, playing = 1, suspended = -1 };

struct DataSlice {
  uint32_t timeStamp;
  uint32_t controlData;
  DataType dataType;
  vex::brakeType brakeType_;
  DataSlice(){};
  DataSlice(uint32_t timeStamp_, uint32_t controlData_, DataType dataType_,
            vex::brakeType _brakeType_) {
    this->timeStamp = timeStamp_;
    this->controlData = controlData_;
    this->dataType = dataType_;
    this->brakeType_ = _brakeType_;
  }
};

#define BUFFER_SIZE 500
class MotorRecordAdapter {
private:
  const vex::motor &motor_;
  const char *motorID;
  std::list<DataSlice> sampleBuffer;

  AdapterState state;
    public:
  DataType dataType;

  vex::timer &time;
  MotorRecordAdapter(const vex::motor &motor__, const char *motorID_,
                      vex::timer &time_,const uint32_t sampleRate_,DataType dataType_);

  const uint32_t sampleRate;
  const motor &getMotor();
  const char *getID();
  AdapterState getState();

  void startRecording();
  void startPlayback();
  void stopRecording();
  void stopPlayBack();
  void handle();
  void record();
  void playback();
};

#endif