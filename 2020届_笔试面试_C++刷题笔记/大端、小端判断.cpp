#include <iostream>
using namespace std;
int main_大端_小端() // main_大端_小端
{
	short int c = 0x1122; // 16进制，每个数字占4bit，则两个数字占8bit，即1字节
	char *p = (char *)(&c); // 取单个字节、
	printf("%x \n", p); // 16进制输出
	printf("%x \n", *p);
	printf("%x \n", p + 1);
	printf("%x \n", *(p + 1));
	cout << "Hello World!" << endl;
	//若*p=0x11,则是大端; 若*p=0x22,则是小端......此编译器是小端。
	return 0;
}