/*
简单实现链表增加，删除，修改，显示四项操作
*/
#pragma once
#ifndef L__In_k_L_Ist
#define L__In_k_L_Ist
#define True 1

typedef struct Student {
	int sid;//学号
	int age; //年龄
	char * next;
}Student;

Student * InitStudent();  //初始化链表
int Welcome();  //欢迎界面
int AddStudent(Student ** add_stu); //增加
int DelStudent(Student ** del_stu, int sid); //删除
int ModStudent(Student ** mod_stu, int sid);  //修改
int PrintStudent(Student * print_stu); //显示
int FreeStudent(Student ** free_stu);//释放
void InsertStudent(Student ** Insert_stu);  //插入

#endif