#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	//���ֲ���/�۰���ұ��������������
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int to_find = 5;
	//[left,right] ����������
	int left = 0;
	//sizeof(arr)������ռ���ֽ���
	//sizeof(arr[0])�����е�һ��Ԫ����ռ���ֽ���
	//C++ arr.size()
	//Python len(arr)
	int right = sizeof(arr) / sizeof(arr[0] - 1);
	//�������������Ԫ�صĻ�.��Ӧ�ü�������
	//<=��ʱȡ�����һ��Ԫ��
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] < to_find) {
			//ע����Ҫ mid+1,��Ϊmidλ�õ�Ԫ��
			//�Ѿ������ܺ� to_find �����,û��Ҫ�����Ƚ���
			left = mid + 1;
		}
		else if(arr[mid] > to_find){
			right = to_find - 1;
		}
		else {
			//printf("�ҵ���!\n");
			break;
		}
	}
	if (left <= right) {
		printf("�ҵ���!\n");
	}
	else {
		printf("û�ҵ���!\n");
	}
	system("pause");
	return 0;                          
}