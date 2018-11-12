#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	const int maxi=20;
	int max;
	int sent[maxi+1];
	int received[maxi+1];
	int ctr1=0,ctr2=0;
    cout<<"Enter the size of the data :: \t";
    cin>>max;
	for(int i=0;i<max;i++){
	//	 srand(time(NULL)+sent[i-1]);
  		 sent[i] = rand()%2;//generates 0/1
		 if(sent[i]==1)
		  ctr1++;
	}
	if(ctr1%2==1)
	  sent[max]=1;
	else
	  sent[max]=0;
	//srand(time(NULL));
  	int index = rand()%max;
  	cout<<"\nActual Information ::\t";
	for(int i=0;i<max;i++)
        cout<<sent[i];
  	cout<<"\nTRANSMITTED SIGNAL ::\t";
	for(int i=0;i<max+1;i++)
        cout<<sent[i];
	cout<<"\nIndex Error Occured ::\t"<<index;
	for(int i=0;i<max+1;i++)
	{
		received[i]=sent[i];
		if(received[i]==1)
		 ctr2++;
	}

	if(index<=max)
	if(received[index]==1)
	 {received[index]=0;ctr2--;}
	else
	 {received[index]=1;ctr2++;}

	cout<<"\nRECIEVED SIGNAL ::\t";
	for(int i=0;i<max+1;i++)
	 cout<<received[i];



	if(ctr2%2==0)
	  cout<<"\n\nNO ERROR IN THE SIGNAL!!!";
	else
	  cout<<"\n\nERROR IN THE SIGNAL!!!";


	cout<<"\n";
    return 0;
}
