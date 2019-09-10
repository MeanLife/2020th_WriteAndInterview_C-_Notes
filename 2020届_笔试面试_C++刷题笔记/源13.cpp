//#include <iostream>
//#include <string>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//static int search(vector<int> &array, int size, int target, int flag)
//{
//	int left = 0, right = size - 1;
//	int mid = 0, last = -1;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (array[mid] > target) {
//			right = mid - 1;
//		}
//		else if (array[mid] < target) {
//			left = mid + 1;
//		}
//		else {
//			last = mid;
//			if (flag == 0) {//找第一个值等于target的索引
//			   //在左边继续查找
//				right = mid - 1;
//			}
//			else if (flag == 1) {//找最后一个值等于target的索引
//			  //在右边继续查找
//				left = mid + 1;
//			}
//		}
//	}
//	return last;
//}
//static int function(vector<int> &array, int num)
//{
//	int len = array.size();
//	int first = search(array, len, num, 0);
//	int last = search(array, len, num, 1);
//	if (first == -1) {
//		return 0;
//	}
//	return last - first + 1;
//}
//int main(void)
//{
//	vector<int> a= { 1,2,3,3,3,3,4,5 };
//	int num = 3;
//
//	cout << function(a, num) << endl;
//
//	return 0;
//}