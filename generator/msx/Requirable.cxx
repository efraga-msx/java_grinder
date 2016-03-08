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

#include "Requirable.h"

class NullRequirable : public Requirable
{
  virtual Requirable* setRequirableAction(RequirableAction* ra);
  virtual Requirable* setNext(Requirable* next);

  virtual void doAction(MSX *msx, FILE *out);
};

Requirable::Requirable()
{
  m_isRequired = false;
  m_ra = NULL;
  m_next = NULL;
}

Requirable::~Requirable()
{
  printf("Requirable::~Requirable()");
  if (m_ra != NULL)
  {
    delete m_ra;
    m_ra = NULL;
  }
  if (m_next != NULL)
  {
    delete m_next;
    m_next = NULL;
  }
}

void Requirable::setRequired()
{
  m_isRequired = true;
}


bool Requirable::isRequired()
{
  return m_isRequired;
}

Requirable* Requirable::setRequirableAction(RequirableAction* ra)
{
  if (m_ra != NULL) { delete m_ra; }

  m_ra = ra;

  return this;
}

Requirable* Requirable::setNext(Requirable* next)
{
  if (m_next != NULL) { delete m_next; }

  m_next = next;

  return next;
}

void Requirable::doAction(MSX *msx, FILE *out)
{
  if (m_isRequired) { m_ra->doAction(msx, out); }

  if (m_next != NULL) { m_next->doAction(msx, out); }
}

RequirableAction::RequirableAction()
{
}

RequirableAction::~RequirableAction()
{
}

void RequirableAction::doAction(MSX *msx, FILE *out)
{
  // null pattern : does nothing
}

void NullRequirable::doAction(MSX *msx, FILE *out)
{
  // null pattern : does nothing
}

Requirable* NullRequirable::setRequirableAction(RequirableAction* ra)
{
  // null pattern : does nothing
  return this;
}

Requirable* NullRequirable::setNext(Requirable* next)
{
  // null pattern : does nothing
  return this;
}
