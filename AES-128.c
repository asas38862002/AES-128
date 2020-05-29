#include "GFmath.h"
#include<stdio.h>

//int degreed[8]={0x100,0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1};
/*
struct EX_GCD { //s,t是裴蜀等式中的系数，gcd是a,b的最大公约数
	int s;
	int t;
	int gcd;
};*/
/*
void setNum(int *num2 )
{
	printf("before setting, num2: %d\n", num2);
	num2 = 5;
	printf("after setting, num2: %d\n", num2);
}*/

/*
struct EX_GCD extended_euclidean(int a, int b) {
	struct EX_GCD ex_gcd;
	if (b == 0) { //b等于0时直接结束求解
		ex_gcd.s = 1;
		ex_gcd.t = 0;
		ex_gcd.gcd = 0;
		return ex_gcd;
	}
	int old_r = a, r = b;
	int old_s = 1, s = 0;
	int old_t = 0, t = 1;
	while (r != 0) { //按扩展欧几里得算法进行循环
		int q = old_r / r;     //q = a/b 
		int temp = old_r;  // temp first get b value
		old_r = r;
		r = temp - q * r;
		//================ old_r = b ,r = a's q=================
		temp = old_s;
		old_s = s;
		s = temp - q * s;
		//================Si+1 caculate=======================
		temp = old_t;
		old_t = t;
		t = temp - q * t;
		//================Ti+1 caculate=======================
		
	}
	ex_gcd.s = old_s;
	ex_gcd.t = old_t;
	ex_gcd.gcd = old_r;
	return ex_gcd;
	}
*/


/*
int add(int a,int b)
{
	int out = 0x00 ;
		
	out = a ^ b;	
	
	return out ;
}
//=====================add ==================================
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
*/


int main()
{
	unsigned int 	a  =0x11B ;
	unsigned int 	b  =0x53 ;
	unsigned int 	q  =0x00 ;
	unsigned int    r   =0x00 ;
	unsigned int 	out=0x00 ;
	//printf("%X \n",a)	;	
	//printf("%X \n",b)	;
	
	/*for(int i =1 ;i<255;i++)
	{
	  printf("Roop %d: %X * %X ",i,a,b)	;	  	
   	  a =  mutiplication(a,b) ; 
	  printf("= %X \n",a)	;W
	}*/

//	out =  mutiplication(a,b) ; 
	printf("add: %X\n",add(a,b));
	out =  mutiplication(a,b) ; 	
	printf("muti: %X\n",out);
	//printf("%X * %X equal %X \n",a,b,out)	;
	/*out = 0x15c ;
	out = ( (out>>8) & 0x01 >0 ) ? out^0x11B : out ;
	printf("%X \n",out)	;*/
	//r=devide(4,3,&q);
	printf("t: %X\n",GCD(a,b));
	//sub(1,2);
/*
	printf("Please input two integers divided by a space.\n");
	scanf("%d%d", &a, &b);
	if (a < b) { //如果a小于b，则交换a和b以便后续求解
		int temp = a;
		a = b;
		b = temp;
	}

	struct EX_GCD solution = extended_euclidean(a, b);
	printf("%d*%d+%d*%d=%d\n", solution.s, a, solution.t, b, solution.gcd);
	printf("Press any key to exit.\n");
	getchar();
	getchar();
*/
	
	return 0;

}