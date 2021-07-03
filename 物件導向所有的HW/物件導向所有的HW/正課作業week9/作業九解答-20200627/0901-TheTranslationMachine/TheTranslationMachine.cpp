//Project : The Translation Machine
//Create : Cheryl Huang
//Date : 20200123
//E-mail : m10815032@gapps.ntust.edu.tw

#include <iostream>
using namespace std;

int ruleTable[26][26];
int isChecked[26], canTranslate[26];

int getCharNum(char c);
int getLength(char* str);
void clearArrays();

int main(void) {
	int m, n;
	cin >> m >> n;
	while (m > 0 && n > 0)
	{
		for (int i = 0; i < 26; i++) 	// init
		{
			for (int j = 0; j < 26; j++) ruleTable[i][j] = 0;
			ruleTable[i][i] = 1;
			isChecked[i] = 0;
			canTranslate[i] = 0;
		}
		for (int i = 0; i < m; i++) 	// put in rules
		{
			char x, y;
			cin >> x >> y;
			ruleTable[getCharNum(x)][getCharNum(y)] = 1;	// input rules
		}

		for (int k = 0; k < n; k++) 	// for each task cases
		{
			int j = 0;
			bool flag = true;
			char str1[50] = "";
			char str2[50] = "";
			cin >> str1 >> str2;

			if (getLength(str1) != getLength(str2)) 	// don't have the same length
			{
				flag = false;
			}
			else 	// have same lengths
			{
				int length = getLength(str1);

				for (j = 0; j < length; j++) 		// for each character
				{
					int num1 = getCharNum(str1[j]);
					int num2 = getCharNum(str2[j]);

					if (num1 != num2) 				// not the same character
					{
						int ch = num1;
						bool findNext = false;

						bool checkDone = false;
						while (!checkDone) 
						{
							for (int i = 0; i < 26; i++) 		// run the row of character 'ch' rules
							{
								if (ruleTable[ch][i]) 
								{
									canTranslate[i] = 1;
									if (num2 == i) 
									{
										checkDone = true;		// can translate
										clearArrays();
										break;
									}
								}
							}
							if (checkDone) break;
							isChecked[ch] = 1;
							for (int i = 0; i < 26; i++) 
							{
								if (!isChecked[i] && canTranslate[i]) 
								{
									ch = i;				// next character
									findNext = true;
									break;
								}
								else findNext = false;
							}
							if (!findNext) 
							{
								checkDone = true;		// can't translate
								clearArrays();
								flag = false;
							}
						} // while (!checkDone)
					}
				}
			}	// have same length

			if (flag) 
				cout << "yes" << endl;
			else 
				cout << "no" << endl;

		} // for n tast cases

		cin >> m >> n;
	}
	return 0;
}

int getCharNum(char c)
{
	if (c >= 'a' && c <= 'z') 
		return ((int)c - 'a');
	else 
		return -1;
}

int getLength(char* str)
{
	int num = 0;
	while (str[num] != '\0') num++;
	return num;
}

void clearArrays()
{
	for (int i = 0; i < 26; i++)
	{
		canTranslate[i] = 0;
		isChecked[i] = 0;
	}
}