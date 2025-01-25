#include "day4_head.h"

int Sort_Arr_Ascend_Descend(int arr[],int size, int flag)
{
	int i,j,ret_val = FAIL ;
	if(flag == ASCEND)
	{
		for(i =0 ; i < ARRAY_SIZE ; i++) 
			for(j =i+1 ; j < ARRAY_SIZE ; j++)
				if(arr[i] > arr[j])
					Swap(&arr[i],&arr[j]);
		ret_val = SUCCESS;
	}
	if(flag == DESCEND)
	{
		for(i =0 ; i < ARRAY_SIZE ; i++) 
			for(j =i+1 ; j < ARRAY_SIZE ; j++)
				if(arr[i] < arr[j])
					Swap(&arr[i],&arr[j]);
		ret_val = SUCCESS;
	}
	return ret_val;
}

void Swap(int *num1,int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void Print_Arr(int arr[] ,int size)
{
	int i;
	printf("\n");
	for(i =0; i < size ; i++)
		printf("%d ",arr[i]);
}

int Find_Max_Min(int arr[],int size,int *max,int *min)
{
	int i , ret_val = FAIL;
	*max = arr[0];
	*min = arr[0];
	for(i =1; i< size ; i++)
	{
		if(arr[i] > *max)
			*max = arr[i];
		if(arr[i] < *min)
			*min = arr[i];

		ret_val = SUCCESS ;
	}
	return ret_val;
}

int Linear_Search(int arr[] ,const int size,const int element)
{
	int i;
	for(i = 0;i < size; i++)
		if(element == arr[i])
			return FOUND;
	return NOT_FOUND;	
}
int Set_Union(int A[] ,int B[],int A_size,int B_size,int result[])
{
	int result_size = 0;
	int i;
	for (i = 0; i < A_size; ++i)
		if(NOT_FOUND == Linear_Search(result, result_size, A[i]))
		{
			result[result_size] = A[i];
			result_size++;
		}

	for(i = 0;i < B_size; i++)
		if(NOT_FOUND == Linear_Search(result, result_size, B[i]))
		{
			result[result_size] = B[i];
			result_size++;
		}
	return result_size;
}

int Set_Intersection(int A[] ,int B[],int A_size,int B_size,int result[])
{
	int i ,j,result_len = 0;
	for(i = 0;i < A_size; i++)
		for(j = 0;j < B_size; j++)
			if(A[i] == B[j])
			{
				result[result_len] = A[i];
				result_len++;
			}
	return result_len;		
}

int Set_Diffference(int A[] ,int B[],int A_size,int B_size,int result[],const int flag)
{
	int i,result_len =0;

	if(0 == flag)
	for(i =0 ;i < A_size; i++)
		if(NOT_FOUND == Linear_Search(B ,B_size ,A[i]))
			{
				result[result_len] = A[i];
				result_len++;
			}

	if(1 == flag)
	for(i =0 ;i < B_size; i++)
		if(NOT_FOUND == Linear_Search(A ,A_size ,B[i]))
			{
				result[result_len] = B[i];
				result_len++;
			}

	return result_len;
}

int Remove_Dulic_elem(int arr[],int size)
{
	int i , j,arr_len = 0;
	Sort_Arr_Ascend_Descend(arr,size, ASCEND );

	for(i = 0;i < size; i++)
		for(j = i+1;j < size; j++)
			if((arr[i] != arr[j]) && (arr[i] < arr[j]))
				{
					arr_len += 1;
					arr[arr_len] = arr[j];
					i = arr_len;
				}
		

	return arr_len;
}	

int Sum_Of_Prod_Of_Consec_Num(int arr[],const int size)
{
	int i ,j,Sum_Of_Prod = 0;

	for(i =0;i < size-1; i++)
			Sum_Of_Prod += arr[i]*arr[i+1];

	return Sum_Of_Prod;
}

int Binary_Search(int arr[],int start_index,int final_index,const int element)
{
	int mid = 0;

	while(start_index <= final_index)
	{
		mid = (final_index - start_index)/2 ;
		if(element == arr[mid])
			return FOUND;
		else if (element < arr[mid])
			final_index = mid-1 ;
		else if(element > arr[mid])
			start_index = mid+1;
	}
		
	return NOT_FOUND;

}
unsigned int String_Length(char str[])
{
	int i = 0;

	if(NULL == str) return FAIL;
	else
		while(str[i] != '\0') i++;
	
	return i;
}

int Date_Month_print(unsigned int date,unsigned int month,unsigned int year)
{
	if((date < 1)||(date > 31) || (month < 1)|| (month > 12)) return FAIL;

	switch(month)
	{
		case 1 : printf("\n%d January, %d",date,year);
				 break;
		case 2 : printf("\n%d February, %d",date,year);
				 break; 
		case 3 : printf("\n%d March, %d",date,year);
				 break;
		case 4 : printf("\n%d April, %d",date,year);
				 break; 
		case 5 : printf("\n%d May, %d",date,year);
				 break;
		case 6 : printf("\n%d June, %d",date,year);
				 break; 
		case 7 : printf("\n%d July, %d",date,year);
				 break;
		case 8 : printf("\n%d August, %d",date,year);
				 break; 
		case 9 : printf("\n%d September, %d",date,year);
				 break;
		case 10 : printf("\n%d October, %d",date,year);
				 break; 
		case 11 : printf("\n%d November, %d",date,year);
				 break;
		case 12 : printf("\n%d December, %d",date,year);
				 break; 
		defaul : printf("\nwrong input");
				return FAIL;
				 break;
	}

	return SUCCESS;
}

void  All_Lower_2_Upp_Case(char *str,char *U_Case)
{
	int i  , str_len =0;
	
	str_len = String_Length(str);

	for( i =0; i < str_len;i++)
		if((str[i] >= 'a')&&(str[i] <= 'z'))
			U_Case[i] = str[i] -32;
			
}

void Reverse_String(char str[] ,char revers_str[])
{
	unsigned int str_len =0;
	int i =0;

	str_len = String_Length(str);

	while(str_len > 0)
	{
		revers_str[i] = str[str_len - 1] ;
		str_len--;
		i++;
	} 
}
int Is_String_Palindrom(char str[])
{
	char rev_str[20]={'\0'};
	unsigned int str_len = 0;

	Reverse_String(str,rev_str);
	str_len = String_Length(str);
	for(int i =0;i < str_len; i++)
		if(str[i] != rev_str[i])
			return FAIL;

		return SUCCESS;
}

void String_Concat(char str1[],char str2[],char res[])
{
	unsigned int str1_len, str2_len, res_len,i,j = 0;

	str1_len = String_Length(str1);
	str2_len = String_Length(str2);
	res_len = str1_len + str2_len;
	
	memset(res,'\0',sizeof(char)*(str1_len+str2_len));

	for(i =0; i < res_len ;i++)
		if(i < str1_len)
			res[i] = str1[i];
		else
		{
			res[i] = str2[j];
			j++;
		}
}

void Construct_Matrix(int matrix[][COL],int row,int col)
{
	int i,j;
	for(i = 0;i < row; i++)
		for(j = 0;j < col;j++)
			matrix[i][j] = (27*col*(i+27)-j)%100;//simply generating some numbers

}
void Display_Matrix(int matrix[][COL],int row,int col)
{
	int i,j;
	for(i = 0;i < row; i++)
	{
		printf("\n");
		for(j = 0;j < col;j++)
			printf("%d  ",matrix[i][j]);
	}
}

int Transpose_Matrix(int matrix[][COL],int row,int col)
{
	int i,j,var;

	if(row != col) return FAIL;

	for(i = 0;i < row ;i++)
		for(j = i+1 ;j < col ;j++)
			if(i != j)
			{
				var = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = var;
			}
	return SUCCESS;
}
void Sum_Of_Col_In_Matrix(int matrix[][COL],int col,int row,int sum[])
{
	int i,j;
	memset(sum,0,sizeof(int)*col);

	for(i = 0;i < col; i++)
		for(j = 0;j < row ; j++)
		{
			sum[i] += matrix[j][i];
		}
}

int Is_Sparse_Matrix(int matrix[][COL],int row,int col)
{
	unsigned int i,j,count = 0;

	for(i = 0;i < row ;i++)
		for(j = 0;j < col ; j++)
			if(0 == matrix[i][j]) count++;

		if(count < (row*col)/2) return FAIL;

return SUCCESS;
}
