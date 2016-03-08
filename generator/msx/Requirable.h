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

#ifndef _MSX_REQUIRABLE_H
#define _MSX_REQUIRABLE_H


class MSX;

class RequirableAction;

class Requirable
{
public:
  Requirable();
  virtual ~Requirable();

  virtual void setRequired();
  virtual bool isRequired();

  virtual Requirable* setRequirableAction(RequirableAction* ra);
  virtual Requirable* setNext(Requirable* next);

  virtual void doAction(MSX *msx, FILE *out);

private:
  bool m_isRequired;
  RequirableAction* m_ra;
  Requirable* m_next;
};


class RequirableAction
{
public:
  RequirableAction();
  virtual ~RequirableAction();

  virtual void doAction(MSX *msx, FILE *out);

private:
};

#endif
