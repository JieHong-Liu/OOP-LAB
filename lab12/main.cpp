#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
void GET(char memory[], int position, string type, int total_memory);
void SET(char memory[], int position, string type, string value, int total_memory);
void int2hex(int, vector<int> &v, int*);
int main()
{
    int total_memory;
    int instruction;
    cout << "input total memory:";
    cin >> total_memory;
    cout << "input how many instructions:";
    cin >> instruction;
    char *memory = new char[total_memory];
    for (int i = 0; i < total_memory; i++)
    {
        memory[i] = '\0';
    }
    string line;
    string ins; // get,set
    int position;
    string type;
    string value;
    stringstream ss;
    cout << "input your instruction here:" << endl;
    // clear the buffer
    cin.ignore();
    for (int i = 0; i < instruction; i++)
    {
        // initialize the stringstream
        ss.str("");
        ss.clear();

        // input the instruction
        getline(cin, line);
        ss << line; // put line into stringstream
        ss >> ins >> position >> type;

        if (ins == "Get")
        {
            GET(memory, position, type, total_memory);
        }
        else if (ins == "Set")
        {
            ss >> value;
            SET(memory, position, type, value, total_memory);
        }
    }
    return 0;
}
void SET(char memory[], int position, string type, string value, int total_memory)
{
    if (position < 0 || position >= total_memory)
    {
        cout << "Violation Access!" << endl;
    }
    else
    {
        stringstream ss;
        ss.str("");
        ss.clear();
        ss << value;
        if (type == "int" || type == "short")
        {
            int v = 0;
            ss >> v; // convert string value to v;
            vector<int> put_array;
            int size_of_put_array;
            int2hex(v, put_array, &size_of_put_array);
            //cout << "size_of_put_array = " << size_of_put_array << endl;
            for (int i = 0; i < size_of_put_array; i++)
            {
                memory[position + i] = put_array[i];
            }
        }
        else if (type == "char")
        {
            int c;
            ss >> c;
            memory[position] = c;
        }
        else if (type == "String")
        {
            string str;
            ss >> str;
            if (position + str.size() >= total_memory)
            {
                cout << "Violation Access!" << endl;
            }
            for (int i = 0; i < str.size(); i++)
            {
                memory[position + i] = str[i];
            }
        }
    }
}

void int2hex(int value2hex, vector<int>& put_array, int *size_of_put_array)
{
    char *hex_array;
    int temp = value2hex;
    int counter = 0;
    if (value2hex <= 16)
    {
        counter = 1;
        hex_array = new char[1];
        hex_array[0] = value2hex;
    }
    else
    {
        while (temp) // count how many bits
        {
            temp = temp / 16;
            counter++;
        }
        hex_array = new char[counter + 1];
        // initialize the temp and counter
        counter = 0;
        temp = value2hex;
        while (temp)
        {
            hex_array[counter] = temp % 16;
            temp = temp / 16;
            counter++;
        }
    }
    *size_of_put_array = counter / 2;
    // put_array = new int[*size_of_put_array];
    for (int i = 0; i < *size_of_put_array; i++)
    {
        int sum = 0;
        sum = hex_array[i * 2 + 1] * 16 + hex_array[i * 2];
        put_array.push_back(sum);
//        cout << put_array[i] << "\t";
    }
    cout << endl;
}

void GET(char memory[], int position, string type, int total_memory)
{
    if (position < 0 || position >= total_memory)
    {
        cout << "Violation Access!" << endl;
    }
    else
    {
        if (type == "int")
        {
            cout << (int)memory[position] << endl;
        }
        else if (type == "String")
        {
            for (int i = position; (memory[i] != '\0')&&(i < total_memory); i++)
            {
                cout << memory[i];
            }
            cout << endl;
        }
        else if (type == "char")
        {
            cout << (int)memory[position] << endl;
        }
    }
}
