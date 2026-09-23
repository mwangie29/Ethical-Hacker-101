#include <stdio.h> //input output library.
#include <math.h> //math library.
#include <stdlib.h> //standard library.
#include <string.h> //string library.
#include <stdbool.h> //boolean library.
#include <ctype.h> //character type library.

//Examples of Globally initialized variables.
int exampleOfInitializedVar = 999;
char exampleOfInitializedChar[] = "another example";

//globally uninitialized variables.
int globalVar;
char message[50];

//Memory layout.
int gvar = 66;
const int cgvar = 1010;
int ugvar;



/*
int main()
{
    int a = 100;
    double b1 = 99.99;
    float b2 = 59.99;
    char string[20] = "Hello, Lewis!";

    // static int staticVar = 888; //eg of static variable.
    int name;

    int c = 80;
    int *ptrX; // initializing the pointer directing it to the home of c variable using &.
    ptrX = &c;
    
        printf("Trying to find value using address: %d\n", *ptrX);

        // Inputing Values.
        printf("Input/scan Integer using, %%d: ");          // test for input.
        scanf("%c", &c);                                    // format specifier %c for character
        printf("Input/scan Character using, %%c: %c\n", c); // format specifier %c for character

        // Printing values.
        printf("Print String using, %%s: %s\n", string);           // format specifier %s for string
        printf("Print Integer using, %%d: %d\n", a);               // format specifier %d for integer
        printf("Print Integer using, %%i: %i\n", a);               // another format specifier %i for integer
        printf("Print Character using, %%c: %c\n", string[0]);     // format specifier %c for character
        printf("Print ASCII value using, %%d: %d\n", string[0]);   // to print the ASCII value of the character
        printf("Print Double using, %%.2f: %.2f\n", b1);           // format specifier %.2f for 2 decimal places
        printf("Print Decimal using double, %%.2f: %.2f\n", b2);   // format specifier %.2f for 2 decimal places
        printf("Print Decimal using float and %%f: %f\n", b2);     // format specifier %f for float
        printf("Print float/double using %%e: %e\n", b1);          // format specifier %e for scientific notation (exponential form)
        printf("Print float/double using %%E: %E\n", b1);          // format specifier %E for scientific notation (exponential form)
        printf("Print lowercase Hexadecimal using %%x: %x\n", a);  // format specifier %x for hexadecimal representation
        printf("Print uppercase Hexadecimal using %%X: %X\n", b1); // format specifier %X for hexadecimal representation (uppercase)
        printf("Print Octal using %%o: %o\n", b2);                 // format specifier %o for octal representation

        // understanding pointer address operator (&).
        printf("Print Pointer Address using %%p: %p\n", &b2); // address pointer with '&' operator.
        printf("Print Pointer Address using %%p: %p\n", b2);  // address pointer without '&' operator.

        printf("Trying to find value using address: %d\n\n", *ptrX);

        // Figuring out how ro have a statement when expecting/requesting input.
        // referencing the initialized empty 'name' variable.
        printf("Dear Sir/Madam, kindly enter your name: ");
        scanf("%s", name);
        printf("Choice awards %s", name);
    

    return 0;
};
*/

// Creating Functions.
// void functions - no returns.
/*/
void swap(int x, int y)
{
  int temp = x;
  x = y;
  y = temp;
}

// Driver code to test swap.
int main() 
{
  int x = 10, y = 20;
  swap(x, y);
  printf("\nValues before swap function are: %d, %d",
          x, y);
  return 0;
} //somehow I see no swap the values at this point are the same as declared.
*/

/*
//trying out the swap with pointers.
void swapPointer(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//pointing in a function using '*'.
int main() 
{
  int x = 10, y = 20;
  swapPointer(&x, &y);
  printf("\nValues after swap function are: %d, %d",
          x, y);
  return 0;
}//Ooh I have it right now.

*/

//Testing out Heap segment memory allocation.
// int main () 
// {
//     //initializing a static variable.
//     static int staticVar;

//     //trying to assign variables to the globally uninitialized vars.
//     globalVar = 33;
//     staticVar = 59;
//     snprintf(message, sizeof(message), "This is Uninitialized Data Segment BSS");
//     printf("Message: %s\n", message);
    
//     return 0;
// }


//Testing out Stack Segment.
void foo() {
    
    // Local variable
    int lvar = 1;
    printf("Address of lvar:\t%p", (void*)&lvar);
}

int main() {
    
    // Heap variable
    int *hvar = (int*)malloc(sizeof(int));
    
    
    // Checking and comparing address of different
    // elements of program that should be stored in
    // different segements of the memory
    printf("Address of foo:\t\t%p\n", (void*)&foo);
    printf("Address of cgvar:\t%p\n", (void*)&cgvar);
    printf("Address of gvar:\t%p\n", (void*)&gvar);
    printf("Address of ugvar:\t%p\n", (void*)&ugvar);
    printf("Address of hvar:\t%p\n", (void*)hvar);
    foo();
    
	return 0;
}
