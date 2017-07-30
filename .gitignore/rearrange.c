#include <stdio.h>

#define size 500

int main(void) {
	int testcases;
	scanf("%d",&testcases);

	while(testcases--){
		int i,n,pos,temp,index;
		int arr[size];

		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
			arr[i]++;
		}

		pos=0;
		temp=arr[0];
		while(pos<n){
			if(arr[arr[pos]-1]<0 || arr[pos]-1<0){
				arr[pos]=-temp;
				pos=0;
				while(arr[pos]<0 && pos<n)
					pos++;
				if(pos>=n) break;
				temp=arr[pos];
			}else{
				index=arr[pos]-1;
				arr[pos]=-arr[index];
				pos=index;
			}
		}

		for(i=0;i<n;i++){
			arr[i]=(-arr[i])-1;
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	return 0;
}

