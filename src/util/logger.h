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

#include <log4cxx/log4cxx.h>
#include <log4cxx/logger.h>

#include "format.h"


namespace util {
// start of namespace util


class Logger {
public:
	static Logger getLogger(const char *name);

    static inline log4cxx::LevelPtr ALL   = log4cxx::Level::getAll();
    static inline log4cxx::LevelPtr DEBUG = log4cxx::Level::getDebug();
    static inline log4cxx::LevelPtr INFO  = log4cxx::Level::getInfo();
    static inline log4cxx::LevelPtr WARN  = log4cxx::Level::getWarn();
    static inline log4cxx::LevelPtr ERROR = log4cxx::Level::getError();
    static inline log4cxx::LevelPtr FATAL = log4cxx::Level::getFatal();
    static inline log4cxx::LevelPtr OFF   = log4cxx::Level::getOff();

	static void pushLevel(log4cxx::LevelPtr newValue);
	static void popLevel();


	// std::string
	void debug(const std::string& string) const {
		logger->debug(string);
	}
	void info(const std::string& string) const {
		logger->info(string);
	}
	void warn(const std::string& string) const{
		logger->warn(string);
	}
	void error(const std::string& string) const {
		logger->error(string);
	}
	void fatal(const std::string& string) const {
		logger->fatal(string);
	}

	// const char*
	void debug(const char* string) const {
		logger->debug(std::string(string));
	}
	void info(const char* string) const {
		logger->info(std::string(string));
	}
	void warn(const char* string) const {
		logger->warn(std::string(string));
	}
	void error(const char* string) const {
		logger->error(std::string(string));
	}
	void fatal(const char* string) const {
		logger->fatal(std::string(string));
	}


    template<typename... Args> void debug(const char* format, Args&& ... args) const {
    	logger->debug(sprintf(format, args...));
    }
    template<typename... Args> void info(const char* format, Args&& ... args) const {
     	logger->info(sprintf(format, args...));
     }
    template<typename... Args> void warn(const char* format, Args&& ... args) const {
     	logger->warn(sprintf(format, args...));
     }
    template<typename... Args> void error(const char* format, Args&& ... args) const {
    	logger->error(sprintf(format, args...));
    }
    template<typename... Args> void fatal(const char* format, Args&& ... args) const {
    	logger->fatal(sprintf(format, args...));
    }

private:
    static inline std::vector<log4cxx::LevelPtr> levelStack;

	log4cxx::LoggerPtr logger;
	Logger(log4cxx::LoggerPtr logger_) : logger(logger_) {}
};


// end of namespace util
}
