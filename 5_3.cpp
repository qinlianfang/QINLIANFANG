/*5—3最小重量机器设计问题
算法设计：
a.部件有n个，供应商有m个，分别用w[i][j]和c[i][j]存储从供应商j 处购得的部件i的重量和相应价格，d为总价格的上限。
b.用递归函数backtrack(i)来实现回溯法搜索排列树（形式参数i表示递归深度）。
① 若cp>d，则为不可行解，剪去相应子树，返回到i-1层继续执行。
② 若cw>=sum，则不是最优解，剪去相应子树，返回到i-1层继续执行。
③ 若i>n，则算法搜索到一个叶结点，用sum对最优解进行记录，返回到i-1层继续执行；
④ 用for循环对部件i从m个不同的供应商购得的情况进行选择(1≤j≤m）。
4.算法时间复杂度：
程序中最大的循环出现在递归函数backtrack(i)中，而此函数遍历排列树的时间复杂度为O(n!),故该算法的时间复杂度为O(n!)。 */


#include<iostream>
#define N 1000
using namespace std;//c++语言使用标准命名空间 
int n,m,d,i,cp=0,//价格
cw=0,//重量 sum=0;//选择机器的总重量
int c[N][N],w[N][N];//定义两个二维数组存储从供应商j 处购得的部件i的重量和相应价格
void backtrack(int i)//函数声明{
     if(i>n){
       if(cw<sum)
         sum = cw;
       return ;//在当前部件i大于机器部件的前提下当前的重量小于选择机器的总重量的话，将当前的重量的值赋给选择机器的总重量sum，将结果 return返回

     }
     for(int j=1;j<=m;j++){//如果不是上面这种情况，则程序往下执行，定义j=1,j小于供应商数量，j++
         cw+=w[i][j];
         cp+=c[i][j];//递归调用，不断累加得到重量和价值
         if(cw<sum && cp<=d)//总价格的上限
           backtrack(i+1);
         cw-=w[i][j];
         cp-=c[i][j];//调用递归函数backtrack，将重量和价值不断自减
     }
}

int main(){
    cin>>n>>m>>d;//Cin是相应的价格,d总价格的上限
    for( i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
        cin>>c[i][j];
      sum+=c[i][1];//供应商j 处购得的部件i的价值
    }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>w[i][j];//供应商j 处购得的部件i的重量
    backtrack(1);
    cout<<sum<<endl;
    system("pause");
    return 0;
}
