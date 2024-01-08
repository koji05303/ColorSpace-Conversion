#include "cpt.h"
#include "cpt_ch.h"

ColorConversion::RGB2XYZ(r, g, b, x, y, z);  // RGB 轉換 XYZ
ColorConversion::XYZ2LAB(x, y, z, L, A, B);  // XYZ 轉換 LAB
ColorConversion::RGB2LAB(r, g, b, L, A, B);  // RGB 轉換 LAB
ColorConversion::RGB2YUV(r, g, b, Y, U, V); //  RGB 轉換 LUV
ColorConversionCH::RGB2CMY(r, g, b, CMY_c, CMY_m, CMY_y); //    RGB 轉換 CMY
ColorConversionCH::RGB2HSV(r, g, b, HSV_h, HSV_s, HSV_v); //RGB 轉換 HSV