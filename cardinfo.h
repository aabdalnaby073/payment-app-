
struct carddata {
unsigned char ownername[30] ;
unsigned char cardPAN[20] ;
unsigned char expirationdate[10] ;
};
 extern void dataoncard (struct carddata *card);

