#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputStream;
    ofstream outputStream;
    inputStream.open("inputfile.txt");
    outputStream.open("outputfile.txt", ios::app);
    int first, second, third;
    inputStream >> first >> second >> third;
    outputStream << "The sum of the first three is " << (first + second + third) << endl;
    inputStream.close();
    outputStream.close();
    return 0;
}
