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



#endif //CPROG_LABS_TRAD_H
