#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{ printf ("Please, state your name:\n");
    string s = GetString();
    char ch[] =" ";
if (s != NULL)
{
    if (islower (s[0]))
        {
            printf ("%c", toupper (s[0]));
        }
        else
        {
            printf ("%c", (s[0]));
        }
    for (int i = 0; i < strlen(s); i++)
    
    {
        if (s[i] ==ch[0] )
    {
        if (islower (s[i+1]))
        {
            printf ("%c", toupper (s[i+1]));
        }
        else
        {
            printf ("%c", (s[i+1]));
        }
    }
    }
}
     printf ("\n");
    

}