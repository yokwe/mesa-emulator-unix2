/*******************************************************************************
 * Copyright (c) 2023, Yasuhiro Hasegawa
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

//
// mesa.h
//

#pragma once

#include <string>

namespace util {
// start of namespace util


//From System.mesa
//-- Time of day
//
//GreenwichMeanTime: TYPE = RECORD [LONG CARDINAL];
//-- A greenwich mean time t represents the time which is t-gmtEpoch seconds after
//-- midnight, 1 January 1968, the time chosen as the epoch or beginning of the Pilot
//-- time standard.  Within the range in which they overlap, the Alto and Pilot time
//-- standards assign identical bit patterns, but the Pilot standard runs an additional
//-- 67 years before overflowing.
//-- Greenwich mean times should be compared directly only for equality; to find which of
//-- two gmt's comes first, apply SecondsSinceEpoch to each and compare the result.  If t2
//-- is a gmt known to occur after t1, then t2-t1 is the seconds between t1 and t2.  If t
//-- is a gmt, then System.GreenwichMeanTime[t+60] is the gmt one minute after t.
//gmtEpoch: GreenwichMeanTime = [2114294400];
//-- = (67 years * 365 days + 16 leap days) * 24 hours * 60 minutes * 60 seconds
//GetGreenwichMeanTime: PROCEDURE RETURNS [gmt: GreenwichMeanTime];

// Unix Time Epoch  1970-01-01 00:00:00
// Mesa Time Epoch  1968-01-01 00:00:00
//   Difference between above 2 date is 731 days.
inline constexpr uint32_t EPOCH_DIFF = (uint32_t)2114294400 + (uint32_t)(731 * 60 * 60 * 24);

inline uint32_t toMesaTime(uint32_t unixTime) {
	return unixTime + EPOCH_DIFF;
}
inline uint32_t toUnixTime(uint32_t mesaTime) {
	return mesaTime - EPOCH_DIFF;
}

//
// convert mesa style number string to int
//   0x... => hexadecimal number
//   0...  => octal number
//   ...H  => hexadecimal number
//   ...B  => octal number
//   ...   => decimal number
//
int toIntMesaNumber(const std::string& string);


// end of namespace util
}
