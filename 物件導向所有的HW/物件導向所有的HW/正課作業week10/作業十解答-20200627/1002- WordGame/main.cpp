#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

const int step[8][2] = { {-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1} };

bool compareSup(vector<string> input, int indexX, int indexY, string compareWord, int wordIndex) {
	if (compareWord.length() == wordIndex) return false;
	input[indexX][indexY] = 0;
	int newX = -1, newY = -1, next = wordIndex + 1;
	for (int i = 0; i < 8; i++) {
		newX = indexX + step[i][0];
		if (newX < 0 || newX >= 4)continue;
		newY = indexY + step[i][1];
		if (newY < 0 || newY >= 4)continue;
		if (input[newX][newY] == 0)continue;
		if (input[newX][newY] == compareWord[wordIndex]) {
			if (compareWord.length() == next) {
				cout << compareWord << endl;
				return true;
			}
			//表示已經找到組合
			if (compareSup(input, newX, newY, compareWord, next))return true;
		}
	}
	return false;
}

int main() {
	string fileName = "words.txt";//檔案名稱
	ifstream in(fileName);	
	if (in) {
		vector<string>datas;
		string data = "";
		while (getline(in, data)) {
			datas.push_back(data);
		}
		in.close();
		vector<string> input;//輸入的字
		string rowData = "";
		int times = 4;
		while (cin >> rowData) {
			input.push_back(rowData);
			times--;
			if (times == 0) {
				for (int i = 0; i < datas.size(); i++) {
					data = datas[i];
					for (int i = 0, x = 0, y = 0; i < 16; i++, x = i / 4, y = i % 4)
						if (input[x][y] == data[0])
							if (compareSup(input, x, y, data, 1))
								break;
				}
				input.clear();
				times = 4;
			}
		}
	}
	return 0;
}