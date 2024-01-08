#include "cpt_ch.h"
#include <cmath>
#include <algorithm>

namespace ColorConversionCH 
{
    /////////////////////////////////////////////// XYZ 2 CMY ///////////////////////////////////////////////
	void RGB2CMY(double r, double g, double b, double& C, double& M, double& Y)
	{
		C = 1.0 - (r / 255.0f);
		M = 1.0 - (g / 255.0f);
		Y = 1.0 - (b / 255.0f);
	}

    /////////////////////////////////////////////// XYZ 2 HSV ///////////////////////////////////////////////
	void RGB2HSV(double r, double g, double b, double& H, double& S, double& V)
	{
        double var_R, var_G, var_B;

        var_R = (r / 255);                    //RGB from 0 to 255
        var_G = (g / 255);
        var_B = (b / 255);

        double var_Min, var_Max, del_Max;
        var_Min = std::min(std::min(var_R, var_G), var_B);
        var_Max = std::max(std::max(var_R, var_G), var_B);
        del_Max = var_Max - var_Min;            //Delta RGB value 

        V = var_Max;

        if (del_Max == 0)                     //This is a gray, no chroma
        {
            H = 0;                               //HSV results from 0 to 1
            S = 0;
        }
        else                                    //Chromatic data
        {
            S = del_Max / var_Max;

            double del_R, del_G, del_B;
            del_R = (((var_Max - var_R) / 6) + (del_Max / 2)) / del_Max;
            del_G = (((var_Max - var_G) / 6) + (del_Max / 2)) / del_Max;
            del_B = (((var_Max - var_B) / 6) + (del_Max / 2)) / del_Max;

            if (var_R == var_Max)
                H = del_B - del_G;
            else if (var_G == var_Max)
                H = (1 / 3) + del_R - del_B;
            else if (var_B == var_Max)
                H = (2 / 3) + del_G - del_R;

            if (H < 0)
                H += 1;
            if (H > 1)
                H -= 1;
        }
	}
}