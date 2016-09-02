#include <stdio.h>
#include <cs50.h>
int main (void)
{
int x, y, z;
do 
{
    printf ("Please give me an int between 1 and 23:\n");
    x = GetInt ();
}
   while (x < 0 || x > 23);

     for (y = 1; y <= x; y++)
    {
        for (z = 0; z < (x - y); z++)

        printf (" ");
        
        for(z = 0; z <= y; z++)
       printf ("#");
       printf ("\n");
        
    }
 
}