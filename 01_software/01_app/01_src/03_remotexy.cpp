#include "01_includes.h"

// you can enable debug logging to Serial at 115200
// #define REMOTEXY__DEBUGLOG    
#define USE_BLE
#ifdef USE_BLE
  // RemoteXY select connection mode and include library 
  #define REMOTEXY_MODE__ESP32CORE_BLE
  #include <BLEDevice.h>

  // RemoteXY connection settings 
  #define REMOTEXY_BLUETOOTH_NAME CONFIG_REMOTEXY_BLUETOOTH_NAME

#else
  #define REMOTEXY_MODE__WIFI_POINT
  #include <WiFi.h>
  // RemoteXY connection settings 
  #define REMOTEXY_WIFI_SSID "wdy_wifi_01"
  #define REMOTEXY_WIFI_PASSWORD "12345678"
  #define REMOTEXY_SERVER_PORT 6377
#endif

#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 176 bytes
  { 255,3,0,15,0,169,0,19,0,0,0,0,179,2,130,200,108,200,1,1,
  5,0,5,32,128,71,71,23,109,60,60,21,137,178,179,68,1,52,128,62,
  3,41,33,40,51,180,50,133,94,68,105,115,116,97,110,99,101,0,83,112,
  101,101,100,0,66,97,116,116,101,114,121,0,72,66,22,37,37,2,3,24,
  24,108,166,140,178,180,0,0,0,0,0,0,200,66,0,0,0,0,137,0,
  0,0,0,0,0,240,65,79,0,0,248,65,0,0,112,66,50,0,0,116,
  66,0,0,200,66,1,1,1,128,20,40,253,24,24,9,179,31,119,111,114,
  107,115,104,111,112,45,100,105,121,46,111,114,103,32,58,32,65,80,80,95,
  86,49,46,48,0,69,17,27,19,19,2,175,20,20,0,150 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_01_x; // from -100 to 100
  int8_t joystick_01_y; // from -100 to 100
  uint8_t button_01; // =1 if button pressed, else =0

    // output variables
  float onlineGraph_01_distance;
  float onlineGraph_02_speed;
  float onlineGraph_03_battery;
  int8_t circularBar_01; // from 0 to 100
  int16_t sound_01; // =0 no sound, else ID of sound, =1001 for example, look sound list in app

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   

#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

// ===========================================================================
void remotexy_init(void) {
// ===========================================================================
  // Initialize RemoteXY
  RemoteXY_Init();
}

// ===========================================================================
void remotexy_handler(void) {
// ===========================================================================
  // Initialize RemoteXY
 RemoteXY_Handler();
}

// ===========================================================================
int8_t remotexy_get_joystick_01_x( ) {
// ===========================================================================
  return RemoteXY.joystick_01_x;
}

// ===========================================================================
int8_t remotexy_get_joystick_01_y( ) {
// ===========================================================================
  return RemoteXY.joystick_01_y;
}

// ===========================================================================
uint8_t remotexy_get_button_01( ) {
// ===========================================================================
  return RemoteXY.button_01;
}

// ===========================================================================
float remotexy_get_onlineGraph_01_distance( ) {
// ===========================================================================
  return RemoteXY.onlineGraph_01_distance;
}

// ===========================================================================
float remotexy_get_onlineGraph_02_speed( ) {
// ===========================================================================
  return RemoteXY.onlineGraph_02_speed;
}

// ===========================================================================
float remotexy_get_onlineGraph_03_battery( ) {
// ===========================================================================
  return RemoteXY.onlineGraph_03_battery;
}

// ===========================================================================
int8_t remotexy_get_circularBar_01( ) {
// ===========================================================================
  return RemoteXY.circularBar_01;
}

// ===========================================================================
int16_t remotexy_get_sound_01( ) {
// ===========================================================================
  return RemoteXY.sound_01;
}

// ===========================================================================
uint8_t remotexy_get_connect_flag( ) {
// ===========================================================================
  return RemoteXY.connect_flag;
}

// ===========================================================================
// ===========================================================================
// ===========================================================================

// ===========================================================================
void remotexy_set_joystick_01_x( int8_t p_joystick_01_x) {
// ===========================================================================
  RemoteXY.joystick_01_x = p_joystick_01_x;
}

// ===========================================================================
void remotexy_set_joystick_01_y( int8_t p_joystick_01_y) {
// ===========================================================================
   RemoteXY.joystick_01_y = p_joystick_01_y;
}

// ===========================================================================
void remotexy_set_button_01(uint8_t p_button_01) {
// ===========================================================================
   RemoteXY.button_01 = p_button_01;
}

// ===========================================================================
void remotexy_set_onlineGraph_01_distance(float p_onlineGraph_01_distance) {
// ===========================================================================
   RemoteXY.onlineGraph_01_distance = p_onlineGraph_01_distance;
}

// ===========================================================================
void remotexy_set_onlineGraph_02_speed( float p_onlineGraph_02_speed) {
// ===========================================================================
   RemoteXY.onlineGraph_02_speed = p_onlineGraph_02_speed;
}

// ===========================================================================
void remotexy_set_onlineGraph_03_battery( float p_onlineGraph_03_battery) {
// ===========================================================================
   RemoteXY.onlineGraph_03_battery = p_onlineGraph_03_battery;
}

// ===========================================================================
void remotexy_set_circularBar_01( int8_t p_circularBar_01) {
// ===========================================================================
   RemoteXY.circularBar_01 = p_circularBar_01;
}

// ===========================================================================
void remotexy_set_sound_01(int16_t p_sound_01) {
// ===========================================================================
   RemoteXY.sound_01 = p_sound_01;
}

// ===========================================================================
void remotexy_set_connect_flag( uint8_t p_connect_flag) {
// ===========================================================================
   RemoteXY.connect_flag = p_connect_flag;
}