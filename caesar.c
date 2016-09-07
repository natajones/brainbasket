
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 

int main(int argc, string argv[])
{
    
    int key;
    int result;
    
   
 
    
    if (argc != 2)
    {
        printf("You didn't enter a key. Run program and enter key.\n");
        return 1;
    }
 
    
    string Text = GetString();
 
    
    key = atoi(argv[1]);
 
    
    if (key >= 26)
    {
        key = (key % 26);
    }
 
   
    for(int i = 0, length = strlen(Text); i < length; i++)
    {
        
        result = (Text[i] + key);
 
        
        if (isupper(Text[i]) && (result > 'Z'))
        {
            result = (result - 26);
        }
 
        
        if (islower(Text[i]) && (result > 'z'))
        {
            result = (result - 26);
        }
 
        
 
        
        if (isalpha(Text[i]))
        {
            printf("%c", result);
        }
 
        
        else
        {
            printf("%c", Text[i]);
        }
 
    }
 
    printf("\n");
    return 0;
}