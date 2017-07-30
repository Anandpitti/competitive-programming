#include <stdio.h>
#define size 1000

long long int dp[size][size];
int in[size];

long long int max(long long a, long long b){
	if(a>b) return a;
	return b;
}

void builddp(int n){
	int l,i,j,k,a,b;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)dp[i][j]=in[i];
			else dp[i][j]=0;
		}
	}

	for(l=2;l<=n;l++){
		for(i=0;i<n-l+1;i++){
			j=i+l-1;
			for(k=i;k<=j;k++){
				if(k>i)
					a=dp[i][k];
				else a=1;
				if(k<j)
					b=dp[k][j];
				else b=1;
				dp[i][j] = max(dp[i][j],a*b/in[k]);
			}
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%lld\t",dp[i][j]);
		printf("\n");
	}
}

int main(){
	int testcases,t;
	scanf("%d",&testcases);

	for(t=1;t<=testcases;t++){
		int n,i;

		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&in[i]);
		
		builddp(n);
		printf("#%d %lld\n",t,dp[0][n-1]);
	
	}
	return 0;
}
