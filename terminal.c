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
        printf("the card is expired\n") ;
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

