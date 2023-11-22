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