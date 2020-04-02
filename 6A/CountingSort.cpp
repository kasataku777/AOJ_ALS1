#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAX 2000001
#define VMAX 10000

int main() {
	short *A, *B;
	int C[VMAX + 1];
	int n;

	scanf("%d", &n);

	A = new  short[n + 1];
	B = new  short[n + 1];

	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < VMAX+1; i++) {
		C[i] = 0;
	}

	for (int j = 1; j <= n; j++) {
		C[A[j]]++;
	}

	for (int i = 1; i < VMAX + 1; i++) {
		C[i] = C[i] + C[i - 1];
	}

	for (int j = n; j > 0; j--) {
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}

	for (int i = 1; i <= n; i++) {
		if(i!=n)cout << B[i] << " ";
		if (i == n)cout <<B[i]<< endl;
	}

	delete[] A;
	delete[] B;

	return 0;
}