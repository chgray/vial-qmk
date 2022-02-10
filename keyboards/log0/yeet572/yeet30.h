#ifndef YEET_30_H
#define YEET_30_H

#include "quantum.h"

 //A = 10
 //B = 11
 //C = 12
 //D = 13

  // 18, 17, 17, 16, 15, 11
  #define LAYOUT( \
    K1D,   K3C,   K0D,   K52,   K30,   K43,   K44,   K45,   K46,   K65,   K60,   K62,   K67,   K64,   K63,   K68,   K61,   K66, \
    K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K57,   K58,   K59,   K2C,   K0C,   K2D, \
    K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K53,   K54,   K2A,   K1B,   K5B,   K4B,   K4C, \
    K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K4A,   K5A,   K0B,   K2B,   K1A,   K3A, \
    K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K50,   K56,   K55,   K51,   K1C,   K5C, \
    K40,   K41,   K42,   K49,   K69,   K47,   K48,   K3B,   K5D,   K4D,   K3D \
    ) { \
    {K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,  K0D}, \
    {K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,  K1D}, \
    {K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,  K2D}, \
    {K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,  K3D}, \
    {K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,   K48,   K49,   K4A,   K4B,   K4C,  K4D}, \
    {K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57,   K58,   K59,   K5A,   K5B,   K5C,  K5D}, \
    {K60,   K61,   K62,   K63,   K64,   K65,   K66,   K67,   K68,   K69,   0,0,0,0} \
  }

  #define LED_LAYOUT( \
    K1D,   K3C,   K0D,   K52,   K30,   K43,   K44,   K45,   K46,   K65,   K60,   K62,   K67,   K64,   K63,   K68,   K61,   K66, \
    K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K57,   K58,   K59,   K2C,   K0C,   K2D, \
    K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K53,   K54,   K2A,   K1B,   K5B,   K4B,   K4C, \
    K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K4A,   K5A,   K0B,   K2B,   K1A,   K3A, \
    K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K50,   K56,   K55,   K51,   K1C,   K5C, \
    K40,   K41,   K42,   LS1,   LS2,   K49,   LS3,   LS4,   K69,   K47,   K48,   K3B,   K5D,   K4D,   K3D \
    ) K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,  K0D, \
      K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,  K1D, \
      K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,  K2D, \
      K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,  K3D, \
      K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,   K48,   K49,   K4A,   K4B,   K4C,  K4D, \
      K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57,   K58,   K59,   K5A,   K5B,   K5C,  K5D, \
      K60,   K61,   K62,   LS1,   LS2,   K63,   LS3,   LS4,   K64,   K65,   K66,   K67,   K68,  K69


#endif
