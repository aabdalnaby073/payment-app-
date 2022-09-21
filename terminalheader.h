#include"cardinfo.h"
struct terminal_data
{
   double transAmount;
    double maxTransAmount;
    unsigned char transactionDate[11];
};
typedef enum EN_terminalError_t
{
OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;
