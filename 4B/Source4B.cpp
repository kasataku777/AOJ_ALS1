#include<iostream>
#include<cstdio>

using namespace std;



int binary_search(int* A,int key,int n) {
	int left = 0;
	int right = n;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] == key) return 1;
		else if (A[mid] > key) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}



	return 0;
}

int main() {

	//int a[] = { 1,2,3 };
	//cout << *a  << endl;

	int n;
	int A[100000 + 1];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int q,key;
	int sum = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> key;
		if (binary_search(A, key,n)) {
			sum++;
		}
	}
	cout << sum << endl;
	//cout<<binary_search()
	return 0;
}