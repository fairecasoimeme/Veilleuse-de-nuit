#include <ESP8266WiFi.h>
extern "C" {
#include <user_interface.h>
}
#define FPM_SLEEP_MAX_TIME 0xFFFFFFF

int redPin = 4;
int greenPin = 13;
int bluePin = 12;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void early_init()
{
  WiFi.persistent(false);
  WiFi.mode(WIFI_OFF);
  WiFi.forceSleepBegin();
  wifi_station_disconnect();
  wifi_set_opmode(NULL_MODE);
  wifi_set_sleep_type(MODEM_SLEEP_T);
  wifi_fpm_open();
  wifi_fpm_do_sleep(FPM_SLEEP_MAX_TIME);
}

void loop()
{
  int i=0;
  for (i=0;i<255;i++)
  {
    delay(10);
    setColor(i, 0, 0);  // red
  }
  for (i=255;i==0;i--)
  {
    delay(10);
    setColor(i, 0, 0);  
  }
  delay(1000);
  for (i=0;i<255;i++)
  {
    delay(10);
    setColor(0, i, 0);  // green
  }
  for (i=255;i==0;i--)
  {
    delay(10);
    setColor(0, i, 0);  
  }
  delay(1000);
  for (i=0;i<255;i++)
  {
    delay(10);
    setColor(0, 0, i);  // blue
  }
  for (i=255;i==0;i--)
  {
    delay(10);
    setColor(0, 0, i);  
  }
  delay(1000);
   for (i=0;i<255;i++)
  {
    delay(10);
    setColor(i, i, 0);  
  }
  for (i=255;i==0;i--)
  {
    delay(10);
    setColor(i, i, 0);  //yellow
  }
  delay(1000);  
   for (i=0;i<255;i++)
  {
    delay(10);
    setColor(i, 0, i);  
  }
  for (i=255;i==0;i--)
  {
    delay(10);
    setColor(i, 0, i);  //purple
  }
  delay(1000);
  for (i=0;i<255;i++)
  {
    delay(10);
    setColor(0, i, i);  // blue
  }
  for (i=255;i==0;i--)
  {
    delay(10);
    setColor(0, i, i);  //aqua
  }
  delay(1000);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}