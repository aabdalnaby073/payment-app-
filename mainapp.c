#include"terminalheader.h"
#include"cardinfo.h"
#include"serverheader.h"
//database for our program to act as a bank server
struct accountbalance dataBase[] =
        {
                {"123456789", 1000.00},
                {"234567891",6000.00},
                {"567891234",340.25},
                {"456789123",1600.12},
                {"258649173",540.00},
                {"654823719",200.00},
                {"971362485",0.0},
                {"793148625",123.00 },
                {"123123456", 1033.12},
                {"456789321", 0.55},
        };
//talking the card data
void dataoncard (struct carddata *owner) {
    printf("\tPlease enter card data\n\n\n\n");
    printf("Please enter card holder name:\n\n");
    scanf("%[^\n]%*c" , owner ->ownername) ;
    printf("Please enter your card num [PAN] : \n\n") ;
    scanf("%s" , owner ->cardPAN ) ;
    printf("Please enter the expiration date \t\t (MM/YY) : \n\n") ;
    scanf("%s" , owner ->expirationdate) ;
 }
 //preform the process and make sure that card is not expired
 //talking the amount of money in this transaction and compare it to the maximum
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
// function check the card expiration
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
// searching for the account of the user in server and preform the process
int  server (struct accountbalance *database , struct carddata *card , struct terminal_data *ter)
{
    int found = SERCHINGFORCARD(database , 8 , card ->cardPAN ) ;
    if (found == -1)
    {
       printf("Account did not found \n") ;
       return 0 ;
    }
    else
    {
        if (database[found].cardbalance >= ter->transAmount)
        {
            printf ("1 for purchase \n");
            printf( "2 for refund \n ") ;
             int ans ;
            scanf("%d" ,&ans) ;
            if (ans ==1) {
            printf("processed successfully\n" ) ;
           database[found].cardbalance = (database[found].cardbalance) - (ter ->transAmount) ;
            printf("Your account balance is now %lf" , &database[found].cardbalance) ;
            }
            else if (ans == 2)
            {
                  printf("processed successfully\n" ) ;
           database[found].cardbalance = (database[found].cardbalance) + (ter ->transAmount) ;
            printf("Your account balance is now %lf" , &database[found].cardbalance) ;
            }

        }
    }
}
int SERCHINGFORCARD (struct accountbalance *database , int size , unsigned char *cardPAN[20])
{
  for (int i = 0 ; i < size ; i++)
  {
      if (strcmp((char *) database[i].cardnumber ,(char *) cardPAN)== 0)
      {
          return i ;
      }
      else
        return -1 ;
  }
}
int main ()
{
printf("\t\tWelcome\n\n");
struct carddata c = {"", "", ""};
struct terminal_data t = {0.0, 10000.0,0.0, ""};
struct carddata *cptr = &c;
struct terminal_data *tptr = &t;
dataoncard(cptr) ;
int res = terminal(cptr , tptr) ;
server(dataBase , cptr , tptr) ;
}
