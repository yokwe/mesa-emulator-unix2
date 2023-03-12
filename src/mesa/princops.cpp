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
// princops.cpp
//

#include "princops.h"

// ERROR is defined in util.h
#include "../util/util.h"

#include "../util/logger.h"
static const auto logger = util::Logger::getLogger("princops");

namespace mesa {
// start of namespace mesa


FrameLink MakeFrameLink(ControlLink link) {
	if (ControlLinkType(link) != LinkType::frame) ERROR();
	return (CARD16)link;
}

IndirectLink MakeIndirectLink(ControlLink link) {
	if (ControlLinkType(link) != LinkType::indirect) ERROR();
	return (CARD16)link;
}

CARD32 MakeProcDesc(ControlLink link) {
	if (ControlLinkType(link) != LinkType::oldProcedure) ERROR();
	return link;
}

CARD32 MakeNewProcDesc(ControlLink link) {
	if (ControlLinkType(link) != LinkType::newProcedure) ERROR();
	return link;
}

LocalFrameHandle AVFrame(CARD16 u) {
	AVItem avi = {u};
	if (avi.tag != (CARD16)AVItemType::frame) ERROR();
	return u;
}

POINTER AVLink(CARD16 u) {
	AVItem avi = {u};
	if (avi.tag != (CARD16)AVItemType::frame) ERROR();
	return u;
}



// 3.3.2 Evaluation Stack
CARD16 stack[StackDepth];
CARD16 SP;

// 3.3.3 Data and Status Registers
CARD16 PID[4]; // Processor ID
//CARD16 MP;     // Maintenance Panel
//CARD32 IT;     // Interval Timer
//CARD16 WM;     // Wakeup mask register - 10.4.4
//CARD16 WP;     // Wakeup pending register - 10.4.4.1
//CARD16 WDC;    // Wakeup disable counter - 10.4.4.3
//CARD16 PTC;    // Process timeout counter - 10.4.5
CARD16 XTS;    // Xfer trap status - 9.5.5

// 3.3.1 Control Registers
CARD16            PSB; // PsbIndex - 10.1.1
//MdsHandle         MDS;
LocalFrameHandle  LF;  // POINTER TO LocalVariables
GlobalFrameHandle GF;  // LONG POINTER TO GlobalVarables
CARD32            CB;  // LONG POINTER TO CodeSegment
CARD16            PC;
GFTHandle         GFI;

// 4.5 Instruction Execution
CARD8  breakByte;
CARD16 savedPC;
CARD16 savedSP;

// 10.4.1 Scheduler
//int running;

// 10.4.5 Timeouts
// TimeOutInterval:LONG CARDINAL;
// One tick = 40 milliseconds
//const LONG_CARDINAL TimeOutInterval = 40 * 1000;

// time: LONG CARDINAL
// Due to name conflict with time, rename to time_CheckForTimeouts
//LONG_CARDINAL lastTimeoutTime;


// end   of namespace mesa
}
