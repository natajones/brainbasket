#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    
    

    float a;
    int n;
    n = 0;
    
    do
    {
        printf ("How much change is owed?:\n");
         a = GetFloat();
         a =  (int)round(a * 100);
      
    }  
    while( a < 0 || a == 0);
    
    

   while ( a> 0)
   {
       
   
   while (a >= 25)
    {
        n++;
        
        a = a - 25;
    
    }
    
    
   while (a >= 10)
    {
        n++;
        
        a = a - 10;
        
    }
    
    
    while (a >=5)
    {
        n++;
        
        a = a - 5;
        
    }
    
    
    while (a >= 1)
    {
       n++;
       
        a = a - 1;
        
    }
    
    
   }
    
    printf("%d\n", n);
    
}