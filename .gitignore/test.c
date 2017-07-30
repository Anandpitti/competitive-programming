#include <stdio.h>
#include <string.h>

long long int dp[10];

int digits(long long int n){
	int dig=0;
	while(n){
		dig++;
		n=n/10;
	}
	return dig;
}

long long int sumtono(long long int n){
	long long int sum=0;
	while(n){
		sum=sum+n%10;
		n=n/10;
	}
	return sum;
}

long long int findans(long long int no){
	long long int temp;
	if(digits(no)<=1)
		return dp[no];
	temp=no%10;
	return((findans((no/10)-1)*10)+(dp[9]*(no/10))+((temp+1)*sumtono(no/10))+dp[temp]);
}

int main(){

	int i;
	dp[0]=0;
	for(i=1;i<10;i++)
		dp[i]=dp[i-1]+i;

	long long int ans,no=0;
	scanf("%lld",&no);
	ans=findans(no);
	printf("%lld\n",ans);
}
