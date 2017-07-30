#include <stdio.h>

long long int pow2(int n){
	if(n==0)
		return 1;
	else if(n==1)
		return 2;
	else if((n%2)==0)
		return pow2(n/2)*pow2(n/2);
	else if((n%2)==1)
		return 2*pow2(n/2)*pow2(n/2);
}

int main(){
	int level,pos,ans;
	long long int no;

	printf("%lld\n",pow2(5000));
	/*
	scanf("%d%d",&level,&pos);

	while(level>2){
		no = pow2(level-3);
		if(pos > no*3)
			pos = pos - no*3;
		else if(pos > no*2)
			pos = pos - no;
		level--;
	}
	if(level == 2){
		ans = pos;
	}
	else if(level == 1)
		ans = 1;

	ans == 1 ? printf("E\n") : printf("D\n");
	*/
} 
