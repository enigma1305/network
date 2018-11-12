#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<math.h>
using namespace std;

void checkBits(int b[],int x,int r){
	int i=-1;
	while(x>0){
		b[++i]+=x%2;
		x/=2;
	}
}

int main(){
	int ch,n,*a,*b,*c,m,r,z=0;
	cout<<"\t\tMENU"
        <<"\n1).User generated"
        <<"\n2).System generated"
        <<"\n\nEnter your choice ::\t";
    cin>>ch;
    cout<<"\nEnter the length of the Dataword ::\t";
	cin>>n;
	for(r=0;n+r>pow(2,r)-1;++r);
	m=n+r;
	a=new int[m];
    switch(ch){
        case 1: cout<<"\nEnter the DataWord ::\n";
                for(int i=0;i<m;i++){
                    if(i+1==pow(2,z)){
                        a[i]=-1;
                        z++;
                    }
                    else{
                        cin>>a[i];
                    }
                }
                break;
        case 2: srand(time(NULL));
                for(int i=0;i<m;i++){
                    if(i+1==pow(2,z)){
                        a[i]=-1;
                        z++;
                    }
                    else{
                        a[i]=rand()%2;
                    }
                }
                break;
        default: cout<<"\nWRONG CHOICE ENTERED!!!\n";
                    exit(0);
    }


	cout<<"\nDataWord Code :: ";
	z=0;
	for(int i=0;i<m;i++){
		if((i+1)==pow(2,z))
			z++;
		else
			cout<<a[i];
	}
	cout<<"\nNumber of Redundant Bits required ::\t";
	cout<<r;
	b=new int[r];
	c=new int[r];
	for(int i=0;i<r;i++){
		b[i]=0;
		c[i]=0;
	}

	for(int i=0;i<m;i++){
		if(a[i]==1)
			checkBits(b,(i+1),r);
	}
	Sleep(400);
	cout<<"\n==>> Check Bits Are ::";
	for(int i=0;i<r;i++){
		if(b[i]%2==0)
			b[i]=0;
		else
			b[i]=1;
		cout<<"\nr["<<i+1<<"] = "<<b[i];
	}
	Sleep(200);
	cout<<"\n==>> CodeWord :: \t\t\t";
	for(int i=0;i<r;i++){
		int k=pow(2,i)-1;
			a[k]=b[i];
	}
	for(int i=0;i<m;i++){
		Sleep(200);
		cout<<a[i];
	}
	Sleep(500);
	cout<<"\n==>> Random Error At Bit :: \t\t";
	srand(time(NULL));
	int index = rand()%m+1;	
	Sleep(200);		//generating random Error
	cout<<index;
	a[index-1]=1-a[index-1];
	cout<<"\n==>> Recieved Incorrect CodeWord ::\t";
	for(int i=0;i<m;i++){
		Sleep(200);
		cout<<a[i];
	}
	z=0;
	for(int i=0;i<r;i++){			//setting b with new check bits of recieved codeword
		int k=pow(2,i)-1;
			b[i]=a[k];
	}
	for(int i=0;i<m;i++){
		if((i+1)==pow(2,z))
			z++;
		else if(a[i]==1){
			checkBits(c,(i+1),r);
		}
	}
	for(int i=0;i<r;i++){
		if(c[i]%2==0)
			c[i]=0;
		else
			c[i]=1;
	}
	int sum=0;
	for(int i=0;i<r;i++){
		if(b[i]!=c[i])
			sum+=pow(2,i);
	}
	cout<<"\n==>> Error At Bit :: \t\t\t"<<sum;
	a[sum-1]=1-a[sum-1];
	cout<<"\n\n==>> Corrected CodeWord :: \t\t";
	for(int i=0;i<m;i++){
		Sleep(200);
		cout<<a[i];
	}
	return 0;
}
