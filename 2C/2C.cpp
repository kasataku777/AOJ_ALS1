#include<iostream>
#include<vector>
#include<string>
using namespace std;



int main() {

	int n;

	cin >> n;
	string s[40];
	for (int i = 0; i < n; i++) {
		cin >> s[i];


	}

	string in[40];
	for (int i = 0; i < n; i++) {
		in[i] = s[i];
	}
	int i = 0;
	while (i <= n - 1) {
		for (int j = n - 1; j > i; j--) {
			if (s[j][1] < s[j - 1][1]) {
				string tmp = s[j];
				s[j] = s[j - 1];
				s[j - 1] = tmp;
				
			}
		}

		i++;
	}


	for (int i = 0; i < n; i++) {
		if (i != n - 1)cout << s[i] << " ";
		if (i == n - 1)cout << s[i] << endl;
	}


	string x[10], y[10];

	for (int i = 0; i < n; i++) {
		x[in[i][1] - '0'] += in[i][0];
		y[s[i][1] - '0'] += s[i][0];
	}
	int ans = 1;
	for (int i = 0; i < 10; i++) {
		if (x[i] != y[i])ans = 0;
	}
	cout << (ans ? "Stable": "Not stable") << endl;

	for (int i = 0; i < n; i++) {
		s[i] = in[i];
	}
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (s[j][1] < s[minj][1]) {
				minj = j;
			}
		}
		if (minj != i) {
			string tmp = s[i];
			s[i] = s[minj];
			s[minj] = tmp;
		}
	}
	for (int i = 0; i < 10; i++) x[i] = y[i] = "";

	ans = 1;

	for (int i = 0; i < n; i++) {
		if (i != n - 1)cout << s[i] << " ";
		if (i == n - 1)cout << s[i] << endl;
	}
	for (int i = 0; i < n; i++) {
		x[in[i][1] - '0'] += in[i][0];
		y[s[i][1] - '0'] += s[i][0];
	}
	 ans = 1;
	for (int i = 0; i < 10; i++) {
		if (x[i] != y[i])ans = 0;
	}
	cout << (ans ? "Stable" : "Not stable") << endl;


}

