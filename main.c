/*
	简单实现链表增加，删除，修改，显示四项操作
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
	stu = InitStudent();//初始化链表
	while (True)
	{
		select = Welcome(); //欢迎页面
		switch (select)
		{
		case 1:
			AddStudent(&stu);
			break;
		case 2:
			printf("请输入修改学生学号:");
			scanf("%d", &sid);
			ModStudent(&stu, sid);
			break;
		case 3:
			PrintStudent(stu);
			break;
		case 4:
			printf("请输入删除学生学号:");
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
			printf("输入错误，没有该选项。\n");
			break;
		}
	}
	return ret;
}

int Welcome()  //欢迎界面
{
	int select;//翻译：选择

	printf("链表测试第一节\n");
	printf("1.增加学生信息.\n");
	printf("2.修改学生信息.\n");
	printf("3.显示学生信息.\n");
	printf("4.删除学生信息.\n");
	printf("5.插入学生信息.\n");
	printf("0.退出.\n");
	printf("选择:");
	scanf("%d", &select);

	return select;
}
Student * InitStudent()  //初始化链表
{
	Student * stu = NULL;
	stu = (Student *)malloc(sizeof(Student));
	stu->age = 0;
	stu->sid = 0;
	stu->next = NULL;

	return stu;  //初始化链表但并不操作数据
}
int AddStudent(Student ** add_stu) //增加
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
		printf("请输入学生学号:");
		scanf("%d", &sid);
		printf("请输入学生年龄:");
		scanf("%d", &age);
		stu->sid = sid;
		stu->age = age;
		stu->next = NULL;
	}
	else
	{
		Student *stu_fb = NULL;
		stu_fb = (Student *)malloc(sizeof(Student));  //在此malloc的空间要在最后释放
		printf("请输入学生学号:");
		scanf("%d", &sid);
		printf("请输入学生年龄:");
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
int DelStudent(Student ** del_stu, int sid) //删除
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
			if (count == 0)//如果count==0就说明这是链表头
			{				//已修复
				p = stu->next;	//获取链表头的下一节，有可能是NULL
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
			else  //如果下一站不为空，我就先指向下一站在删除这一站
			{
				p = stu->next;//保存下一节点
				free(stu);//释放当前节点
				stu = NULL; //将此节点设置成NULL，以免野指针
				ph->next = p;
				break;
			}
		}

		stu = stu->next;
		if (count == 1)
		{
			ph = ph->next;   //此if是为了让ph晚更新一节，这样从上一节指向这一节
		}
		count++;
	}

	return ret;
}
int ModStudent(Student ** mod_stu, int sid)  //修改
{
	int ret = 0;
	int age = 0;
	Student * stu = *mod_stu;
	while (stu)
	{
		if (stu->sid == sid)
		{
			printf("输入该同学年龄:");
			scanf("%d", &age);
			stu->age = age;
			printf("修改%d学生信息完成.", sid);
			break;
		}
		else
		{
			stu = stu->next;
		}
	}

	return ret;
}
int PrintStudent(Student *print_stu) //显示
{
	int count = 0;
	int ret = 0;
	Student *stu = print_stu;
	while (stu)
	{
		printf("%d号学生的年龄为%d\n", stu->sid, stu->age);
		stu = stu->next;
		count++;
	}
	printf("所有学生信息都以显示完毕\n共显示%d位同学\n", count);
	return ret;
}
int FreeStudent(Student ** free_stu)//释放
{
	int ret = 0;
	Student *stu = *free_stu;
	Student *ph = stu;
	while (stu != NULL)
	{
		ph = stu->next; //保存下节地址
		free(stu); //释放
		stu = ph;  //将下节地址拿过来
	}
	*free_stu = NULL;
	printf("释放完成!\n");

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
	printf("请输入你想插入哪位同学后边(学号):");
	scanf("%d", &Down_sid);
	printf("请输入你的学号:");
	scanf("%d", &sid);
	printf("请输入你的年龄:");
	scanf("%d", &age);
	Insertstu->sid = sid;
	Insertstu->age = age;
	Insertstu->next = NULL;
	while (stu)
	{
		if (stu->sid == Down_sid)
		{
			p = stu->next; //保存下一节地址
			stu->next = Insertstu; //将下一节改为新增内容
			Insertstu->next = p; //将新增内容的下一节改为原来内容
			break;
		}
		stu = stu->next;
	}
	

	return;
}