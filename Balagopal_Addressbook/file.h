#ifndef FILE_H
#define FILE_H

#include "contact.h"                //including all contents of contact.h file

void saveContactsToFile(AddressBook *addressBook);            //function prototype to save the modified info/data to file
void loadContactsFromFile(AddressBook *addressBook);          //function prototype to load data/info from file to RAM


//function prototypes - validation of phone 
int validate_phone( char* str , AddressBook *addressBook);         
int check_phone_digits(char* phone);
int check_phone_unique(char* str , AddressBook *addressBook);

//function prototype - validation of name
int validate_name(char* str);

//function prototypes - validation of email
int validate_email(char* email , AddressBook *addressBook);
int check_email_basic(char* str);
int check_email_lowercase(char *str);
int check_space_char(char* str);
int check_email_unique(char* str, AddressBook * addressBook);


#endif
