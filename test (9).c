#include <stdio.h>
#include <stdlib.h>
int count = 0;
//普通的斐波那锲数列
int Fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	if (n == 3) {
		++count;
	}
	return Fib(n - 1) + Fib(n - 2);
}
//将斐波那锲数列优化为循环
int Fib2(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	int last2 = 1; //第i - 2项
	int last1 = 1; //第i - 1项
	int cur = 0;   //第i项
	for (int i = 3; i <= n; ++i) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}
int main() {
	printf("ret = %d\n", Fib2(40));
	printf("%d\n", count);
	system("pause");
	return 0;
}
////伪递归算法的斐波那锲数列
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<Windows.h>
//long long fib3(long long first, long long second, long long n) {
//	if (n < 3)
//		return 1;
//	if (n == 3)
//		return first + second;
//	return fib(second, first + second, n - 1);
//}
//int main() {
//	long long n = 0;
//	scanf("%llu", &n);
//	printf("%llu\n", fib(1, 1, n));
//	system("pause");
//	return 0;
//}
