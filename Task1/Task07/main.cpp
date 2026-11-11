
#include <iostream>
#include <vector>
using namespace std;

// Find the index of the highest mark.
int highestMarkIndex(const vector<int>& marks) {
    if (marks.empty()) {
        return -1;
    }

    int highest = 0;

    for (int i = 1; i < static_cast<int>(marks.size()); i++) {
        if (marks[i] > marks[highest]) {
            highest = i;
        }
    }

    return highest;
}

// Read-only function using const reference.
void displayMarks(const vector<int>& marks) {
    cout << "Marks: ";

    for (int mark : marks) {
        cout << mark << " ";
    }

    cout << '\n';
}

// Modify the highest mark safely using its index.
void improveHighestMark(vector<int>& marks, int bonus) {
    int index = highestMarkIndex(marks);

    if (index != -1) {
        marks[index] += bonus;
    }
}

int main() {
    vector<int> marks = {75, 88, 92, 81, 85};

    cout << "Original Marks\n";
    displayMarks(marks);

    int index = highestMarkIndex(marks);

    if (index != -1) {
        cout << "Highest Mark: " << marks[index] << '\n';
        cout << "Highest Mark Index: " << index << '\n';
    }

    improveHighestMark(marks, 2);

    cout << "\nAfter Adding Bonus\n";
    displayMarks(marks);

    // Test vector growth.
    marks.push_back(95);

    cout << "\nAfter Adding New Mark\n";
    displayMarks(marks);

    index = highestMarkIndex(marks);

    if (index != -1) {
        cout << "New Highest Mark: " << marks[index] << '\n';
    }

    // Test empty vector.
    vector<int> emptyMarks;

    cout << "\nEmpty Vector Test\n";

    if (highestMarkIndex(emptyMarks) == -1) {
        cout << "No marks available\n";
    }

    return 0;
}
