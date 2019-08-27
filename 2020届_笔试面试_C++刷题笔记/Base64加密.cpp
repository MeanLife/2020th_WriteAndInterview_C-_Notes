#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

static const string BASE64CODE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

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
			ans += t - 10 + 'a'; // 大小写：'a'与'A'互换
		}
		n /= radix;
	} while (n != 0);    //使用do{}while（）以防止输入为0的情况
	reverse(ans.begin(), ans.end());
	while (ans.size() < 8) // 补齐8位使用
	{
		ans = "0" + ans;
	}
	return ans;
}

static string encode(string &data)
{
	if (data.size() == 0)
	{
		return data;
	}
	vector<int> ASCII;
	string BINARY = "";
	for (auto it : data)
	{
		ASCII.push_back((int)it); // 转为ASCII码
		BINARY += TenToredix(ASCII.back(), 2); // 将ASCII码转为2进制。
	}
	//若长度不能被6整除，则在低位补0到能被6整除为止
	while (BINARY.size() % 6 != 0)
	{
		BINARY += "0";
	}
	//按6个一组拆分成字串数组
	vector<string> BINARY_6;
	string temp = "";
	while (BINARY.size() / 6 > 0)
	{
		temp = BINARY.substr(0, 6);
		BINARY = BINARY.substr(6);
		BINARY_6.push_back(temp);
	}
	// 确定最终补位长度
	int overLen = 0;
	if (data.size() % 3 != 0)
	{
		overLen = 3 - data.size() % 3;
	}
	// 存放编码结果
	vector<int> index(BINARY_6.size(), 0);
	string code(index.size() + overLen , 0);
	for (int i = 0; i < BINARY_6.size(); i++)
	{
		// 将二进位转换成十进制数字
		index[i] = radixToTen(BINARY_6[i], 2);
		//Base64 : Value -> Encoding
		code[i] = BASE64CODE[index[i]];
	}
	// 补位‘=’
	switch (overLen)
	{
	case 2:
		code[code.size() - 2] = '=';//不需要break
	case 1:
		code[code.size() - 1] = '=';
	default:
		break;
	}
	return code;
}

int main_Base64加密(void)
{
	string input;
	while (cin >> input)
	{
		cout << encode(input) << endl;
	}
	return 0;
}

// 解密
//public static String decode(String srcData) {
//	//检测元数据中“=”的个数，并将之去除
//	int counter = 0;
//	if (srcData.contains("=")) {
//		counter = 1;
//		if (srcData.substring(srcData.length() - 2, srcData.length() - 1).equals("=")) {
//			counter = 2;
//		}
//	}
//	srcData = srcData.replaceAll("=", "");
//	//将密文根据Base64编码表转换成对应Value，再转换成二进位 ，然后将所有二进位补足6位，最后将所有二进位存进一个字串
//	char[] srcCh = srcData.toCharArray();
//	StringBuffer bin6SB = new StringBuffer();
//	int index;
//	String bin6Str;
//	for (int i = 0; i < srcCh.length; i++) {
//		//获得Base64编码表的Value
//		index = base64Code.indexOf(srcCh[i]);
//		//将Value转为二进位
//		bin6Str = Integer.toBinaryString(index);
//		//在长度不足6位的二进位的高位上补0直到补足6位，再保存进字串
//		while (bin6Str.length() < 6) {
//			bin6Str = "0" + bin6Str;
//		}
//		bin6SB.append(bin6Str);
//	}
//	String bin6Str_all = bin6SB.toString();
//	//如果二进位字串后有多补的0，将之去除
//	if (counter == 1) {
//		bin6Str_all = bin6Str_all.substring(0, bin6Str_all.length() - 2);
//	}
//	else if (counter == 2) {
//		bin6Str_all = bin6Str_all.substring(0, bin6Str_all.length() - 4);
//	}
//	//按8个一组拆分成字串数组
//	List<String> bin8List = new ArrayList<String>();
//	String temp;
//	while (bin6Str_all.length() / 6 > 0) {
//		temp = bin6Str_all.substring(0, 8);
//		bin6Str_all = bin6Str_all.substring(8);
//		bin8List.add(temp);
//	}
//	String[] bin8Str = bin8List.toArray(new String[bin8List.size()]);
//	//将该字串数组的每个元素（即一组二进位）转成十进制数，再强制转换成char类型
//	char[] ascii = new char[bin8Str.length];
//	for (int i = 0; i < ascii.length; i++) {
//		ascii[i] = (char)Integer.parseInt(bin8Str[i], 2);
//	}
//	return String.valueOf(ascii);
//}
