/**
 *  Java Grinder
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPL
 *
 * Copyright 2014-2015 by Michael Kohn
 *
 */

/*
 *   MSX support by Giovanni Nunes - https://github.com/plainspooky
 *                  Emiliano Fraga - https://github.com/efraga-msx
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "JavaClass.h"
#include "msx_.h"

#define CHECK_FUNC(funct,sig) \
  printf("msx_ CHECK_FUNC funct: %s\tsig: %s\n", #funct, #sig); \
  if (strcmp(#funct#sig, method_name) == 0) \
  { \
    return generator->msx_##funct##sig(); \
  }

#define CHECK_FUNC_CONST(funct,sig) \
  printf("msx_ CHECK_FUNC_CONST funct: %s\tsig: %s\n", #funct, #sig); \
  if (strcmp(#funct#sig, method_name) == 0) \
  { \
    return generator->msx_##funct##sig(const_val); \
  }

#define CHECK_FUNC_CONST_2(funct,sig) \
  printf("msx_ CHECK_FUNC_CONST_2 funct: %s\tsig: %s\n", #funct, #sig); \
  if (strcmp(#funct#sig, function) == 0) \
  { \
    return generator->msx_##funct##sig(const_val1, const_val2); \
  }

#define CHECK_FUNC_CONST_3(funct,sig) \
  printf("msx_ CHECK_FUNC_CONST_3 funct: %s\tsig: %s\n", #funct, #sig); \
  if (strcmp(#funct#sig, function) == 0) \
  { \
    return generator->msx_##funct##sig(const_val1, const_val2, const_val3); \
  }

int msx(JavaClass *java_class, Generator *generator, char *method_name)
{
  //CHECK_FUNC(someFunction,_I)
  CHECK_FUNC(cls,)
  CHECK_FUNC(beep,)
  CHECK_FUNC(color,_BBB)
  CHECK_FUNC(screen,_B)
  CHECK_FUNC(width,_B)
  CHECK_FUNC(keyOn,)
  CHECK_FUNC(keyOff,)
  CHECK_FUNC(fillVRAM,_III)
  CHECK_FUNC(copyVRAM,_III)
  CHECK_FUNC(putChar,_C)
  CHECK_FUNC(putS,_IaC)
  CHECK_FUNC(setCursor,_BB)

  return -1;
}

int msx(JavaClass *java_class, Generator *generator, char *method_name, int const_val)
{
  //CHECK_FUNC_CONST(someFunction,_I)
  CHECK_FUNC_CONST(putChar,_C)
  CHECK_FUNC_CONST(screen,_B)
  CHECK_FUNC_CONST(width,_B)

  return -1;
}

int msx(JavaClass *java_class, Generator *generator, char *function, int const_val1, int const_val2)
{
  //CHECK_FUNC_CONST_2(someFunction,_II)
  CHECK_FUNC_CONST_2(setCursor,_BB)

  return -1;
}

int msx(JavaClass *java_class, Generator *generator, char *function, int const_val1, int const_val2, int const_val3)
{
  //CHECK_FUNC_CONST_3(someFunction,_II)
  CHECK_FUNC_CONST_3(color,_BBB)

  return -1;
}
