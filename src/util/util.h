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
// util.h
//

#pragma once

#include <string>
#include <vector>

#include <signal.h>

#include "format.h"
#include "logger.h"

namespace util {
// start of namespace util

#define DEBUG_TRACE() logger.debug("****  TRACE  %-20s %5d %s", __FUNCTION__, __LINE__, __FILE__)

class ErrorError {
public:
	const char *func;
	const char *file;
	const int   line;

	ErrorError(const char *func_, const char *file_, const int line_) : func(func_), file(file_), line(line_) {}
};

#define ERROR() { logger.fatal("ERROR %s %d %s", __FILE__, __LINE__, __FUNCTION__); logBackTrace(); throw ErrorError(__FUNCTION__, __FILE__, __LINE__); }

class Abort {
public:
	const char *func;
	const char *file;
	const int   line;

	Abort(const char *func_, const char *file_, const int line_) : func(func_), file(file_), line(line_) {}
};
#define ERROR_Abort() throw Abort(__FUNCTION__, __FILE__, __LINE__)



std::vector<std::string> getBackTrace();

void logBackTrace(const Logger& logger);
void logBackTrace();

void signalHandler(int signum);

inline void setSignalHandler(int signum = SIGSEGV) {
	signal(signum, signalHandler);
}

std::string demangle(const char* mangled);


// end of namespace util
}
