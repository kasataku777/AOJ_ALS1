#include<iostream>
#include<cstdio>

//ƒRƒbƒz‹Èü

using namespace std;


void koch(int n, double p1[], double p2[]) {

	if (n == 0)return ;

	double s[2], t[2], u[2];

	s[0] =( p1[0] * 2 + p2[0])/3;
	s[1] = (2 * p1[1] + p2[1]) / 3;
	t[0] = (p1[0] + 2 * p2[0]) / 3;
	t[1] = (p1[1] + 2 * p2[1]) / 3;
	u[0] = (t[0] - s[0]) / 2 - (t[1] - s[1])*1.7320508 / 2 + s[0];
	u[1] = (t[0] - s[0])*1.7320508 / 2 + (t[1] - s[1])/ 2 + s[1];

	koch(n - 1, p1, s);
	printf("%.8f %.8f\n", s[0], s[1]);
	koch(n - 1, s, u);
	printf("%.8f %.8f\n", u[0], u[1]);
	koch(n - 1, u, t);
	printf("%.8f %.8f\n", t[0], t[1]);
	koch(n - 1, t, p2);
}

int main() {
	int n;
	cin >> n;
	double p1[2] = { 0.00000000,0.00000000 };
	double p2[2] = { 100.00000000,0.00000000 };
	printf("%.8f %.8f\n", p1[0], p1[1]);
	koch(n, p1, p2);
	printf("%.8f %.8f\n",p2[0], p2[1]);
}