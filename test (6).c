#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Menu() {
	printf("=================\n");
	printf(" 1. 开始游戏\n");
	printf(" 0. 退出游戏\n");
	printf("=================\n");
	printf("请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

// shift + alt + r (VA)能够对变量或函数重命名
void Init(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	// 1. 对于 show_map, 需要设为 *
	for (int row = 0; row <= MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			show_map[row][col] = '*';
		}
	}
	// 2. 对于 mine_map,需要随机生成若干个地雷
	//  使用 0 表示没有地雷, 使用 1 表示地雷
	for (int row = 0; row <= MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			mine_map[row][col] = 0; //'0'表示48也可以
		}
	}
	int n = MINE_COUNT;
	while (n > 0) {
		//生成一组坐标
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1') {
			//该位置已经是地雷了,需要从新生成
			continue;
		}
		mine_map[row][col] = '1';
		--n;
	}
}

void PrintshowMap(char show_map[MAX_ROW][MAX_COL]) {
	//不光能打印出地图,还能带坐标
	//先打印
}

void Game() {
    // 1.先创建地图, 并初始化
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	//不是地雷的位置
	int blank_count_already_show = 0;
	Init(show_map, mine_map);
	while (1) {
		//2. 打印地图
		PrintMap(show_map);
		//3. 让用户输入坐标并进行合法性检验
		printf("请输入一组坐标(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW
			|| col < 0 || col >= MAX_COL) {
			printf("您的输入非法!请重新输入");
			continue;
		}
		if (show_map[row][col != '*']) {
			printf("您输入的位置已经翻开了!\n");
			continue;
		}
		//4.判断是否是地雷
		if (mine_map[row][col] == '1') {
			printf("游戏结束!\n");
			PrintMap(mine_map);
			break;
		}
		// 5. 判定游戏是否胜利
		//    判定所有非地雷位置都被翻开了
		++blank_count_already_show;
		if (blank_count_already_show
			== MAX_COL * MAX_ROW - MINE_COUNT) {
			printf("游戏胜利!\n");
			PrintMap(mine_map);
			break;
		}
		//6. 统计当前位置雷的个数
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
			printf("您的输入有误!\n");
		}
	}



	system("pause");
	return 0;
}