#include <stdio.h>
#include <math.h>

int arr[1009][1009];
long long int dp[1009][1009];

int isprime(int a){
	int i=2;
	int n=sqrt(a);
	for(i=2;i<=n;i++){
		if(a%i==0)
			return 0;
	}
	return 1;
}

void builddp(int n,int m){
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(i==0 && j==0 && isprime(arr[i][j]))
				dp[i][j]=1;
			else{
				if(!isprime(arr[i][j])){
					dp[i][j]=0;
				}
				else{
					long long int ans=0;
					if(j-1>=0)
						ans=(ans+dp[i][j-1])%1000000007;
					if(i-1>=0 && j-1>=0)
						ans=(ans+dp[i-1][j-1])%1000000007;
					if(i-1>=0)
						ans=(ans+dp[i-1][j])%1000000007;
					dp[i][j]=ans;
				}
			}
		}
	}
			
	printf("%lld\n",dp[n-1][m-1]);
	
	i=0;
	j=0;
	while(1){
		printf("%d %d\n",i+1,j+1);
		if((i==n-1) && (j==m-1))
			break;
		if(i+1<n && j+1<m && dp[i+1][j+1]!=0){
			i++;j++;
			continue;
		}
		if(i+1<n && dp[i+1][j]!=0){
			i++;
			continue;
		}
		if(j+1<m && dp[i][j+1]!=0){
			j++;
			continue;
		}
	}
	
}

int main(void) {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	builddp(n,m);
	return 0;
}

