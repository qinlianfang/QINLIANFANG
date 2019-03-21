
#include<stdio.h> 
void Split(int a[],int &left,int &right,int n){//这里进行函数的分割,分左边界，右边界并定义为整形
int mid=n/2;//取中位数
for(left=0;left<n;left++)//进行分割左界限,时间复杂度O(n)
{
if(a[left]==a[mid])//如果左边的数等于中间的数，则表明数字相同，没有比较的意义
break;
}
for(right=left+1;right<n;right++)//进行分割右界限，时间复杂度O(n)
{
if(a[right]!=a[mid])
break;
}
}
template<class Type>//声明一个函数模版
void Mode(Type *a,int &number,int &MaxTime,int n)//计算众数和重数
{
int left,right;
Split(a,left,right,n);//将数组进行切割成两端
int num=n/2;//第一组的中位数（假设为众数）
int cnt=right-left;///第一组中位数的个数（重数）
if(cnt>MaxTime)//进行作比较，每次把最大值进行保留下来
{
MaxTime=cnt;
number=a[num];
}

if(left+1>MaxTime)//表示左边的个数，左边的个数必须大于中位数的个数，才有进行搜索的意义
{
Mode(a,number,MaxTime,left+1);
}

if(n-right>MaxTime)//同理，右边的个数将要大于中位数的个数才有继续搜寻的意义，同时右边数组的起始位置进行改变
{
Mode(a,number,MaxTime,n-right);
}
}

int main()
{
int a[]={6,1,2,2,2,3,5};
int n =sizeof(a)/sizeof(a[0]);//输出数组长度

int MaxTime=0;
int number=0;
Mode(a,number,MaxTime,n);
printf("%d %d\n",number,MaxTime);
return 0;
}
