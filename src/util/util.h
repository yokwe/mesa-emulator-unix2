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

#include <type_traits>
#include <string>

#include <log4cxx/logger.h>


template<typename T>
auto std_sprintf_convert_(T&& value) {
	constexpr auto is_std_string = std::is_same<std::remove_cv_t<std::remove_reference_t<T>>, std::string>::value;

	// comment out line below to detect QString
	if constexpr (is_std_string) {
		return (value).c_str();
	} else {
		return std::forward<T>(value);
	}
}

template <typename ... Args>
void std_sprintf_(std::string& result, int bufferSize, const char* format, Args&& ... args) {
	char buf[bufferSize];
	int ret = std::snprintf(buf, bufferSize, format, args ...);
	if (bufferSize <= ret) {
		// failure
		// + 1 for trailing null character
		std_sprintf_(result, ret + 1, format, args ...);
	} else {
		// success
		result += buf;
	}
}

#define STD_SPRINTF_DEFAULT_BUFFER_SIZE 512
template<typename ... Args>
std::string std_sprintf(const char* format, Args&& ... args) {
	std::string result;
    std_sprintf_(result, STD_SPRINTF_DEFAULT_BUFFER_SIZE, format, std_sprintf_convert_(std::forward<Args>(args)) ...);
    return result;
}

class Logger {
public:
	static Logger getLogger(const char *name);

//	static void pushPriority(log4cpp::Priority::Value newValue);
//	static void popPriority();


	// std::string
	void debug(const std::string& string) const {
		m_logger->debug(string);
	}
	void info(const std::string& string) const {
		m_logger->info(string);
	}
	void warn(const std::string& string) const{
		m_logger->warn(string);
	}
	void error(const std::string& string) const {
		m_logger->error(string);
	}
	void fatal(const std::string& string) const {
		m_logger->fatal(string);
	}

	// const char*
	void debug(const char* string) const {
		m_logger->debug(std::string(string));
	}
	void info(const char* string) const {
		m_logger->info(std::string(string));
	}
	void warn(const char* string) const {
		m_logger->warn(std::string(string));
	}
	void error(const char* string) const {
		m_logger->error(std::string(string));
	}
	void fatal(const char* string) const {
		m_logger->fatal(std::string(string));
	}


    template<typename... Args> void debug(const char* format, Args&& ... args) const {
    	m_logger->debug(std_sprintf(format, args...));
    }
    template<typename... Args> void info(const char* format, Args&& ... args) const {
     	m_logger->info(std_sprintf(format, args...));
     }
    template<typename... Args> void warn(const char* format, Args&& ... args) const {
     	m_logger->warn(std_sprintf(format, args...));
     }
    template<typename... Args> void error(const char* format, Args&& ... args) const {
    	m_logger->error(std_sprintf(format, args...));
    }
    template<typename... Args> void fatal(const char* format, Args&& ... args) const {
    	m_logger->fatal(std_sprintf(format, args...));
    }

private:
	log4cxx::LoggerPtr m_logger;
	Logger(log4cxx::LoggerPtr logger) : m_logger(logger) {}
};


