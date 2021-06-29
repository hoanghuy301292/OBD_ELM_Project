/*
  ELM327.h - Library communicating with an ELM327 device over serial
  Created by Evan d'Entremont, March 2016

  ELM327 obd(Serial);
  obd.get(PID_RPM);

  TODO: Debug / test with a real car.
  TODO: handle max/min and throw out bad reads.
  TODO: throttle DELAYLENGTH until consistently getting good reads.
  TODO: Don't use delay for processing incoming data.. Wait for > character.
  TODO: Handle PID's supported - 00, 20, 30, 40, 50, 60, A0, C0
  TODO: Mode 09 02 (Read VIN)
  TODO: Bitmap / text string of manufacturer based on VIN 09 02 (bitmaps optional by define.)
  TODO: Mode 09 0A (Get ECU name)
  TODO: Handle Trouble Codes.
  TODO: Turn headers off  (AT H0)
  TODO: Turn Echo off (perhaps add a debug mode with optional serial parameter?) (AT E0)
  TODO: investigate AT CS (detects hardware errors)
  TODO: A nicer hex to dec wrapper
  TODO: make the responses numeric, with a second call for units. Units are only necessary for text output and hinder use on gauges.
*/
#ifndef ELM327_h
#define ELM327_h

#include "Arduino.h"
#include "Arduino_HW.h"
#include "HardwareSerial.h"
#include "PID.h"
#include "LookupDTC.h"
#include "utypedef.h"

#define TIME_FOR_CONNECTION 500
#define TIME_FOR_SEARCHING  2000
#define TIME_OUT            4000

#define elmSerial Serial3

class ELM327
{
  public:
    void ELM327_init(void);
    String get(String command);
    String getDTCs(void);
  private:
    String query(String command);
    String process(String command, String result);
};

#endif
