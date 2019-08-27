#include<iostream>
using namespace std;
int a[100] = { 1,2,3,5,12,12,12,15,29,55 };//数组中的数（由小到大）
int k;//要找的数字
int found(int low, int high)
{
	int mid = low + (high - low) / 2;
	if (low > high)//查找完毕没有找到答案，返回-1
		return -1;
	else
	{
		if (a[mid] == k)
			return mid;//找到!返回位置.
		else
			return a[mid] > k ? found(low, mid - 1) : found(mid + 1, high);
		//else if (a[mid] > k)
		//	return found(low, mid - 1);//找左边
		//else
		//	return found(mid + 1, high);//找右边
	}
}
//int BinSearch(SeqList *R，int n, KeyType K)
//{
//	//在有序表R[0..n-1]中进行二分查找，成功时返回结点的位置，失败时返回-1
//	int low = 0, high = n - 1, mid；     //置当前查找区间上、下界的初值
//		while (low <= high)
//		{
//			if (R[low].key == K)
//				return low;
//			if (R[high].key == k)
//				return high;          //当前查找区间R[low..high]非空
//			mid = low + (high - low) / 2;
//			/*使用(low+high)/2会有整数溢出的问题
//			（问题会出现在当low+high的结果大于表达式结果类型所能表示的最大值时，
//				这样，产生溢出后再/2是不会产生正确结果的，而low+((high-low)/2)
//				不存在这个问题*/
//			if (R[mid].key == K)
//				return mid;             //查找成功返回
//			if (R[mid].key < K)
//				low = mid + 1;              //继续在R[mid+1..high]中查找
//			else
//				high = mid - 1;             //继续在R[low..mid-1]中查找
//		}
//	if (low > high)
//		return -1;//当low>high时表示所查找区间内没有结果，查找失败
//}

int main_二分法()
{
	cin >> k;//输入要找的数字   c语言把cin换为scanf即可
	cout << found(0, 9);//从数组a[0]到a[9]    c语言把cout换为printf即可
	return 0;
}