/*********************************************************************************************************************
    Function:- Ucase_To_Lcase
    converts upper case letter to lower case letter

    Input = Upper case letter
    output/return = lower case letter

    Ascii values are used to do operation

*********************************************************************************************************************/
char Ucase_To_Lcase(const char);

/*********************************************************************************************************************
    Function:- Area_Of_Circle
    Takes radius of circle as input and returns area of circle

    Input = Radius of circle i.e float value
    output/return = Area of circle

   Area = (22/7)*r*r

*********************************************************************************************************************/
double Area_Of_Circle(const float);

/*********************************************************************************************************************
    Function:- No_Of_Char_bw_2Char
    takes 2 char input either capital or small letter alphabet and calcultes number of lettrs between them
    Input 1 = alphabet
    input 2 = alphabet
    output/return = integer number of letters between 2 alphabet

   ascii value of capital letters A-Z 65-90
                  small letters a-z   97-122

**********************************************************************************************************************/
int No_Of_Char_bw_2Char(const char,const char);



/*********************************************************************************************************************
    Function:- Temp_Celsi_To_Fahren

    takes 1 float input of celsius value and converts it to Fahrenheit value

    Input = celsius Temperature value
    output/return = Fahrenheit Temperature value

**********************************************************************************************************************/

float Temp_Celsi_To_Fahren(const float);

/*********************************************************************************************************************
    Function:- No_Is_Even_Odd

    takes 1 integer input and checks whether it is a even or odd

    Input = integer

    output/return = returns 0 if even
                    else returns 1 for odd
**********************************************************************************************************************/

int No_Is_Even_Odd(const int);

/*********************************************************************************************************************
    Function:- Is_Leap_Year()

    takes 1 integer input and checks whether it is Leap year or not

    Input = integer

    output/return = returns 0 if Leap year
                    else returns 1 for Non leap year
**********************************************************************************************************************/

int Is_Leap_Year(const unsigned int);

/*********************************************************************************************************************
    Function:- Two_Power()

    takes 1 unsigned integer input as power of 2 and calculates its value by shift operation

    Input = unsigned integer

    output/return = 2 power value
**********************************************************************************************************************/
int Two_Power(const unsigned int);


/*********************************************************************************************************************
    Function:- Check_Num_Or_Char()

    takes 1  input as whether characters or 0 to 9 numbers

    Input = character input/0 to 9 numbers

    output/return = returns 0 for character
                    1 for 0 to 9 numbers

    ascii value of 0 to 9 is 48 to 57
**********************************************************************************************************************/
int Check_Num_Or_Char(const char);


/*********************************************************************************************************************
    Function:- Sum_Of_2_Rand_Num()


    Input = generates two random number by rand() function

    output/return = sum of two random number

**********************************************************************************************************************/
int Sum_Of_2_Rand_Num();
