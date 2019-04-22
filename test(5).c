#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int year;
	printf("请输入年份:");
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		printf("%d是闰年\n", year);
	}
	else {
		printf("%d不是闰年\n", year);
	}
	system("pause");
	return 0;
}
四年一润, 百年不润, 四百年再润
#include<stdio.h>
#include<stdlib.h>

int leap(int year)
{
	int ret  = 0;;
	if (((year  % 4 == 0)
		&& (year  % 100 != 0))
		|| (year  % 400 == 0))
	{
		return 1;
	}
	else
	{
	return  - 1;
	}
}

int main()
{
	int Year  = 0;
	printf("please input the year:\n");
	scanf("%d", &Year);
	int ret  = leap(Year);   /*将调用得到的函数值返回到ret中*/
	if (ret  == 1)
	{
		printf("%d is leap year!", Year);
	}
	else
	{
	printf("%d is not leap year!", Year);
	}
	system("pause");
	return 0;
}