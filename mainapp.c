#include"terminalheader.h"
#include"cardinfo.h"
unsigned char terminal(struct carddata *c, struct terminal_data *t) {
    printf("\n\t\tPlease enter terminal data\n\n");
    printf("Please Enter the transaction Amount:\n");
    scanf("%lf", &t->transAmount);
    if (t->transAmount > t->maxTransAmount) {
        printf("The Transaction is not approved \n");
        printf("Error: Transaction Amount > Maximum Transaction Amount\n\n");
    }
    else
    {
         printf("Please Enter transaction Date:\t\t (DD/MM/YYYY)\n");
       scanf ("%s" , t->transactionDate);
        int check = dateofcardcheck(c ->  expirationdate , t->transactionDate) ;
        if (check == 0)
        {
            printf("The Transaction is not approved \n");
            printf("The card is expired \n\n ");
            return 0 ;
        }
        else
        {
            return 1 ;
        }
    }
    }

int dateofcardcheck(unsigned char expirationdate[10] , unsigned char transactionDate[11])
{
    unsigned char *tmptr = &transactionDate[4] ;
    unsigned char *typtr = &transactionDate[7] ;
    unsigned char *cmptr = &expirationdate[1] ;
    unsigned char *cyptr = &expirationdate[4] ;
    int mint = atoi(tmptr) ;
    int yint = atoi(typtr) ;
    int monc = atoi(cmptr) ;
    int yonc = atoi(cyptr) ;
    if (yint > yonc)
    {
        return 0 ;
    }
    else if (yint == yonc && monc < mint)
    {
        return 0 ;
    }
    else return 1 ;
}
 void dataoncard (struct carddata *owner) {
    printf("\tPlease enter card data\n\n\n\n");
    printf("Please enter card holder name:\n\n");
    scanf("%[^\n]%*c" , owner ->ownername) ;
    printf("Please enter your card num [PAN] : \n\n") ;
    scanf("%s" , owner ->cardPAN ) ;
    printf("Please enter the expiration date \t\t (MM/YY) : \n\n") ;
    scanf("%s" , owner ->expirationdate) ;
 }

int main ()
{
printf("\t\tWelcome\n\n");
struct carddata c = {"", "", ""};
struct terminal_data t = {0.0, 6000.0, ""};
struct carddata *cptr = &c;
struct terminal_data *tptr = &t;
dataoncard(cptr) ;
int res = terminal(cptr , tptr) ;
}
