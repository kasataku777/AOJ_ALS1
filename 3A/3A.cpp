//#include<stdio.h>
//#include<iostream>
//using namespace std;
//
//#define BUF_SIZE 1024
//
//
//class Stack {
//
//private:
//	int* m_array;
//	int m_index;
//
//public:
//	Stack(int stack_size){
//		m_index = 0;
//	m_array = new int[stack_size];
//
//	};
//	~Stack() {
//		delete[] m_array;
//		
//	};
//
//	void push(int var) {
//		 m_array[m_index++] =var;
//	};
//	int pop() {
//		return m_array[--m_index];
//
//
//	};
//
//	bool isEmpty() {
//		return m_index == 0;
//	};
//
//
//
//};
//
//
//int main() {
//
//	char buf[BUF_SIZE];
//
//	for (int i = 0; i < BUF_SIZE; i++) {
//		buf[i] = 'e';
//	}
//	fgets(buf, BUF_SIZE, stdin);
//
//	Stack stack(BUF_SIZE);
//
//	bool numFLG = false;
//
//	int S = 0, op1 = 0, op2 = 0;
//
//	for (int i = 0; buf[i] != 'e'; i++) {
//		if (buf[i] >= '0' && buf[i] <= '9') {
//			numFLG = true;
//			S =  (buf[i] - '0');
//		}
//		else {
//			if (numFLG) {
//				stack.push(S);
//				S = 0;
//				numFLG = false;
//			}
//
//			if (buf[i] == '+') {
//				op2 = stack.pop();
//				op1 = stack.pop();
//				stack.push(op1 + op2);
//
//			}
//			else if (buf[i] == '-') {
//				op2 = stack.pop();
//				op1 = stack.pop();
//				stack.push(op1 - op2);
//			}
//			else if (buf[i] == '*') {
//				op2 = stack.pop();
//				op1 = stack.pop();
//				stack.push(op1*op2);
//			}
//		}
//	}
//	op1 = stack.pop();
//	printf("%d\n", op1);
//}


//aoj-book
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int top, S[1000];
//
//void push(int x) {
//	S[++top] = x;
//}
//
//int pop() {
//	top--;
//	return S[top + 1];
//}
//
//int main() {
//	int a, b;
//	top = 0;
//	char s[100];
//
//	while (scanf("%s", s) != EOF) {
//		if (s[0] == '+') {
//			a = pop();
//			b = pop();
//			push(a + b);
//		}
//		else if (s[0] == '-') {
//			b = pop();
//			a = pop();
//			push(a - b);
//		}
//		else if (s[0] == '*') {
//			a = pop();
//			b = pop();
//			push(a*b);
//		}
//		else {
//			push(atoi(s));
//		}
//	}
//	printf("%d\n", pop());
//
//	return 0;
//}


#include <iostream>
#include<cstdlib>
#include<stack>
#include<string>
using namespace std;

int main() {
	stack<int> S;
	int a, b, x;
	string s;


	while (cin >> s) {
		if (s[0] == '+') {
			a = S.top(); S.pop();
			b = S.top(); S.pop();
			S.push(a + b);
		}
		else if (s[0] == '-') {
			b = S.top(); S.pop();
			a = S.top(); S.pop();
			S.push(a - b);
		}
		else if (s[0] == '*') {
			a = S.top(); S.pop();
			b = S.top(); S.pop();
			S.push(a * b);
		}
		else {
			S.push(atoi(s.c_str()));
		}
	}

	cout << S.top() << endl;
	return 0;
}