#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf ("Let's see how many bootles of water you use while taking a shower. How much time you shower?:\n");
 int a,b,c;
 a = GetInt ();
 b = 12;
 c = a * b;
 
  
  printf ("Minutes: %d\nBottles: %d\n", a, c);
  
}