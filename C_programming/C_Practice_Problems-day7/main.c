#include "day7_head.h"

int main()
{
	int *arr,*arr_subset,max,min;
	int sum_of_even = 0,sum_of_odd = 0;

	arr = Get_Int_Arr_Memory(ARRAY_SIZE);
	assert(arr != NULL);

	Insert_Elem(arr , ARRAY_SIZE);
	Display_Arr(arr , ARRAY_SIZE);

	assert(NOT_FOUND == Linear_Search(arr, ARRAY_SIZE, 0));
	assert(FOUND == Linear_Search(arr, ARRAY_SIZE, 8));
	assert(FOUND == Linear_Search(arr, ARRAY_SIZE, 49));
	assert(FOUND == Linear_Search(arr, ARRAY_SIZE, 81));
	assert(NOT_FOUND == Linear_Search(arr, ARRAY_SIZE, 100));

	Max_Min_In_Arr(arr,ARRAY_SIZE,&max,&min);

	assert(92 == max);
	assert(8 == min);

	EvenSum_OddSum_Arr(arr ,ARRAY_SIZE, &sum_of_even, &sum_of_odd);

	assert(159 == sum_of_odd);
	assert(338 == sum_of_even);

	assert(FAIL == Is_Arr_Palindrome(arr, ARRAY_SIZE));

	for(int i = 0; i <ARRAY_SIZE ;i++)
		if(i < ARRAY_SIZE/2) arr[i] = i+1;
		else arr[i] = 10-i ;

	//Display_Arr(arr , ARRAY_SIZE);
	assert(SUCCESS == Is_Arr_Palindrome(arr, ARRAY_SIZE));

	arr_subset = Get_Int_Arr_Memory(ARRAY_SUBSET_SIZE);
	assert(NULL != arr_subset);

	Insert_Elem(arr , ARRAY_SIZE);
	assert(SUCCESS == Get_Subset_For_Sum(arr,ARRAY_SIZE,arr_subset,73));
	assert(SUCCESS == Get_Subset_For_Sum(arr,ARRAY_SIZE,arr_subset,72));
	assert(SUCCESS == Get_Subset_For_Sum(arr,ARRAY_SIZE,arr_subset,100));
	assert(SUCCESS == Get_Subset_For_Sum(arr,ARRAY_SIZE,arr_subset,88));
	assert(FAIL == Get_Subset_For_Sum(arr,ARRAY_SIZE,arr_subset,27));
	assert(FAIL == Get_Subset_For_Sum(arr,ARRAY_SIZE,arr_subset,18));
	
	assert(NULL != arr_subset);
	
	//Display_Arr(arr_subset , ARRAY_SUBSET_SIZE);

	Free_Memory(arr);
	Free_Memory(arr_subset);

	return 0;


}