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
// format.h
//

#pragma once

#include <type_traits>
#include <string>
#include <cstdio>


namespace util {
// start of namespace util


template<typename T>
auto convert_arg_(T&& value) {
	constexpr auto is_std_string = std::is_same<std::remove_cv_t<std::remove_reference_t<T>>, std::string>::value;

	if constexpr (is_std_string) {
		return (value).c_str();
	} else {
		return std::forward<T>(value);
	}
}

template <typename ... Args>
void snprintf_(std::string& result, int buffer_size, const char* format, Args&& ... args) {
	char buf[buffer_size];
	int ret = std::snprintf(buf, buffer_size, format, args ...);
	if (buffer_size <= ret) {
		// failure
		// + 1 for trailing null character
		snprintf_(result, ret + 1, format, args ...);
	} else {
		// success
		result += buf;
	}
}


//
// snprintf - can take std::string as argument and return result as std::string
//
template <typename ... Args>
void snprintf(std::string& result, int buffer_size, const char* format, Args&& ... args) {
	snprintf_(result, buffer_size, format, convert_arg_(std::forward<Args>(args)) ...);
}
//
// sprintf - can take std::string as argument and return result as std::string
//
template<typename ... Args, int DEFAULT_BUFFER_SIZE=512>
std::string sprintf(const char* format, Args&& ... args) {
	std::string result;
    snprintf(result, DEFAULT_BUFFER_SIZE, format, args...);
    return result;
}
//
// fprintf - can take std::string as argument
template<typename ... Args, int DEFAULT_BUFFER_SIZE=512>
int fprintf(std::FILE* file, const char* format, Args&& ... args) {
	std::string result;
    snprintf(result, DEFAULT_BUFFER_SIZE, format, args...);

    // to keep same semantics for return value
    int ret = std::fputs(result.c_str(), file);
    return ret < 0 ? ret : result.size();
}


// end of namespace util
}
