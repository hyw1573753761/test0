#include <stdio.h>
#include <stdlib.h>

//int Strlen(char str[]) {
//	int size = 0;
//	for (int i = 0; str[i] != '\0'; ++i) {
//		++size;
//	}
//	return size;
//}
int Strlen(char str[]) {
	if (str[0] == '\0') {
		return 0;
	}
	return 1 + Strlen(str + 1);
}

int main() {
	char str[] = "abcd";
	int ret = Strlen(str);
	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}