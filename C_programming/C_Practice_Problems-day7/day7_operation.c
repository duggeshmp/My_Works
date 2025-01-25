#include "day7_head.h"

int * Get_Int_Arr_Memory(int size)
{
	int *arr;

	arr = (int *) malloc(sizeof(int)*size);

	return arr;
}
void Insert_Elem(int *arr,int size)
{
	int i;
	for(i = 0;i < size; i++ )
		arr[i] = ((11*59)/(i+1))%100;
}

void Display_Arr(int *arr, int size)
{
	for(int i = 0; i < size; i++) printf("\n %d",arr[i] );
}

int Linear_Search(int *arr ,int size,const int elem)
{
	for(int i = 0;i < size; i++)
		if(elem == arr[i]) return FOUND;
	return NOT_FOUND;
}
void Max_Min_In_Arr(int *arr,int size,int *max,int *min)
{
	*max = arr[0];
	*min = arr[0];

	for(int i = 0;i < size; i++)
	{
		if(*max < arr[i]) *max = arr[i];
		if(*min > arr[i]) *min = arr[i];
	}
		
}


void EvenSum_OddSum_Arr(int *arr,int size,int *Even_sum,int *Odd_Sum)
{
	for(int i = 0;i < size;i++)
		if(0 == arr[i]%2) *Even_sum += arr[i];
		else *Odd_Sum += arr[i];
}

int Is_Arr_Palindrome(int *arr,int size)
{
	int i = 0, j =0;
	for(int i = 0,j = size-1; i < size/2 ,j > size/2 ; i++,j--)
		if(arr[i] != arr[j])	return FAIL;

	return SUCCESS;
}

int Get_Subset_For_Sum(int *arr,int arr_size,int *subset,int sum)
{
	
	for(int i = 0;i < arr_size; i++)
		for(int j = 1;j < arr_size ; j++)
			if(sum == (arr[i] + arr[j])) 
			{
				
				subset[0] = arr[i];
				subset[1] = arr[j];
				return SUCCESS;
			}
	return FAIL;
}

void Free_Memory(int *memory)
{
	free(memory);
}