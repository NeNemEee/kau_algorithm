#include <iostream>
using namespace std;

class Coin{
	public:
		Coin(int y,int x){
			this->arrayBoundX = x;
			this->arrayBoundY = y;
			this->coinMap = new int*[y];
			for(int i=0;i<y;i++)
				coinMap[i] = new int[x];
		}
		
		int getMaxValue(){
			int left;
			int up;
			printf("\n\n%d\n\n",this->arrayBoundX);
			for(int i=0;i<this->arrayBoundY;i++){
				for(int j=0;j<this->arrayBoundX;j++){
					left = 0;
					up = 0;
					
					if(i!=0){
						up = coinMap[i-1][j];
					}
					
					if(j!=0){
						left = coinMap[i][j-1];
					}
					
					up += coinMap[i][j];
					left += coinMap[i][j];
					
					if(up<left)
						coinMap[i][j] = left;
					else
						coinMap[i][j] = up;
					printf("%d ",coinMap[i][j]);
				}
				printf("\n");
			}
			
			return coinMap[this->arrayBoundY-1][this->arrayBoundX-1];
		}
		
		void inputMap(){
			for(int i=0;i<this->arrayBoundY;i++)
				for(int j=0;j<this->arrayBoundX;j++){
					cin>>this->coinMap[i][j];
					printf("%d ",coinMap[i][j]);
				}
		}
	private:
		int arrayBoundX,arrayBoundY;
		int** coinMap;
};

int main(){
	int x, y;
	scanf("%d %d",&x,&y);
	Coin* coin = new Coin(x,y);
	coin->inputMap();
	cout<<coin->getMaxValue();
	return 0;
}
