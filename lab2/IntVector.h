//Felix Lidö feli8145

// Labb2, IntVector.h – klassdefinition

#include <initializer_list>
#include <iostream>

struct Node
{
    int data;
    Node* next;
};


class IntVector
{
public:
    IntVector(std::initializer_list<int>);
    IntVector();
    IntVector(const IntVector&);
//
//    void push_back(int);

    int size() const;
    int& operator[](int);
    const int& operator[](int) const;
    IntVector& operator=(const IntVector&);
    friend std::ostream& operator<<(std::ostream&, const IntVector&);

    void push_back(int value);

private:
    Node* head = nullptr;
    int sz = 0;

    int & getDataAt(int index) const;
    Node* getNodeAt(int) const;
};
