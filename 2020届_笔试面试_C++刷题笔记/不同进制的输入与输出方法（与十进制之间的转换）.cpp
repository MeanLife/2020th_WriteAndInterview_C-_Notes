#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

/***************************************
1.C中指定格式输出
	printf("%05o\n",35);    //按八进制格式输出，保留5位高位补零
	printf("%03d\n",35);    //按十进制格式输出，保留3位高位补零
	printf("%05x\n",35);    //按十六进制格式输出，保留5位高位补零

2.C++中指定格式输出
	cout << "35的8进制:" << std::oct << 35<< endl;
	cout << "35的10进制" << std::dec << 35 << endl;
	cout << "35的16进制:" << std::hex << 35 << endl;
	cout << "35的2进制: " << bitset<8>(35) << endl;      //<8>：表示保留8位输出

二.C/C++各种进制转换库函数
1.strol()函数（可以将一个任意的2-36进制字符串转换为十进制数）：
	函数原型：long int strtol(const char *nptr, char **endptr, int base)
	格式：base是要转化的数的进制，非法字符会赋值给endptr，nptr是要转化的字符，
	例子：
	char a[20]="10549stend#12";
	char *stop;
	int ans=strtol(a, &stop, 8);   //将八进制数"1054"转成十进制，后面均为非法字符
2.itoa（）函数（可以将一个10进制数转换为任意的2-36进制字符串）:
	函数原型：char*itoa(int value,char*string,int radix);
	格式：itoa(num, str, 2); num是一个int型的，是要转化的10进制数，str是转化结果，后面的值为目标进制。
	例子：
	int num = 10;
	char str[100];
	_itoa(num, str, 2);  //c++中一般用_itoa，用itoa也行,
3.sprintf()函数（可以将一个10进制数转换为指定格式的n进制字符串）：
	函数原型：int sprintf( char *buffer, const char *format, [ argument] … )
	例子：
	char s[100]={0};
	sprintf(s, "%d", 123); //十进制输出产生"123"
	sprintf(s, "%4d%4d", 123, 4567); //指定宽度不足的左边补空格，产生：" 1234567"
	sprintf(s, "%8o", 123);    //八进制输出，宽度占8个位置
	sprintf(s, "%8x", 4567); //小写16 进制，宽度占8 个位置，右对齐
	sprintf(s, "%10.3f", 3.1415626); //产生：" 3.142"
	int i = 100;
	sprintf(s, "%.2f", i);    //注意这是不对的
	sprintf(s, "%.2f", (double)i);    //要按照这种方式才行
***************************************/

/***************************************
// 任意2~36进制数转化为10进制（任意进制转十进制）
// s:是输入的radix进制的字符串，不带前缀，比如0x
// ans:返回10进制的数。
***************************************/
static int radixToTen(string s, int radix)
{
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		char t = s[i];
		if (t >= '0'&&t <= '9')
		{
			ans = ans * radix + t - '0';
		}
		else
		{
			ans = ans * radix + t - 'A' + 10; // 大小写：'a'与'A'互换
		}
	}
	return ans;
}
/***************************************
// 将10进制数转换为任意的radix进制数（十进制转任意进制）
// n:是输入的待转的十进制的整形
// ans:返回radix进制的字符串，不带前缀，比如0x
***************************************/
static string TenToredix(int n, int radix)
{
	string ans = "";
	do 
	{
		int t = n % radix;
		if (t >= 0 && t <= 9)
		{    
			ans += t + '0';
		}
		else 
		{
			ans += t - 10 + 'A'; // 大小写：'a'与'A'互换
		}
		n /= radix;
	} while (n != 0);    //使用do{}while（）以防止输入为0的情况
	reverse(ans.begin(), ans.end());
	//while (ans.size() < 8) // 补齐8位使用
	//{
	//	ans = "0" + ans;
	//}
	return ans;
}

int main_任意进制与十进制相互转换(void)
{
	//int input;
	//while (cin >> hex >> input) // a or A
	//{
	//	cout << dec << input << endl; // 10 and 10
	//	cout << hex <<input << endl; // A or a
	//	cout << hex << setiosflags(ios::uppercase) << input << endl; // A and A
	//	printf("%x\n", input); // a and a
	//	printf("%d\n", input); // 10 and 10
	//	cout << endl;
	//}

	int input;
	cin >> input;
	string str = TenToredix(input, 16);
	cout << "str = " << str << endl;

	string input2;
	cin >> input2;
	int out = radixToTen(input2, 16);
	cout << "out = " << out << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}