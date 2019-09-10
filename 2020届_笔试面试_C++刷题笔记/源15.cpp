//#include <iostream>  
//using namespace std;
//
//int num_of_1(int n) // µÚËÄÌâ
//{
//	int pow1 = 1;
//	int pow2 = 10 * pow1;
//	int  count = 0;
//	while (n >= pow1) {//  
//		int pow2 = 10 * pow1;
//		switch ((n % pow2) / pow1) {
//		case 0:
//			count += (n / pow2) * pow1;
//			break;
//		case 1:
//			count += (n / pow2) * pow1;
//			count += n % pow1 + 1;
//			break;
//		default:
//			count += (n / pow2 + 1) * pow1;
//		}
//		pow1 *= 10;
//	}
//	return count;
//}
//
//int main()
//{
//	cout << num_of_1(12) << endl;
//	getchar();
//	return 0;
//}