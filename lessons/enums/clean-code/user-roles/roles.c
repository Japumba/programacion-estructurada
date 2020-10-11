#include <stdio.h>

/**
 * These are the user role values:
 * 0 = Admin
 * 1 = Staff
 * 2 = Teacher
 * 3 = Student
 * 4 = Visitor
 */

/**
 * Prints the complete name of a role value to the standard output
 * without newline at the end.
 */
void useless_function_name(int);

int main()
{
    int x = 0;
    printf("The user role is: ");
    useless_function_name(x);
    printf("\n");

    return 0;
}

void useless_function_name(int a)
{
    if (a == 0)
        printf("Admin");
    else if (a == 1)
        printf("Staff");
    else if (a == 2)
        printf("Teacher");
    else if (a == 3)
        printf("Student");
    else if (a == 4)
        printf("Visitor");
    else
        printf("Unknown");
}