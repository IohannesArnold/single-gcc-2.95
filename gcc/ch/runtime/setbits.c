/* Implement POWERSET runtime actions for CHILL.
   Copyright (C) 1992,1993 Free Software Foundation, Inc.
   Author: Wilfried Moser, et al

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

#define __CHILL_LIB__

#include "config.h"
#include <stdio.h>
#include "powerset.h"

extern void __cause_ex1 (char *exname, char *file, int lineno);

/*
 * function __setbits
 *
 * parameters:
 *	out		result
 *      bitlength       length of bitstring in bits
 *	startbit	starting bitnumber
 *	endbit		ending bitnumber
 *
 * returns:
 *	void
 *
 * exceptions:
 *   rangefail
 *
 * abstract:
 *  set all bits from starting bitnumber to ending bitnumber
 *  in a powerset
 *
 */
void
__setbits (out, bitlength, startbit, endbit)
     SET_WORD      *out;
     unsigned long  bitlength;
     long  startbit;
     long  endbit;
{
  unsigned long i;
  
  if (out == NULL
      || startbit < 0
      || startbit >= bitlength 
      || endbit < 0
      || endbit >= bitlength 
      || endbit < startbit)
    __cause_ex1 ("rangefail", "__setbits", __LINE__);
  
  if (bitlength <= SET_CHAR_SIZE)
    for (i = startbit; i <= endbit; i++)
      SET_BIT_IN_CHAR (*((SET_CHAR *)out), i);
  else if (bitlength <= SET_SHORT_SIZE)
    for (i = startbit; i <= endbit; i++)
      SET_BIT_IN_SHORT (*((SET_SHORT *)out), i);
  else
    {
      SET_WORD	*p;
      unsigned long       bitnr;
      
      /* FIXME - this is inefficient! */
      for (i = startbit; i <= endbit; i++)
	{
	  p = out + (i / SET_WORD_SIZE);
	  bitnr = i % SET_WORD_SIZE;
	  SET_BIT_IN_WORD (*p, bitnr);
	}
    }
} 