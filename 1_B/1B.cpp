#include<iostream>
using namespace std;

int gcd(int x, int y);

int main() {
	int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << endl;



	
}

int gcd(int x, int y) {
	if (y > x) {
		swap(x, y);
	}
	while (y>0) {
		int  r = x % y;
		x = y;
		y = r;
	}
	return x;

}