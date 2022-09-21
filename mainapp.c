#include"terminalheader.h"
#include"cardinfo.h"
#include"serverheader.h"
//database for our program to act as a bank server
struct accountinfo dataBase[] =
        {
                {"12345678912345678", 1000.00},
                {"234567891028745340",6000.00},
                {"567891234458987976",340.25},
                {"45678912343856556",1600.12},
                {"25864917347344643",540.00},
                {"65482371912431213",200.00},
                {"971362485847632113",0.0},
                {"793148625725131311",123.00 },
                {"123123456000000000", 1033.12},
                {"45678932133333333", 0.55},
};
// here we develop function to take a name on card from user and validate it
void getCardHolderName(struct carddata *owner)
 {
   printf("Please enter card holder name:\n\n");
   unsigned char name[30] ;
    scanf("%[^\n]%*c" , name) ;
    int strlenght = strlen(name) ;
    if (strlenght > 24 || strlenght == 0 || strlenght<20){
        printf("WRONG_Name\n close program and try again \n") ;
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
        printf("WRONG_date\n close program and try again \n") ;
       return 0 ;
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
        printf("WRONG_PAN\n close program and try again \n") ;
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
// mother function to take all transaction data an validate it
//all test cases were illustrated in the videos
    int gettransactiondata(struct terminal_data *terminal , struct carddata *card)
    {
    printf("Please Enter transaction Date:\t\t (DD/MM/YYYY)\n");
      unsigned char date[12] ;
    scanf("%s" , date) ;
    int strlenght = strlen(date) ;
    if (strlenght != 10)
    {
    printf("WRONG_date\n") ;
    return 0 ;
    }
    else
    {
        printf("OK") ;
          for (int i = 0 ; i < strlenght ; i++)
          {
              terminal->transactionDate[i] = date[i] ;
              printf("\n") ;
          }
    }
    int ans = dateofcardcheck(card->expirationdate, terminal ->transactionDate) ;
    if (ans == 0)
    {
        printf("the card is expired\n restart the program \n") ;
        return 0 ;
    }
    else
    {
        printf("please enter max transamount \n") ;
        scanf("%lf", &terminal ->maxTransAmount);
        if (terminal->maxTransAmount <0)
        {
            printf("wrong \n" ) ;
            return 0 ;
        }
        else {
          printf("Please Enter the transaction Amount:\n");
        scanf("%lf", &terminal ->transAmount);
        if (terminal->transAmount < 0)
        {
            printf("wrong transaction \n") ;
            return 0 ;
        }
       else
       {

            if (terminal->transAmount > terminal->maxTransAmount) {
        printf("The Transaction is not approved \n");
        printf("Error: Transaction Amount > Maximum Transaction Amount\n\n");
        return 0 ;
       }
    }
    }
    }
    }
int dateofcardcheck(unsigned char expirationdate[10] , unsigned char transactionDate[11])
{
    unsigned char *tmptr = &transactionDate[4] ;
    unsigned char *typtr = &transactionDate[9] ;
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
    else
    return 1 ;
}
int  server (struct accountinfo *database , struct carddata *card , struct terminal_data *ter)
{
        int found = SERCHINGFORCARD(database , 8 , card ->cardPAN) ;
        if (found == -1 )
        {
          printf("DECLINED_STOLEN_CARD\n") ;
            return 0 ;
        }
        else
        {

          if (database[found].balance >= ter->transAmount)
        {
           printf("APPROVED\n") ;
           database[found].balance = database[found].balance - ter->transAmount ;
           printf("Saved \n your balance now is %f" ,database[found].balance) ;
        }
        else
        {
            printf("LOW_BALANCE") ;
        }

}
}
int SERCHINGFORCARD (struct accountinfo *database , int size , unsigned char *cardPAN[20])
{
  for (int i = 0 ; i < size ; i++)
  {
      if (strcmp((char *) database[i].primaryAccountNumber,(char *) cardPAN)== 0)
      {
          return i ;
      }
      else
        return -1 ;
  }
}
int main()
{
    struct carddata c = {"", "", ""};
    struct terminal_data t = {0.0, 6000.0, ""};
    struct terminal_data *tptr = &t;
    struct carddata *cptr = &c;
    getCardHolderName(cptr) ;
    getCardExpiryDate(cptr) ;
    getCardPAN(cptr) ;
    gettransactiondata(tptr ,cptr) ;
    server(dataBase , cptr , tptr) ;
}

