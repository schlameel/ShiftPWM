/*
processor_specific.h - Part of ShiftPWM Library for Arduino to PWM many outputs
using shift registers
Copyright (c) 2020 Schlameel, www.Schlameel.com
All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef PROCESSOR_SPECIFIC_H
#define PROCESSOR_SPECIFIC_H

/*#if defined (__AVR_ATmega4809__)*/
#if defined (ARDUINO_ARCH_MEGAAVR)

#  define UseMegaAVR 1

#  ifndef SPDR
#    define SPDR SPI0.DATA
#  endif

#  ifndef SPSR
#    define SPSR SPI0.CTRLA
#  endif

#  ifndef WaitForCompleteSend
#    define WaitForCompleteSend (SPI0.INTFLAGS & SPI_RXCIF_bm) == 0
#  endif

#else //  not defined (__AVR_ATmega4809__)

#  ifndef WaitForCompleteSend
#    define WaitForCompleteSend !(SPSR & _BV(SPIF))
#  endif

#endif

#endif  // PROCESSOR_SPECIFIC_H