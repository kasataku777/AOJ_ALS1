#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
	ll n, min = 10000000000, max = -10000000000,r;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r;
		if (max < r - min)max = r - min;
				if (min > r)min = r;


	}


	cout << max << endl;

}

