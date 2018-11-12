#include<iostream>
using namespace std;

int total,target,adv,p;
int delay[20][2],table[20][20];
int RT1[20],RT2[20];

void input(){
	cout<<"Enter the total number of routers in the network ::\t";
	cin>>total;
	cout<<"\nEnter the Vertex Whose routing table is to be Found ::\t";
	cin>>target;
	cout<<"\nEnter the number of routers adjacent to Target Vertex "<<target<<" ::\t";
	cin>>adv;
	
	for(int i=0;i<adv;i++){
		cout<<"\nEnter the number of "<<i+1<<"th adjacent router ::\t";
		cin>>p;
		delay[i][0]=p;
		cout<<"\nFill the routing table for router number "<<p<<" ::\n";
		for(int j=0;j<total;j++){
			cout<<j<<".\t";
			if(j==p){
				table[p][j]=0;
				cout<<table[p][j]<<endl;
				continue;
			}
			cin>>table[p][j];
		}
		cout<<"\nEnter the Delay from Target router "<<target<<" to Adjacent Vertex "<<p<<" ::\t";
		cin>>delay[i][1];
	}
}

void DVR(){
	for(int i=0;i<total;i++){
		RT1[i]=-1;
		RT2[i]=-1;	
	}
	
	for(int i=0;i<adv;i++){
		RT1[delay[i][0]]=delay[i][1];
		RT2[delay[i][0]]=delay[i][0];
	}
	RT1[target]=0;
	RT2[target]=target;
	for(int y=0;y<total;y++){
		if(RT1[y]==-1){
			int min=99999,min_point=0;
			for(int i=0;i<adv;i++){
				if(min>table[delay[i][0]][y]+delay[i][1]){
					min=table[delay[i][0]][y]+delay[i][1];
					min_point=delay[i][0];	
				}
			}
			RT1[y]=min;
			RT2[y]=min_point;
		}
	}
}

void result(){
	cout<<"\n==>>Routing table for "<<target<<" is :";
	for(int i=0;i<total;i++){
		cout<<"\n\t"<<i<<".\t"<<RT1[i]<<"\t";	
		if(RT2[i]==target){
			cout<<"-";
		}else{
			cout<<RT2[i];
		}
	}
}

int main(){
	input();
	DVR();
	result();
	return 0;
}
