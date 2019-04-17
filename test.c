#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	//二分查找/折半查找必须针对有序数组
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int to_find = 5;
	//[left,right] 待查找区间
	int left = 0;
	//sizeof(arr)数组所占的字节数
	//sizeof(arr[0])数组中第一个元素所占的字节数
	//C++ arr.size()
	//Python len(arr)
	int right = sizeof(arr) / sizeof(arr[0] - 1);
	//待查找区间存在元素的话.就应该继续查找
	//<=此时取到最后一个元素
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] < to_find) {
			//注意需要 mid+1,因为mid位置的元素
			//已经不可能和 to_find 相等了,没必要继续比较了
			left = mid + 1;
		}
		else if(arr[mid] > to_find){
			right = to_find - 1;
		}
		else {
			//printf("找到了!\n");
			break;
		}
	}
	if (left <= right) {
		printf("找到了!\n");
	}
	else {
		printf("没找到了!\n");
	}
	system("pause");
	return 0;                          
}