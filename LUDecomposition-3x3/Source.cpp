#include<iostream>
#include<cmath>

void LU(double **P, double **L, double **U, int n);
void reset(double **A, int n);
void copy(double **A, double **B, int n);
void print(double **A, int n);
void mult(double **L, double **U, double **C, int n);

int main() {
	int n = 3;

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
	copy(U, P, n);
	for (int i = 0; i < n; i++) {
		L[i][i] = 1;
	}

	double tmp = 0;

	tmp = U[1][0] / U[0][0];
	L[1][0] = tmp;
	for (int i = 0; i < n; i++) {
		U[1][i] = U[1][i] + (-tmp) * U[0][i];
	}

	tmp = U[2][0] / U[0][0];
	L[2][0] = tmp;
	for (int i = 0; i < n; i++) {
		U[2][i] = U[2][i] + (-tmp) * U[0][i];
	}

	tmp = U[2][1] / U[1][1];
	L[2][1] = tmp;
	for (int i = 0; i < n; i++) {
		U[2][i] = U[2][i] + (-tmp) * U[1][i];
	}
}

void reset(double **A, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
}

void copy(double **A, double **B, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = B[i][j];
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
	double tmp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp = tmp + L[0][j] * U[j][i];
		}
		C[0][i] = tmp;
		tmp = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp = tmp + L[1][j] * U[j][i];
		}
		C[1][i] = tmp;
		tmp = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp = tmp + L[2][j] * U[j][i];
		}
		C[2][i] = tmp;
		tmp = 0;
	}
}
