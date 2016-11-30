#include <iostream>
#include <cmath>

void input(double &n);
double *arrayInput(double n);
double total(double *a, double n);
double totalSquare(double *a, double n);
double totalXY(double *x, double *y, double n);

double calSxy(double xy, double n, double totalX, double totalY);
double calSxx(double totalX2, double n, double totalX);
double calSyy(double totalY2, double n, double totalY);
double calB1(double Sxy, double Sxx);
double calB0(double totalX, double totalY, double n, double B1);
double calSSE(double Syy, double Sxy, double B1);
double calS(double SSE, double n);
double calR(double Sxy, double Sxx, double Syy);

int main() {
	double n = 0;
	std::cout << " > Input N value: ";
	input(n);
	double *x = NULL;
	std::cout << " > Input X value: ";
	x = arrayInput(n);
	double *y = NULL;
	std::cout << " > Input Y value: ";
	y = arrayInput(n);
	std::cout << std::endl;

	double totalX = total(x, n);
	double totalY = total(y, n);

	double totalX2 = totalSquare(x, n);
	double totalY2 = totalSquare(y, n);

	double xy = totalXY(x, y, n);

	double Sxy = calSxy(xy, n, totalX, totalY);
	double Sxx = calSxx(totalX2, n, totalX);
	double Syy = calSyy(totalY2, n, totalY);
	double B1 = calB1(Sxy, Sxx);
	double B0 = calB0(totalX, totalY, n, B1);
	double SEE = calSSE(Syy, Sxy, B1);
	double S = calS(SEE, n);
	double r = calR(Sxy, Sxx, Syy);

	std::cout << " Sxy = " << Sxy << std::endl;
	std::cout << " Sxx = " << Sxx << std::endl;
	std::cout << " Syy = " << Syy << std::endl;
	std::cout << " B1 = " << B1 << std::endl;
	std::cout << " B0 = " << B0 << std::endl;
	std::cout << " SEE = " << SEE << std::endl;
	std::cout << " s = " << S << std::endl;
	std::cout << " r = " << r << std::endl;
	std::cout << std::endl;

	std::cout << " y = " << B0 << " + " << B1 << "x" << std::endl;
	std::cout << std::endl;

	std::cout << " > Input x: ";
	double inputX = 0;
	input(inputX);
	std::cout << " y = " << B0 + B1 * inputX << std::endl;
	std::cout << std::endl;

	delete[] x;
	delete[] y;

	system("pause");
	return 0;
}

void input(double &n) {
	std::cin >> n;
}

double *arrayInput(double n) {
	double *a = new double[n];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	return a;
}

double total(double *a, double n) {
	double result = 0;
	for (int i = 0; i < n; i++) {
		result = result + a[i];
	}
	return result;
}

double totalSquare(double *a, double n) {
	double result = 0;
	for (int i = 0; i < n; i++) {
		result = result + a[i] * a[i];
	}
	return result;
}

double totalXY(double *x, double *y, double n) {
	double result = 0;
	for (int i = 0; i < n; i++) {
		result = result + x[i] * y[i];
	}
	return result;
}

double calSxy(double xy, double n, double totalX, double totalY) {
	return xy - (1 / n) * totalX * totalY;
}

double calSxx(double totalX2, double n, double totalX) {
	return totalX2 - (1 / n) * totalX * totalX;
}

double calSyy(double totalY2, double n, double totalY) {
	return totalY2 - (1 / n) * totalY * totalY;
}

double calB1(double Sxy, double Sxx) {
	return Sxy / Sxx;
}

double calB0(double totalX, double totalY, double n, double B1) {
	return (totalY / n) - B1 * (totalX / n);
}

double calSSE(double Syy, double Sxy, double B1) {
	return Syy - B1 * Sxy;
}

double calS(double SSE, double n) {
	return sqrt((SSE) / (n - 2));
}

double calR(double Sxy, double Sxx, double Syy) {
	return (Sxy) / (sqrt(Sxx) * sqrt(Syy));
}
