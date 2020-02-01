#include<iostream>
using namespace std;

int isPrime(int x);

int main() {
	int n;

	cin >> n;
	int sum = 0;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (isPrime(a))sum++;
	}


	cout << sum << endl;

}

int isPrime(int x) {
	if (x == 2) return true;
	if (x < 2 || x % 2 == 0) {
		return false;
	}

	int i = 3;
	while (i*i <= x) {
		if (x%i == 0)return false;
		i = i + 2;
	}
	return true;
}