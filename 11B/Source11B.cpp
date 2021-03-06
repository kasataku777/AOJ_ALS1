//#include<stdio.h>
//#define N 100
//#define WHITE 0
//#define GRAY 1
//#define BLACK 2
//
//int n, M[N][N];
//int color[N], d[N], f[N], tt;
//
//void dfs_visit(int u) { //再帰によるDFS
//	int v;
//	color[u] = GRAY;
//	d[u] = ++tt;
//
//	for (v = 0; v < n; v++) {
//		if (M[u][v] == 0)continue;
//		if (color[v] == WHITE) {
//			dfs_visit(v);
//		}
//	}
//	color[u] = BLACK;
//	f[u] = ++tt; //訪問完了
//}
//
//void dfs() {
//	int u;
//	for (u = 0; u < n; u++)color[u] = WHITE;
//	tt = 0;
//	for (u = 0; u < n; u++) {
//		if (color[u] == WHITE)dfs_visit(u);
//	}
//
//	for (u = 0; u < n; u++) {
//		printf("%d %d %d\n", u + 1, d[u], f[u]);
//	}
//}
//
//int main() {
//	int u, v, k, i, j;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < n; j++)M[i][j] = 0;
//	}
//
//	for (i = 0; i < n; i++) {
//		scanf("%d %d", &u, &k);
//		u--;
//		for (j = 0; j < k; j++) {
//			scanf("%d", &v);
//			v--;
//			M[u][v] = 1;
//		}
//	}
//
//	dfs();
//
//	return 0;
//}


//stackを用いるdfs

#include<iostream>
#include<stack>
using namespace std;
static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[N][N];
int color[N], d[N], f[N], tt;
int nt[N];

int next(int u) {
	for (int v = nt[u]; v < n; v++) {
		nt[u] = v + 1;
		if (M[u][v])return v;
	}
	return -1;
}

void dfs_visit(int r) {
	for (int i = 0; i < n; i++)nt[i] = 0;

	stack<int> S;

	S.push(r);
	color[r] = GRAY;
	d[r] = ++tt;

	while (!S.empty()) {
		int u = S.top();
		int v = next(u);
		if (v != -1) {
			if (color[v] == WHITE) {
				color[v] = GRAY;
				d[v] == ++tt;
				S.push(v);
			}
		}
		else {
			S.pop();
			color[v] = BLACK;
			f[u] = ++tt;
		}
	}
}
void dfs() {
	for (int i = 0; i < n; i++) {
		color[i] = WHITE;
		nt[i] = 0;
	}
	tt = 0;

	for (int u = 0; u < n; u++) {
		if (color[u] == WHITE)dfs_visit(u);
	}
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " " << d[i] << " " << f[i] << endl;
	}
}

int main() {
	int u, k, v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)M[i][j] = 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> u >> k;
		u--;
		for (int j = 0; j < k; j++) {
			cin >> v;
			v--;
			M[u][v] = 1;
		}
	}

	dfs();
	return 0;
}