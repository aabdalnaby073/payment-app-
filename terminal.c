#include"cardinfo.h"
#include"terminalheader.h"
int istransdatevalid (unsigned char td[11] , unsigned char cd[10])
{
    unsigned char *tmptr = &td[4] ;
    unsigned char *typtr = &td[7] ;
    unsigned char *cmptr = &cd[1] ;
    unsigned char *cyptr = &cd[4] ;
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
