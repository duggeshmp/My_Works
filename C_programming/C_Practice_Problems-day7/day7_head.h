#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 10
#define ARRAY_SUBSET_SIZE 2
#define FOUND 0
#define NOT_FOUND -1
#define SUCCESS 1
#define FAIL 0

int * Get_Int_Arr_Memory(int size);//returns integer array starting memory

void Insert_Elem(int *arr,int size);//inserts random numbers into array

void Display_Arr(int *arr, int size);//prints array on screen

int Linear_Search(int *arr ,int size,const int elem);//searches the element in array and returns it

void Max_Min_In_Arr(int *arr,int size,int *max,int *min);//finds maximum and minimum value in array

void EvenSum_OddSum_Arr(int *arr,int size,int *Even_sum,int *Odd_Sum);//finds sum of even elements and sum of odd elements

int Is_Arr_Palindrome(int *arr,int size);//returns 0 if palindrome else returns -1

int Get_Subset_For_Sum(int *arr,int arr_size,int *subset,int sum);

void Free_Memory(int *);