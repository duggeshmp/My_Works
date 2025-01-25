#include "day2_head.h"

int main()
{
    //unsigned char shape = 0;
    unsigned int shape =0,length =0,breadth =0,height =0,radius =0;


    assert(Sum_Of_Digits_Of_Num(14895) == 27);
    assert(Sum_Of_Digits_Of_Num(87924) == 30);
    assert(Sum_Of_Digits_Of_Num(73219) == 22);
    assert(Sum_Of_Digits_Of_Num(12040) == 7);
    assert(Sum_Of_Digits_Of_Num(26089) == 25);
    assert(Sum_Of_Digits_Of_Num(70001) == 8);

    assert(Reverse_Num(157984) == 489751);
    assert(Reverse_Num(728) == 827);
    assert(Reverse_Num(123456) == 654321);
    assert(Reverse_Num(7) == 7);

    assert(Occur_Of_Digit(4559872,8) == 1);
    assert(Occur_Of_Digit(5968772,7) == 2);
    assert(Occur_Of_Digit(68429731,0) == 0);
    assert(Occur_Of_Digit(7855555,5) == 5);
    assert(Occur_Of_Digit(12343211,1) == 3);
    assert(Occur_Of_Digit(800001,0) == 4);

    assert(Is_Num_Palindrome(12321) == SUCCESS);
    assert(Is_Num_Palindrome(325894) == FAILURE);
    assert(Is_Num_Palindrome(58785) == SUCCESS);
    assert(Is_Num_Palindrome(1221) == SUCCESS);
    assert(Is_Num_Palindrome(56788765) == SUCCESS);

    First_N_Prime_Num(10);

    assert(Sum_Of_Pattern(5) == 12345);
    assert(Sum_Of_Pattern(2) == 12);
    assert(Sum_Of_Pattern(7) == 1234567);
    assert(Sum_Of_Pattern(4) == 1234);

    assert(Is_Armstrong_Num(153) == SUCCESS);
    assert(Is_Armstrong_Num(1634) == SUCCESS);
    assert(Is_Armstrong_Num(15795) == FAILURE);
    assert(Is_Armstrong_Num(123) == FAILURE);
    assert(Is_Armstrong_Num(93084) == SUCCESS);

    assert(Is_Num_Pair_Amicable(284,220) == SUCCESS);
    assert(Is_Num_Pair_Amicable(194,240) == FAILURE);
    assert(Is_Num_Pair_Amicable(1184,1210) == SUCCESS);
    assert(Is_Num_Pair_Amicable(2924,2620) == SUCCESS);
    assert(Is_Num_Pair_Amicable(63020,76084) == SUCCESS);

    assert(Menue_Driven(564,235,1) == 799);
    assert(Menue_Driven(564,235,2) == 329);
    assert(Menue_Driven(564,235,3) == 132540);
    assert(Menue_Driven(13,0,3) == 0);
    assert(Menue_Driven(378,-85,1) == 293);
    assert(Menue_Driven(378,-85,8) == FAILURE);

    printf("\nPlease Choose the shape to calculate Volume by entering its corresponding number");
    printf("\n 1 for cube \n 2 for cuboid \n 3 for sphere \n 4 for cylinder \n 5 for cone\n");
    scanf("\n %d",&shape);
    switch(shape)
    {
        case 1 : printf("\n Enter side length of cube");
                 scanf("\n %d",&length);
                 Volume_Of_Cuboid(length,length,length); /* cube is a derrivative of cuboid where all sides of cuboid
                                                        are same*/
                 break;
        case 2 : printf("\n Enter length breadth height of cuboid respectively");
                 scanf("\n %d %d %d",&length,&breadth,&height);
                 Volume_Of_Cuboid(length,breadth,height);
                 break;
        case 3 : printf("\n Enter radius of Sphere");
                 scanf("\n %d",&radius);
                 Volume_Of_Sphere(radius);
                 break;
        case 4 : printf("\n Enter Radius and Height of cylinder respectively ");
                 scanf("\n %d %d",&radius,&height);
                 Volume_Of_Cylinder(radius , height);
                 break;
        case 5 : printf("\n Enter Radius and Height of cone respectively");
                 scanf("\n %d %d",&radius,&height);
                 Volume_Of_Cone(radius , height);
        default : break;
    }

    assert(Electricity_Bill(200) == 1000);
    assert(Electricity_Bill(230) == 1210);
    assert(Electricity_Bill(430) == 3000);
    assert(Electricity_Bill(0) == 0);
    return 0;
}
