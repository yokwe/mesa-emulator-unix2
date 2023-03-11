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
// logger.h
//

#pragma once

#include <vector>
#include <string>

#include <log4cxx/logger.h>

#include "format.h"


namespace util {
// start of namespace util


class Logger {
public:
	static Logger get_logger(const char *name);

    static log4cxx::LevelPtr ALL;
    static log4cxx::LevelPtr DEBUG;
    static log4cxx::LevelPtr INFO;
    static log4cxx::LevelPtr WARN;
    static log4cxx::LevelPtr ERROR;
    static log4cxx::LevelPtr FATAL;
    static log4cxx::LevelPtr OFF;

	static void push_level(log4cxx::LevelPtr newValue);
	static void pop_level();


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
    	m_logger->debug(sprintf(format, args...));
    }
    template<typename... Args> void info(const char* format, Args&& ... args) const {
     	m_logger->info(sprintf(format, args...));
     }
    template<typename... Args> void warn(const char* format, Args&& ... args) const {
     	m_logger->warn(sprintf(format, args...));
     }
    template<typename... Args> void error(const char* format, Args&& ... args) const {
    	m_logger->error(sprintf(format, args...));
    }
    template<typename... Args> void fatal(const char* format, Args&& ... args) const {
    	m_logger->fatal(sprintf(format, args...));
    }

private:
    static std::vector<log4cxx::LevelPtr> level_stack;

	log4cxx::LoggerPtr m_logger;
	Logger(log4cxx::LoggerPtr logger) : m_logger(logger) {}
};


// end of namespace util
}
