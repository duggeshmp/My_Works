#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


#define NAME_SIZE 20
#define TOTAL_STUDENTS 10

typedef struct _Student_Details_
	{
		int RollNo;
		int Marks;
		int Age;
		char Name[NAME_SIZE];
	}Student;

void Insert_Student_Data(Student *stud,int size);

Student * Get_Student_Memory(int size);

