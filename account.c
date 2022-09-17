#include"cardinfo.h"
#include"terminalheader.h"
#include"serverheader.h"
unsigned char server (struct accountbalance *database , struct carddata *card , struct terminal_data *ter)
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
            printf("processed successfully\n" ) ;
            database[found].cardbalance - ter ->transAmount ;
            printf("Your account balance is now %lf" , &database[found].cardbalance) ;
            return 1 ;
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
