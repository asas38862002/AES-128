
 #ifndef AESfuction_H
 #define AESfuction_H


void shiftrow(unsigned char state[][4]); 

void mixcolumn(unsigned char state[][4]);

void keyExpansion(unsigned char roundkey[4][44]);

void creat_sbox();

void subbytes(unsigned char state[][4]);

void Inv_subbytes(unsigned char state[][4]);

void displaykeyExpansion(unsigned char roundkey[4][44]);

void addroundkey(unsigned char state[][4],unsigned char roundkey[4][44],int round);

void displaystate(unsigned char state[][4]);

void creat_Inv_sbox();

void Inv_shiftrow(unsigned char state[][4]);

void Inv_mixcolumn(unsigned char state[][4]);
  
 #endif /* AESfuction */

