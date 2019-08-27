#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
7.memcpy:拷贝某段内存
思路：一个一个的拷贝
***************************************/
// 指针法
static void * my_memcpy(const void * source ,void * dest, size_t len)
{
	if (dest == nullptr || source == nullptr)
	{
		return nullptr;
	}
	
	char *pdest = (char *)(dest);
	char *psor = (char *)(source);
	char *plast = (char *)(source) + len;
	while (psor < plast)
	{
		*pdest++ = *psor++;
	}
	return dest;
}


int main_my_memcpy(void)
{
	char str[50] = "fengcong is fucking too handsome";
	char dest[50] = { 0 };
	char *pstr = dest;  //在栈上开辟一段内存，数组指针

	cout << (char *)my_memcpy(str, pstr, 30) << endl;
	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}