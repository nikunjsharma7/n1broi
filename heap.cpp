# include <iostream>
using namespace std;
int arr[100],n;
void display()
{       
	int i;
	if(n==0)
	{
		cout<<"Heap is empty\n";
		return;
	}
	for(i=0;i<n;i++)
		cout<<arr[i]<<endl;
	cout<<"\n";
}
void insert(int num,int loc)
{
	int p;
	while(loc>0)
	{
		p=(loc-1)/2;
		if(num<=arr[p])
		{
			arr[loc]=num;
			return;
		}
		arr[loc]=arr[p];
		loc=p;
	}
	arr[0]=num; 
}
void del(int num)
{
	int left,right,i,temp,p;

	for(i=0;i<n;i++)
	{
		if(num==arr[i])
		break;
	}
	if( num!=arr[i] )
	{
		cout<<num<< " not found in heap\n";
		return;
	}
	arr[i]=arr[n-1];
	n=n-1;
	p=(i-1)/2;   
	if(arr[i] > arr[p])
	{
		insert( arr[i],i);
		return;
	}
	left=2*i+1;  
	right=2*i+2; 
	while(right < n)
	{
		if( arr[i]>=arr[left] && arr[i]>=arr[right] )
			return;
		if( arr[right]<=arr[left] )
		{
			temp=arr[i];
			arr[i]=arr[left];
			arr[left]=temp;
			i=left;
		}
		else
		{
			temp=arr[i];
			arr[i]=arr[right];
			arr[right]=temp;
			i=right;
		}
		left=2*i+1;
		right=2*i+2;
	}
	if( left==n-1 && arr[i]<arr[left] )
	{	temp=arr[i];
		arr[i]=arr[left];
		arr[left]=temp;
	}
}
int main()
{
	int choice;
	float num;
	n=0;
	{	
		do
		{
		cout<<"1.Insert\n";
		cout<<"2.Delete\n";
		cout<<"3.Display\n";
		cout<<"4.Quit\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
		 case 1:
			cout<<"Enter Percentage of student : ";
			cin>>num;
			insert(num,n);
			n=n+1;
			break;
		 case 2:
			cout<<"Enter Percentage of student to be deleted : ";
			cin>>num;
			del(num);
			break;
		 case 3:
			display();
			break;
		 case 4:
            break;
		 default:
			cout<<"Wrong choice\n";
		}
	}while(choice!=4);
	}
}


