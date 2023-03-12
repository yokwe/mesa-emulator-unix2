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
// test_util.cpp
//

#include "../util/logger.h"
static const auto logger = util::Logger::getLogger("test_util");

#include "test_base.h"

#include "../util/util.h"

class test_util : public test_base {
	CPPUNIT_TEST_SUITE(test_util);

	CPPUNIT_TEST(test_demangle);
	CPPUNIT_TEST(test_startsWith);
	CPPUNIT_TEST(test_endsWith);

	CPPUNIT_TEST_SUITE_END();

public:
	void test_demangle() {
		auto a = typeid(std::vector<int>).name();
		auto b = util::demangle(a);
		auto c = util::demangle(typeid(std::vector<int>).name());

		logger.info("a = %s!", a);
		logger.info("b = %s!", b);
		logger.info("c = %s!", c);
    	CPPUNIT_ASSERT_EQUAL(b, c);
	}
	void test_startsWith() {
		CPPUNIT_ASSERT_EQUAL(true,  util::startsWith("aabbcc", "aa"));
		CPPUNIT_ASSERT_EQUAL(false, util::startsWith("aabbcc", "aaa"));
	}
	void test_endsWith() {
		CPPUNIT_ASSERT_EQUAL(true,  util::endsWith("aabbcc", "cc"));
		CPPUNIT_ASSERT_EQUAL(false, util::endsWith("aabbcc", "ccc"));
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_util);
