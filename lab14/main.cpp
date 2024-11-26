#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
using namespace std;

std::vector<int>getNumbersFromFile(string fileName)
{
    fstream ofs(fileName, ios::in);
    vector<int>numbers(0);
    if (ofs.is_open())
    {
        int aa;
        while(ofs>>aa)
            numbers.push_back(aa);
        ofs.close();
    }
    else
    {
        throw "�� ������� ������� ����!!!" ;
    }
    return numbers;
}

template<typename T>
void printVector(vector<T>numbers)
{
    for (T value : numbers)
        cout << value << "  ";
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int>a = getNumbersFromFile("1.txt");
    printVector(a);
    int n;
    cout << "������� n = "; cin>>n;
    int coutOfn = count(a.begin(), a.end(), n);
    cout << "����� " << n << " ����������� " << coutOfn << " ���. " << endl;
    cout << "������� ����� " << n << ": ";
    auto iter = a.begin();
    while (iter <= a.end())
    {
        iter = std::find(iter, a.end(), n);
        if (iter != a.end())
            cout << iter-a.begin()<< " ";
        iter++;
    }
    cout << endl;
    int c1 = std::count_if(
        a.begin(),
        a.end(),
        [](int c) {
            return (c%2 == 0);
        }
    );
    cout << "���������� ������ �����:  " << c1 << endl;
    iter = a.begin();
    cout << "������� ������ ���������:  ";
    while (iter <= a.end())
    {
        iter = find_if(iter, a.end(), [](int value){ return value % 2 == 0; });
        if (iter != a.end())
            cout << iter-a.begin()<< " ";
        iter++;
    }
    cout << endl;
    int c2 = std::count_if(
        a.begin(),
        a.end(),
        [](int c) {
            return (c%2 != 0);
        }
    );
    cout << "���������� �������� �����:  " << c2<<  endl;
    iter = a.begin();
    cout << "������� �������� ���������:  ";
    while (iter <= a.end())
    {
        iter = find_if(iter, a.end(), [](int value){ return value % 2 != 0; });
        if (iter != a.end())
            cout << iter-a.begin()<< " ";
        iter++;
    }
    cout << endl;
    int sum = 0;
    if (c1>c2)
    {
        sum = accumulate(a.begin(), a.end(), 0,
        [](int c, int sum) {
            if ((sum % 2) == 0) {
                return c + sum;
            } else {
                return c;
            }
        });
        cout << "����� ������ ���������:  " << sum <<endl;
    }
    else
    {
        sum = accumulate(a.begin(), a.end(), 0);
        cout << "����� ���� ���������:  " <<sum <<endl;
    }

    cout << "��������������� ������ " << endl;
    vector<int>l;
    l.resize(a.size());
    std::copy(a.rbegin(), a.rend(), l.begin());
    std::sort(l.begin(), l.end());
    printVector(l);
    cout << "������ ����� ������������ ������� � ����������" << endl;
    std::swap(*a.begin(), *(a.end()-1));
    printVector(a);
    return 0;
}
