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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "MSX.h"

MSX::MSX() :
  need_ldirvv(false)
{
  // MSX Memory layout:
  //   0x0000..0x3fff : MSX-BIOS (16KiB)
  //   0x4000..0xbfff : For 8, 16 or 32K cartridges (32Kib)
  //   0xc000..0xffff : RAM (16KiB) -- Don't touch in the last 4KiB!

  //start_org = 0x4000;
  //ram_start = 0xc000;
  //ram_end = 0xdfff;

//  requirables[0] = new Requirable("msx_console.inc");
//  requirables[1] = new Requirable("msx_screen2.inc");
}

MSX::~MSX()
{
  if (need_ldirvv) { insert_ldirvv(); }
  //if (need_plot_lores) { add_plot_lores(); }
  fprintf(out, "\nAPP_END:\n");

  for (int i = 0; i < _REQ_MSX_MAX; i++)
  {
    if (requirables[i]->isActive())
    {
      fprintf(out, ".include \"%s\"\n", requirables[i]->getStr());
    }
    delete requirables[i];
  }

  fprintf(out, "\nINCLUDE_END:\n");
}

int MSX::open(const char *filename)
{
  if (Z80::open(filename) != 0) { return -1; }
  fprintf(out, ".include \"msx.inc\"\n\n");
  fprintf(out, "ram_start equ 0xc000\n");
  fprintf(out, "heap_ptr equ ram_start\n");
  fprintf(out, "save_iy equ heap_ptr\n");

  //fprintf(out, "  _sound_waveform_start equ 0\n");
  //fprintf(out, "  _sound_waveform_end equ 2\n");
  //fprintf(out, "  _sound_waveform_ptr equ 4\n");

  return 0;
}

int MSX::start_init()
{
  fprintf(out, "\n");
  fprintf(out, ".org 0x4000\n");

  fprintf(out, "db\t\"AB\"\t; ROM cartridge\n");
  fprintf(out, "dw\tAPP_START\t; start address\n");
  fprintf(out, "dw\t0x0\t\t; statement\n");
  fprintf(out, "dw\t0x0\t\t; device\n");
  fprintf(out, "dw\t0x0\t\t; text\n");
  fprintf(out, "ds\t6\t\t; reserved 6 x 0h\n");

  fprintf(out, "APP_START:\n");
  return 0;
}

/*
 *  just like MSX-BASIC syntax
 */
int MSX::msx_beep()
{
  fprintf(out,"  call BEEP\n");
  return 0;
}

int MSX::msx_color_BBB()
{
  fprintf(out,"  ;; color_BBB\n");

  fprintf(out,"  pop de\n");
  fprintf(out,"  ld a, e\n");
  fprintf(out,"  ld (BDRCLR),a\n");

  fprintf(out,"  pop de\n");
  fprintf(out,"  ld a, e\n");
  fprintf(out,"  ld (BAKCLR),a\n");

  fprintf(out,"  pop de\n");
  fprintf(out,"  ld a, e\n");
  fprintf(out, "  ld (FORCLR),a\n");

  fprintf(out,"  call CHGCLR\n");
  return 0;
}

int MSX::msx_color_BBB(uint8_t foreground, uint8_t background, uint8_t border)
{
  fprintf(out,"  ;; color_BBB (const)\n");

  fprintf(out,"  ld a, 0x%02x\n", border);
  fprintf(out,"  ld (BDRCLR),a\n");

  fprintf(out,"  ld a, 0x%02x\n", background);
  fprintf(out,"  ld (BAKCLR),a\n");

  fprintf(out,"  ld a, 0x%02x\n", foreground);
  fprintf(out, "  ld (FORCLR),a\n");

  fprintf(out,"  call CHGCLR\n");
  return 0;
}

int MSX::msx_screen_B()
{
  fprintf(out,"  ;; screen_B()\n");

  // change screen mode
  fprintf(out,"  pop de\n");
  fprintf(out,"  ld a, e\n");

  fprintf(out,"  call CHGMOD\n");

  insertMaxWidth();

  return 0;
}

int MSX::msx_screen_B(uint8_t mode)
{
  fprintf(out,"  ;; screen_B (const)\n");

  // change screen mode
  fprintf(out,"  ld a, 0x%02x\n", mode);

  fprintf(out,"  call CHGMOD\n");

  insertMaxWidth();

  return 0;
}

void MSX::insertMaxWidth(void)
{
  int lbl_sc1 = incLabelCount();
  int lbl_width = incLabelCount();
  int lbl_end = incLabelCount();

  // adjust text modes to maximum width
  fprintf(out,"  ld a, (SCRMOD)\n");

  fprintf(out,"  and a\n");
  fprintf(out,"  cp 1\n");
  fprintf(out,"  jr nc, label_%d\n", lbl_sc1);  // mode is 0 (lesser than 1)

  fprintf(out,"  ld a, 40\n");
  fprintf(out,"  jp label_%d\n", lbl_width);


  fprintf(out, "label_%d:\n", lbl_sc1);
  fprintf(out,"  cp 2\n");
  fprintf(out,"  jr nc, label_%d\n", lbl_end);  // mode is 1 (lesser than 2)
  fprintf(out,"  ld a, 32\n");

  fprintf(out, "label_%d:\n", lbl_width);
  fprintf(out,"  ld (LINLEN), a\n");

  fprintf(out, "label_%d:\n", lbl_end);
}

int MSX::msx_width_B()
{
  fprintf(out,"  ;; width_B()\n");

  // adjust text modes
  fprintf(out,"  pop de\n");
  fprintf(out,"  ld a, e\n");
  fprintf(out,"  ld (LINLEN), a\n");

  return 0;
}

int MSX::msx_width_B(uint8_t w)
{
  fprintf(out,"  ;; width_B (const)\n");

  // adjust text modes
  fprintf(out,"  ld a, 0x%02x\n", w);
  fprintf(out,"  ld (LINLEN), a\n");

  return 0;
}

int MSX::msx_cls()
{
  fprintf(out,"  call CLS\n");
  return 0;
}

int MSX::msx_keyOn()
{
  fprintf(out,"  call DSPFNK\n");
  return 0;
}

int MSX::msx_keyOff()
{
  fprintf(out,"  call ERAFNK\n");
  return 0;
}

/*
 *  VRAM manipulation
 */
//int MSX::msx_copyVRAM_III(int len, int source, int dest)
int MSX::msx_copyVRAM_III()
{
#if 0
  need_ldirvv = true;
  len = len & 65535;
  source = source & 65535;
  dest = dest & 65535;
  fprintf(out,"  ld bc,0x%02x\n",len);
  fprintf(out,"  ld de,0x%02x\n",dest);
  fprintf(out,"  ld hl,0x%02x\n",source);
#endif
  //fprintf(out,"  call FILVRM\n");
  fprintf(out,"  call LDIRVV");
  return 0;
}

//int MSX::msx_fillVRAM_III(int c, int len, int addr)
int MSX::msx_fillVRAM_III()
{
#if 0
  c = c & 255;
  len = len & 65535;
  addr = addr & 65535;
  fprintf(out,"  ld a,0x%02x\n",c);
  fprintf(out,"  ld bc,0x%02x\n",len);
  fprintf(out,"  ld hl,0x%02x\n",addr);
#endif
  fprintf(out,"  call FILVRM\n");
  return 0;
}

/*
 *  Text console
 */
int MSX::msx_setCursor_BB()
{
  fprintf(out,"  ;; setCursor_BB\n");
  fprintf(out,"  pop de\n");
  fprintf(out,"  ld a, e\n");
  fprintf(out,"  ld (CSRY),a\n");

  fprintf(out,"  pop de\n");
  fprintf(out,"  ld a, e\n");
  fprintf(out,"  ld (CSRX),a\n");
  return 0;
}

/*
 *  Text console
 */
int MSX::msx_setCursor_BB(uint8_t col, uint8_t lin)
{
  fprintf(out,"  ;; setCursor_BB (const)\n");
  fprintf(out,"  ld a, 0x%02x\n", lin);
  fprintf(out,"  ld (CSRY),a\n");

  fprintf(out,"  ld a, 0x%02x\n", col);
  fprintf(out,"  ld (CSRX),a\n");
  return 0;
}


int MSX::msx_putChar_C()
{
  fprintf(out,"  ;; putChar_C\n");
  fprintf(out,"  pop de\n");
  fprintf(out,"  ld a, e\n");
  fprintf(out, "  call CHPUT\n");
  return 0;
}


int MSX::msx_putChar_C(char c)
{
  fprintf(out,"  ;; putChar_C (const)\n");
  fprintf(out,"  ld a, 0x%02x\n", c);
  fprintf(out, "  call CHPUT\n");
  return 0;
}


int MSX::msx_putS_IaC()
{
  fprintf(out,"  ;; putS_IaC\n");
//  fprintf(out,"  pop de\n");
//  fprintf(out,"  ld a, e\n");
//  fprintf(out, "  call CHPUT\n");
  return 0;
}


/*
 *  Support routines
 */
void MSX::insert_ldirvv(void)
{
  fprintf(out,"LDIRVV:\n");
  fprintf(out,"  call RDVRM\n");
  fprintf(out,"  ex de,hl\n");
  fprintf(out,"  call WRTVRM\n");
  fprintf(out,"  ex de,hl\n");
  fprintf(out,"  inc de\n");
  fprintf(out,"  cpi\n");
  fprintf(out,"  jp PE,LDIRVV\n");
  fprintf(out,"  ret\n");
}

int MSX::getLabelCount(void)
{
  return label_count;
}


int MSX::incLabelCount(void)
{
  return label_count++;
}


int MSX::msx_getChar()
{
//  requirables[REQ_MSX_CONSOLE]->activate();

  fprintf(out,"  ;; getChar\n");
  fprintf(out,"  call CHGET\n");
  fprintf(out,"  ld l, a\n");
  fprintf(out,"  ld h, 0\n");
  fprintf(out,"  push hl\n");
  return 0;
}

// ------------ Requirable sub class ----

Requirable::Requirable (const char* str) {
    m_b = false;
    m_str = str;
}

Requirable::~Requirable() {
  printf("Requirable::~Requirable() : %s\n", m_str);
}

void Requirable::activate() {
    m_b = true;
}

bool Requirable::isActive() {
    return m_b;
}

const char* Requirable::getStr() {
    return m_str;
}
