#include<iostream>
#include<string.h>
#include<curses.h>
#include<stdlib.h>


using namespace std;

struct DATA
{
	int num;
	char mesg[20];
};
int flag;

void from_SDL();
int to_SPL(DATA);
int to_RPL(DATA);
int to_RDL(DATA);

int main()
{
	from_SDL();
	return 0;
}

void from_SDL()
{
	int n = 0,i = 0;
	char *msg[] = {"Good","morning","to","you","0"};

	while(strcmp(msg[i],"0")!=0)
	{
		DATA D;
		D.num = n;
		if(n==0)
		{
			n=1;
		}
		else
		{
			n=0;
		}

		strcpy(D.mesg,msg[i]);
		cout<<"\n SENDER DATA LINK MESSAGE:"<<D.mesg;
		int ACKno = to_SPL(D);
		if(ACKno!=D.num)
		{
	  		cout<<"\n\n MESSAGE"<<i<<"TRANFERRED SUCCESSFULLY";
			i++;
		}
		else
		{
			cout<<"\n\n MESSAGE"<<i<<"NOT TRANFERRED SUCCESSFULLY";
			if(n==0)
			{
				n=1;
			}
			else
			{
				n=0;
			}
		}

	}

}

int to_SPL(DATA D)
{
	cout<<"\n SENDER PHYSICAL LINK MESSAGE:"<<D.mesg<<" "<<D.num;
	int ACKno = to_RPL(D);
	return ACKno;
}

int to_RPL(DATA D)
{
	cout<<"\n RECEIVER PHYSICAL LINK MESSAGE:"<<D.mesg<<" "<<D.num;
	int ACKno = to_RDL(D);
	return ACKno;
}

int to_RDL(DATA D)
{
	cout<<"\n RECEIVER DATA LINK MESSAGE:"<<D.mesg<<" "<<D.num;
	int ACKno = 1-D.num;
	int c=(rand())%5+1;
	cout<<endl<<"RAndon num"<<c;
	flag = (rand())%5+1;

	if(flag==c)
	{
	 	return 1-ACKno;
	}
	else
   		return ACKno;
}
