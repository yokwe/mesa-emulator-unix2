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

#include "../util/format.h"
#include "../util/mesa.h"
#include "../util/util.h"

class test_util : public test_base {
	CPPUNIT_TEST_SUITE(test_util);

	// format.h
	CPPUNIT_TEST(test_snprintf);
	CPPUNIT_TEST(test_sprintf);
	// mesa.h
	CPPUNIT_TEST(test_toIntMesaNumber);
	// util.h
	CPPUNIT_TEST(test_demangle);
	CPPUNIT_TEST(test_startsWith);
	CPPUNIT_TEST(test_endsWith);
	CPPUNIT_TEST(test_toHexString);

	CPPUNIT_TEST_SUITE_END();

public:
	// format.h
	void test_snprintf() {
		{
			std::string a = "ab  ";
			std::string b;
			util::snprintf(b, 2, "%-4s", "ab");
			CPPUNIT_ASSERT_EQUAL(a, b);
		}
		{
			std::string a = "ab  ";
			std::string b;
			util::snprintf(b, 10, "%-4s", "ab");
			CPPUNIT_ASSERT_EQUAL(a, b);
		}
		{
			std::string a = "ab  ";
			std::string b;
			util::snprintf(b, 10, "%-4s", std::string("ab"));
			CPPUNIT_ASSERT_EQUAL(a, b);
		}
		{
			std::string a = "ab     3";
			//               12341234
			std::string b;
			util::snprintf(b, 10, "%-4s%4d", "ab", 3);
			CPPUNIT_ASSERT_EQUAL(a, b);
		}
	}
	void test_sprintf() {
		{
			std::string a = "ab  ";
			std::string b = util::sprintf("%-4s", "ab");
			CPPUNIT_ASSERT_EQUAL(a, b);
		}
		{
			std::string a = "ab  ";
			std::string b = util::sprintf("%-4s", std::string("ab"));
			CPPUNIT_ASSERT_EQUAL(a, b);
		}
		{
			std::string a = "ab     3";
			//               12341234
			std::string b = util::sprintf("%-4s%4d", "ab", 3);
			CPPUNIT_ASSERT_EQUAL(a, b);
		}
	}
	// mesa.h
	void test_toIntMesaNumber() {
		CPPUNIT_ASSERT_EQUAL(16, util::toIntMesaNumber(std::string("0x10")));
		CPPUNIT_ASSERT_EQUAL(16, util::toIntMesaNumber(std::string("10H")));
		CPPUNIT_ASSERT_EQUAL(16, util::toIntMesaNumber(std::string("20B")));
		CPPUNIT_ASSERT_EQUAL(16, util::toIntMesaNumber(std::string("16")));
	}
	// util.h
	void test_demangle() {
		enum AA {aa};
		auto a = util::demangle(typeid(AA).name());
		auto b = std::string("test_util::test_demangle()::AA");
    	CPPUNIT_ASSERT_EQUAL(a, b);
	}
	void test_startsWith() {
		(void)logger;
		CPPUNIT_ASSERT_EQUAL(true,  util::startsWith("aabbcc", "aa"));
		CPPUNIT_ASSERT_EQUAL(false, util::startsWith("aabbcc", "aaa"));
	}
	void test_endsWith() {
		CPPUNIT_ASSERT_EQUAL(true,  util::endsWith("aabbcc", "cc"));
		CPPUNIT_ASSERT_EQUAL(false, util::endsWith("aabbcc", "ccc"));
	}
	void test_toHexString() {
		const uint8_t data[] = "AB";
		auto a = util::toHexString(2, data);
		auto b = std::string("4142");
    	CPPUNIT_ASSERT_EQUAL(a, b);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_util);
