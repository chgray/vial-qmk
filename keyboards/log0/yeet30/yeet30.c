#include "yeet30.h"



//https://docs.qmk.fm/#/feature_rgb_matrix?id=common-configuration


  // 18, 17, 17, 16, 15, 11
#define R18(row,  a,b,c,d,e,  f,g,h,i,j,  k,l,m,n,o,  p,q,r) \
    {a, row},{b, row},{c, row},{d, row},{e, row}, \
    {f, row},{g, row},{h, row},{i, row},{j, row}, \
    {k, row},{l, row},{m, row},{n, row},{o, row}, \
    {p, row},{q, row},{r, row}

#define R17( row, a,b,c,d,e,  f,g,h,i,j,  k,l,m,n,o,  p,q) \
    {a, row},{b, row},{c, row},{d, row},{e, row}, \
    {f, row},{g, row},{h, row},{i, row},{j, row}, \
    {k, row},{l, row},{m, row},{n, row},{o, row}, \
    {p, row},{q, row}

#define R16(row,  a,b,c,d,e,  f,g,h,i,j,  k,l,m,n,o,  p) \
    {a, row},{b, row},{c, row},{d, row},{e, row}, \
    {f, row},{g, row},{h, row},{i, row},{j, row}, \
    {k, row},{l, row},{m, row},{n, row},{o, row}, \
    {p, row}

#define R15(row,  a,b,c,d,e,  f,g,h,i,j,  k,l,m,n,o) \
    {a, row},{b, row},{c, row},{d, row},{e, row}, \
    {f, row},{g, row},{h, row},{i, row},{j, row}, \
    {k, row},{l, row},{m, row},{n, row},{o, row}

#define R11( row, a,b,c,d,e,  f,g,h,i,j,  k) \
    {a, row},{b, row},{c, row},{d, row},{e, row}, \
    {f, row},{g, row},{h, row},{i, row},{j, row}, \
    {k, row}

#define CALL(macro, ...)  macro(__VA_ARGS__)
#define MP(x, y) {x, y}
#define YD1 {0,12}
#define YD2 {178,25}
#define YD3 {87,38}
#define YD4 {93,51}
#define YD5 {223,64}
#define YD6 {13,12}
#define YD7 {161,25}
#define YD8 {100,38}
#define YD9 {80,51}
#define YD10 {52,0}
#define YD11 {26,12}
#define YD12 {148,25}
#define YD13 {113,38}
#define YD14 {67,51}
#define YD15 {175,12}
#define YD16 {39,12}
#define YD17 {135,25}
#define YD18 {126,38}
#define YD19 {54,51}
#define YD20 {142,0}
#define YD21 {51,12}
#define YD22 {122,25}
#define YD23 {139,38}
#define YD24 {42,51}
#define YD25 {129,0}
#define YD26 {64,12}
#define YD27 {109,25}
#define YD28 {152,38}
#define YD29 {29,51}
#define YD30 {181,0}
#define YD31 {77,12}
#define YD32 {96,25}
#define YD33 {173,38}
#define YD34 {8,51}
#define YD35 {116,0}
#define YD36 {90,12}
#define YD37 {84,25}
#define YD38 {198,38}
#define YD39 {1,63}
#define YD40 {168,0}
#define YD41 {103,12}
#define YD42 {71,25}
#define YD43 {211,38}
#define YD44 {18,63}
#define YD45 {198,0}
#define YD46 {116,12}
#define YD47 {58,25}
#define YD48 {223,38}
#define YD49 {34,63}
#define YD50 {155,0}
#define YD51 {129,12}
#define YD52 {45,25}
#define YD53 {26,0}
#define YD54 {64,0}
#define YD55 {211,0}
#define YD56 {142,12}
#define YD57 {32,25}
#define YD58 {38,0}
#define YD59 {77,0}
#define YD60 {224,0}
#define YD61 {155,12}
#define YD62 {19,25}
#define YD63 {223,51}
#define YD64 {90,0}
#define YD65 {54,63}
#define YD66 {198,12}
#define YD67 {3,25}
#define YD68 {211,51}
#define YD69 {103,0}
#define YD70 {106,63}
#define YD71 {211,12}
#define YD72 {5,38}
#define YD73 {198,51}
#define YD74 {131,63}
#define YD75 {68,63}
#define YD76 {223,12}
#define YD77 {22,38}
#define YD78 {170,51}
#define YD79 {147,63}
#define YD80 {94,63}
#define YD81 {0,0}
#define YD82 {35,38}
#define YD83 {145,51}
#define YD84 {163,63}
#define YD85 {82,63}
#define YD86 {13,0}
#define YD87 {48,38}
#define YD88 {132,51}
#define YD89 {180,63}
#define YD90 {224,25}
#define YD91 {61,38}
#define YD92 {119,51}
#define YD93 {198,64}
#define YD94 {211,25}
#define YD95 {74,38}
#define YD96 {106,51}
#define YD97 {211,63}
#define YD98 {198,25}



#define LED_MAP(L00,L01,L02,L03,L04,        L05,L06,L07,L08,L09,   L10,L11,L12,L13,L14,    L15,L16,L17, \
                L18,L19,L20,L21,L22,        L23,L24,L25,L26,L27,   L28,L29,L30,L31,L32,    L33,L34, \
                L35,L36,L37,L38,L39,        L40,L41,L42,L43,L44,   L45,L46,L47,L48,L49,    L50,L51, \
                L52,L53,L54,L55,L56,        L57,L58,L59,L60,L61,   L62,L63,L64,L65,L66,    L67, \
                L68,L69,L70,L71,L72,        L73,L74,L75,L76,L77,   L78,L79,L80,L81,L82, \
                L83,L84,L85,  L86,L87,      L88,L89,L90,L91,L92,   L93,L94,L95,L96,L97) \
                L16, L17, L51, L52, L82,    L71, L72, L73, L74, L87,     L85, L84, L90, L88, L86,   L89, L91, L92, \
                L00, L01, L02, L03, L04,    L05, L06, L07, L08, L09,     L10, L11, L12, L83, L13,   L14, L15, \
                L34, L33, L32, L31, L30,    L29, L28, L27, L26, L25,     L24, L23, L22, L21, L20,   L19, L18, \
                L35, L36, L37, L38, L39,    L40, L41, L42, L43, L44,     L45, L46, L47, L48, L49,   L50, \
                L67, L66, L65, L64, L63,    L62, L61, L60, L59, L58,     L57, L56, L55, L54, L53, \
                L68, L69, L70, L86, L87,    L97, L88, L89, L75, L76,     L77, L78, L79, L80, L81 \


//https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_led_matrix#additional-config.h-options-id-additional-configh-options


//0, 12, 25, 38, 51, 64
led_config_t g_led_config = {
  LAYOUT(    16, 17, 51, 52, 82,    71, 72, 73, 74, 87,     85, 84, 90, 88, 86,    89, 91, 92,
              0,  1,  2,  3,  4,     5,  6,  7,  8,  9,     10, 11, 12, 83, 13,    14, 15,
             34, 33, 32, 31, 30,    29, 28, 27, 26, 25,     24, 23, 22, 21, 20,    19, 18,
             35, 36, 37, 38, 39,    40, 41, 42, 43, 44,     45, 46, 47, 48, 49,    50,
             67, 66, 65, 64, 63,    62, 61, 60, 59, 58,     57, 56, 55, 54, 53,
             68, 69, 70, 97, 75,    76, 77, 78, 79, 80,     81)
 , {
        YD1, YD6, YD11, YD16, YD21,   YD26, YD31, YD36, YD41, YD46,   YD51, YD56, YD61, YD66, YD71,   YD76, YD81, YD86, YD90, YD94,
        YD98, YD2, YD7, YD12, YD17,   YD22, YD27, YD32, YD37, YD42,   YD47, YD52, YD57, YD62, YD67,   YD72, YD77, YD82, YD87, YD91,
        YD95, YD3, YD8, YD13, YD18,   YD23, YD28, YD33, YD38, YD43,   YD48, YD53, YD58, YD63, YD68,   YD73, YD78, YD83, YD88, YD92,
        YD96, YD4, YD9, YD14, YD19,   YD24, YD29, YD34, YD39, YD44,   YD49, YD54, YD59, YD64, YD69,   YD74, YD79, YD84, YD89, YD93,
        YD97, YD5, YD10, YD15, YD20,  YD25, YD30, YD35, YD40, YD45,   YD50, YD55, YD60, YD65, YD70,   YD75, YD80, YD85

 },{
             4, 4, 4, 4, 4,    4, 4, 4, 4, 4,     4, 4, 4, 4, 4,    4, 4, 4,
             4, 4, 4, 4, 4,    4, 4, 4, 4, 4,     4, 4, 4, 4, 4,    4, 4,
             4, 4, 4, 4, 4,    4, 4, 4, 4, 4,     4, 4, 4, 4, 4,    4, 4,
             4, 4, 4, 4, 4,    4, 4, 4, 4, 4,     4, 4, 4, 4, 4,    4,
             4, 4, 4, 4, 4,    4, 4, 4, 4, 4,     4, 4, 4, 4, 4,
             4, 4, 4, 2, 2,    4, 2, 2, 4, 4,     4, 4, 4, 4, 4
} };


#if 1
void matrix_init_kb()
{
    matrix_init_user();
    uprintf("Welcome to Log0 YEET 3.3!!!");

    int i=6000;
    for(;i>0; --i)
    {
        uprintf("....booting in %d\r\n",i);
    }
}
#endif