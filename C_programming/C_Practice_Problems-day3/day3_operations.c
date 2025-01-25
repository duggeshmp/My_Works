
#include "day3_head.h"

int Binary_2_Decimal(unsigned int binary_num)
{
    int decimal_num = 0, power = 0;
    while(0 != binary_num)
    {
        decimal_num +=  pow(2 , power) * (binary_num % 10);
        binary_num = binary_num/10 ;
        power++;
    }
    return decimal_num ;
}

void Sequence_Generator1(unsigned int num_of_elemts)
{
    int fst_elem =0,sec_elem =0,thrd_elem =1,final_elem =0;
    if(3 > num_of_elemts )
    {
        if(1 == num_of_elemts) printf("\n %d",fst_elem);
        if(2 == num_of_elemts) printf("\n %d %d",fst_elem,sec_elem);
    }
    else
    {
        printf("\n %d %d %d",fst_elem,sec_elem,thrd_elem);
        while(3 != num_of_elemts)
        {
            final_elem = fst_elem + sec_elem+thrd_elem;
            printf(" %d",final_elem);
            fst_elem = sec_elem;
            sec_elem = thrd_elem;
            thrd_elem = final_elem;
            num_of_elemts--;
        }
    }

}

void Sequence_Generator2(unsigned int num_of_rows)
{
    int i, j,k;
    for(i =0;i < num_of_rows; i++)
    {
        k = i;
        printf("\n");
        while(0 != k)
        {
            printf("  ");
            k--;
        }
        for(j = i; j < num_of_rows ; j++) printf("* ");
    }
}

void Sequence_Generator3(unsigned int num_of_rows)
{
    int i = 0,k =0;
    printf("\n");
    while(i < num_of_rows)
    {
        if(k <= i)
        {
           printf("* "); k++ ;
        }

        else
        {
            printf("\n");
            i++;
            k = 0 ;
        }

    }
}
