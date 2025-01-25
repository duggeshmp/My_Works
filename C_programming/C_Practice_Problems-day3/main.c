#include "day3_head.h"


int main()
{

    assert(Binary_2_Decimal(1010) == 10);
   /* assert(Binary_2_Decimal(0101) == 5); wrong input because it should not start with zero,
                                if it starts it will consider as octal number*/
    assert(Binary_2_Decimal(101) == 5);
    assert(Binary_2_Decimal(1111) == 15);
    assert(Binary_2_Decimal(1000) == 8);
    assert(Binary_2_Decimal(101101) == 45);

    Sequence_Generator1(0);
    Sequence_Generator1(1);
    Sequence_Generator1(2);
    Sequence_Generator1(3);
    Sequence_Generator1(4);
    Sequence_Generator1(7);
    Sequence_Generator1(12);

    Sequence_Generator2(3);
    Sequence_Generator2(5);
    Sequence_Generator2(1);
    Sequence_Generator2(0);
    Sequence_Generator2(7);

    Sequence_Generator3(4);
    Sequence_Generator3(5);
    Sequence_Generator3(1);
    Sequence_Generator3(0);
    Sequence_Generator3(7);

    return 0;
}
