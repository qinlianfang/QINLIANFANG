/*4—1会场安排问题
解题思路
1.对活动进行排序，开始时间越早排在越前面，如果两个活动时间相同，则结束时间越早的排在越前面
2.开始时间最早和持续时间最短的优先安排会场，并记录会场号，
3.其余活动的开始时间大于或等于已安排活动的结束时间的安排在同一会场，
4.若某活动的开始时间小于已经安排了会场的活动的结束时间，则安排在另一会场，记录会场号，
5.依次循环，直到所有活动均被安排*/
#include<stdio.h> 
#include<stdlib.h>
void sort(int a[],int n){ // 函数sort的功能是对给定区间所有函数进行排序，这里即是对数组a和n进行排序
for(int i=0;i<n;i++){
 for(int j=i;j<n;j++){ //依次循环
	if(a[i]>a[j]){ 
int temp=a[i]; a[i]=a[j]; a[j]=temp; 
	} 
 } 
} 
} 
int main(){
int n,i; printf("请输入事件个数(n)："); 
scanf("%d",&n); int *start=(int *)malloc(sizeof(int)*n); //表示定义一个int类型的指针变量start，并申请n*sizeof(int)个字节（即4*n个字节）的存储空间。int *end=(int *)malloc(sizeof(int)*n); 表示定义一个int类型的指针变量end，并申请n*sizeof(int)个字节（即4*n个字节）的存储空间
printf("请依次输入各事件的开始和结束时间：\n"); 
for (i=0;i<n;i++) 
scanf("%d%d",&start[i], &end[i]); sort(start,n); //对活动开始时间和会场号进行排序
sort(end,n);//对活动结束时间和会场号进行排序 int j=0; int sum=0; 
//会场个数 
for(i=0;i<n;i++){ if(start[i]<end[j]) sum++;
//如果开始时间小于结束时间则另开辟一个会场 
else j++; //否则和下一个结束时间进行比较 
} 
printf("需要会场：%d",sum); 
return 0;
 }


