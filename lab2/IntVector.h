//Felix Lidö feli8145

// Labb2, IntVector.h – klassdefinition

#include <initializer_list>
#include <iostream>

class IntVector
{
public:
    IntVector(std::initializer_list<int>);
    IntVector();
    IntVector(const IntVector&);

    void push_back(int);

    int size() const;
    int& operator[](int);
    const int& operator[](int) const;
    IntVector& operator=(const IntVector&);
    friend std::ostream& operator<<(std::ostream&, const IntVector&);
private:
    void changeSize(int[], int);
    int data[8];
};
