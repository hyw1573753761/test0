#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main() {
	char str1[] = "welcome to bite";
	char str2[] = "###############";
	int left = 0;
	//获取最后一个元素的下标
	int right = strlen(str2) - 1;
	while (left <= right) {
		printf("%s\n", str2);
		str2[left] = str1[left];
		str2[right] = str1[right];
		++left;
		--right;
		//vs中跳转函数/变量的定义 F12/ctrl + 速表左键
		//回到上次位置 ctrl + <- 
		Sleep(200);
	    //cls 清屏
		system("cls");
	}
	system("pause");
	return 0;
}