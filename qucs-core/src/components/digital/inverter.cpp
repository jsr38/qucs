/*
 * inverter.cpp - logical inverter class implementation
 *
 * Copyright (C) 2005 Stefan Jahn <stefan@lkcc.org>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this package; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
 * Boston, MA 02110-1301, USA.  
 *
 * $Id: inverter.cpp,v 1.2 2005-12-05 07:04:57 margraf Exp $
 *
 */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>

#include "complex.h"
#include "object.h"
#include "circuit.h"
#include "component_id.h"
#include "constants.h"
#include "digital.h"
#include "inverter.h"

inverter::inverter () : digital () {
  type = CIR_INVERTER;
  setSize (2);
}

void inverter::calcOutput (void) {
  nr_double_t v = getPropertyDouble ("V");
  Vout = v / 2 * (1 - calcTransfer (0));
}

void inverter::calcDerivatives (void) {
  g[0] = - 0.5 * calcDerivative (0) + GMin;
}
