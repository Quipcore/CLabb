//Felix Lidö feli8145

// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner

#include "IntVector.h"

IntVector::IntVector(std::initializer_list<int> values)
{
    for (int value : values)
    {
        push_back(value);
    }
}

IntVector::IntVector(const IntVector &other) {
    sz = other.sz;
    head = other.head;
}

IntVector::IntVector() {

}

int IntVector::size() const {
    return sz;
}

Node* IntVector::getNodeAt(int index) const{
    Node* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp;
}

int & IntVector::getDataAt(int index) const {
    Node* node = getNodeAt(index);
    return node->data;
}

int &IntVector::operator[](int index) {
    return getDataAt(index);
}

const int &IntVector::operator[](int index) const {
    return getDataAt(index);
}

IntVector &IntVector::operator=(const IntVector &other) {
    sz = 0;
    head = nullptr;
    for(int i = 0; i < other.sz; i++){
        push_back(other[i]);
    }

    return *this;
}

std::ostream &operator<<(std::ostream &ostream, const IntVector &vector) {
    for(int i = 0; i < vector.sz; i++){
        ostream << vector[i] << " ";
    }
    return ostream;
}

void IntVector::push_back(int value) {
    sz++;
    Node* node = new Node();
    node->data = value;
    node->next = nullptr;

    if(head == nullptr){
        head = node;
    }else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = node;
    }
}











