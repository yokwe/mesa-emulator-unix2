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
// mesa.cpp
//

#include "mesa.h"

#include "util.h"

#include "logger.h"
static const auto logger = util::Logger::getLogger("mesa");

namespace util {
// start of namespace util


int toIntMesaNumber(const std::string& string) {
	int radix = 0;
	std::string numberString;

	if (startsWith(string, "0x") || startsWith(string, "0X")) {
		// c style hexadecimal
		radix = 16;
		numberString = string.substr(2, string.length() - 2);
	} else if (startsWith(string, "0")) {
		// c style octal
		radix = 8;
		numberString = string.substr(1, string.length() - 1);
	} else if (endsWith(string, "H")) {
		// mesa style hexadecimal
		radix = 16;
		numberString = string.substr(0, string.length() - 1);
	} else if (endsWith(string, "B")) {
		// mesa style octal
		radix = 8;
		numberString = string.substr(0, string.length() - 1);
	} else {
		// decimal
		radix = 10;
		numberString = string;
	}

	try {
		size_t idx;
		int ret = std::stoi(numberString,  &idx, radix);
		if (numberString.length() != idx) {
			logger.error("Unexpect");
			logger.error("  end          = %d", numberString.length());
			logger.error("  idx          = %d \"%s\"", idx, numberString.substr(idx, numberString.length() - idx));
			logger.error("  string       = %d \"%s\"", string.length(), string.c_str());
			logger.error("  numberString = %d \"%s\"", numberString.length(), numberString.c_str());
			ERROR();
		}
		return ret;
	} catch (const std::invalid_argument& e) {
		logger.error("exception");
		logger.error("  name   = %s!", typeid(e).name());
		logger.error("  what   = %s!", e.what());
		logger.error("  string = %s!", string);
		ERROR();
	} catch (const std::out_of_range& e) {
		logger.error("exception");
		logger.error("  name   = %s!", typeid(e).name());
		logger.error("  what   = %s!", e.what());
		logger.error("  string = %s!", string);
		ERROR();
	}
}


// end   of namespace util
}
