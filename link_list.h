/*
��ʵ���������ӣ�ɾ�����޸ģ���ʾ�������
*/
#pragma once
#ifndef L__In_k_L_Ist
#define L__In_k_L_Ist
#define True 1

typedef struct Student {
	int sid;//ѧ��
	int age; //����
	char * next;
}Student;

Student * InitStudent();  //��ʼ������
int Welcome();  //��ӭ����
int AddStudent(Student ** add_stu); //����
int DelStudent(Student ** del_stu, int sid); //ɾ��
int ModStudent(Student ** mod_stu, int sid);  //�޸�
int PrintStudent(Student * print_stu); //��ʾ
int FreeStudent(Student ** free_stu);//�ͷ�
void InsertStudent(Student ** Insert_stu);  //����

#endif