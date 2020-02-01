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

	int i = 0;
	while (i <= n - 1) {
		for (int j = n - 1; j > i ; j--) {
			if (a[j] < a[j - 1]) {
				int tmp = a[j];
				a[j] = a[j-1];
				a[j - 1] = tmp;
				sum++;
			}
		}

		i++;
	}

	for (int i = 0; i < n; i++) {
		if(i!=n-1)cout << a[i] << " ";
		if (i == n - 1)cout << a[i] << endl;
	}
	cout << sum << endl;
}

