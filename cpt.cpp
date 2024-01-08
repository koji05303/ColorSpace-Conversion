#include "cpt.h"
#include <cmath>
#include <algorithm>

namespace ColorConversion
{
    ///////////////////////////////////////////////RGB 2 LUV  ///////////////////////////////////////////////
    void RGB2YUV(double r, double g, double b, double& Y, double& U, double& V)
    {
        Y = static_cast<double>(0.257 * r + 0.504 * g + 0.098 * b + 16); // y
        U = static_cast<double>(-0.148 * r - 0.291 * g + 0.439 * b + 128); // u
        V = static_cast<double>(0.439 * r - 0.368 * g - 0.071 * b + 128); // v
    }
    ///////////////////////////////////////////////RGB 2 XYZ ///////////////////////////////////////////////
    void RGB2XYZ(double r, double g, double b, double& x, double& y, double& z) {
        double var_R, var_G, var_B;
        var_R = (r / 255.0f);
        var_G = (g / 255.0f);
        var_B = (b / 255.0f);

        if (var_R > 0.04045)
        {
            var_R = pow((var_R + 0.055) / 1.055, 2.4);

        }
        else
        {
            var_R = var_R / 12.92;
        }
        if (var_G > 0.04045)
        {
            var_G = pow((var_G + 0.055) / 1.055, 2.4);
        }
        else
        {
            var_G = var_G / 12.92;
        }
        if (var_B > 0.04045)
        {
            var_B = pow((var_B + 0.055) / 1.055, 2.4);
        }
        else
        {
            var_B = var_B / 12.92;
        }

        var_R = var_R * 100.0f;
        var_G = var_G * 100.0f;
        var_B = var_B * 100.0f;

        //Observer.   =   2°,   Illuminant   =   D65   
        x = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
        y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
        z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;
    }
    /////////////////////////////////////////////// XYZ 2 RGB ///////////////////////////////////////////////
    void XYZ2LAB(double x, double y, double z, double& L, double& A, double& B) {
        double var_X, var_Y, var_Z;
        var_X = x / 95.047f;
        var_Y = y / 100.000f;
        var_Z = z / 108.883f;

        if (var_X > 0.008856)
        {
            var_X = pow((float)var_X, 1.0f / 3.0f);
        }
        else
        {
            var_X = (7.787 * var_X) + (16 / 116);
        }
        if (var_Y > 0.008856)
        {
            var_Y = pow((float)var_Y, 1.0f / 3.0f);
        }
        else
        {
            var_Y = (7.787 * var_Y) + (16 / 116);
        }
        if (var_Z > 0.008856)
        {
            var_Z = pow((float)var_Z, 1.0f / 3.0f);
        }
        else
        {
            var_Z = (7.787 * var_Z) + (16 / 116);
        }

        L = (116 * var_Y) - 16;
        A = 500 * (var_X - var_Y);
        B = 200 * (var_Y - var_Z);
    }
    /////////////////////////////////////////////// RGB 2 LAB ///////////////////////////////////////////////
    void RGB2LAB(double r, double g, double b, double& L, double& A, double& B)
    {
        double x, y, z;
        RGB2XYZ(r, g, b, x, y, z);
        XYZ2LAB(x, y, z, L, A, B);
    }
}