#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include"cardinfo.h"
 void dataoncard (struct carddata *owner) {
     printf("Please enter card data\n\n\n\n");
    printf("Please enter card holder name:\n\n");
    scanf("%[^\n]%*c" , owner ->ownername) ;
    printf("Please enter your card num [PAN] : \n\n") ;
    scanf("%s" , owner ->cardPAN ) ;
    printf("Please enter the expiration date \t\t (MM/YY) : \n\n") ;
    scanf("%s" , owner ->expirationdate) ;

 }
 int main()
{
printf("\t\tWelcome\n\n");
struct carddata c = {"", "", ""};
struct carddata *cptr = &c;
dataoncard(cptr) ;
}