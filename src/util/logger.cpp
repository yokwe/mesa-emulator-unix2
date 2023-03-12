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
// logger.cpp
//

#include "logger.h"

#include <log4cxx/log4cxx.h>
#include <log4cxx/logmanager.h>
#include <log4cxx/level.h>
#include <log4cxx/logger.h>
#include <log4cxx/propertyconfigurator.h>

namespace util {
// start of namespace util


void Logger::pushLevel(log4cxx::LevelPtr newValue) {
	// save current level to priorityStack
	levelStack.push_back(log4cxx::LogManager::getRootLogger()->getLevel());
	// set root logger level
	log4cxx::LogManager::getRootLogger()->setLevel(newValue);
}
void Logger::popLevel() {
	if (levelStack.empty()) return;

	// restore current level from priorityStack
	log4cxx::LevelPtr newValue = levelStack.back();
	levelStack.pop_back();

	log4cxx::LogManager::getRootLogger()->setLevel(newValue);
}



Logger Logger::getLogger(const char* name) {
	static struct config_t {
		config_t() {
			static char *file_name = getenv("LOG_CONFIG");
			if (file_name == nullptr) {
				std::fprintf(stderr, "file_name == nullptr\n");
				exit(1);
			}

			log4cxx::LogManager::resetConfiguration();
			log4cxx::PropertyConfigurator::configure(file_name);
		}
		~config_t() {
			log4cxx::LogManager::shutdown();
		}
	} config;


	auto logger = log4cxx::LogManager::getLogger(name);

	return Logger(logger);
}

// end of namespace util
}
