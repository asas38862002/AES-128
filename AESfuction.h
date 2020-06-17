
 #ifndef AESfuction_H
 #define AESfuction_H


void shiftrow(unsigned char state[][4]); 

void mixcolumn(unsigned char state[][4]);

void keyExpansion(unsigned char roundkey[4][44]);

void creat_sbox();

void subbytes(unsigned char state[][4]);
  
 #endif /* AESfuction */

