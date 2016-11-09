#include<iostream>
#include<cmath>

void LU(double **P, double **L, double **U, int n);
void reset(double **A, int n);
void print(double **A, int n);
void mult(double **L, double **U, double **C, int n);

int main() {
	int n = 2;

	double **P = new double*[n];
	for (int i = 0; i < n; i++) {
		P[i] = new double[n];
	}
	reset(P, n);
	std::cout << "Input Values: ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> P[i][j];
		}
	}

	double **L = new double*[n];
	for (int i = 0; i < n; i++) {
		L[i] = new double[n];
	}
	reset(L, n);

	double **U = new double*[n];
	for (int i = 0; i < n; i++) {
		U[i] = new double[n];
	}
	reset(U, n);

	double **M = new double*[n];
	for (int i = 0; i < n; i++) {
		M[i] = new double[n];
	}
	reset(M, n);

	LU(P, L, U, n);

	printf("L = \n");
	print(L, n);
	printf("\n");

	printf("U = \n");
	print(U, n);
	printf("\n");

	printf("L*U = \n");
	mult(L, U, M, n);
	print(M, n);
	printf("\n");

	for (int i = 0; i < n; i++) {
		delete[] P[i];
	}
	delete[] P;

	for (int i = 0; i < n; i++) {
		delete[] L[i];
	}
	delete[] L;

	for (int i = 0; i < n; i++) {
		delete[] U[i];
	}
	delete[] U;

	for (int i = 0; i < n; i++) {
		delete[] M[i];
	}
	delete[] M;

	return 0;
}

void LU(double **P, double **L, double **U, int n) {
	double tmp = 0;
	tmp = P[1][0] / P[0][0];
	U[0][0] = P[0][0];
	U[0][1] = P[0][1];
	for (int i = 0; i < n; i++) {
		U[1][i] = P[0][i] * (-tmp) + P[1][i];
	}
	L[1][0] = tmp;
	L[0][0] = 1;
	L[1][1] = 1;
}

void reset(double **A, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
}

void print(double **A, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%8.2f ", A[i][j]);
		}
		printf("\n");
	}
}

void mult(double **L, double **U, double **C, int n) {
	C[0][0] = U[0][0];
	C[0][1] = U[0][1];
	C[1][0] = L[1][0] * U[0][0];
	C[1][1] = L[1][0] * U[0][1] + U[1][1];
}
