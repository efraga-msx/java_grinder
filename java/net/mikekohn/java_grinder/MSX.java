/**
 *  Java Grinder
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.naken.cc/
 * License: GPL
 *
 * Copyright 2014-2016 by Michael Kohn
 *
 */

/*
 *   MSX support by Giovanni Nunes - https://github.com/plainspooky
 *                  Emiliano Fraga - https://github.com/efraga-msx
 */

package net.mikekohn.java_grinder;

abstract public class MSX
{
  protected MSX() { }

  public static void backColor(int color) { }
  public static void beep() { }
  public static void borderColor(int color) { }
  public static void cls() { }
  public static void color(int foreground, int background, int border) { }
  public static void copyVRAM(int source, int dest, int size) { }
  public static void fillVRAM(int value, int addr, int size) { }
  public static void foreColor(int color) { }
  public static int  getChar() { return 0; }
  public static int  getStick(int joy) { return 0; }
  public static int  getTrig(int joy) { return 0; }
  public static void keyOff() { }
  public static void keyOn() { }
  public static void putChar(char c) { }
  // not working
  public static void putS(int i, char[] s) { }
  // not working
  public static int  readVDP(int reg) { return 0; }
  public static int  readVRAM(int addr) { return 0; }
  public static void screen(int mode) { }
  public static void setCursor(int column, int line) { }
  public static void width(int w) { }
  public static void writePSG(int reg, int value) { }
  public static void writeVDP(int reg, int value) { }
  public static void writeVRAM(int addr, int value) { }
}
