#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 

int main(int argc, string argv[])
{
    
    int result;
    int KeyWord;
 
    if (argc != 2)
    {
        printf("nuh-hu, nu-huh, you didn't enter a key word!!!\n");
        return 1;
    }
 
    
    string key = argv[1]; 
 
    
    for (int n = 0, keylength = strlen(argv[1]); n < keylength; n++)
    {
        if ((key[n] >= '0') && (key[n] <= '9'))
        {
            printf("Noo, invalid key word!!!\n");
            return 1;
        }
    }
 
    string Text = GetString();   
 
    
    for(int i = 0, j = 0, length = strlen(Text); i < length; i++, j++)
    {
       
        if (j >= strlen(key))
        {
            j = 0;
        }
 
        
        KeyWord = key[j]; 
 
        if (!isalpha(Text[i]))
        {
            j = (j - 1);
        }  
 
        if ((KeyWord >= 'A') && (KeyWord <=  'Z'))
        {
            KeyWord = (KeyWord -  'A');
        }
 
        if ((KeyWord >= 'a') && (KeyWord <= 'z'))
        {
            KeyWord = (KeyWord - 'a');
        }
 
        
        result = (Text[i] + KeyWord);
 
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