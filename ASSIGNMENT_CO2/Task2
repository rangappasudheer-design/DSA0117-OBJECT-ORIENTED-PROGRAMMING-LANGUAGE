
#include <iostream>
#include <vector>
using namespace std;

// Return reference to the highest mark
int& highestMark(int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
        {
            highest = i;
        }
    }

    return marks[highest];
}

// Return const reference
const int& highestMarkConst(const int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
        {
            highest = i;
        }
    }

    return marks[highest];
}

// Return a copy
int highestMarkCopy(const int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
        {
            highest = i;
        }
    }

    return marks[highest];
}

// Dangerous example: returning local reference
int& dangerousFunction()
{
    int value = 50;
    return value; // Dangling reference: undefined behaviour
}

int main()
{
    int marks[5] = {75, 82, 91, 68, 88};

    cout << "Original marks: ";

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    cout << "\nHighest mark: "
         << highestMark(marks, 5) << endl;

    // Modify highest mark directly
    highestMark(marks, 5) += 2;

    cout << "After moderation: ";

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    cout << "\nConst reference result: "
         << highestMarkConst(marks, 5) << endl;

    cout << "Copy result: "
         << highestMarkCopy(marks, 5) << endl;

    // Vector example
    vector<int> studentMarks = {70, 80, 90};

    int& ref = studentMarks[2];

    cout << "Before vector growth: " << ref << endl;

    studentMarks.push_back(95);

    cout << "Vector size after growth: "
         << studentMarks.size() << endl;

    cout << "Do not use ref after possible reallocation.\n";

    return 0;
}
