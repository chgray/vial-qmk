#include "yeet30.h"


#ifdef RGB_MATRIX_ENABLE


//https://docs.qmk.fm/#/feature_rgb_matrix?id=common-configuration


  // 18, 17, 17, 16, 15, 11
#define R18(row, a,b,c,d,e,  f,g,h,i,j,  k,l,m,n,o,  p,q,r) \
    {row,a},{row,b},{row,c},{row,d},{row,e}, \
    {row,f},{row,g},{row,h},{row,i},{row,j}, \
    {row,k},{row,l},{row,m},{row,n},{row,o}, \
    {row,p},{row,q},{row,r}

#define R17(row, a,b,c,d,e,  f,g,h,i,j,  k,l,m,n,o,  p,q,r) \
    {row,a},{row,b},{row,c},{row,d},{row,e}, \
    {row,f},{row,g},{row,h},{row,i},{row,j}, \
    {row,k},{row,l},{row,m},{row,n},{row,o}, \
    {row,p},{row,q}

#define R16(row, a,b,c,d,e,  f,g,h,i,j,  k,l,m,n,o,  p,q,r) \
    {row,a},{row,b},{row,c},{row,d},{row,e}, \
    {row,f},{row,g},{row,h},{row,i},{row,j}, \
    {row,k},{row,l},{row,m},{row,n},{row,o}, \
    {row,p}

#define R15(row, a,b,c,d,e,  f,g,h,i,j,  k,l,m,n,o,  p,q,r) \
    {row,a},{row,b},{row,c},{row,d},{row,e}, \
    {row,f},{row,g},{row,h},{row,i},{row,j}, \
    {row,k},{row,l},{row,m},{row,n},{row,o}

#define R11(row, a,b,c,d,e,  f,g,h,i,j,  k,l,m,n,o,  p,q,r) \
    {row,a},{row,b},{row,c},{row,d},{row,e}, \
    {row,f},{row,g},{row,h},{row,i},{row,j}, \
    {row,k}



/*
,
             R2(0, 1, 2, 3, 4,    5, 6, 7, 5, 5,     5, 5, 5, 5, 5,    5, 5),
             R3(5, 5, 5, 5, 5,    5, 5, 5, 5, 5,     5, 5, 5, 5, 5,    5, 5),
             R4(5, 5, 5, 5, 5,    5, 5, 5, 5, 5,     5, 5, 5, 5, 5,    5),
             R5(5, 5, 5, 5, 5,    5, 5, 5, 5, 5,     5, 5, 5, 5, 5),
             R6(5, 5, 5, 5, 5,    5, 5, 5, 5, 5,     5)
*/

led_config_t g_led_config = {
    LAYOUT(  16, 17, 51, 52, 82,    71, 72, 73, 74, 87,     85, 84, 90, 88, 86,    89, 91, 92,
              0,  1,  2,  3,  4,     5,  6,  7,  8,  9,     10, 11, 12, 83, 13,    14, 15,
             34, 33, 32, 31, 30,    29, 28, 27, 26, 25,     24, 23, 22, 21, 20,    19, 18,
             35, 36, 37, 38, 39,    40, 41, 42, 43, 44,     45, 46, 47, 48, 49,    50,
             67, 66, 65, 64, 63,    62, 61, 60, 59, 58,     57, 56, 55, 54, 53,
             68, 69, 70, 97, 75,    76, 77, 78, 79, 80,     81)
, {
             R18(1,    1, 1, 5, 5, 8,    5, 5, 5, 5, 5,     5, 5, 5, 5, 5,    5, 5, 5)
}, {
     UNGROUPED_LAYOUT(
        16, 17, 51, 52, 82,    71, 5, 5, 5, 5,     5, 5, 5, 5, 5,    5, 5, 5,
             0, 1, 2, 3, 4,    5, 6, 7, 5, 5,     5, 5, 5, 5, 5,    5, 5,
             5, 5, 5, 5, 5,    5, 5, 5, 5, 5,     5, 5, 5, 5, 5,    5, 5,
             5, 5, 5, 5, 5,    5, 5, 5, 5, 5,     5, 5, 5, 5, 5,    5,
             5, 5, 5, 5, 5,    5, 5, 5, 5, 5,     5, 5, 5, 5, 5,
             5, 5, 5, 5, 5,    5, 5, 5, 5, 5,     5)
} };
#endif
