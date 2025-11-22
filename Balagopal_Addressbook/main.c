//including all necessary libraries and files
#include <stdio.h> 
#include "file.h"

int main() 
{                                  //start of main
    int choice;                    //choice declared to read input from user , to determine what operation user needs to perofrm  
    AddressBook addressBook;       //creating structure varibale 
    initialize(&addressBook);      // Initialize the address book

    printf("\n********************* WELCOME TO ADDRESSBOOK *********************\n");
    do {
        printf("\nADDRESS BOOK MAIN MENU:\n");                  // menu prompt, user can decide any one based on his required operation
        printf("1. CREATE CONTACTS\n");
        printf("2. SEARCH CONTACT\n");
        printf("3. EDIT CONTACT\n");
        printf("4. DELETE CONTACT\n");
        printf("5. LIST ALL CONTACTS\n");
    	printf("6. SAVE AND EXIT SCONTACTS\n");		
        printf("7. EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);                     //reading choice from user 
        
        switch (choice)                           //if choice is between 1-7, enter 
        {
            case 1:
                createContact(&addressBook);      //function call to create contact
                break;
            case 2:
                searchContact(&addressBook);      //function call to search contact
                break;
            case 3:
                editContact(&addressBook);        //function call to edit contact
                break;
            case 4:
                deleteContact(&addressBook);      //function call to delete contact 
                break;
            case 5:          
                listContacts(&addressBook);       //function call to list contacts
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook); //function call to save new updated data and exit
                printf("\n********************* THANK YOU, VISIT AGAIN *********************\n");
                return 0;
            case 7:
                printf("\n********************* THANK YOU, VISIT AGAIN *********************\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 7);                       //loop runs till user opts choice-7(Exit)
    return 0;
}                                                //end of main function