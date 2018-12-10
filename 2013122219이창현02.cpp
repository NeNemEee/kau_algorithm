 #include<iostream>

int **input(int n, int m);
int cal(int**arr, int n, int m);
int max(int a, int b);



int main(void){
	
	int n,m;
	
	std::cin>>n>>m;
	
	int **arr = input(n,m);
	
	std::cout<<cal(arr,n,m);
	
	int i;
	
	for(i=0;i<n;i++){
		delete arr[i];
	}
	
	delete arr;
	
	return 0;
}

int **input(int n, int m){
	
	int **arr = new int*[n];
	
	int k;
	
	for(k=0;k<n;k++){
		 arr[k] = new int[m];
	}
		
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			std::cin>>arr[i][j];
	}
	
	return arr;
	
}

int cal(int**arr,int n, int m){
	
	int i;
	int j;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(i==0){
				if(j!=0)
					arr[i][j]=arr[i][j]+arr[i][j-1];
			}else{
				if(j==0)
					arr[i][j]=arr[i][j]+arr[i-1][j];
				else
					arr[i][j]=arr[i][j]+max(arr[i-1][j],arr[i][j-1]);
			}
		}
	}
	
	return arr[n-1][m-1];
	
}

int max(int a, int b){
	return a>b?a:b;
}



