//
// Felix Lidö feli8145
//

#ifndef CPROG_LABS_TRAD_H
#define CPROG_LABS_TRAD_H

#include "stdexcept"
#include <iostream>

template<class T>
class Trad{
public:
    Trad(): rot(0){};

    Trad(T t){
        rot = new Nod(t);
    };

    Trad(const Trad<T> &t){
        kopiera(t);
    };

    ~Trad(){
        delete rot;
    };

    bool tom() const{
        return !rot;
    };

    T &varde() const{
        kolla();
        return rot->data;
    };

    Trad<T> &v_barn() const{
        kolla();
        return *rot->left;
    };

    Trad<T> &h_barn() const{
        kolla();
        return *rot->right;
    };

    Trad<T> &operator=(const Trad<T> &);
    bool operator==(const Trad<T> &) const;
    void skriv_ut();

    void satt_in(T t);
    bool sok(T t);


private:
    class Nod{
        friend class Trad<T>;
        T data;
        Trad<T> *left, *right;
        Nod(T t ): data(t), left(new Trad<T>), right(new Trad<T>){};
        ~Nod()
        {
            delete left;
            delete right;
        };
    };

    Nod *rot;
    void kolla() const{
        if(tom()){
            throw std::range_error("Trad");
        }
    };
    void kopiera(const Trad<T> &t);
};

#include "Trad.h"

template<class T>
void Trad<T>::satt_in(T t) {
    if(tom()){
        rot = new Nod(t);
        return;
    }

    if(t < rot->data){
        v_barn().satt_in(t);
        return;
    }

    if(t > rot->data){
        h_barn().satt_in(t);
        return;
    }

}

template<class T>
bool Trad<T>::sok(T t) {
    if(tom()){
        return false;
    }


    if(rot->data == t){
        return true;
    }

    if(t < rot->data){
        return v_barn().sok(t);
    }

    if(t > rot->data){
        return h_barn().sok(t);
    }

    return false;
}

//Assignment includes this in cpp
template<class T>
Trad<T> &Trad<T>::operator=(const Trad<T> &t) {
    if(rot != t.rot){
        delete rot;
        kopiera(t);
    }
    return *this;
}

//Assignment includes this in cpp
template<class T>
bool Trad<T>::operator==(const Trad<T> &t) const {

    return (tom() && t.tom()) ||
           (!tom() && !t.tom() &&
            varde() == t.varde() &&
            v_barn() == t.v_barn() &&
            h_barn() == t.h_barn());
}

//Assignment includes this in cpp
template<class T>
void Trad<T>::skriv_ut() {
    if(!tom()){
        v_barn().skriv_ut();
        std::cout << varde() << " ";
        h_barn().skriv_ut();
    }
}

//Assignment includes this in cpp
template<class T>
void Trad<T>::kopiera(const Trad<T> &t) {
    if(t.tom()){
        rot = 0;
        return;
    }

    rot = new Nod(t.varde());
    v_barn().kopiera(t.v_barn());
    h_barn().kopiera(t.h_barn());
}

#endif //CPROG_LABS_TRAD_H
