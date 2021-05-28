#include<stdio.h>

void rungame(int n, int a[][n]){
	int i;
	int j;
	int count;
	int flag;
	int bfr[n][n];
	int i1;
	int j1;
	int safety;
	flag=1;
	//safety=100;
	
	while(flag==1 /* && safety>0*/){
		flag=0;
		safety--;
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				bfr[i][j]=a[i][j];
			}
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				count=0;
				for(i1=i-1;i1<=i+1;i1++){
					if(i1<0||i1>n-1){
					}else{
						for(j1=j-1;j1<=j+1;j1++){
							if(j1<0||j1>n-1){
							} else if(bfr[i1][j1]==1 && !(i1==i && j1==j)){
								
								
									count++;
							
							}
						}
					}
				}
				if(count<2){
					a[i][j]=0;
				} else if(count==3){
					a[i][j]=1;
				} else if(count>3){
					a[i][j]=0;
				}
			}
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(a[i][j]!=bfr[i][j]){
					flag=1;
				}
				printf("%3d",a[i][j]);
			}
			printf("\n");
		}
	}
}
int main(void){
	int n;
	scanf("%d", &n);
	int a[n][n];
	int i;
	int j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	rungame(n,a);
	return 0;
}
