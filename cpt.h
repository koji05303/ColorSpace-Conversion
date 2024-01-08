#ifndef cpt_cpp_H
#define cpt_cpp_H

namespace ColorConversion
{
	void RGB2XYZ(double r, double g, double b, double& x, double& y, double& z);
	void XYZ2LAB(double x, double y, double z, double& L, double& A, double& B);
	void RGB2LAB(double r, double g, double b, double& L, double& A, double& B);
	void RGB2YUV(double r, double g, double b, double& Y, double& U, double& V);
}

#endif
