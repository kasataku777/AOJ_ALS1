#include<iostream>
#include<vector>
using namespace std;



int main() {

	int n;

	cin >> n;
	int a[105];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum = 0;

	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (minj != i) {
			int tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			sum++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i != n - 1)cout << a[i] << " ";
		if (i == n - 1)cout << a[i] << endl;
	}
	cout << sum << endl;
}

