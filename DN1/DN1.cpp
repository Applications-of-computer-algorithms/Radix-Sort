// RADIX SORT ALGORITHM

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// Function to read numbers from a file and store them in a vector
bool readNumbers(vector<unsigned char>& A, string s) {
    ifstream input(s);  //"input.txt"
    int number;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> number;
        A.push_back(number);
        while (isspace(input.peek())) input.get();
    }
    input.close();
    cout << "File successfully read!" << endl;
    return true;
}

// Function to perform counting sort based on a specific bit position
void countingSort(vector <unsigned char>& A, int bitPos) {
    vector <int> count(2, 0);
    for (unsigned int i = 0; i < A.size(); i++) {
        count[(A[i] >> bitPos) & 1] = count[((A[i] >> bitPos) & 1)] + 1;
    }
    count[1] += count[0];

    vector <unsigned char> sortedArray(A.size(), 0);
    for (int i = A.size() - 1; i >= 0; i--) {
        sortedArray[--count[(A[i] >> bitPos) & 1]] = A[i];
    }

    swap(A, sortedArray);
}

// Function to perform binary radix sort
void binaryRadixSort(vector <unsigned char>& A) {
    for (int bitPos = 0; bitPos < 8; bitPos++) {
        cout << "Sorting bit " << bitPos + 1 << endl;
        countingSort(A, bitPos);
    }
}

// Function to print the elements of the vector to an output file
void print(vector <unsigned char> A) {
    ofstream output("out.txt");

    for (int i = 0; i < A.size(); i++)
        output << (int)A[i] << ' ';
}

int main(int argc, const char* argv[]) {
    vector <unsigned char> A;

    if (!readNumbers(A, argv[1])) {
        return 0;
    }

    binaryRadixSort(A);

    print(A);

    return 0;
}