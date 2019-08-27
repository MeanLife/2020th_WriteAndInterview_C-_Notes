#include <iostream>
using namespace std;
int main_大端_小端() {
	int c = 0x12345; // 16进制输入
	char *a = (char *)(&c); // 取单个字节、
	printf("%x \n", a); // 16进制输出
	printf("%x \n", *a);
	printf("%x \n", a + 1);
	printf("%x \n", *(a + 1));
	cout << "Hello World!" << endl;

	return 0;
}