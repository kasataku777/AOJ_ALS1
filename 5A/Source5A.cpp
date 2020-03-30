#include<iostream>


using namespace std;


int a[2005];
bool solve(int i, int m,int n) {

	if (m == 0)return true;

	if (i >= n)return false;

	bool res = solve(i + 1, m, n) || solve(i + 1, m - a[i],n);

	return res;

}

int main(){

	int n;
	int q,m;


	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> m;
		bool ans = solve(0, m, n);
		if (ans) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;

}