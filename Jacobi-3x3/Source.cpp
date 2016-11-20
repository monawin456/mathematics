#include<iostream>
#include<cstdio>
#include<cmath>

void jacobi(double &x1, double &x2, double &x3, double es);
double func1(double x2, double x3);
double func2(double x1, double x3);
double func3(double x1, double x2);
double mAbs(double x);
double calEa(double m_x, double x);
double maxEa(double ea1, double ea2, double ea3);

int main() {
	double x1 = 0;
	double x2 = 0;
	double x3 = 0;
	double es = 5;
	jacobi(x1, x2, x3, es);
	return 0;
}

void jacobi(double &x1, double &x2, double &x3, double es) {
	double m_x1 = x1;
	double ea1;
	double m_x2 = x2;
	double ea2;
	double m_x3 = x3;
	double ea3;
	double ea = 100;

	printf("Iter                            Ea            Max Ea\n\n");

	int i = 0;
	while (true) {
		i++;

		m_x1 = func1(x2, x3);
		m_x2 = func2(x1, x3);
		m_x3 = func3(x1, x2);

		ea1 = calEa(m_x1, x1);
		ea2 = calEa(m_x2, x2);
		ea3 = calEa(m_x3, x3);

		ea = maxEa(ea1, ea2, ea3);

		printf("%2d     x1   %12f   %12f   %12f\n", i, m_x1, ea1, ea);
		printf("       x2   %12f   %12f\n", m_x2, ea2);
		printf("       x3   %12f   %12f\n\n", m_x3, ea3);

		x1 = m_x1;
		x2 = m_x2;
		x3 = m_x3;

		if (ea <= es) {
			break;
		}
	}
}

double func1(double x2, double x3) {
	return (-20 - x2 + 2 * x3) / (-8);
}

double func2(double x1, double x3) {
	return (-38 - 2 * x1 + x3) / (-6);
}

double func3(double x1, double x2) {
	return (-34 + 3 * x1 + x2) / (7);
}

double mAbs(double x) {
	if (x < 0) {
		return -x;
	}
	else {
		return x;
	}
}

double calEa(double m_x, double x) {
	return mAbs((m_x - x) / (m_x) * 100);
}

double maxEa(double ea1, double ea2, double ea3) {
	double tmp;
	if (ea1 >= ea2) {
		tmp = ea1;
	}
	else {
		tmp = ea2;
	}
	if (tmp >= ea3) {
		return tmp;
	}
	else {
		return ea3;
	}
}
