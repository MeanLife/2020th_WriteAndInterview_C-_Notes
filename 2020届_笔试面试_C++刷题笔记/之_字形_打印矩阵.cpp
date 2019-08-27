#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

template<typename T>
void printMatrix(vector<vector<T>>& my_matrix) {
	for (int i = 0; i < my_matrix.size(); ++i) {
		for (int j = 0; j < my_matrix[0].size(); ++j) {
			cout << my_matrix[i][j] << ",";
		}
	}
}
/*
给定一个矩阵matrix,按照“之”字形的方式打印这个矩阵,例如: 1 2 3 4 5 6 7 8 9 10 11 12.
“之”字形打印的结果为:1,2,5,9,6,3,4,7,10,11,8,12额外空间复杂度为O(1) O(1)O(1).

上坐标（tR，tC）的初始为（0,0），先沿着矩阵的第一行移动（tC++）,当达到第一行最右边的元素后，再沿着矩阵最后一列移动 (tR++)。
下坐标（dR，dC）的初始为（0,0），先沿着矩阵的第一列移动（dR++），当到达第一列最下边的元素时，再沿着矩阵的最后一行一定（dC++）。
上坐标与下坐标同步移动，每次移动后的上坐标与下坐标的连线就是矩阵中的一条斜线，打印斜线上的元素即可。
如果上次斜线是从左下向右上打印的，这次一定是从右上向左下打印，反之亦然。总之，可以把打印的方向用bool变量表示，每次取反即可。

参考博客：<https://blog.csdn.net/alxe_made/article/details/90712149>
*/
template<typename T>
void printLevel(vector<vector<T>>& my_matrix, int tR, int tC, int dR, int dC, bool updown) 
{
	if (updown) {
		while (tR != dR + 1) {
			cout << my_matrix[tR++][tC--] << ",";
		}
	}
	else {
		while (dR != tR - 1) {
			cout << my_matrix[dR--][dC++] << ",";
		}
	}
}

template<typename T>
void printMatrixZigZag(vector<vector<T>>& my_matrix) {
	int tR = 0;
	int tC = 0;
	int dR = 0;
	int dC = 0;
	bool updown = false;
	int endR = my_matrix.size() - 1;
	int endC = my_matrix[0].size() - 1;
	while (tR < endR + 1) 
	{
		printLevel(my_matrix, tR, tC, dR, dC, updown);
		tR = (tC == endC ? tR + 1 : tR); // 是否到了最后一列？到了，行+1
		tC = (tC == endC ? tC : tC + 1); // 是否到了最后一列？到了，列不变
		dC = (dR == endR ? dC + 1 : dC); // 是否到了最后一行？到了，列+1
		dR = (dR == endR ? dR : dR + 1); // 是否到了最后一行？到了，行不变
		updown = !updown; // ！表示逻辑取反，~表示按位取反
	}
	cout << "\n";
}


int main011222000315220505202(void)
{
	vector<vector<int>> my_matrix = { {1, 2, 3, 4},
									  {5, 6, 7, 8},
									  {9, 10,11,12} };
	cout << "origin matrix is:" << endl;
	printMatrix(my_matrix);
	cout << "\n";
	cout << "zigzig matrix is:" << endl;
	printMatrixZigZag(my_matrix);

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}