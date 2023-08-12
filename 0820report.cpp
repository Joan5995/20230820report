/給定N群數字，每群都恰有M個正整數。若從每群數字中各選擇一個數字 (假設第 i群所選出數字為ti)，
將所選出的N個數字加總即可得和 S = t1+t2+…+ +…+ tN。請寫程式計算 S的最大值 (最大總和 )，
並判斷各群所選出的數字是否可以整除 S。/
#include<iostream>
using namespace std;
	
int main()
{
	int N, M, c[20][20], S;
	int i, j, k;
	int max[20]={0}, print[20]={0};
	
	//輸入題目所求數值// 
	cin>>N>>M;                  //輸入題目(N=有幾行,M=每行中有幾個) 
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			cin>>c[i][j];      //輸入第i行中第j個數字 
			if(c[i][j]>max[i])
				max[i]=c[i][j]; //取每行中最大的數字=該行max 
		}
	}
	
	//分別求出S，以及會被印出來的數值//	
	S=0;
	for(i=0;i<N;i++)
		S=S+max[i];            //將每行的max加起來=S 
	
	k=0;
	for(i=0;i<N;i++)
	{
		if(S%max[i]==0)        //當S除以max為整數時 
		{	
			print[k]=max[i];   //將該行max加入新陣列print中(會被印出來的數值) 
			k=k+1; 
		} 
	}
	
	//印出題目所求// 
	cout<<S<<endl;              //印出每行max的加總 
	if(k!=0)
		for(i=0;i<k;i++)
			cout<<print[i]<<" ";   //印出可以整除的數字 
	else if(k==0)
		cout<<"-1";               //如果沒有任一行的max可以被整除，則印出-1 
			
	return 0;
}
