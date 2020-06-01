#include<stdio.h>
#include "GFmath.h"
#include <stdbool.h> 

int degreed[9]={0x100,0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1};

int add(int a,int b)
{
	int out = 0x00 ;
		
	out = a ^ b;	
	
	return out ;
}

int devide(int a,int b,int  * q)
{
	//int  q = 0 ;
	int Hideg  = 1;
	int Lodeg  = 0 ;
	int disdeg = 0 ;
	int  r            = 0 ;
	int Temp  = 0  ;
	//printf("a:  %x  b: %x\n",a,b);

	//for(int j =0;j<5;j++)
	while (Hideg>=Lodeg && a!=1)
	{			
		for(int i =0;i<9;i++)
		{ 
			Temp = (a & degreed[i]) >> (8-i)  ;
			//printf("Temp: %x\n",Temp);

			if(Temp == 1 )
			{
				Hideg = (8-i) ;
				break ;
			}
		}	
		Temp  = 0 ;
		//===============================sertch a high degreen=================================
		for(int i =0;i<9;i++)
		{
			Temp = (b & degreed[i]) >> (8-i)  ;
			if(Temp == 1 )
			{
				Lodeg = (8-i) ;
				break; 
			}
		}
		Temp = 0 ;
		//===============================sertch b high degreen================================
		if(Hideg>=Lodeg)
		{
			//printf("Hideg : %d\n",Hideg);
			//printf("Lodeg. %d\n",Lodeg);
			disdeg = Hideg - Lodeg  ;
			r = r^1<<disdeg ;  //quotent
			//printf("R: %x\n",1<<disdeg);		 
			a = a^(b<<disdeg ) ; //Remainder 
			//printf("R: %X\n",r) ;
		}
	}//loop 
	*q = r ;
	//*out_r = r ;
		//printf("a after devide. %x\n",q);
	//printf("R: %x\n",r);

	return a ;  //return remainder
}
//=====================devide==================================

int mutiplication(int a,int b)
{
	int out = 0x00 ;
	
	
	for(int i=7;i>0;i--)
	{
		out = out ^  (a* (b>>i & 0x01) );
		out = out <<1 ;
		out = ( (out>>8) & 0x01 >0 ) ? out^0x11B : out ;
		//printf("bit %d value %X \n",i,out)	;	
	}	
	out = out ^  (a* (b & 0x01) );	
	
	return out ;
}
//=====================mutiplication==================================

int GCD(int a,int b)
{
	
	int old_r = a, r = b;
	int old_s = 1, s = 0;
	int old_t = 0, t = 1;
	int q   = 0x00;
	int temp = 0x00;
	int temp_muti = 0x00 ;
	//int  r   = 0x00 ;
	if(b == 0 )
	{
			return 0 ;
	}

	while(r!=1)
	{
		temp=devide(old_r,r,&q);  // devide(old_r,r,&q) return remainder ,call by reference return quotient
		//printf("%x / %x equal %x\n",old_r,r,q);
		//printf("%x mod %x equal %x\n",old_r,r,temp);
		old_r = r ;
		r = temp;//=============================change old_r <-r , r<- new remainder 
		//printf("a:%x \n",old_r);
		//printf("b:%x \n",r);
		//================ old_r = b ,r = a's q=================
		temp = old_s;
		old_s = s;
		temp_muti = mutiplication(q,s) ;
		s= add(temp, temp_muti) ;
		//printf("temp_muti %X\n",temp_muti);
		//printf("s:%X \n",s);	
		//================Si+1 caculate=======================
		temp = old_t;
		old_t = t;
		temp_muti = mutiplication(q,t) ;
		t = add(temp, temp_muti);//temp - q * t;
		//printf("temp_muti %X\n",temp_muti);
		//printf("t:%X \n",t);
		//================Ti+1 caculate=======================	
	}
	//	printf("old_r:%X\n",old_r);
	//	printf("r:%X\n",r);

	return t ;
}

int sub(int a,int b){
	return a-b;
}

char subbye(int a)
{
	unsigned char b = 0x53 ; //  0xCA Hex up and down replace to 0xAC
	unsigned char b_prime = 0x00 ;
	unsigned char out = 0 ;
	unsigned char Temp = 0 ;
	unsigned char Ob   = 0 ;
	unsigned char sub[]={0x8f,0xc7,0xE3,0xF1,0xF8,0x7C,0x3E,0x1F};
	bool c[8]={0x01,0x01,0x00,0x00,0x00,0x01,0x01,0x00};  // c  0x63
	//b = ( (b^y)<<4 ) ^ x;
	//printf("a= %X \n",a)	;
	for(int i=0;i<8;i++)
	{
		b_prime = ( i>=1 ) ? (b_prime<<1 )^(a&0x01)  :  b_prime ^ (a&0x01)  ;
		a = a>>1  ;
	} // invert a binary

	//printf("b invert= %X \n",b_prime)	;
		
	for(int j=0;j<8;j++)
	{
		out = 0 ; // init out
		Temp =  sub[j] & b_prime ; //sub[0]*b
	//	printf("get %X \n",Temp)	;				
		
		for(int i=0;i<8;i++)
		{
			
			out  = out ^ ( Temp&0x01 ) ; 
			Temp = Temp>>1 ;
			//printf("get %X \n",out)	;
		}
	//	printf("out is %X \n",out)	;
		out = out ^ c[j] ;
		Ob =  ( j>=1 ) ? Ob^(out <<j) : Ob^out ;
		//Ob = Ob^out ; 	
		//printf("%X \n",out)	;				
	}	
	//printf("Ob: %X \n",Ob)	;
	return Ob ;
}