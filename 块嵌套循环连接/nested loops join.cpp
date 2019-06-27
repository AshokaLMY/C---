#include<iostream>
#include<fstream>
#include <algorithm>

 using namespace std;

 const int maxsize=100;
 int num=0;///结果集个数
 struct node  ///元组结构
 {
     int key;
     int data;
 };
 struct form  ///连接结果元组结构
 {
     int key;
     int a;///A表的data
     int b;///B表的data
 };

ostream&operator<<(ostream &output,node &n)///重载<<
{
    output<<n.key<<" "<<n.data;
    return output;
}

     node A[maxsize];
     node B[maxsize];
     node result[maxsize];



 int main()
 {
     /*node A[maxsize];
     node B[maxsize];
     form result[maxsize];*/
/*int kk[5]={55,12,36,44,9};
sort(kk,kk+5);
for(int i=0;i<5;i++)cout<<kk[i]<<' ';*/

cout<<"输入测试文件名"<<endl;
     char filename[20];
     cin>>filename;
     ifstream infile;
     infile.open(filename,ios::in);

cout<<"分别输入两表的元组数"<<endl;
   int x,y;
   cin>>x>>y;

   for(int i=0;i<x;i++)
   {
       infile>>A[i].key; //cout<<A[i].key<<endl;
       infile>>A[i].data;// cout<<A[i].data<<endl;
   }

   for(int i=0;i<y;i++)
{
    infile>>B[i].key;
    infile>>B[i].data;
}
   infile.close();///关闭文件

     cout<<"A表:"<<endl;
     for(int i=0;i<x;i++)
     cout<<A[i]<<endl;

     cout <<"B表："<<endl;
     for(int i=0;i<y;i++)
     cout<<B[i]<<endl;


  int temp[7];///模拟一次只能取出7个元组
  int k=x/7;
  int position=0;///position个key已经输出到temp元组
  for(int i=0;i<k;i++)
  {
      for(int j=0;j<7;j++) ///取出7个元组
      {
          if(A[position].key!=0)
           {temp[j]=A[position].key;
           position++;}
      }
      sort(temp,temp+7);
      ///与B组的key进行比较（二分查找）
      for(int k=0;k<y;k++)
      {

          int low=0,high=6,mid=0;
          while(low<=high)
          {
              mid=(low+high)/2;
              if(temp[mid]<B[k].key)
                 low=mid+1;
              else if(temp[mid]>B[k].key)
                high=mid-1;
              else ///存放到结果集
              {
              result[num].key=B[k].key;
              result[num].data=B[k].data;
              num++;break;
              }
          }
      }
  }

  cout<<"结果表:"<<endl;
     for(int i=0;i<num;i++)
     cout<<result[i]<<endl;
     /*cout<<"A表:"<<endl;
     for(int i=0;i<x;i++)
     cout<<A[i]<<endl;

     cout <<"B表："<<endl;
     for(int i=0;i<y;i++)
     cout<<B[i]<<endl;
     return 0;*/
 }
