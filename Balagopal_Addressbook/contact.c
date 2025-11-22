//including all necessary libraries and files
#include<stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook)            //function definition to list all data/info in the file/RAM
{
    if(addressBook -> contactCount == 0)
    {
        printf("*FILE Empty*\nCreate New Conatacts\n");
        return ;
    }
    int sortCriteria;                                  //sortcriteriia variable is used to store the choice of user based upon the menu 
list_again:    printf("\nChoose a method to display\n");          //promt for user - menu
    printf("1.Sort By Name\n");
    printf("2.Sort By Phone\n");
    printf("3.Sort By Email\n");
    printf("4.Normal Display\n");
    printf("5.Return To Main Menu\n");
    printf("\nEnter your choice: ");                   //promt for user to enter the choice
    scanf("%d", &sortCriteria);                        //read choice from the user
    switch(sortCriteria)                               //switch case starts here
    {
        case 1:                                        //case 1: Sorting all names in ascending order
        {
            for (int i = 0 ; i < addressBook -> contactCount-1 ; i++)
            {
                for (int j = 0 ; j < addressBook -> contactCount-i-1 ; j++)
                {
                    int ret = strcmp(addressBook -> contacts[j].name , addressBook -> contacts[j+1].name);     //comparing the two two strings, present and next string
                    if(ret>0)                   //if ret>0, that is if next string is greator than present string then shift 
                    {                           //shifting logic
                        char str[50];
                        strcpy(str,addressBook -> contacts[j].name);
                        strcpy(addressBook -> contacts[j].name, addressBook -> contacts[j+1].name);
                        strcpy(addressBook -> contacts[j+1].name,str);

                        strcpy(str,addressBook -> contacts[j].phone);
                        strcpy(addressBook -> contacts[j].phone, addressBook -> contacts[j+1].phone);
                        strcpy(addressBook -> contacts[j+1].phone,str);

                        strcpy(str,addressBook -> contacts[j].email);
                        strcpy(addressBook -> contacts[j].email, addressBook -> contacts[j+1].email);
                        strcpy(addressBook -> contacts[j+1].email,str);
                    }
                }      //end of inner for loop
            }       //end of outer for loop
            printf("\n%-10s%-20s%-20s%-20s\n","Index","Name","Phone","Email");           //printing the sequence of data
            for (int i = 0; i < addressBook -> contactCount; i++)
            {
                printf("%-10d%-20s%-20s%-20s\n", i,addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
            }
        }            
        break;           //end of case-1

        case 2:                          //case 2 - sorting phone info in ascending order 
        {
            for (size_t i = 0; i < addressBook -> contactCount-1; i++)
            {
                for (size_t j = 0; j < addressBook -> contactCount-i-1; j++)
                {
                    int ret = strcmp(addressBook -> contacts[j].phone,addressBook -> contacts[j+1].phone);        //comparing the two two strings, present and next string
                    if(ret>0)            //if ret>0, that is if next string is greator than present string then shift
                    {
                        char str2[50];
                        strcpy(str2,addressBook -> contacts[j].phone);
                        strcpy(addressBook -> contacts[j].phone, addressBook -> contacts[j+1].phone);
                        strcpy(addressBook -> contacts[j+1].phone,str2);

                        strcpy(str2,addressBook -> contacts[j].name);
                        strcpy(addressBook -> contacts[j].name, addressBook -> contacts[j+1].name);
                        strcpy(addressBook -> contacts[j+1].name,str2);

                        strcpy(str2,addressBook -> contacts[j].email);
                        strcpy(addressBook -> contacts[j].email, addressBook -> contacts[j+1].email);
                        strcpy(addressBook -> contacts[j+1].email,str2);
                    }
                }         //end of inner for loop
            }         //end of outer for loop
            printf("\n%-10s%-20s%-20s%-20s\n","Index","Name","Phone","Email");           //printing the sequence of data
            for (int i = 0; i < addressBook -> contactCount; i++)
            {
                printf("%-10d%-20s%-20s%-20s\n", i,addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
            }
        }
        break;           //end of case-2

        case 3:                          //case 3 - sorting emails info in ascending order 
        {
            for (size_t i = 0; i < addressBook -> contactCount-1; i++)
            {
                for (size_t j = 0 ; j < addressBook -> contactCount-i-1 ; j++)
                {
                    int ret = strcmp(addressBook -> contacts[j].email,addressBook -> contacts[j+1].email);          //comparing the two two strings, present and next string
                    if(ret>0)                       //if ret>0, that is if next string is greator than present string then shift
                    {
                        char str3[50];
                        strcpy(str3,addressBook -> contacts[j].email);
                        strcpy(addressBook -> contacts[j].email, addressBook -> contacts[j+1].email);
                        strcpy(addressBook -> contacts[j+1].email,str3);

                        strcpy(str3,addressBook -> contacts[j].name);
                        strcpy(addressBook -> contacts[j].name, addressBook -> contacts[j+1].name);
                        strcpy(addressBook -> contacts[j+1].name,str3);

                        strcpy(str3,addressBook -> contacts[j].phone);
                        strcpy(addressBook -> contacts[j].phone, addressBook -> contacts[j+1].phone);
                        strcpy(addressBook -> contacts[j+1].phone,str3);
                    }
                }             //end of inner for loop
            }             //end of outer for loop
            printf("\n%-10s%-20s%-20s%-20s\n","Index","Name","Phone","Email");           //printing the sequence of data
            for (int i = 0; i < addressBook -> contactCount; i++)
            {
                printf("%-10d%-20s%-20s%-20s\n", i,addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
            }
        }                //end of case-3
        break;

        case 4:             //case 4- print in random unsorted order or print in previously sorted order
        {
            printf("\n%-10s%-20s%-20s%-20s\n","Index","Name","Phone","Email");           //printing the sequence of data
            for (int i = 0; i < addressBook -> contactCount; i++)
            {
                printf("%-10d%-20s%-20s%-20s\n", i,addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
            }
        }               //end of case-4
        break;

        case 5:
                return;

        default:            //if user entered choice other than 1-4, then display error message
        {
            printf("Enter Valid Option\n");           //error message - prompting the user to re=enter the option
            goto list_again;
        }
    }                       //end of switch
}                      //end of listContacts function


void initialize(AddressBook *addressBook)         //function definition of initialize function where we load the data from file to RAM before displaying main menu of addressbook
{
    addressBook->contactCount = 0;                //initial no. of conatacts are initialized as 0
    //populateAddressBook(addressBook);
    loadContactsFromFile(addressBook);            // Loading contacts from file during initialization (After files)
}                                                 //end of initialize function


void saveAndExit(AddressBook *addressBook)        //function definition to save the modified data to the file and exit the program
{
    saveContactsToFile(addressBook); //Save contacts to file
}

//CODE TO CREATE NEW CONTACT IN ADDRESSBOOK 
void createContact(AddressBook *addressBook)      //function definition starts
{
    char newName[50];                             //temporary variable to store new name
    char newPhone[20];                            //temporary variable to store new phone
    char newEmail[50];                            //temporary variable to store new email
create_again:    printf("\nEnter the New Name : ");
    scanf(" %[^\n]",newName);                     //reading new name form user
    printf("Enter the New Phone Detail : ");
    scanf(" %[^\n]",newPhone);                    //reading new phone data from user
    printf("Enter the New Email : ");
    scanf(" %[^\n]",newEmail);                    //reading new email from user

    int ret = validate_name( newName );           //validating new name and collecting the result using ret
    int ret2 = validate_phone( newPhone ,addressBook);        //validating new phone data and collecting the result using ret2
    int ret3 = validate_email( newEmail, addressBook );       //validating new email and collecting the result using ret3                           

    if( ret==0 || ret2==0 || ret3==0)             //if any one validation fails then display the error message 
    {
        printf("\n***WARNING: Contact Information Incomplete***\n");
        printf("Enter valid details to create contact in Addressbook\n");       //asking user to reenter the data 
        goto create_again;                       //goto the loaction where create_again is used
    }
    if(ret && ret2 && ret3)                      //if all the validation is successfull the create the contact profile 
    {
        strcpy(addressBook->contacts[addressBook -> contactCount].name , newName);
        strcpy(addressBook->contacts[addressBook -> contactCount].phone , newPhone);
        strcpy(addressBook->contacts[addressBook -> contactCount].email , newEmail);
        addressBook -> contactCount++;           //after each succcessful creation increment the contactcount
        printf("***Contact Creation Successful***\n");
    }
}                    //end of createContact function

//CODE TO SEARCH CONTACT FROM EXISTING DATA
int searchContact(AddressBook *addressBook)      //function definition starts here
{
    int searchChoice;                            //searchChoice decleared to store the user choice
search_again:    printf("\nChoose any one option to search by\n");        //promt menu for the user to search by
    printf("1.Search By Name\n");
    printf("2.Search By Phone\n");
    printf("3.Search By Email\n");
    printf("4.Return To Main Menu\n");
    printf("\nEnter your choice : ");
    __fpurge(stdin);
    scanf("%d",&searchChoice);                   //read the user's choice

    int flag = 0;                                //flag decleared to check whether the search data is found or not
    switch(searchChoice)                         //switch case begings
    {
        case 1: while(!flag)                     //case-1 search by name
        {
            int i;
            char searchName[50] ;                //temp vatable to store user entered data 
            printf("\nEnter the name to search : ") ;
            __fpurge(stdin);                     //clearing the stdin buffer
            scanf("%[^\n]",searchName) ;         //reading data from user and store in temp variable

            for(i = 0 ; i < addressBook -> contactCount ; i++ )      //loop to check all names till the last
            {
                int ret = strcmp (addressBook -> contacts[i].name , searchName ) ;      //comparing two strings of existing and new user entered data
                if(ret==0)                       //if same, then contact found, so display the contacts full details
                {
                    flag=1;                      //set flag to 1 if contact found
                    printf("\n%-20s%-20s%-20s%-20s\n","Index","Name","Phone","Email");
                    printf("%-20d%-20s%-20s%-20s\n", i,addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
                }
            }
            if(flag==0)                          //if the contact not found then, flag is zero
            {
                printf("**No data found under this name**\nEnter Valid Name\n");     //display the error message
            }
            else
            {
                return flag;                     //else return 1 to function call
            }
        }
        break;

        case 2: while(!flag)                     //case-2 search by phone
        {
            int i;
            char searchPhone[20];                //temp vatable to store user entered data 
            printf("\nEnter your phone no : ");
            __fpurge(stdin);                     //clearing the stdin buffer
            scanf("%[^\n]",searchPhone);         //reading data from user and store in temp variable
            
            for( i = 0 ; i < addressBook -> contactCount ; i++ )        //loop to check all phone data till the last
            {
                int ret = strcmp ( addressBook -> contacts[i].phone , searchPhone ) ;       //comparing two strings of existing and new user entered data
                if ( ret == 0 )                  //if same, then contact found, so display the contacts full details
                {
                    flag=1;                      //set flag to 1 if contact found
                    printf("\n%-20s%-20s%-20s%-20s\n","Index","Name","Phone","Email");
                    printf("%-20d%-20s%-20s%-20s\n", i, addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
                    //break ;
                }
            }
            if( flag == 0 )                      //if the contact not found then, flag is zero
            {
                printf("**No data found under this Phone**\nEnter Valid Phone Data\n");         //displayerror message
            }
            else
            {
                return flag;                     //else return 1 to function call
            }
        }
        break;

        case 3: while(!flag)                     //case-3 search by email
        {
            int i;
            
            char searchEmail[50];                //temp vatable to store user entered data 
            printf("\nEnter your email : ");
            __fpurge(stdin);                     //clearing the stdin buffer
            scanf(" %[^\n]", searchEmail) ;      //reading data from user and store in temp variable

            for( i = 0 ; i < addressBook -> contactCount ; i++ )         //loop to check all eamil till the last
            {
                int ret = strcmp ( addressBook -> contacts[i].email , searchEmail ) ;             //comparing two strings of existing and new user entered data
                if( ret == 0 )
                {
                    flag=1;                      //set flag to 1 if contact found
                    printf("\n%-20s%-20s%-20s%-20s\n","Index","Name","Phone","Email");
                    printf("%-20d%-20s%-20s%-20s\n", i, addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
                    //break ;
                }
            }
            if( flag == 0 )                      //if the contact not found then, flag is zero
            {
                printf("**No data found under this email**\nEnter Valid Email\n");          //display error message
            }
            else
            {
                return flag;                     //else return 1 to function call
            }
        }
        break;

        case 4:                       //case-4 Return to main menu
                return 0;             //return to function call by return 0

        default:                      //if user enters option beyond 1-4
        {
            printf("Enter a valid option\n");       //error correction promt
            goto search_again;        //start the function from start
        }
    }
}              //end of searchContact function

//CODE TO EDIT CONTACT FROM EXISTING DATA
void editContact(AddressBook *addressBook)       //function definition starts here 
{
    int ret = searchContact(addressBook);        //function call to check whether the contact exists or not
    if(ret == 0 )                                //if contacts not found then return to main menue 
    {
        return;
    }
    int index;                                   //index decleared to select one contact out of multiple contacts that share same credentials
    printf("\nEnter the index u want to edit: ");
    scanf("%d",&index);                          //reading the index to edit 
    int choice;
edit_again:    printf("\nChoose any one option to edit\n");      //user promt menue
    printf("1.Edit Name\n");
    printf("2.Edit Phone\n");
    printf("3.Edit Email\n");
    printf("4.Return to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);                          //reading data from user and storing in choice
    char new[50];                                 //temporary string creation to store old new data that replaces the exitsing one
    int flag = 0;                                 //decleared flag to 0 - used to looping purpose

    switch(choice)                                //switch case starts here
    {
        case 1:while(!flag)                       //case 1- edit the name(loop runs till edit with valid name-determined by flag)
        {
            printf("\nEnter the new name: ");
            __fpurge(stdin);
            scanf("%[^\n]",new);                  //reading new name from user
            int ret = validate_name( new  );      //validating the new name
            if(ret==1)                            //if new name is valid, then store it
            {
                flag = 1;                         //setting flag to 1
                strcpy(addressBook->contacts[index].name , new);    //editing the old with new name
                printf("*Contact Name Editied successfully*\n");    
            }
            else
            {
                printf("Re-enter a valid name\n");   //if new name is not valid, then display error message 
            }
        }
        break;

        case 2:while(!flag)                       //case 1- edit the phone(loop runs till edit with valid phone-determined by flag)
        {
            printf("\nEnter the new Phone: ");
            __fpurge(stdin);
            scanf("%[^\n]",new);                 //reading new phone from user
            int ret = validate_phone( new , addressBook );   //validating the new phone
            if(ret==1)                           //if new phone is valid, then store it
            {
                flag =1;                         //setting flag to 1
                strcpy(addressBook->contacts[index].phone , new);      //editing the old with new phone
                printf("*Contact Phone Editied successfully*\n");
            }
            else
            {
                printf("Re-enter a valid Phone\n");       //if new phone is not valid, then display error message 
            }
        }
        break;

        case 3:while(!flag)                 //case 3- edit the email(loop runs till edit with valid email-determined by flag)
        {
            printf("\nEnter the new email: ");
            __fpurge(stdin);
            scanf("%[^\n]",new);            //reading new email from user
            int ret = validate_email( new , addressBook );     //validating the new email
            if(ret==1)                      //if new email is valid, then store it
            {
                flag ==1;                   //setting flag to 1
                strcpy(addressBook->contacts[index].email , new);
                printf("*Contact Email Editied successfully*\n");          //editing the old with new email
            }
            else
            {
                printf("Re-enter a valid email\n");     //if new email is not valid, then display error message 
            }
        }
        break;

        case 4:           //case 1- return to main menue
        {
            return ;
        }

        default:         //if user enters invalid choice that is, beyond 1-4
        {
            printf("\n***Invalid choice***\nEnter a valid option\n");
            goto edit_again;             //goto start of menue's again
        }
    }
}               //end of editContact function

//CODE TO DELETE THE EXISTING CONTACTS
void deleteContact(AddressBook *addressBook)           //function definition starts here
{
    int ret = searchContact(addressBook);              //calling searchContact to check whether the contact exists or not
    if(ret == 0)                                       //if contact does not exists then return to main menue
    {
        return;
    }
    int index;                          //index variable used to store the choice of user
    printf("\nEnter the index to delete: ");       
    scanf("%d",&index);                 //read the index which the user intends to delete
    for(int i=index;i<addressBook->contactCount;i++)          //deleating is done by shifting the contact structure one by one
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];  //shifting done here
    }
    addressBook->contactCount--;        //once deleated, decrement contactCount by 1
    printf("*Contact Deleated Sucessfully*\n"); 
}                 //end of deleteContacts function