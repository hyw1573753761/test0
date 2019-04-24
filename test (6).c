#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Menu() {
	printf("=================\n");
	printf(" 1. ��ʼ��Ϸ\n");
	printf(" 0. �˳���Ϸ\n");
	printf("=================\n");
	printf("����������ѡ��: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

// shift + alt + r (VA)�ܹ��Ա�������������
void Init(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	// 1. ���� show_map, ��Ҫ��Ϊ *
	for (int row = 0; row <= MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			show_map[row][col] = '*';
		}
	}
	// 2. ���� mine_map,��Ҫ����������ɸ�����
	//  ʹ�� 0 ��ʾû�е���, ʹ�� 1 ��ʾ����
	for (int row = 0; row <= MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			mine_map[row][col] = 0; //'0'��ʾ48Ҳ����
		}
	}
	int n = MINE_COUNT;
	while (n > 0) {
		//����һ������
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1') {
			//��λ���Ѿ��ǵ�����,��Ҫ��������
			continue;
		}
		mine_map[row][col] = '1';
		--n;
	}
}

void PrintshowMap(char show_map[MAX_ROW][MAX_COL]) {
	//�����ܴ�ӡ����ͼ,���ܴ�����
	//�ȴ�ӡ
}

void Game() {
    // 1.�ȴ�����ͼ, ����ʼ��
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	//���ǵ��׵�λ��
	int blank_count_already_show = 0;
	Init(show_map, mine_map);
	while (1) {
		//2. ��ӡ��ͼ
		PrintMap(show_map);
		//3. ���û��������겢���кϷ��Լ���
		printf("������һ������(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW
			|| col < 0 || col >= MAX_COL) {
			printf("��������Ƿ�!����������");
			continue;
		}
		if (show_map[row][col != '*']) {
			printf("�������λ���Ѿ�������!\n");
			continue;
		}
		//4.�ж��Ƿ��ǵ���
		if (mine_map[row][col] == '1') {
			printf("��Ϸ����!\n");
			PrintMap(mine_map);
			break;
		}
		// 5. �ж���Ϸ�Ƿ�ʤ��
		//    �ж����зǵ���λ�ö���������
		++blank_count_already_show;
		if (blank_count_already_show
			== MAX_COL * MAX_ROW - MINE_COUNT) {
			printf("��Ϸʤ��!\n");
			PrintMap(mine_map);
			break;
		}
		//6. ͳ�Ƶ�ǰλ���׵ĸ���
		UpdateShowMap();
	}
}

int main() {
	while (1) {
		int choice = Menu;
		if (choice == 1) {
			Gane();
		}
		else if (choice == 0) {
			printf("goodbye!\n");
			break;
		}
		else {
			printf("������������!\n");
		}
	}



	system("pause");
	return 0;
}