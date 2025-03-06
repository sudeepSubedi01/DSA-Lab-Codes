#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int low, int high, vector<int> &list, int target)
{
    if (low > high)
    {
        return -1;
    }

    int midpoint = (low + high) / 2;

    if (list[midpoint] == target)
    {
        return midpoint;
    }
    else if (list[midpoint] < target)
    {
        return binarySearch(midpoint + 1, high, list, target);
    }
    else
    {
        return binarySearch(low, midpoint - 1, list, target);
    }
}

void sort(vector<int> &list)
{
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = i + 1; j < list.size(); j++)
        {
            if (list[i] > list[j])
            {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

int main()
{
    vector<int> list = {1, 2, 3, 54, 32, 6, 4, 234, 2, 423, 22, 34, 322};
    sort(list);
    int position = binarySearch(0, list.size() - 1, list, 322);
    if (position != -1)
    {

        cout << "The number is at position " << position << endl;
        cout << "The number at the position is " << list[position] << endl;
    }
    else
    {
        cout << "The number is not in the list" << endl;
    }

    return 0;
}