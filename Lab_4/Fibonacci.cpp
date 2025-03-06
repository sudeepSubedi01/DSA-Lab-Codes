#include <iostream>
#include <vector>

using namespace std;

void recursiveFibonacci(int n, vector<int> &series)
{
    if (series.size() == n)
    {
        return;
    }

    if (series.size() < 2)
    {
        series.push_back(series.size());
    }
    else
    {
        series.push_back(series[series.size() - 1] + series[series.size() - 2]);
    }

    recursiveFibonacci(n, series);
}

vector<int> fibonacci(int n)
{
    vector<int> series;
    recursiveFibonacci(n, series);
    return series;
}

int main()
{
    int n = 7;
    cout << "Fibonacci series: ";

    vector<int> series = fibonacci(n);

    for (int i = 0; i < series.size(); i++)
    {
        cout << series[i] << " ";
    }
    cout << endl;

    return 0;
}