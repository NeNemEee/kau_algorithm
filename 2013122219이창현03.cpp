#include<iostream>
using namespace std;

class arrc{
	private:
		int n,m;
		int **arr;
		
	public:
		arrc(int y, int x){
			this->n=y;
			this->m=x;
			
			this->arr = new int*[y];

			for(int i=0;i<y;i++)
				arr[i]= new int[x];
			
		}
		
		~arrc(){
			for(int i=0;i<this->n;i++)
				delete this->arr[i];
				
			delete this->arr;
		}
		
		int inarr();
		int comp();
		int*shape(int*temp,int y, int x);
};

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	
	arrc* arrr =new arrc(n,m);
	
	arrr->inarr();
	
	printf("%d\n",arrr->comp());
	
	delete arrr;
	
	return 0;

}

int arrc::inarr(){
	for(int i=0;i<this->n;i++)
		for(int j=0;j<this->m;j++)
			cin>>this->arr[i][j];
	
	return 0;
}

int arrc::comp(){
	
	int*temp=new int[6];
	int max=0;
	
	temp=this->shape(temp,0,0);
	
	for(int i=0;i<this->n;i++){
	
		for(int j=0;j<this->m;j++){
			temp=this->shape(temp,i,j);
			
			for(int k=0;k<6;k++){
				if(max<temp[k]){
					max=temp[k];
				}
			}
		}
	}
	
	delete temp;
	
	return max;
}

int* arrc::shape(int*temp,int y, int x){
	if(x+2<this->m)
		temp[0]=this->arr[y][x]+this->arr[y][x+1]+this->arr[y][x+2];
	
	if(y+2<this->n)
		temp[1]=this->arr[y][x]+this->arr[y+1][x]+this->arr[y+2][x];
		
	if((x+1)<m&&(y+1)<n){
		temp[2]=this->arr[y][x]+this->arr[y+1][x]+this->arr[y][x+1];
		temp[3]=this->arr[y][x]+this->arr[y+1][x+1]+this->arr[y][x+1];
		temp[4]=this->arr[y][x+1]+this->arr[y+1][x+1]+this->arr[y+1][x];
		temp[5]=this->arr[y][x]+this->arr[y+1][x]+this->arr[y+1][x+1];
	}
		
	return temp;
	
}




