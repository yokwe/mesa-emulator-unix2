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
// type.h
//

#pragma once

#include <cstdint>

// offset of is defined in stddef.h
#include <stddef.h>

namespace mesa {
// start of namespace mesa


// base data type
using CARD8  = std::uint8_t;
using CARD16 = std::uint16_t;
using CARD32 = std::uint32_t;

using INT8  = std::int8_t;
using INT16 = std::int16_t;
using INT32 = std::int32_t;

// derived data type
using BYTE = CARD8;

using POINTER      = CARD16;
using LONG_POINTER = CARD32;

using UNSPEC      = CARD16;
using LONG_UNSPEC = CARD32;

using CARDINAL      = CARD16;
using LONG_CARDINAL = CARD32;

using INT      = INT16;
using LONG_INT = INT32;


// common macro
#define SIZE(t)       ((mesa::CARD32)(sizeof(t) / sizeof(mesa::CARD16)))
#define ELEMENTSOF(t) ((mesa::CARD32)(sizeof(t) / sizeof(t[0])))

// OFFSET must returns CARD32 for CPPUNIT_ASSERT_EQUAL
#define OFFSET(s,m)      (mesa::CARD32)(offsetof(s,m) / sizeof(mesa::CARD16))
#define OFFSET3(s,m,n)   (mesa::CARD32)(OFFSET(s,m)    + ((offsetof(s,m[1])   - offsetof(s,m[0])) * n) / sizeof(mesa::CARD16))
#define OFFSET4(s,m,n,p) (mesa::CARD32)(OFFSET3(s,m,n) + ((offsetof(s,m[0].p) - offsetof(s,m[0])))     / sizeof(mesa::CARD16))


// end   of namespace mesa
}
