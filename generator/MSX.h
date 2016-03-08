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
#ifndef _MSX_H
#define _MSX_H

#include "Z80.h"

//  macros to send/receive parameters from/to stack
#define __PUSH_HL_A \
  fprintf(out,"  ld l,a\n"); \
  fprintf(out,"  ld h,0\n"); \
  fprintf(out,"  push hl\n");

#define __POP_A_DE \
  fprintf(out,"  pop de\n"); \
  fprintf(out,"  ld e,a\n");

#define __POP_A_HL \
  fprintf(out,"  pop hl\n"); \
  fprintf(out,"  ld e,a\n");

// Macros to save multiples registers (and avoid mistakes)
#define __PUSH_BCDE \
  fprintf(out,"  push bc\n"); \
  fprintf(out,"  push de\n");

#define __PUSH_BCDEHL \
  fprintf(out,"  push bc\n"); \
  fprintf(out,"  push de\n"); \
  fprintf(out,"  push hl\n");

#define __PUSH_BCHL \
  fprintf(out,"  push bc\n"); \
  fprintf(out,"  push hl\n");

// Macros to retrieve multiple registers (and avoid mistakes)
#define __POP_BCDE \
  fprintf(out,"  pop de\n"); \
  fprintf(out,"  pop bc\n");

#define __POP_BCDEHL \
  fprintf(out,"  pop hl\n"); \
  fprintf(out,"  pop de\n"); \
  fprintf(out,"  pop bc\n");

#define __POP_BCHL \
  fprintf(out,"  pop hl\n"); \
  fprintf(out,"  pop bc\n");

#define __VERBOSE \
  if (VERBO) {\
    fprintf(out,"; -- calling function %s() --\n",__FUNCTION__); \
  }

enum
{
//  REQ_MSX_CONSOLE = 0,
//  REQ_MSX_SCREEN2
};

#define _REQ_MSX_MAX 0

class Requirable
{
public:
  Requirable(const char* str);
  ~Requirable();
  void activate();
  bool isActive();
  const char* getStr();
private:
  bool m_b;
  const char* m_str;
};

class MSX : public Z80
{
public:
  MSX();
  virtual ~MSX();
  virtual int open(const char *filename);
  virtual int start_init();
  // start of MSX methods
  virtual int msx_backColor_B();
  virtual int msx_backColor_B(uint8_t color);
  virtual int msx_beep();
  virtual int msx_borderColor_B();
  virtual int msx_borderColor_B(uint8_t color);
  virtual int msx_cls();
  virtual int msx_color_BBB();
  virtual int msx_color_BBB(uint8_t foreground, uint8_t background, uint8_t border);
  virtual int msx_copyVRAM_III();
  virtual int msx_copyVRAM_III(int source, int dest, int size);
  virtual int msx_fillVRAM_III();
  virtual int msx_fillVRAM_III(int value, int addr, int size);
  virtual int msx_foreColor_B();
  virtual int msx_foreColor_B(uint8_t color);
  virtual int msx_getChar();
  virtual int msx_getStick_B();
  virtual int msx_getStick_B(uint8_t joy);
  virtual int msx_getTrig_B();
  virtual int msx_getTrig_B(uint8_t joy);
  virtual int msx_keyOff();
  virtual int msx_keyOn();
  virtual int msx_putChar_C();
  virtual int msx_putChar_C(char c);
  virtual int msx_putS_IaC();
  virtual int msx_readVDP_B();
  virtual int msx_readVDP_B(uint8_t reg);
  virtual int msx_readVRAM_I();
  virtual int msx_readVRAM_I(int addr);
  virtual int msx_screen_B();
  virtual int msx_screen_B(uint8_t mode);
  virtual int msx_setCursor_BB();
  virtual int msx_setCursor_BB(uint8_t col, uint8_t lin);
  virtual int msx_width_B();
  virtual int msx_width_B(uint8_t w);
  virtual int msx_writePSG_BB();
  virtual int msx_writePSG_BB(uint8_t reg, uint8_t value);
  virtual int msx_writeVDP_BB();
  virtual int msx_writeVDP_BB(uint8_t reg, uint8_t value);
  virtual int msx_writeVRAM_II();
  virtual int msx_writeVRAM_II(int addr, int value);
  // end of MSX methods

private:
  void insert_ldirvv(void);
  void insert_changecolors(void);

  bool need_ldirvv:1;
  bool need_change_colors:1;
  Requirable* requirables[_REQ_MSX_MAX];
};

#endif
