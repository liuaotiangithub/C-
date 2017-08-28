/*
	��ʵ���������ӣ�ɾ�����޸ģ���ʾ�������
*/
#include <stdio.h>
#include <malloc.h>
#include "link_list.h"

int main(void)
{
	Student *stu;
	int ret = 0;
	int select = 0;
	int sid = 0;
	stu = InitStudent();//��ʼ������
	while (True)
	{
		select = Welcome(); //��ӭҳ��
		switch (select)
		{
		case 1:
			AddStudent(&stu);
			break;
		case 2:
			printf("�������޸�ѧ��ѧ��:");
			scanf("%d", &sid);
			ModStudent(&stu, sid);
			break;
		case 3:
			PrintStudent(stu);
			break;
		case 4:
			printf("������ɾ��ѧ��ѧ��:");
			scanf("%d", &sid);
			DelStudent(&stu, sid);
			break;
		case 5:
			InsertStudent(&stu);
			break;
		case 0:
			FreeStudent(&stu);
			return ret;
		default:
			printf("�������û�и�ѡ�\n");
			break;
		}
	}
	return ret;
}

int Welcome()  //��ӭ����
{
	int select;//���룺ѡ��

	printf("������Ե�һ��\n");
	printf("1.����ѧ����Ϣ.\n");
	printf("2.�޸�ѧ����Ϣ.\n");
	printf("3.��ʾѧ����Ϣ.\n");
	printf("4.ɾ��ѧ����Ϣ.\n");
	printf("5.����ѧ����Ϣ.\n");
	printf("0.�˳�.\n");
	printf("ѡ��:");
	scanf("%d", &select);

	return select;
}
Student * InitStudent()  //��ʼ������
{
	Student * stu = NULL;
	stu = (Student *)malloc(sizeof(Student));
	stu->age = 0;
	stu->sid = 0;
	stu->next = NULL;

	return stu;  //��ʼ������������������
}
int AddStudent(Student ** add_stu) //����
{
	if (*add_stu == NULL)
	{
		*add_stu = InitStudent();
		Student * stu = *add_stu;
	}
	int ret = 0;
	int age = 0;
	int sid = 0;
	Student * stu = *add_stu;
	if (stu->age == 0 && stu->sid == 0)
	{
		printf("������ѧ��ѧ��:");
		scanf("%d", &sid);
		printf("������ѧ������:");
		scanf("%d", &age);
		stu->sid = sid;
		stu->age = age;
		stu->next = NULL;
	}
	else
	{
		Student *stu_fb = NULL;
		stu_fb = (Student *)malloc(sizeof(Student));  //�ڴ�malloc�Ŀռ�Ҫ������ͷ�
		printf("������ѧ��ѧ��:");
		scanf("%d", &sid);
		printf("������ѧ������:");
		scanf("%d", &age);
		stu_fb->sid = sid;
		stu_fb->age = age;
		stu_fb->next = NULL;
		while (stu)
		{
			if (stu->next == NULL)
			{
				stu->next = stu_fb;
				break;
			}
			stu = stu->next;
		}
	}

	return ret;
}
int DelStudent(Student ** del_stu, int sid) //ɾ��
{
	int ret = 0;
	int count = 0;
	Student * stu = *del_stu;
	Student * ph = stu;
	Student * p = NULL;
	while (stu)
	{
		if (stu->sid == sid)
		{
			if (count == 0)//���count==0��˵����������ͷ
			{				//���޸�
				p = stu->next;	//��ȡ����ͷ����һ�ڣ��п�����NULL
				if (p == NULL)
				{
					free(stu);
					stu = NULL;
					*del_stu = NULL;
				}
				free(stu);
				stu = NULL;
				*del_stu = p;
				break;
			}
			else  //�����һվ��Ϊ�գ��Ҿ���ָ����һվ��ɾ����һվ
			{
				p = stu->next;//������һ�ڵ�
				free(stu);//�ͷŵ�ǰ�ڵ�
				stu = NULL; //���˽ڵ����ó�NULL������Ұָ��
				ph->next = p;
				break;
			}
		}

		stu = stu->next;
		if (count == 1)
		{
			ph = ph->next;   //��if��Ϊ����ph�����һ�ڣ���������һ��ָ����һ��
		}
		count++;
	}

	return ret;
}
int ModStudent(Student ** mod_stu, int sid)  //�޸�
{
	int ret = 0;
	int age = 0;
	Student * stu = *mod_stu;
	while (stu)
	{
		if (stu->sid == sid)
		{
			printf("�����ͬѧ����:");
			scanf("%d", &age);
			stu->age = age;
			printf("�޸�%dѧ����Ϣ���.", sid);
			break;
		}
		else
		{
			stu = stu->next;
		}
	}

	return ret;
}
int PrintStudent(Student *print_stu) //��ʾ
{
	int count = 0;
	int ret = 0;
	Student *stu = print_stu;
	while (stu)
	{
		printf("%d��ѧ��������Ϊ%d\n", stu->sid, stu->age);
		stu = stu->next;
		count++;
	}
	printf("����ѧ����Ϣ������ʾ���\n����ʾ%dλͬѧ\n", count);
	return ret;
}
int FreeStudent(Student ** free_stu)//�ͷ�
{
	int ret = 0;
	Student *stu = *free_stu;
	Student *ph = stu;
	while (stu != NULL)
	{
		ph = stu->next; //�����½ڵ�ַ
		free(stu); //�ͷ�
		stu = ph;  //���½ڵ�ַ�ù���
	}
	*free_stu = NULL;
	printf("�ͷ����!\n");

	return ret;
}
void InsertStudent(Student ** Insert_stu)
{
	int sid = 0;
	int age = 0;
	int Down_sid = 0;
	if (*Insert_stu == NULL)
	{
		return;
	}
	Student * stu = *Insert_stu;
	Student * ph = stu;
	Student * p = NULL;
	Student * Insertstu = NULL;
	Insertstu = (Student *)malloc(sizeof(Student));

	PrintStudent(stu);
	printf("���������������λͬѧ���(ѧ��):");
	scanf("%d", &Down_sid);
	printf("���������ѧ��:");
	scanf("%d", &sid);
	printf("�������������:");
	scanf("%d", &age);
	Insertstu->sid = sid;
	Insertstu->age = age;
	Insertstu->next = NULL;
	while (stu)
	{
		if (stu->sid == Down_sid)
		{
			p = stu->next; //������һ�ڵ�ַ
			stu->next = Insertstu; //����һ�ڸ�Ϊ��������
			Insertstu->next = p; //���������ݵ���һ�ڸ�Ϊԭ������
			break;
		}
		stu = stu->next;
	}
	

	return;
}