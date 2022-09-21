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
int  server (struct accountinfo *database , struct carddata *card , struct terminal_data *ter)
{
        int found = SERCHINGFORCARD(database , 8 , card ->cardPAN) ;
        if (found == -1)
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
