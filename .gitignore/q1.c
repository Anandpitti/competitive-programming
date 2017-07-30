#include <stdio.h>

#define MOD 1000000007

long long int arr[100009];

void multiply(long long int F[2][2],long long int M[2][2])
{
  long long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  F[0][0] = x%MOD;
  F[0][1] = y%MOD;
  F[1][0] = z%MOD;
  F[1][1] = w%MOD;
}

void power(long long int F[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}

long long int fib(int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	int n,q,a,b,i,j;
	
	scanf("%d%d",&n,&q);
	
	for(i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}

	for(i=0;i<q;i++){
		scanf("%d%d",&a,&b);
		long long ans=arr[a];
		for(j=a+1;j<=b;j++){
			ans=gcd(ans,arr[j]);
		}
		printf("%lld\n",fib(ans));
	}
	return 0;
}

