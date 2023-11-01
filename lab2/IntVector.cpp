//Felix Lidö feli8145

// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner

#include "IntVector.h"



IntVector::IntVector(std::initializer_list<int> values)
{
    changeSize(data, values.size());
    int i = 0;
    for (int value : values) {
        data[i] = value;
        i++;
    }

}


int IntVector::size() const {
    return 0;
}

int& IntVector::operator[](int index) {
    return data[index];
}

const int& IntVector::operator[](int index) const {
    return data[index];
}

IntVector& IntVector::operator=(const IntVector& other) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, const IntVector& v) {
    return os;
}

void IntVector::changeSize(int arr[], int size) {
    int* temp = new int[size];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

IntVector::IntVector() {
    changeSize(data, 8);
}

IntVector::IntVector(const IntVector& other) {
    changeSize(data, other.size());
    for (int i = 0; i < other.size(); i++) {
        data[i] = other[i];
    }
}

void IntVector::push_back(int num){

}