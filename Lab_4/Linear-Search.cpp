#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> &list, int target)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> list = {1, 2, 3, 54, 32, 6, 4, 234, 2, 423, 22, 34, 322};
    int position = linearSearch(list, 322);
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