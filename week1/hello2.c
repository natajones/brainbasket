#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("State your name/n");
    string name = GetString();
    printf("hello, %s\n", name);
}