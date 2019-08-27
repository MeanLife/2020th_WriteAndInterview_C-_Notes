#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
例如：
　　 1　->　2　->　3　->　4
						  |
　　 5　  　6　  　7　  　8
						  |
　　 9   　 10 　   11 　 12
						  |
　　 13 <-　14　<- 15 <-　16

打印结果为：1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10
*/
template<typename T>
void pirntEdage(vector<vector<T>>& my_matrix, int tR, int tC, int dR, int dC) {
	if (tR == dR) { // same rows，即只有一行
		for (int i = tC; i <= dC; ++i) {
			cout << my_matrix[tR][i] << ",";
		}
	}
	else if (tC == dC) {  // same colums，即只有一列
		for (int i = tR; i <= dR; ++i) {
			cout << my_matrix[i][tC] << ",";
		}
	}
	else {    // print 4 edges
		int curR = tR;
		int curC = tC;
		while (curC != dC) {
			cout << my_matrix[tR][curC] << ", ";
			++curC;
		}
		while (curR != dR) {
			cout << my_matrix[curR][dC] << ", ";
			++curR;
		}
		while (curC != tC) {
			cout << my_matrix[dR][curC] << ", ";
			--curC;
		}
		while (curR != tR) {
			cout << my_matrix[curR][tC] << ", ";
			--curR;
		}
	}
}

template<typename T>
void spiralOrderPrint(vector<vector<T>>& my_matrix) {
	int tR = 0; // 左上角
	int tC = 0;
	int dR = my_matrix.size() - 1;  // 右下角
	int dC = my_matrix[0].size() - 1;
	while (tR <= dR && tC <= dC) {
		pirntEdage(my_matrix, tR++, tC++, dR--, dC--);
	}
}


int main20021231323112213(void)
{
	vector<vector<int>> my_matrix = { {1, 2, 3, 4},
									  {5, 6, 7, 8},
									  {9, 10, 11, 12},
									  {13,14, 15, 16} };
	spiralOrderPrint(my_matrix);

	
	cout << "Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}