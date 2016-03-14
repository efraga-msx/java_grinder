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
  virtual int msx_backColor_I() { return -1; }
  virtual int msx_backColor_I(int color) { return -1; }
  virtual int msx_beep() { return -1; }
  virtual int msx_borderColor_I() { return -1; }
  virtual int msx_borderColor_I(int color) { return -1; }
  virtual int msx_cls() { return -1; }
  virtual int msx_color_III() { return -1; }
  virtual int msx_color_III(int foreground, int background, int border) { return -1; }
  virtual int msx_copyVRAM_III() { return -1; }
  virtual int msx_copyVRAM_III(int source, int dest, int size) { return -1; }
  virtual int msx_fillVRAM_III() { return -1; }
  virtual int msx_fillVRAM_III(int value, int addr, int size) { return -1; }
  virtual int msx_foreColor_I() { return -1; }
  virtual int msx_foreColor_I(int color) { return -1; }
  virtual int msx_getChar() { return -1; }
  virtual int msx_getStick_I() { return -1; }
  virtual int msx_getStick_I(int joy) { return -1; }
  virtual int msx_getTrig_I() { return -1; }
  virtual int msx_getTrig_I(int joy) { return -1; }
  virtual int msx_keyOff() { return -1; }
  virtual int msx_keyOn() { return -1; }
  virtual int msx_putChar_C() { return -1; }
  virtual int msx_putChar_C(char c) { return -1; }
  virtual int msx_putS_IaC() { return -1; }
  virtual int msx_readVDP_I() { return -1; }
  virtual int msx_readVDP_I(int reg) { return -1; }
  virtual int msx_readVRAM_I() { return -1; }
  virtual int msx_readVRAM_I(int addr) { return -1; }
  virtual int msx_screen_I() { return -1; }
  virtual int msx_screen_I(int mode) { return -1; }
  virtual int msx_setCursor_II() { return -1; }
  virtual int msx_setCursor_II(int col, int lin) { return -1; }
  virtual int msx_width_I() { return -1; }
  virtual int msx_width_I(int w) { return -1; }
  virtual int msx_writePSG_II() { return -1; }
  virtual int msx_writePSG_II(int reg, int value) { return -1; }
  virtual int msx_writeVDP_II() { return -1; }
  virtual int msx_writeVDP_II(int reg, int value) { return -1; }
  virtual int msx_writeVRAM_II() { return -1; }
  virtual int msx_writeVRAM_II(int addr, int value) { return -1; }
};

#endif
