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

/*
 * function __powerset_slice
 *
 * parameters:
 *      dps             dest powerset
 *      dbl             destination bit length
 *	sps		sourcepowerset
 *	sbl     	source powerset length in bits
 *      start           starting bit number
 *      end             ending bit number
 *
 * exceptions:
 *  none
 *
 * abstract:
 *  Extract into a powerset a slice of another powerset.
 *
 */
extern void
__pscpy (SET_WORD      *dps,
	 unsigned long  dbl,
	 unsigned long  doffset,
	 SET_WORD      *sps,
	 unsigned long  sbl,
	 unsigned long  start,
	 unsigned long  length);

void
__psslice (dps, dbl, sps, sbl, start, length)
     SET_WORD      *dps;
     unsigned long  dbl;
     SET_WORD      *sps;
     unsigned long  sbl;
     unsigned long  start;
     unsigned long  length;
{
  /* simply supply a zero destination offset and copy the slice */
  __pscpy (dps, dbl, (unsigned long)0, sps, sbl, start, length);
}