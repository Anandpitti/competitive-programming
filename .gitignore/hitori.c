#include <stdio.h>

int row,col,no;
int arr[8][8];
char inputs[68];

struct matpair{
	int row,col,status;
};

void printarr(){
	int i,j;

	printf("%d:\n",no);
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}

void printsol(struct matpair sol[][8]){
	int i,j;

	printf("%d:\n",no);
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			printf("%d ",sol[i][j].status);
		printf("\n");
	}
}



void solvehit(struct matpair sol[][8]){
	int i,j,trow,tcol,temp;

	//corner cases

	//top left corner
	tcol=0;
	trow=0;
	if(arr[trow+0][tcol+0]==arr[trow+0][tcol+1]&&arr[trow+0][tcol+0]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+0].status=1;
		sol[trow+0][tcol+1].status=0;
		sol[trow+1][tcol+0].status=0;
		//change 01,10 in row and col (4)
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+0][tcol+0]==arr[trow+0][tcol+1]){
		sol[trow+1][tcol+0].status=0;
		//change all 10 as black in row and col
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+0][tcol+0]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+1].status=0;
		//change all 01 as black in row and col
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	
	if(arr[trow+1][tcol+1]==arr[trow+0][tcol+1]&&arr[trow+1][tcol+1]==arr[trow+1][tcol+0]){
		sol[trow+1][tcol+1].status=1;
		sol[trow+0][tcol+1].status=0;
		sol[trow+1][tcol+0].status=0;
		//change 01,10 in row and col (4)
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+1][tcol+1]==arr[trow+0][tcol+1]){
		sol[trow+1][tcol+0].status=0;
		//change all 10 as black in row and col
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+1][tcol+1]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+1].status=0;
		//change all 10 as black in row and col
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}

	//top right corner
	tcol=col-2;
	trow=0;
	if(arr[trow+0][tcol+0]==arr[trow+0][tcol+1]&&arr[trow+0][tcol+0]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+0].status=1;
		sol[trow+0][tcol+1].status=0;
		sol[trow+1][tcol+0].status=0;
		//change 01,10 in row and col (4)
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+0][tcol+0]==arr[trow+0][tcol+1]){
		sol[trow+1][tcol+0].status=0;
		//change all 10 as black in row and col
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+0][tcol+0]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+1].status=0;
		//change all 01 as black in row and col
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	
	if(arr[trow+1][tcol+1]==arr[trow+0][tcol+1]&&arr[trow+1][tcol+1]==arr[trow+1][tcol+0]){
		sol[trow+1][tcol+1].status=1;
		sol[trow+0][tcol+1].status=0;
		sol[trow+1][tcol+0].status=0;
		//change 01,10 in row and col (4)
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+1][tcol+1]==arr[trow+0][tcol+1]){
		sol[trow+1][tcol+0].status=0;
		//change all 10 as black in row and col
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+1][tcol+1]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+1].status=0;
		//change all 10 as black in row and col
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}

	//bottom left corner
	tcol=0;
	trow=row-2;
	if(arr[trow+0][tcol+0]==arr[trow+0][tcol+1]&&arr[trow+0][tcol+0]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+0].status=1;
		sol[trow+0][tcol+1].status=0;
		sol[trow+1][tcol+0].status=0;
		//change 01,10 in row and col (4)
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+0][tcol+0]==arr[trow+0][tcol+1]){
		sol[trow+1][tcol+0].status=0;
		//change all 10 as black in row and col
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+0][tcol+0]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+1].status=0;
		//change all 01 as black in row and col
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	
	if(arr[trow+1][tcol+1]==arr[trow+0][tcol+1]&&arr[trow+1][tcol+1]==arr[trow+1][tcol+0]){
		sol[trow+1][tcol+1].status=1;
		sol[trow+0][tcol+1].status=0;
		sol[trow+1][tcol+0].status=0;
		//change 01,10 in row and col (4)
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+1][tcol+1]==arr[trow+0][tcol+1]){
		sol[trow+1][tcol+0].status=0;
		//change all 10 as black in row and col
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+1][tcol+1]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+1].status=0;
		//change all 10 as black in row and col
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}

	//bottom right corner
	tcol=col-2;
	trow=row-2;
	if(arr[trow+0][tcol+0]==arr[trow+0][tcol+1]&&arr[trow+0][tcol+0]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+0].status=1;
		sol[trow+0][tcol+1].status=0;
		sol[trow+1][tcol+0].status=0;
		//change 01,10 in row and col (4)
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+0][tcol+0]==arr[trow+0][tcol+1]){
		sol[trow+1][tcol+0].status=0;
		//change all 10 as black in row and col
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+0][tcol+0]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+1].status=0;
		//change all 01 as black in row and col
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	
	if(arr[trow+1][tcol+1]==arr[trow+0][tcol+1]&&arr[trow+1][tcol+1]==arr[trow+1][tcol+0]){
		sol[trow+1][tcol+1].status=1;
		sol[trow+0][tcol+1].status=0;
		sol[trow+1][tcol+0].status=0;
		//change 01,10 in row and col (4)
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+1][tcol+1]==arr[trow+0][tcol+1]){
		sol[trow+1][tcol+0].status=0;
		//change all 10 as black in row and col
		i=trow+1;
		j=tcol+0;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}
	else if(arr[trow+1][tcol+1]==arr[trow+1][tcol+0]){
		sol[trow+0][tcol+1].status=0;
		//change all 10 as black in row and col
		i=trow+0;
		j=tcol+1;
		if(sol[i][j].row!=-1){
			temp= sol[i][j].row;
			while(temp!=j){
				sol[i][temp].status=1;
				temp=sol[i][temp].row;
			}
		}
		if(sol[i][j].col!=-1){
			temp= sol[i][j].col;
			while(temp!=i){
				sol[temp][j].status=1;
				temp=sol[temp][j].col;
			}
		}
	}

	//done

	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(sol[i][j].status==-1){
				if(sol[i][j].row==-1&&sol[i][j].col==-1){
					sol[i][j].status=0;
					//no erase needed
				}
				else if(sol[i][j].row==-1){
					sol[i][j].status=0;
					//erase in col
					if(sol[i][j].col!=-1){
						temp= sol[i][j].col;
						while(temp!=i){
							sol[temp][j].status=1;
							temp=sol[temp][j].col;
						}
					}
				}else if(sol[i][j].col==-1){
					sol[i][j].status=0;
					//erase in row
					if(sol[i][j].row!=-1){
						temp= sol[i][j].row;
						while(temp!=j){
							sol[i][temp].status=1;
							temp=sol[i][temp].row;
						}
					}
				}
				else{
					if(j+2<col && arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2]){
						//row triplet
						sol[i][j].status=1;
						sol[i][j+1].status=0;
						sol[i][j+2].status=1;
						//change row and column
						if(sol[i][j+1].row!=-1){
							temp= sol[i][j+1].row;
							while(temp!=j+1){
								sol[i][temp].status=1;
								temp=sol[i][temp].row;
							}
						}
						if(sol[i][j+1].col!=-1){
							temp= sol[i][j+1].col;
							while(temp!=i){
								sol[temp][j+1].status=1;
								temp=sol[temp][j+1].col;
							}
						}
					}
					if(i+2<row && arr[i][j]==arr[i+1][j] && arr[i][j]==arr[i+2][j]){
						//column triplet
						sol[i][j].status=1;
						sol[i+1][j].status=0;
						sol[i+2][j].status=1;
						//change in row and col
						if(sol[i+1][j].row!=-1){
							temp= sol[i+1][j].row;
							while(temp!=j){
								sol[i+1][temp].status=1;
								temp=sol[i+1][temp].row;
							}
						}
						if(sol[i+1][j].col!=-1){
							temp= sol[i+1][j].col;
							while(temp!=i+1){
								sol[temp][j].status=1;
								temp=sol[temp][j].col;
							}
						}
					}
					//- - case
					if(j+1<col && arr[i][j]==arr[i][j+1]){
						if(sol[i][j].col==-1){
							sol[i][j].status=0;
							//change in row
							if(sol[i][j].row!=-1){
								temp= sol[i][j].row;
								while(temp!=j){
									sol[i][temp].status=1;
									temp=sol[i][temp].row;
								}
							}
						}
						else if(sol[i][j+1].col==-1){
							sol[i][j+1].status=0;
							//change in row
							if(sol[i][j+1].row!=-1){
								temp= sol[i][j+1].row;
								while(temp!=j+1){
									sol[i][temp].status=1;
									temp=sol[i][temp].row;
								}
							}
						}else{
							//add to backtrack;
						}
					}
					//|
					//| case
					if(i+1<row && arr[i][j]==arr[i+1][j]){
						if(sol[i][j].row==-1){
							sol[i][j].status=0;
							//change in col
							if(sol[i][j].col!=-1){
								temp= sol[i][j].col;
								while(temp!=i){
									sol[temp][j].status=1;
									temp=sol[temp][j].col;
								}
							}
						}
						else if(sol[i+1][j].row==-1){
							sol[i+1][j].status=0;
							//change in col
							if(sol[i+1][j].col!=-1){
								temp= sol[i+1][j].col;
								while(temp!=i+1){
									sol[temp][j].status=1;
									temp=sol[temp][j].col;
								}
							}
						}else{
							//add to backtrack;
						}
					}

				}
			}
		}
	}

	//do the back tracking if any present
	printsol(sol);

}

void solvehitori(){
	int i,j;
	int fill[10];
	int first[10];
	
	struct matpair mat[8][8];
	
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			mat[i][j].row = mat[i][j].col = mat[i][j].status = -1;
		}
	}

	for(i=0;i<row;i++){
		for(j=0;j<10;j++){
			fill[i]=first[i]=-1;
		}
		for(j=0;j<col;j++){
			if(fill[arr[i][j]]==-1){
				first[arr[i][j]]=j;
				fill[arr[i][j]]=j;
			}
			else{
				mat[i][arr[i][j]].row=j;
				mat[i][j].row=first[arr[i][j]];
				fill[arr[i][j]]=j;
			}
		}
	}

	for(i=0;i<col;i++){
		for(j=0;j<10;j++){
			fill[i]=first[i]=-1;
		}
		for(j=0;j<row;j++){
			if(fill[arr[j][i]]==-1){
				first[arr[j][i]]=j;
				fill[arr[j][i]]=j;
			}
			else{
				mat[arr[j][i]][i].col=j;
				mat[j][i].col=first[arr[j][i]];
				fill[arr[j][i]]=j;
			}
		}
	}

	printarr();
	solvehit(mat);
}

void getinput(){
	int i,j,k;

	scanf("%d%d",&row,&col);
	scanf("%s",inputs);

	k=0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			arr[i][j]=inputs[k]-'0';
			k++;
		}
	}
}

int main(){
	int testcases;

	scanf("%d",&testcases);
	no=1;

	while(no<testcases){
		getinput();
		solvehitori();
		no++;
	}
	return 0;
}
