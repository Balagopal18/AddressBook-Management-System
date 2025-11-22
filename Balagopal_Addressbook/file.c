//including all necessary libraries and files
#include<stdio.h>
#include<string.h>
#include "file.h"
#include "contact.h"

void saveContactsToFile(AddressBook *addressBook)          //function definition to save the new/modified data to file
{
    FILE* fptr = fopen("contacts.csv","w");                //opening the file in write only mode                                         
    fprintf(fptr,"%d\n",addressBook -> contactCount);      //saving the contactcount as 1st data in file 
    for (int i = 0; i < addressBook -> contactCount ; i++)        //start saving all remaining data from next line
    {
        fprintf(fptr,"%s,%s,%s\n", addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);    //printing all contents to file having file pointter-fptr
    }
    fclose(fptr);                              //after the shifting is done, closing the file
}                                              //end of save and exit function

void loadContactsFromFile(AddressBook *addressBook)       //function definition to load all data from file to RAM so as to perform operations on it
{
    FILE* fptr = fopen("contacts.csv","r");                 //opening the file which has all the previously saved data in read only mode
    fscanf(fptr,"%d\n",&addressBook -> contactCount);       //read the contactcount data from file(1st integer value)
    if(addressBook -> contactCount==0)                      //if the contactcount is found to be 0,then inform user the file is empty
    {
        printf("*WARNING: DataBase is empty\n");             //warning message
        return;                                             //return back to function call
    }
    for( int i=0; i<addressBook -> contactCount;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);         //scaning all contents from file to RAM
    }
    fclose(fptr);                                           //after loading of all data, closing of file is done
}

//PHONE DATA VALIDATION - (OF NEW PERSON)
/*
Conditions:
    str len =10
    all digits
    str should be unique
*/
int validate_phone( char* str , AddressBook *addressBook)         //function definition to validate whether the new phone number satisfies all basic norms
{
    int ret = strlen(str);                              //checking the length of phone string and collecting it in ret variable
    if(ret==10)                                         //if the length of string is 10 then check further conditions!
    {
        if(check_phone_digits(str))                     //if the phone string contains only digits then check remaining condition
        {
            if(check_phone_unique(str,addressBook))     //if the phone string is unique then return 1 to function where it was called.
            {
                return 1;                               //returning 1 to main function
            }
            else                                        //else print the error message - string is not unique
            {
                printf("\n*ERROR: Phone data already exists\n");
            }
        }
        else                                            //else print the error message - string contain characters other than digits
        {
            printf("\n*ERROR: Phone data should have only digits\n");
        }
    }
    else                                                //else print the error message - string length is not equal to 10
    {
        printf("\n*ERROR: Phone data does not contain 10 digits.\n");
    }
    return 0;                                           //if even one condition fails then return 0
}

//SUB FUNCTION OF VALIDATION OF PHONE DETAILS
int check_phone_digits(char* phone)                    //function definition to check whether the phone string contains only digits(0-9) 
{
    int i=0;
    while(phone[i])                                    //loop runs till '\0' of string
    {
        if(phone[i]>=48 && phone[i]<=57)               //checking if character is digit or not
        {
            i++;                                       //if digit, then check next character
        }
        else
        {
            return 0;                                  //else, return 0 to phone_validation function
        }
    }
    if(phone[i]=='\0')                                 //if all characters in the phone string is digits, then return 1
    {
        return 1;                                      //returning 1
    }
}                                                      //end of function

//SUB FUNCTION OF VALIDATION OF PHONE DETAILS
int check_phone_unique(char* str , AddressBook *addressBook)     //function definition to check whether the new phone string is unique
{
    int i=0;
    for( i = 0 ; i < addressBook -> contactCount ; i++ )         //check with all available details
    {
        int ret = strcmp ( addressBook -> contacts[i].phone , str ) ;     //compare two string using strcmp function
        if ( ret == 0 )                                          //if strings are equal then the ret will be 0
        {
            return 0;                                            //if the new string is not unique then return 0 to phone_validation function
        }
    }
    if(i==addressBook -> contactCount)                           //if the string is found to be unique then return 1 phone_validation function
    {
        return 1;                                      //returning 1 
    }
}                                                      //end of function

//NAME DATA VALIDATION - (OF NEW PERSON)
/*int validate_name(char* name)
{
    int ret = check_name_alpha(name); 

}*/
int validate_name(char* str)                          //function definition to check if the name string satisfies all necessary norms! 
{
    int i=0;
    while(str[i])                                     //check the string till '\0'
    {
        if(str[i]==' ' || (str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))         //name string can only contain alphabet characters of uppercase/lowercase/spaces
        {
            i++;                                      //if character satisfies above condition, then increment to next character
        }
        else                                          //else, return 0 to function call
        {
            printf("\n*ERROR: Name should contain only alphabets\n");
            return 0;                                 //returning 0
        }
    }
    if(str[i]=='\0')                                  //if all characters satisfies the condition then return 1 to function call
    {
        return 1;
    }
}                                                     //end of function

//EMAIL DATA VALIDATION - (OF NEW PERSON)
/*
conditons:
    check @ and . prsent
    check lowercase 
    check ch before . and @
    check ' ' before @
    check unique
*/
int validate_email(char* email , AddressBook *addressBook)
{
    if(check_email_basic(email))                      //checking basic lvl - presence of '@' and '.'
    {
        if(check_email_lowercase(email))              //all characetrs are in lower case
        {
            if(check_space_char(email))               //checking other advance norms related to - '@' and '.'
            {
                if(check_email_unique(email,addressBook))     //ckecking the uniqueness of email, if all conditions satisfied 
                {
                    return 1;                         //return 1 to main function call
                }
                else
                {
                    printf("\n*ERROR: Email already present\n");     
                    return 0;                         //else, print error message and return 0 to main function call  
                }
            }
        }
    }
    printf("\n*ERROR: Enter valid email\n");            
    return 0;                                         //if any condition fails then return 0 to main function call
}                                                     //function ends here

//SUB FUNCTION OF VALIDATION OF EMAIL DETAILS
int check_email_basic(char* str)                      //function definition to check whether the new email string conatin '@' and '.' characters
{
    int i=0;
    while(str[i])                                     //loop runs till '\0'
    {
        if(str[i]=='@')                               //first '@' found, then check for '.' character
        {
            int j=i;
            while(str[j])
            {
                if(str[j]=='.')
                {
                    return 1;                         //if both '@' and '.' characters present then return 1 to function call
                }
                j++;
            }
        }
        i++;
    }
    return 0;                                         //else, return 0 to function call
}

//SUB FUNCTION OF VALIDATION OF EMAIL DETAILS
int check_email_lowercase(char *str)                    //function definition to check the uniqueness of email
{
    int i=0;
    while(str[i])                                       //loop runs till '\0'
    {
        if((str[i]>=97 && str[i]<=122) || (str[i]>=48 && str[i]<=57) || str[i]=='@' || str[i]=='.')      //if characters is alphabet(lowercase) / digit / '@' /'.'
        {
            i++;                                        //then, increment i so as to check next character
        }
        else                                            //else
        {
            return 0;                                   //return 0 to validate_email function 
        }
    }
    return 1;                                           //if all characters satisfies the above if condition then return 1 to validate_email function call 
}

//SUB FUNCTION OF VALIDATION OF EMAIL DETAILS
int check_space_char(char* str)                         //function definition to check whether email string contain spaces/@and . next to each other
{
    int i=0;
    while(str[i])
    {
        if(str[i]=='@' && i==0)                         //error if : @gamil.com   X (return 0)
        {
            return 0;
        }
        else if(str[i]=='@')                            //error if : abc@.com   X (return 0)
        {
            if(((str[i-1]>=97 && str[i-1]<=122) || (str[i-1]>=48 && str[i-1]<=57)) && (str[i+1]>=97 && str[i+1]<=122))
            {
                i++;
            }
            else
            {
                return 0;
            }
        }
        else if(str[i] == ' ')                          //error if : abc 123@yahoo.com     X (return 0)
        {
            return 0;
        }
        else if(str[i]== '.')                           //error if : abc123@gmail.     X (return 0)
        {
            if(str[i+1]=='\0')
            {
                return 0;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return 1;                                          //else if all conditions are satisfied then return 1 to validate_email function call
}                                                      //function ends here

//SUB FUNCTION OF VALIDATION OF EMAIL DETAILS
int check_email_unique(char* str, AddressBook * addressBook)        //function definition to check the uniqueness of email
{
    int i=0;
    for( i = 0 ; i < addressBook -> contactCount ; i++ )            //check for existing all email
    {
        int ret = strcmp ( addressBook -> contacts[i].email , str ) ;   //compare two strings using strcmp function
        if ( ret == 0 )                                             //if two strings are equal their is no uniqueness
        {
            return 0;                                               //then return 0 to validate_email function
        }
    }
    if(i==addressBook -> contactCount)                              //else, return 1 to validate_email function
    {
        return 1;                                                  
    }   
}                                                                   //end of function