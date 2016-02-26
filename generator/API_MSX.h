/**
 *  Java Grinder
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPL
 *
 * Copyright 2014-2016 by Michael Kohn
 *
 */

/*
 *   MSX support by Giovanni Nunes - https://github.com/plainspooky
 *                  Emiliano Fraga - https://github.com/efraga-msx
 */

#ifndef _API_MSX_H
#define _API_MSX_H

class API_MSX
{
public:
  // MSX
  virtual int msx_cls() { return -1; }
  virtual int msx_beep() { return -1; }
  virtual int msx_color_BBB() { return -1; }
  virtual int msx_color_BBB(uint8_t foreground, uint8_t background, uint8_t border) { return -1; }
  virtual int msx_screen_B( ) { return -1; }
  virtual int msx_screen_B(uint8_t mode) { return -1; }
  virtual int msx_width_B( ) { return -1; }
  virtual int msx_width_B(uint8_t w) { return -1; }
  virtual int msx_keyOn() { return -1; }
  virtual int msx_keyOff() { return -1; }
  virtual int msx_fillVRAM_III() { return -1; }
  virtual int msx_copyVRAM_III() { return -1; }
  virtual int msx_putChar_C() { return -1; }
  virtual int msx_putChar_C(char c) { return -1; }
  virtual int msx_putS_IaC() { return -1; }
  virtual int msx_setCursor_BB() { return -1; }
  virtual int msx_setCursor_BB(uint8_t col, uint8_t lin) { return -1; }
};

#endif
