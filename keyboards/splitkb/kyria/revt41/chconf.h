/* Copyright 2020 Nick Brassel (tzarc)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#if defined(KEYBOARD_splitkb_kyria_revt41)

// #define CH_CFG_OPTIMIZE_SPEED TRUE
#define CH_CFG_ST_TIMEDELTA 0

#define CH_CFG_TIME_QUANTUM 20

// One tick (minimum sleep interval) will be 100 μs. This value cannot be
// increased arbitrarily: chSysTimerHandlerI() must be executed in less than one
// tick as per http://forum.chibios.org/viewtopic.php?t=3712#p27851
#define CH_CFG_ST_FREQUENCY 10000

#include_next <chconf.h>
#endif
