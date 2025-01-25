#include "day8_head.h"

int main()
{
	Student *stud;

	stud = Get_Student_Memory(10);

	assert(NULL != stud);

	Insert_Student_Data(stud,TOTAL_STUDENTS);

	printf("\n");

	return 0;
}