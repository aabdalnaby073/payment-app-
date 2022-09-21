#include "cardinfo.h"
// here we develop function to take a name on card from user and validate it
void getCardHolderName(struct carddata *owner)
 {
   printf("Please enter card holder name:\n\n");
   unsigned char name[30] ;
    scanf("%[^\n]%*c" , name) ;
    int strlenght = strlen(name) ;
    if (strlenght > 24 || strlenght == 0 || strlenght<20){
        printf("WRONG_Name\n") ;
    }
    else {
        printf("OK\n") ;
          for (int i = 0 ; i < strlenght ; i++)
          {
              owner->ownername[i] = name[i] ;
          }
    }
 }
  //accepted test case
 //ahmed mohamed abdalnaby
 // wrong test case ahmed
//***************************************************************************************************************************************************************************
 // here we develop function to take a name on card from user and validate it

 void getCardExpiryDate(struct carddata *owner)
 {
   printf("Please enter expiration date as MM/YY:\n\n");
   unsigned char date[8] ;
    scanf("%s" , date) ;
    int strlenght = strlen(date) ;
    if (strlenght !=5){
        printf("WRONG_date\n") ;
    }
    else {
        printf("OK") ;
          for (int i = 0 ; i < strlenght ; i++)
          {
              owner->expirationdate[i] = date[i] ;
              printf("\n") ;
          }
    }
 }
 //accepted test case
 //02/22
 // wrong test case
 // 2/22
//***********************************************************************************************************************************************************************************
 void getCardPAN(struct carddata *owner)
 {
   printf("Please enter PAN:\n\n");
   unsigned char PAN[20] ;
    scanf("%s" , PAN) ;
    int strlenght = strlen(PAN) ;
    if (strlenght > 19 || strlenght == 0 || strlenght <16){
        printf("WRONG_PAN\n") ;
    }
    else {
        printf("OK") ;
          for (int i = 0 ; i < strlenght ; i++)
          {
              owner->cardPAN[i] = PAN[i] ;
              printf("\n") ;
          }
    }
 }
 //accepted test case
 //12345678911223344
 //wrong test case
 //12345
