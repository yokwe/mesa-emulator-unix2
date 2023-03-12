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
// princops_constant.h
//

#pragma once

#include "type.h"

namespace mesa {
// start of namespace mesa


// for compatibility
//constexpr CARD16 PageSize = Environment::wordsPerPage;
constexpr CARD16 PageSize = 256;

constexpr CARD16 cSS = 14;
// cSV = SIZE[StateVector] + MAX[SIZE[ControlLink], SIZE[FSIndex], SIZE[LONG POINTER]]
// SIZE[StateVector] = 16 and SIZE[LONG POINTER] = 2. So cSV should be 16 + 2 = 18
constexpr CARD16 cSV = 18;
//constexpr CARD16 cWM = 10; // Noone use this value - cWDC <= cWM
constexpr CARD16 cWDC = 7;
//constexpr CARD16 cTickMin = 15;
//constexpr CARD16 cTickMax = 60;

// 1 tick = 40 milliseconds
constexpr CARD16 cTick = 40;

constexpr CARD32 mPDA = 0x00010000; // 0200000
constexpr CARD32 mGFT = 0x00020000; // 0400000

constexpr CARD16 mAV  = 0x0100; //  0400
constexpr CARD16 mSD  = 0x0200; // 01000
constexpr CARD16 mETT = 0x0400; // 02000

constexpr CARD16 qFrameFault        = 0;
constexpr CARD16 qPageFault         = 1;
constexpr CARD16 qWriteProtectFault = 2;

constexpr CARD16 sBoot            = 001; //  1
constexpr CARD16 sBoundsTrap      = 016; // 14
constexpr CARD16 sBreakTrap       = 000; //  0
constexpr CARD16 sCodeTrap        = 007; //  7
constexpr CARD16 sControlTrap     = 006; //  6
constexpr CARD16 sDivCheckTrap    = 013; // 11
constexpr CARD16 sDivZeroTrap     = 012; // 10
constexpr CARD16 sInterruptError  = 014; // 12
constexpr CARD16 sOpcodeTrap      = 005; //  5
constexpr CARD16 sPointerTrap     = 017; // 15
constexpr CARD16 sProcessTrap     = 015; // 13
constexpr CARD16 sRescheduleError = 003; //  3
constexpr CARD16 sStackError      = 002; //  2
constexpr CARD16 sUnboundTrap     = 011; //  9
constexpr CARD16 sXferTrap        = 004; //  4
constexpr CARD16 sHardwareError   = 010; //  8


// Instruction code
constexpr CARD8 zNOOP    = 00;
constexpr CARD8 zLL0     = 01;
constexpr CARD8 zLL1     = 02;
constexpr CARD8 zLL2     = 03;
constexpr CARD8 zLL3     = 04;
constexpr CARD8 zLL4     = 05;
constexpr CARD8 zLL5     = 06;
constexpr CARD8 zLL6     = 07;

constexpr CARD8 zLL7     = 010;
constexpr CARD8 zLL8     = 011;
constexpr CARD8 zLL9     = 012;
constexpr CARD8 zLL10    = 013;
constexpr CARD8 zLL11    = 014;
constexpr CARD8 zLLB     = 015;
constexpr CARD8 zLLD0    = 016;
constexpr CARD8 zLLD1    = 017;

constexpr CARD8 zLLD2    = 020;
constexpr CARD8 zLLD3    = 021;
constexpr CARD8 zLLD4    = 022;
constexpr CARD8 zLLD5    = 023;
constexpr CARD8 zLLD6    = 024;
constexpr CARD8 zLLD7    = 025;
constexpr CARD8 zLLD8    = 026;
constexpr CARD8 zLLD10   = 027;

constexpr CARD8 zLLDB    = 030;
constexpr CARD8 zSL0     = 031;
constexpr CARD8 zSL1     = 032;
constexpr CARD8 zSL2     = 033;
constexpr CARD8 zSL3     = 034;
constexpr CARD8 zSL4     = 035;
constexpr CARD8 zSL5     = 036;
constexpr CARD8 zSL6     = 037;

constexpr CARD8 zSL7     = 040;
constexpr CARD8 zSL8     = 041;
constexpr CARD8 zSL9     = 042;
constexpr CARD8 zSL10    = 043;
constexpr CARD8 zSLB     = 044;
constexpr CARD8 zSLD0    = 045;
constexpr CARD8 zSLD1    = 046;
constexpr CARD8 zSLD2    = 047;

constexpr CARD8 zSLD3    = 050;
constexpr CARD8 zSLD4    = 051;
constexpr CARD8 zSLD5    = 052;
constexpr CARD8 zSLD6    = 053;
constexpr CARD8 zSLD8    = 054;
constexpr CARD8 zPL0     = 055;
constexpr CARD8 zPL1     = 056;
constexpr CARD8 zPL2     = 057;

constexpr CARD8 zPL3     = 060;
constexpr CARD8 zPLB     = 061;
constexpr CARD8 zPLD0    = 062;
constexpr CARD8 zPLDB    = 063;
constexpr CARD8 zLG0     = 064;
constexpr CARD8 zLG1     = 065;
constexpr CARD8 zLG2     = 066;
constexpr CARD8 zLGB     = 067;

constexpr CARD8 zLGD0    = 070;
constexpr CARD8 zLGD2    = 071;
constexpr CARD8 zLGDB    = 072;
constexpr CARD8 zSGB     = 073;
constexpr CARD8 zBNDCK   = 074;
constexpr CARD8 zBRK     = 075;
//
constexpr CARD8 zSTC     = 077;

constexpr CARD8 zR0      = 0100;
constexpr CARD8 zR1      = 0101;
constexpr CARD8 zRB      = 0102;
constexpr CARD8 zRL0     = 0103;
constexpr CARD8 zRLB     = 0104;
constexpr CARD8 zRD0     = 0105;
constexpr CARD8 zRDB     = 0106;
constexpr CARD8 zRDL0    = 0107;

constexpr CARD8 zRDLB    = 0110;
constexpr CARD8 zW0      = 0111;
constexpr CARD8 zWB      = 0112;
constexpr CARD8 zPSB     = 0113;
constexpr CARD8 zWLB     = 0114;
constexpr CARD8 zPSLB    = 0115;
constexpr CARD8 zWDB     = 0116;
constexpr CARD8 zPSD0    = 0117;

constexpr CARD8 zPSDB    = 0120;
constexpr CARD8 zWDLB    = 0121;
constexpr CARD8 zPSDLB   = 0122;
constexpr CARD8 zRLI00   = 0123;
constexpr CARD8 zRLI01   = 0124;
constexpr CARD8 zRLI02   = 0125;
constexpr CARD8 zRLI03   = 0126;
constexpr CARD8 zRLIP    = 0127;

constexpr CARD8 zRLILP   = 0130;
constexpr CARD8 zRLDI00  = 0131;
constexpr CARD8 zRLDIP   = 0132;
constexpr CARD8 zRLDILP  = 0133;
constexpr CARD8 zRGIP    = 0134;
constexpr CARD8 zRGILP   = 0135;
constexpr CARD8 zWLIP    = 0136;
constexpr CARD8 zWLILP   = 0137;

constexpr CARD8 zWLDILP  = 0140;
constexpr CARD8 zRS      = 0141;
constexpr CARD8 zRLS     = 0142;
constexpr CARD8 zWS      = 0143;
constexpr CARD8 zWLS     = 0144;
constexpr CARD8 zR0F     = 0145;
constexpr CARD8 zRF      = 0146;
constexpr CARD8 zRL0F    = 0147;

constexpr CARD8 zRLF     = 0150;
constexpr CARD8 zRLFS    = 0151;
constexpr CARD8 zRLIPF   = 0152;
constexpr CARD8 zRLILPF  = 0153;
constexpr CARD8 zW0F     = 0154;
constexpr CARD8 zWF      = 0155;
constexpr CARD8 zPSF     = 0156;
constexpr CARD8 zPS0F    = 0157;

constexpr CARD8 zWS0F    = 0160;
constexpr CARD8 zWL0F    = 0161;
constexpr CARD8 zWLF     = 0162;
constexpr CARD8 zPSLF    = 0163;
constexpr CARD8 zWLFS    = 0164;
constexpr CARD8 zSLDB    = 0165;
constexpr CARD8 zSGDB    = 0166;
constexpr CARD8 zLLKB    = 0167;

constexpr CARD8 zRKIB    = 0170;
constexpr CARD8 zRKDIB   = 0171;
constexpr CARD8 zLKB     = 0172;
constexpr CARD8 zSHIFT   = 0173;
constexpr CARD8 zSHIFTSB = 0174;
constexpr CARD8 zMBP     = 0175;
constexpr CARD8 zRBP     = 0176;
constexpr CARD8 zWBP     = 0177;


constexpr CARD8 zCATCH   = 0200;
constexpr CARD8 zJ2      = 0201;
constexpr CARD8 zJ3      = 0202;
constexpr CARD8 zJ4      = 0203;
constexpr CARD8 zJ5      = 0204;
constexpr CARD8 zJ6      = 0205;
constexpr CARD8 zJ7      = 0206;
constexpr CARD8 zJ8      = 0207;

constexpr CARD8 zJB      = 0210;
constexpr CARD8 zJW      = 0211;
constexpr CARD8 zJEP     = 0212;
constexpr CARD8 zJEB     = 0213;
constexpr CARD8 zJEBB    = 0214;
constexpr CARD8 zJNEP    = 0215;
constexpr CARD8 zJNEB    = 0216;
constexpr CARD8 zJNEBB   = 0217;

constexpr CARD8 zJLB     = 0220;
constexpr CARD8 zJGEB    = 0221;
constexpr CARD8 zJGB     = 0222;
constexpr CARD8 zJLEB    = 0223;
constexpr CARD8 zJULB    = 0224;
constexpr CARD8 zJUGEB   = 0225;
constexpr CARD8 zJUGB    = 0226;
constexpr CARD8 zJULEB   = 0227;

constexpr CARD8 zJZ3     = 0230;
constexpr CARD8 zJZ4     = 0231;
constexpr CARD8 zJZB     = 0232;
constexpr CARD8 zJNZ3    = 0233;
constexpr CARD8 zJNZ4    = 0234;
constexpr CARD8 zJNZB    = 0235;
constexpr CARD8 zJDEB    = 0236;
constexpr CARD8 zJDNEB   = 0237;

constexpr CARD8 zJIB     = 0240;
constexpr CARD8 zJIW     = 0241;
constexpr CARD8 zREC     = 0242;
constexpr CARD8 zREC2    = 0243;
constexpr CARD8 zDIS     = 0244;
constexpr CARD8 zDIS2    = 0245;
constexpr CARD8 zEXCH    = 0246;
constexpr CARD8 zDEXCH   = 0247;

constexpr CARD8 zDUP     = 0250;
constexpr CARD8 zDDUP    = 0251;
constexpr CARD8 zEXDIS   = 0252;
constexpr CARD8 zNEG     = 0253;
constexpr CARD8 zINC     = 0254;
constexpr CARD8 zDEC     = 0255;
constexpr CARD8 zDINC    = 0256;
constexpr CARD8 zDBL     = 0257;

constexpr CARD8 zDDBL    = 0260;
constexpr CARD8 zTRPL    = 0261;
constexpr CARD8 zAND     = 0262;
constexpr CARD8 zIOR     = 0263;
constexpr CARD8 zADDSB   = 0264;
constexpr CARD8 zADD     = 0265;
constexpr CARD8 zSUB     = 0266;
constexpr CARD8 zDADD    = 0267;

constexpr CARD8 zDSUB    = 0270;
constexpr CARD8 zADC     = 0271;
constexpr CARD8 zACD     = 0272;
constexpr CARD8 zAL0IB   = 0273;
constexpr CARD8 zMUL     = 0274;
constexpr CARD8 zDCMP    = 0275;
constexpr CARD8 zUDCMP   = 0276;
constexpr CARD8 zVMFIND  = 0277;

constexpr CARD8 zLI0     = 0300;
constexpr CARD8 zLI1     = 0301;
constexpr CARD8 zLI2     = 0302;
constexpr CARD8 zLI3     = 0303;
constexpr CARD8 zLI4     = 0304;
constexpr CARD8 zLI5     = 0305;
constexpr CARD8 zLI6     = 0306;
constexpr CARD8 zLI7     = 0307;

constexpr CARD8 zLI8     = 0310;
constexpr CARD8 zLI9     = 0311;
constexpr CARD8 zLI10    = 0312;
constexpr CARD8 zLIN1    = 0313;
constexpr CARD8 zLINI    = 0314;
constexpr CARD8 zLIB     = 0315;
constexpr CARD8 zLIW     = 0316;
constexpr CARD8 zLINB    = 0317;

constexpr CARD8 zLIHB    = 0320;
constexpr CARD8 zLID0    = 0321;
constexpr CARD8 zLA0     = 0322;
constexpr CARD8 zLA1     = 0323;
constexpr CARD8 zLA2     = 0324;
constexpr CARD8 zLA3     = 0325;
constexpr CARD8 zLA6     = 0326;
constexpr CARD8 zLA8     = 0327;

constexpr CARD8 zLAB     = 0330;
constexpr CARD8 zLAW     = 0331;
constexpr CARD8 zGA0     = 0332;
constexpr CARD8 zGA1     = 0333;
constexpr CARD8 zGAB     = 0334;
constexpr CARD8 zGAW     = 0335;
constexpr CARD8 zCAW     = 0336;
constexpr CARD8 zEFC0    = 0337;

constexpr CARD8 zEFC1    = 0340;
constexpr CARD8 zEFC2    = 0341;
constexpr CARD8 zEFC3    = 0342;
constexpr CARD8 zEFC4    = 0343;
constexpr CARD8 zEFC5    = 0344;
constexpr CARD8 zEFC6    = 0345;
constexpr CARD8 zEFC7    = 0346;
constexpr CARD8 zEFC8    = 0347;

constexpr CARD8 zEFC9    = 0350;
constexpr CARD8 zEFC10   = 0351;
constexpr CARD8 zEFC11   = 0352;
constexpr CARD8 zEFC12   = 0353;
constexpr CARD8 zEFCB    = 0354;
constexpr CARD8 zLFC     = 0355;
constexpr CARD8 zSFC     = 0356;
constexpr CARD8 zRET     = 0357;

constexpr CARD8 zKFCB    = 0360;
constexpr CARD8 zME      = 0361;
constexpr CARD8 zMX      = 0362;
constexpr CARD8 zBLT     = 0363;
constexpr CARD8 zBLTL    = 0364;
constexpr CARD8 zBLTC    = 0365;
constexpr CARD8 zBLTCL   = 0366;
constexpr CARD8 zLP      = 0367;

constexpr CARD8 zESC     = 0370;
constexpr CARD8 zESCL    = 0371;
constexpr CARD8 zLGA0    = 0372;
constexpr CARD8 zLGAB    = 0373;
constexpr CARD8 zLGAW    = 0374;
constexpr CARD8 zDESC    = 0375;

constexpr CARD8 zRESRVD  = 0377;

//
constexpr CARD8 a00      = 00;
constexpr CARD8 a01      = 01;
constexpr CARD8 aMW      = 02;
constexpr CARD8 aMR      = 03;
constexpr CARD8 aNC      = 04;
constexpr CARD8 aBC      = 05;
constexpr CARD8 aREQ     = 06;
constexpr CARD8 aSM      = 07;

constexpr CARD8 aSMF     = 010;
constexpr CARD8 aGMF     = 011;
constexpr CARD8 aAF      = 012;
constexpr CARD8 aFF      = 013;
constexpr CARD8 aPI      = 014;
constexpr CARD8 aPO      = 015;
constexpr CARD8 aPOR     = 016;
constexpr CARD8 aSPP     = 017;

constexpr CARD8 aDI      = 020;
constexpr CARD8 aEI      = 021;
constexpr CARD8 aXOR     = 022;
constexpr CARD8 aDAND    = 023;
constexpr CARD8 aDIOR    = 024;
constexpr CARD8 aDXOR    = 025;
constexpr CARD8 aROTATE  = 026;
constexpr CARD8 aDSHIFT  = 027;
constexpr CARD8 aLINT    = 030;
constexpr CARD8 aJS      = 031;
constexpr CARD8 aRCFS    = 032;
constexpr CARD8 bRC      = 033;
constexpr CARD8 aUDIV    = 034;
constexpr CARD8 aLUDIV   = 035;
constexpr CARD8 bROB     = 036;
constexpr CARD8 bWOB     = 037;

constexpr CARD8 bDSK     = 040;
constexpr CARD8 bXE      = 041;
constexpr CARD8 bXF      = 042;
constexpr CARD8 bLSK     = 043;
constexpr CARD8 aBNDCKL  = 044;
constexpr CARD8 aNILCK   = 045;
constexpr CARD8 aNILCKL  = 046;
constexpr CARD8 aBLTLR   = 047;
constexpr CARD8 aBLEL    = 050;
constexpr CARD8 aBLECL   = 051;
constexpr CARD8 aCKSUM   = 052;
constexpr CARD8 aBITBLT  = 053;
constexpr CARD8 aTXTBLT  = 054;
constexpr CARD8 aBYTBLT  = 055;
constexpr CARD8 aBYTBLTR = 056;
constexpr CARD8 aVERSION = 057;

constexpr CARD8 aDMUL    = 060;
constexpr CARD8 aSDIV    = 061;
constexpr CARD8 aSDDIV   = 062;
constexpr CARD8 aUDDIV   = 063;
constexpr CARD8 a64      = 064;
constexpr CARD8 a65      = 065;
constexpr CARD8 a66      = 066;
constexpr CARD8 a67      = 067;
constexpr CARD8 a70      = 070;
constexpr CARD8 a71      = 071;
constexpr CARD8 a72      = 072;
constexpr CARD8 a73      = 073;
constexpr CARD8 a74      = 074;
constexpr CARD8 a75      = 075;
constexpr CARD8 a76      = 076;
constexpr CARD8 a77      = 077;

// Floating Point (100B-137B are reserved)
constexpr CARD8 aFADD    = 0100;
constexpr CARD8 aFSUB    = 0101;
constexpr CARD8 aFMUL    = 0102;
constexpr CARD8 aFDIV    = 0103;
constexpr CARD8 aFCOMP   = 0104;
constexpr CARD8 aFIX     = 0105;
constexpr CARD8 aFLOAT   = 0106;
constexpr CARD8 aFIXI    = 0107;
constexpr CARD8 aFIXC    = 0110;
constexpr CARD8 aFSTICKY = 0111;
constexpr CARD8 aFREM    = 0112;
constexpr CARD8 aROUND   = 0113;
constexpr CARD8 aROUNDI  = 0114;
constexpr CARD8 aROUNDC  = 0115;
constexpr CARD8 aFSQRT   = 0116;
constexpr CARD8 aFSC     = 0117;

// Cedar collector and allocator (140B-157B are reserved)
//constexpr CARD8 aRECLAIMREF            = 0140;
//constexpr CARD8 aALTERCOUNT            = 0141;
//constexpr CARD8 aRESETSTKBITS          = 0142;
//constexpr CARD8 aGCSETUP               = 0143;
//constexpr CARD8 a144                   = 0144;
//constexpr CARD8 aENUMERATERECLAIMABLE  = 0145;
//constexpr CARD8 a146                   = 0146;
//constexpr CARD8 aCREATEREF             = 0147;
//constexpr CARD8 a150                   = 0150;
//constexpr CARD8 aREFTYPE               = 0151;
//constexpr CARD8 aCANONICALREFTYPE      = 0152;
//constexpr CARD8 aALLOCQUANTIZED        = 0153;
//constexpr CARD8 aALLOCHEAP             = 0154;
//constexpr CARD8 aFREEOBJECT            = 0155;
//constexpr CARD8 aFREEQUANTIZED         = 0156;
//constexpr CARD8 aFREEPREFIXED          = 0157;

//  Read / Write Registers
constexpr CARD8 aWRPSB   = 0160;
constexpr CARD8 aWRMDS   = 0161;
constexpr CARD8 aWRWP    = 0162;
constexpr CARD8 aWRWDC   = 0163;
constexpr CARD8 aWRPTC   = 0164;
constexpr CARD8 aWRIT    = 0165;
constexpr CARD8 aWRXTS   = 0166;
constexpr CARD8 aWRMP    = 0167;
constexpr CARD8 aRRPSB   = 0170;
constexpr CARD8 aRRMDS   = 0171;
constexpr CARD8 aRRWP    = 0172;
constexpr CARD8 aRRWDC   = 0173;
constexpr CARD8 aRRPTC   = 0174;
constexpr CARD8 aRRIT    = 0175;
constexpr CARD8 aRRXTS   = 0176;
constexpr CARD8 a177     = 0177;

// Processor Dependent (200B-237B are reserved)
//constexpr CARD8 aINPUT   = 0200;
//constexpr CARD8 aOUTPUT  = 0201;
//constexpr CARD8 aLOADRAMJ= 0202;

// Dandelion
//constexpr CARD8 aBANDBLT = 0203;

// ESCAlphaExtra3.mesa
//constexpr CARD8 aLOCKQUEUE = 206B;

// Dolphin
//constexpr CARD8 aRPRINTER  = 0203;
//constexpr CARD8 aWPRINTER  = 0204;
//constexpr CARD8 aREADRAM   = 0205;
//constexpr CARD8 aJRAM      = 0206;
//constexpr CARD8 aCCOPR     = 0207;
//constexpr CARD8 aFPOPR     = 0210;
//constexpr CARD8 aSTARTIO   = 0211;

//Guam
constexpr CARD8 aCALLAGENT    = 0211;
constexpr CARD8 aMAPDISPLAY   = 0212;
constexpr CARD8 aSTOPEMULATOR = 0213;
constexpr CARD8 a214          = 0214;
//
constexpr CARD8 aCOLORBLT     = 0300;
constexpr CARD8 a305          = 0305;
constexpr CARD8 a306          = 0306;


// end   of namespace mesa
}
