#include<iostream>
#include<fstream>
#include <algorithm>

 using namespace std;

 const int maxsize=100;
 int num=0;///���������
 struct node  ///Ԫ��ṹ
 {
     int key;
     int data;
 };
 struct form  ///���ӽ��Ԫ��ṹ
 {
     int key;
     int a;///A���data
     int b;///B���data
 };

ostream&operator<<(ostream &output,node &n)///����<<
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

cout<<"��������ļ���"<<endl;
     char filename[20];
     cin>>filename;
     ifstream infile;
     infile.open(filename,ios::in);

cout<<"�ֱ����������Ԫ����"<<endl;
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
   infile.close();///�ر��ļ�

     cout<<"A��:"<<endl;
     for(int i=0;i<x;i++)
     cout<<A[i]<<endl;

     cout <<"B��"<<endl;
     for(int i=0;i<y;i++)
     cout<<B[i]<<endl;


  int temp[7];///ģ��һ��ֻ��ȡ��7��Ԫ��
  int k=x/7;
  int position=0;///position��key�Ѿ������tempԪ��
  for(int i=0;i<k;i++)
  {
      for(int j=0;j<7;j++) ///ȡ��7��Ԫ��
      {
          if(A[position].key!=0)
           {temp[j]=A[position].key;
           position++;}
      }
      sort(temp,temp+7);
      ///��B���key���бȽϣ����ֲ��ң�
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
              else ///��ŵ������
              {
              result[num].key=B[k].key;
              result[num].data=B[k].data;
              num++;break;
              }
          }
      }
  }

  cout<<"�����:"<<endl;
     for(int i=0;i<num;i++)
     cout<<result[i]<<endl;
     /*cout<<"A��:"<<endl;
     for(int i=0;i<x;i++)
     cout<<A[i]<<endl;

     cout <<"B��"<<endl;
     for(int i=0;i<y;i++)
     cout<<B[i]<<endl;
     return 0;*/
 }
