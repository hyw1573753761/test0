#include <stdio.h>
#include <stdlib.h>
//�����������,ʹ������Ͳ���
int Divide(int x, int y, int* ok) {
	if (y == 0) {
		*ok = 0;
		return 0;
	}
	return x / y;
}
int main() {
	int ok = 0;
	int ret = Divide(9, 0, &ok);
	if (ok == 1) {
		printf("%d\n", ret);
	}
	else {
		printf("ok = 0");
	}
	system("pause");
	return 0;
}