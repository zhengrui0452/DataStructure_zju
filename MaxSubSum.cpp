#include <iostream>
using namespace std;
int max_Num(int a,int b,int c)
{
	int maxNum=a>b?a>c?a:c:b>c?b:c;
	return maxNum;
}
int divide(int List[],int left,int right)
{
	int maxleftsum=0,maxrightsum=0,
	leftbordersum=0,rightbordersum=0,
	maxleftbordersum=0,maxrightbordersum=0;

	if(left==right)
	{
		if (List[left]>maxleftsum)
		{
			maxleftsum=List[left];
			return maxleftsum;
		}
		else return 0;
	}

	int center=(left+right)/2;
	maxleftsum = divide(List,left,center);
	maxrightsum = divide(List,center+1,right);

	for (int i = center; i >= left; --i)
	{
		leftbordersum = leftbordersum + List[i];
		if(leftbordersum>maxleftbordersum)
			maxleftbordersum = leftbordersum;
	}
	for (int i = center+1; i <= right; ++i)
	{
		rightbordersum = rightbordersum + List[i];
		if (rightbordersum>maxrightbordersum)
		{
			maxrightbordersum = rightbordersum;
		}
	}

	int maxNum=max_Num(maxleftsum,maxrightsum,maxleftbordersum+maxrightbordersum);
	return maxNum;
}
int main()
{
	// cout<<"hello world!";
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int maxNum=divide(a,0,n-1);
	cout<<maxNum<<endl;
	return 0;
}
