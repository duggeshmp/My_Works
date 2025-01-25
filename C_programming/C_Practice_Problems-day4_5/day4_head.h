/**DRIVE LINK = https://drive.google.com/drive/folders/1XDTurvietkPls8LUeYslGjFhuRUHma59**
 * Leat code*
 stdint.h pragmapack1 */

#include<assert.h>
#include<stdio.h>
#include<string.h>

#define ARRAY_SIZE 10
#define ARRAY_A_SIZE 13
#define ARRAY_B_SIZE  7
#define ASCEND 1
#define DESCEND 0
#define FAIL -1
#define SUCCESS 0
#define FOUND 0
#define NOT_FOUND -1
#define ROW 5
#define COL 5


/***************
Function = Sort_Arr_Ascend_Descend()

input 1 : array pointer
input 2 : Size of array
input 3 : 1 for Ascending
		  0 for  Descending
output/return : returns 0 for success
				 -1 for failure

****************/
int Sort_Arr_Ascend_Descend(int arr[],int,int);

/***************
Function = Swap()

input 1 : integer pointer to number 1
input 2 : integer pointer to number 2

output/return : swaps 2 number
****************/
void Swap(int *,int *);

/***************
Function = Print_Arr()

input 1 : integer array pointer
input 2 : size of array

output/return : prints the array
****************/
void Print_Arr(int arr[] ,int );

/***************
Function = Find_Max_Min()

input 1 : integer array pointer
input 2 : size of array
input 3 : integer pointer for maximum value
input 4 : integer pointer for minimum value

output/return : return 0 for success
					   -1 for Failure
****************/
int Find_Max_Min(int arr[],int ,int *,int *);

/***************
Function = Set_Union()

A union B 

input 1 : integer array pointer for array A
input 2 : integer array pointer for array A
input 3 : size of array A
input 4 : size of array B
input 5 : integer array pointer for resultant array 

output/return : returns length of A union B array
****************/
int Set_Union(int A[] ,int B[],int A_size,int B_size,int result[]);

/***************
Function = Set_Intersection()

A intersection B 

input 1 : integer array pointer for array A
input 2 : integer array pointer for array A
input 3 : size of array A
input 4 : size of array B
input 5 : integer array pointer for resultant array 

output/return : returns length of A intersection B array
****************/
int Set_Intersection(int A[] ,int B[],int A_size,int B_size,int result[]);

/***************
Function = Set_Diffference()

A-B and B-A

input 1 : integer array pointer for array A
input 2 : integer array pointer for array A
input 3 : size of array A
input 4 : size of array B
input 5 : integer array pointer for resultant array 
input 6 : it is flag 0 for A-B
					 1 for B-A
output/return : returns length of A-B and B-A array
****************/

int Set_Diffference(int A[] ,int B[],int A_size,int B_size,int result[],const int);
/***************
Function = Linear_Search()

input 1 : integer array pointer 
input 2 : array size
input 3 : element to search


output/return : return 0 for found
					   -1 for not found
****************/
int Linear_Search(int arr[] ,const int size,const int element);

/***************
Function = Remove_Dulic_elem()

input 1 : integer array pointer 
input 2 : array size

output/return : return 0 for SUCCESS
					   -1 for not FAIL
****************/
int Remove_Dulic_elem(int arr[],int size);	

/***************
Function = Binary_Search()

input 1 : integer array pointer 
input 2 : array starting index
input 3 : array final index
input 4 : element to be searched

output/return : return 0 for Found
					   -1 for not found
****************/
int Binary_Search(int arr[],int start_index,int final_index,const int element);

/***************
Function = Sum_Of_Prod_Of_Consec_Num()

input 1 : integer array pointer 
input 2 : array size

output/return : returns sum of products of two consecutive numbers
****************/

int Sum_Of_Prod_Of_Consec_Num(int arr[],const int);
/***************
Function = String_Length()

input 1 : string array

output/return : returns length of string
****************/
unsigned int String_Length(char str[]);

/***************
Function = Date_Month_print()

input 1 : date
input 2 : month in number format
input 3 : year

output/return : Prints the the date month year format
				e.g. input: d=16, m=7, y=1992
					Output: 16th July, 1992
****************/

int Date_Month_print(unsigned int date,unsigned int month,unsigned int year);

/***************
Function = All_Lower_2_Upp_Case()

To convert all lower-case characters into their upper-case equivalents
input 1 : character pointer for input UPPERCASE
input 2 : character pointer to store lowercase letter

output/return : returns UPPER CASE LETTERS of string
****************/
void  All_Lower_2_Upp_Case(char *str,char *);

/***************
Function = Reverse_String()

To reverse the string
input 1 : input character array
input 2 : reversed string array

output/return : reverse the string and stores in second input array
****************/
void Reverse_String(char str[],char revers_str[]);

/***************
Function = Is_String_Palindrom()

To check string is palindrome or not
input 1 : input character array


output/return : returns 0 for Palindrome
						-1 for not palindrome
****************/
int Is_String_Palindrom(char str[]);

/***************
Function = String_Concat()

concatinates two strings
input 1 : str1 character array
input 2 : str2 character array
input 3 : result character array

output/return : concatinates two string and result is stored
****************/
void String_Concat(char str1[],char str2[],char res[]);

/***************
Function = Construct_Matrix()

input 1 : matrix array
input 2 : row
input 3 : col

output/return : stores random values to array
****************/
void Construct_Matrix(int matrix[][COL],int ,int);

/***************
Function = Display_Matrix()

input 1 : matrix array
input 2 : row
input 3 : col

output/return : display matrix on output screen
****************/
void Display_Matrix(int matrix[][COL],int row,int col);

/***************
Function = Display_Matrix()

input 1 : matrix array
input 2 : row
input 3 : col

output/return : converts matrix to its transpose
****************/
int Transpose_Matrix(int matrix[][COL],int,int);

/***************
Function = Sum_Of_Col_In_Matrix()

input 1 : matrix array
input 2 : row
input 3 : col
input 4 : sum array

output/return : sum of each column in the matrix in sum array
****************/
void Sum_Of_Col_In_Matrix(int matrix[][COL],int ,int ,int sum[]);

/***************
Function = Is_Sparse_Matrix()

input 1 : matrix array
input 2 : row
input 3 : col

output/return : returns 0 if Sparse Matrix
						-1 if not sparse matrix
****************/
int Is_Sparse_Matrix(int matrix[][COL],int row,int col);
