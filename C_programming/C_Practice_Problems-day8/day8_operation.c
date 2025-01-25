#include "day8_head.h"

Student * Get_Student_Memory(int size)
{
	Student *stud;

	stud = (Student *)malloc(sizeof(Student)*size);

	assert(NULL != stud);

	return stud;
}

void Insert_Student_Data(Student *stud ,int size)
{
	char *name;
		*name = 65;

	memset(stud,'\0',sizeof(Student)*size);
	for(int i =0; i <size; i++)
	{
		stud[i].RollNo = i+241039001;
		stud[i].Marks = (27*31*(i+1))%100;

		stud[i].Age = (24*75)%100;

		strncpy(stud[i].Name ,name ,NAME_SIZE);
		*name = *name+1;
	}
}