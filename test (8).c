#include <stdio.h>
#include <stdlib.h>
//求两个整数的最大值
//函数的定义,一个函数只能定义一次
//但是可以被重复调用
//(x,y为形参)
int Max(int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
}
//int main() {
//	int a = 10;
//	int b = 20;
//	//函数调用,实际参数(实参)
//	int ret = Max(a, b);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//实现一个函数完成两个整数交换
//形参和实参的关系,形参是实参的一份拷贝
//函数内部修改形参无发对实参造成影响
//必须通过传指针的方式,通过间接访问操作修改函数变量
//形如这里使用指针作为参数并修改函数外部变量操作,
//把这样的参数称为输出型参数
void Swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int main() {
	int a = 10;
	int b = 20;
	//Swap(&a, &b);
	int* x = &a;
	int* y = &b;
	int tmp = *x;
	*x = *y;
	*y = tmp;
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}