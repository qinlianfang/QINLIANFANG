/*4��1�᳡��������
����˼·
1.�Ի�������򣬿�ʼʱ��Խ������Խǰ�棬��������ʱ����ͬ�������ʱ��Խ�������Խǰ��
2.��ʼʱ������ͳ���ʱ����̵����Ȱ��Ż᳡������¼�᳡�ţ�
3.�����Ŀ�ʼʱ����ڻ�����Ѱ��Ż�Ľ���ʱ��İ�����ͬһ�᳡��
4.��ĳ��Ŀ�ʼʱ��С���Ѿ������˻᳡�Ļ�Ľ���ʱ�䣬��������һ�᳡����¼�᳡�ţ�
5.����ѭ����ֱ�����л��������*/
#include<stdio.h> 
#include<stdlib.h>
void sort(int a[],int n){ // ����sort�Ĺ����ǶԸ����������к��������������Ｔ�Ƕ�����a��n��������
for(int i=0;i<n;i++){
 for(int j=i;j<n;j++){ //����ѭ��
	if(a[i]>a[j]){ 
int temp=a[i]; a[i]=a[j]; a[j]=temp; 
	} 
 } 
} 
} 
int main(){
int n,i; printf("�������¼�����(n)��"); 
scanf("%d",&n); int *start=(int *)malloc(sizeof(int)*n); //��ʾ����һ��int���͵�ָ�����start��������n*sizeof(int)���ֽڣ���4*n���ֽڣ��Ĵ洢�ռ䡣int *end=(int *)malloc(sizeof(int)*n); ��ʾ����һ��int���͵�ָ�����end��������n*sizeof(int)���ֽڣ���4*n���ֽڣ��Ĵ洢�ռ�
printf("������������¼��Ŀ�ʼ�ͽ���ʱ�䣺\n"); 
for (i=0;i<n;i++) 
scanf("%d%d",&start[i], &end[i]); sort(start,n); //�Ի��ʼʱ��ͻ᳡�Ž�������
sort(end,n);//�Ի����ʱ��ͻ᳡�Ž������� int j=0; int sum=0; 
//�᳡���� 
for(i=0;i<n;i++){ if(start[i]<end[j]) sum++;
//�����ʼʱ��С�ڽ���ʱ����������һ���᳡ 
else j++; //�������һ������ʱ����бȽ� 
} 
printf("��Ҫ�᳡��%d",sum); 
return 0;
 }

