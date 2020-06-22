#include<stdio.h>
#include<signal.h>

//Write a function that computes factorial of received integer. The function can return 0 if the integer is negative. 
//Use the function in a program that receives integers from user repeatedly. The program can be terminated only by pressing CTRL+C. 
//We have to include <signal.h>

int fact(int a);
void  INThandler(int sig);

int main(){
	
	int n;
    
    signal(SIGINT,INThandler);
    
    for(;;){
      printf("\nPlease enter an integer:");
	  scanf("%d",&n);
	  printf("%d",fact(n));
	
	}

	return 0;
}
int fact(int a){
	
	if(a<0){
		return 0;
	}
	
	int fact=1;
	while(a>0){
		fact*=a;
		a--;
	}
	return fact;
}
void  INThandler(int sig){
	
     signal(sig, SIG_IGN);
     
          exit(1);
}

