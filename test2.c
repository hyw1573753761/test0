#include <stdio.h>
#include <stdlib.h>

//*������Ϊ��������ʱ,����ʽת��Ϊָ��
//(ָ��������Ԫ�ص�ָ��)
int BinarySearch(int* arr, int size, int to_find) {
	//[left, right]
	int left = 0;
	//4 / 4 - 1 = 0;
	//int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int right = size - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (to_find < arr[mid]) {
			right = mid - 1;
		}
		else if (to_find > arr[mid]){
			left = mid + 1;
		}
		else {
			return 1;
		}
	}
	
	return 0;
}
int main() {
	int arr[4] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = BinarySearch(arr, size, 584);
	if (ret == 1) {
		printf("�ҵ���!\n");
	}
	else {
		printf("û�ҵ�!\n");
	}
	system("pause");
	return 0;

}