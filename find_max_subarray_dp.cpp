/*
Dynamic programming

Algorithms HW1-2 -  non-recursive version program作業
題目說明：
求出一串數字中，連續區間中的和的最大值為多少？
請將課本方法以非遞迴(HW1-2)實現，程式直接讀取測資並以螢幕輸出。

輸入：
第1行為一個整數n，接下來輸入n 個整數，n不超過100000

輸出：
給出這一串數字裡最大的連續區間index(從零開始)以及他們的和，數字之間以空白鍵區隔。

輸入範例：
16
13 -3 -25 20 -3 -16 -23 18 20 -1 12 -5 -22 15 -4 7
8
1 2 3 4 5 6 7 -7

輸出範例：
7 10 49
0 6 28
*/
#include <iostream>
using namespace std;
int start_index, end_index,sum;
void bottom_up_cut_rod(int Arr[], int n)
{	
	start_index = 0;
	end_index = 0;
	   int dpArr[n];
	   int temp = 0;

	   sum = Arr[0];
	   dpArr[0] = Arr[0];
	   for (int i = 1; i < n; i++)
	   {
	   		if (dpArr[i - 1] <= 0)
	   		{
	   			dpArr[i] = Arr[i];  
            	temp = i;
	   		}
	   		else{  
            	dpArr[i] = Arr[i] + dpArr[i - 1];
            }
		    if(dpArr[i] > sum) 
		    {  
		        sum = dpArr[i]; 
		        start_index = temp; 
		        end_index = i; 
		    }  
	}
}
int main ()
{
   	while (1){
	   int n;
	   cin >> n;
	   if (cin.fail())
	   {
	      break;
	   }
	   int Arr[n] ; 
	   for (int i = 0; i < n; i++)
	   {
	      cin >> Arr[i];
	   }
	   bottom_up_cut_rod(Arr, n);
	   cout << start_index <<" " << end_index << " " << sum <<endl;  
   	}
   	return 0;
}