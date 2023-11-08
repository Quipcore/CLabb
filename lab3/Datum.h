//
// Felix Lidö feli8145
//
// Labb3, Datum.h – klassdefinition

#ifndef DATUM_H
#define DATUM_H

#include <array>
#include <iostream>

class Datum
{
    friend std::ostream &operator<<(std::ostream &, const Datum & );
    friend Datum operator+(const int left, const Datum& right);

    unsigned int year;
    unsigned int month;
    unsigned int day;

    // Deklaration av statisk privat medlem, "ant_dagar per månad"
    static const std::array< unsigned int, 13 > ANT_DAGAR_PER_MAANAD;


public:
    Datum( int, int, int );
    Datum();
    Datum(const Datum&);
    void set_date( int, int, int ); // set year, month, day

    static bool is_skott_aar( int ); // Är det skottår?
    bool end_of_month( int ) const; // Är dagen den sista i månaden?

    //const Datum operator+(int left, const Datum& right);
    Datum operator+(int) const;
    Datum operator++(int); //Postfix
    Datum& operator++(); //Prefix
    Datum operator+=(int);
    bool operator<(Datum date);
    bool operator<=(Datum date);
    bool operator>(Datum date);
    bool operator>=(Datum date);
    bool operator==(Datum date);
    bool operator!=(Datum date);

private:
    void step_one_day(); // Öka datum med en dag
};

#endif
