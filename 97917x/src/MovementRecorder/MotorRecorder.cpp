#include "MotorRecorder.h"
MotorRecordAdapter::MotorRecordAdapter(const vex::motor& motor__ , const char * motorID_ ,  vex::timer& time_
                    ,const uint32_t sampleRate_ ,DataType dataType_):motor_(motor__),motorID(motorID_),dataType(dataType_),time(time_),sampleRate(sampleRate_){
  sampleBuffer = list<DataSlice>(BUFFER_SIZE);
  state  = AdapterState::suspended;
}
void  MotorRecordAdapter::startRecording(){
  state = recording;
  sampleBuffer.clear();
  time.reset();
}
  void MotorRecordAdapter::startPlayback(){
    state = playing;
  }
  void MotorRecordAdapter::stopRecording(){
    state = suspended;
  //  vex::thread IOThread();
  }
  void MotorRecordAdapter::stopPlayBack(){
    state  = suspended;
  }
  void MotorRecordAdapter::handle(){
    switch(state){
      case recording:
      record();
      break;
      case playing:
      playback();
      break;
      case suspended:
      default:
      break;
    }
  }
  void MotorRecordAdapter::record(){
  }
  void playback();