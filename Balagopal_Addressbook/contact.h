/*
DOCUMENTATION:
NAME : BALAGOPAL R NAYAK
START DATE : 16-09-2025
END DATE :  23-09-2025
DESCRIPTION : Program to keeps track of names and telephone/mobile numbers and e-mail addresses. It is a console based application which uses standard I/O for adding and deleting contact names, phone numbers and e-mail addresses, searching names and associated numbers and email addresses, updating numbers and email addresses, and deleting contacts.
*/

#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100             // defining maximim space to 100 set of contacts

#include <stdio.h>   

typedef struct                       // Contact structure definition, here we define what information we can store     
{    
    char name[50];                   // to store name
    char phone[20];                  // to store phone 
    char email[50];                  // to store email
} Contact;                           //structure can be accessed by 'contact' 

typedef struct                       //AddressBook structure definition, here be store upto 100 set of data of contact struct type  
{
    Contact contacts[100];           //creating a array of 100 elements of contact struct type and can be accessed using 'contacts' name
    int contactCount;
} AddressBook;                       //name of structure - AddressBook

void createContact(AddressBook *addressBook);          //function prototype to create a new contact 
int searchContact(AddressBook *addressBook);           //function prototype to search conatct from data base
void editContact(AddressBook *addressBook);            //function prototype to edit an existing data from data base
void deleteContact(AddressBook *addressBook);          //function prototype to delete existing data from data base
void listContacts(AddressBook *addressBook);           //funcyion prototype to list all the data/info of addressbook
void initialize(AddressBook *addressBook);             //initialize the adressbook previous information through loading from a file
void saveContactsToFile(AddressBook *AddressBook);     //function prototype to save the modified data/info to file and then exit

#endif