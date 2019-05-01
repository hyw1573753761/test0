#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//实现一个通讯录程序,完成联系人信息的存储.
//1.新增
//2.删除
//3.修改记录
//4.查找记录
//5.打印全部记录
//6.排序记录
//7.清空全部记录
//管理
//1.把基本信息抽象并描述出来(结构体)
//2.需要管理许多数据,就需要组织起来(数据结构)

#define MAX_PERSON_INFO_SIZE 300

typedef struct PersonInfo {
	char name[1024];
	//定义电话号码为一个字符串
	char phone[1024];
} PersonInfo;

typedef struct AddressBook {
	PersonInfo person[MAX_PERSON_INFO_SIZE];
	//[0,size)
	int size;
}AddressBook;
//g_提示为全局变量
AddressBook g_address_book;

void Init() {
	g_address_book.size = 0;
	for (int i = 0; i < MAX_PERSON_INFO_SIZE; ++i) {
		g_address_book.person[i].name[0] = '\0';
		g_address_book.person[i].phone[0] = '\0';

	}
}

int Menu() {
	printf("=================\n");
	printf(" 1. 新增联系人\n");
	printf(" 2. 删除联系人\n");
	printf(" 3. 查找联系人\n");
	printf(" 4. 修改联系人\n");
	printf(" 5. 打印全部联系人\n");
	printf(" 6. 排序联系人\n");
	printf(" 7. 清空联系人\n");
	printf(" 8. 退出\n");
	printf("=================\n");
	printf("请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Empty() {
	//这个函数啥都不干就是用来凑数
}
void AddPersonInfo() {
	printf("新增联系人\n");
	if (g_address_book.size >= MAX_PERSON_INFO_SIZE) {
		printf("新增联系人失败!\n");
		return;
	}
	printf("请输入联系人姓名: ");
	//必须取到一个指针,修改的内容是一个预期的内容
	PersonInfo* person_info = &g_address_book.person[g_address_book.size];
	scanf("%s", person_info->name);
	printf("请输入联系人电话: ");
	scanf("%s", person_info->phone);
	++g_address_book.size;
	printf("新增联系人成功!\n");

}

void DelPersonInfo() {

}

void FindPersonInfo() {

}

void UpdatePersonInfo() {

}

void PrintAllPersonInfo() {

}

void SortPersonInfo() {

}

void ClearAllPersonInfo() {

}

typedef void(*Func)();



int main() {
	Func arr[] = {
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		UpdatePersonInfo,
		PrintAllPersonInfo,
		SortPersonInfo,
		ClearAllPersonInfo
	};

	Init();

	while (1) {
		int choice = Menu();
		if (choice == 0) {
			printf("goodbye!\n");
			break;


		}
	}
}