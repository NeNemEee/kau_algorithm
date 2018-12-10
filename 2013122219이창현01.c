#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int first(char*a, char*b);
int second(char*a, char*b);
int*ppp(int*parr, int pl, char*b);



void main(){
	int n, m;

	while(1){
		scanf("%d %d", &n, &m);
		
		if(n<m||1000000<n||m<1||100<m){
			printf("error\n");
		}else{
			break;
		}
	}

	char*t=(char*)malloc(sizeof(char)*n);
	char*p=(char*)malloc(sizeof(char)*m);
	
	while(1){
		scanf("%s", t);
		scanf("%s", p);
		
		if(n==strlen(t)&&m==strlen(p)){
			break;
		}
		
		fflush(stdin);
	}
	
	first(t,p);
	second(t,p);
	
	free(t);
	free(p);

}

int first(char*a, char*b){
	
	int sc=0;
	int tn=0;
	
	int tl=strlen(a);
	int pl=strlen(b);
	
	int i;
	int j;
	
	for(i=0;i<tl-pl+1;i++){
		for(j=0;j<pl;j++){
			tn++;
			
			if(a[i+j]!=b[j]){
				break;
			}else{
				if(j==pl-1){
					sc++;
				}
			}
			
		}
	}
	
	printf("%d %d\n",sc, tn);
	
	return 0;
}

int second(char*a, char*b){
	
	int sc=0;
	int tn=0;
	
	int tl=strlen(a);
	int pl=strlen(b);
	
	int*parr=ppp(parr,pl,b);
	
	
	int z=0;
	int x=0;
	int tem=0;

	while((z+pl)<=tl){
		
		
		while(1){
			tn++;
				
			if(a[z+x]==b[x]){
				
				x++;
				
				if(x==pl){
					
					sc++;
					
					break;
				}
				
			}else{
				break;
			}
			
		}
		if(x>0){
			tem=parr[x-1];
		}else{
			tem=-1;
		}
		
		z=z+x-tem;
		
		if(tem==-1){
			x=0;
		}else{
			x=tem;
		}	
		
	}
	
	printf("%d %d\n",sc, tn);
	
	return 0;
	
	free(parr);
}

int*ppp(int*parr, int pl, char*b){
	
	parr=(int*)malloc(sizeof(int)*pl);
	
	int cur=0;
	int i=0;
	int j=1;
	
	
	while(i<pl){
		parr[i]=0;
		i++;
	}
	
	i=0;
	
	while(j<pl){
		if(b[i]==b[j]){
			cur++;
			
			if(parr[j]<cur){
				parr[j]=cur;
			}
			
			j++;
			i++;
		
		}else{
	
			i=0;	
			j=j-cur+1;
			cur=0;

		}
	}
	
	return parr;
}



