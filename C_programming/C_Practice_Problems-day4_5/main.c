#include "day4_head.h"

int main()
{
	int max = 0,min = 0, arr_size;
	int arr[ARRAY_SIZE] = {20,7,1,4,10,7,3,1,20,6};
	int A[ARRAY_A_SIZE] = {40,27,39,20,7,9,4,10,35,3,1,15,6};
	int B[ARRAY_B_SIZE] = {7,1,8,12,6,31,26};
	int A_B_size =ARRAY_A_SIZE + ARRAY_B_SIZE;
	int A_B_optn[A_B_size];
	char U_Case[20];
	char *str_rev;
	int i=0;
	int sparse_matx[4][COL] = {{0,0,0,1,2},{3,5,0,0,0},{0,5,0,0,0},{0,0,0,0,7}};

	int matrix[ROW][COL];
	int sum_of_col[COL];

	Print_Arr(arr,ARRAY_SIZE);
	assert(Sort_Arr_Ascend_Descend(arr,ARRAY_SIZE,1) == SUCCESS);
	Print_Arr(arr,ARRAY_SIZE);
	assert(Sort_Arr_Ascend_Descend(arr,ARRAY_SIZE,0) == SUCCESS);
	Print_Arr(arr,ARRAY_SIZE);

	assert(Find_Max_Min(arr , ARRAY_SIZE , &max ,&min) == SUCCESS);

	printf("\n Maximum value in array = %d \n Minimum value in array = %d",max ,min);

	printf("\nArray A and B :-\n");
	Print_Arr(A,ARRAY_A_SIZE);
	Print_Arr(B,ARRAY_B_SIZE);

	A_B_size = Set_Union(A ,B, ARRAY_A_SIZE, ARRAY_B_SIZE, A_B_optn);
	
	printf(" \nA union B\n");
	Print_Arr(A_B_optn,A_B_size);

	A_B_size = Set_Intersection(A ,B, ARRAY_A_SIZE, ARRAY_B_SIZE, A_B_optn);
	
	printf(" \nA Intersection B\n");
	Print_Arr(A_B_optn,A_B_size);

	A_B_size = Set_Diffference(A ,B, ARRAY_A_SIZE, ARRAY_B_SIZE, A_B_optn, 0);
	
	printf(" \nA - B\n");
	Print_Arr(A_B_optn,A_B_size);

	A_B_size = Set_Diffference(A ,B, ARRAY_A_SIZE, ARRAY_B_SIZE, A_B_optn, 1);
	
	printf(" \nB - A\n");
	Print_Arr(A_B_optn,A_B_size);

	printf("\narray before deletion of duplicate elements\n");
	Print_Arr(arr,ARRAY_SIZE);

	arr_size=Remove_Dulic_elem(arr , ARRAY_SIZE);
	printf("\narray after deletion of duplicate elements\n");
	Print_Arr(arr,arr_size);

	
	assert(Sum_Of_Prod_Of_Consec_Num(arr , arr_size) == 351);
	assert(Sum_Of_Prod_Of_Consec_Num(B , ARRAY_B_SIZE) == 1175);

	assert(Binary_Search(arr, 0,arr_size,7) == FOUND);
	assert(Binary_Search(arr, 0,arr_size,10) == FOUND);
	assert(Binary_Search(arr, 0,arr_size,20) == FOUND);
	assert(Binary_Search(arr, 0,arr_size,4) == FOUND);
	assert(Binary_Search(arr, 0,arr_size,6) == FOUND);
	assert(Binary_Search(arr, 0,arr_size,1) == FOUND);

	assert(Binary_Search(arr, 0,arr_size,11) == NOT_FOUND);

	assert(String_Length("string") == 6);
	assert(String_Length("hi all") == 6);
	assert(String_Length("seven27") == 7);

	assert(String_Length("Fail") == 4);

	assert(Date_Month_print(27,8,1919) == SUCCESS);
	assert(Date_Month_print(30,11,2019) == SUCCESS);
	assert(Date_Month_print(40,8,2013) == FAIL);
	assert(Date_Month_print(0,8,1452) == FAIL);

	//assert(All_Lower_2_Upp_Case("hello") == "HELLO");
	memset(U_Case , '\0',sizeof(char)*20);
	All_Lower_2_Upp_Case("lowercase",U_Case);
	printf("\n%s\n",U_Case);

	memset(U_Case , '\0',sizeof(char)*20);
	Reverse_String("HELLO",U_Case);
	printf("\n%s\n",U_Case);

	assert(Is_String_Palindrom("malayalam") == SUCCESS);
	assert(Is_String_Palindrom("abcdcba") == SUCCESS);
	assert(Is_String_Palindrom("tatat") == SUCCESS);
	assert(Is_String_Palindrom("not") == FAIL);

	String_Concat("Hello","people",U_Case);
	String_Concat("how,are","you!All",U_Case);
	printf("\n%s\n",U_Case);

	Construct_Matrix(matrix,ROW,COL);
	Display_Matrix(matrix,ROW,COL);

	printf("\n");
	Transpose_Matrix(matrix,ROW,COL);
	Display_Matrix(matrix,ROW,COL);

	printf("\n");
	Sum_Of_Col_In_Matrix(matrix,COL,ROW,sum_of_col);
	Print_Arr(sum_of_col,COL);
	
	assert(Is_Sparse_Matrix(sparse_matx,4,COL) == SUCCESS);
	assert(Is_Sparse_Matrix(matrix,ROW,COL) == FAIL);

	
	return 0;
}
