#include <iostream>
using namespace std;
class matrix
{
public:
    matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
    }
    int getRows() const
    {
        return this->row;
    }
    int getCols() const
    {
        return this->col;
    }

private:
    int row;
    int col;
};
int main()
{
    int first_row, first_col, second_row, second_col;
    cin >> first_row >> first_col >> second_row >> second_col;
    matrix first(first_row, first_col), second(second_row, second_col);

    // dynamic declare two dimensions array1 (動態宣告二維陣列)
    int **array1 = new int *[first.getRows()];
    for (int i = 0; i < first.getRows(); i++)
    {
        array1[i] = new int[first.getCols()];
    }
    // dynamic declare two dimensions array2 (動態宣告二維陣列)
    int **array2 = new int *[second.getRows()];
    for (int i = 0; i < second.getRows(); i++)
    {
        array2[i] = new int[second.getCols()];
    }

    // input the array1
    for (int i = 0; i < first.getRows(); i++)
    {
        for (int j = 0; j < first.getCols(); j++)
        {
            cin >> array1[i][j];
        }
    }
    // and array2
    for (int i = 0; i < second.getRows(); i++)
    {
        for (int j = 0; j < second.getCols(); j++)
        {
            cin >> array2[i][j];
        }
    }

    // print array1
    for (int i = 0; i < first.getRows(); i++)
    {
        for (int j = 0; j < first.getCols(); j++)
        {
            cout << array1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    // print array2
    for (int i = 0; i < second.getRows(); i++)
    {
        for (int j = 0; j < second.getCols(); j++)
        {
            cout << array2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    if (first.getCols() != second.getRows())
    {
        cerr << "Matrix multiplication failed." << endl;
    }
    else
    {
        matrix ans(first.getRows(), second.getCols());
        int **ans_array = new int *[first.getRows()];
        for (int i = 0; i < first.getRows(); i++)
        {
            ans_array[i] = new int[second.getCols()];
        }
        for (int i = 0; i < ans.getRows(); i++)
        {
            for (int j = 0; j < ans.getCols(); j++)
            {
                ans_array[i][j] = 0;
            }
        }
        for (int i = 0; i < ans.getRows(); i++)
        {
            for (int j = 0; j < ans.getCols(); j++)
            {
                int sum = 0;
                for (int k = 0; k < second.getRows(); k++)
                {
                    sum += array1[i][k] * array2[k][j];
                }
                ans_array[i][j] = sum;
            }
        }
        cout << "Ans array: " << endl;
        for (int i = 0; i < ans.getRows(); i++)
        {
            for (int j = 0; j < ans.getCols(); j++)
            {
                cout << ans_array[i][j] << "\t";
            }
            cout << endl;
        }

        // delete ans_array
        for (int i = 0; i < ans.getRows(); i++)
        {
            delete[] ans_array[i];
        }
        delete[] ans_array;
    }

    // delete array1
    for (int i = 0; i < first.getRows(); i++)
    {
        delete[] array1[i];
    }
    delete[] array1;

    for (int i = 0; i < second.getRows(); i++)
    {
        delete[] array2[i];
    }
    delete[] array2;

    return 0;
}
