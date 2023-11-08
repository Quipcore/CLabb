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

    unsigned int year;
    unsigned int month;
    unsigned int day;

    // Deklaration av statisk privat medlem, "ant_dagar per månad"
    static const std::array< unsigned int, 13 > ANT_DAGAR_PER_MAANAD;
    //void step_one_day(); // Öka datum med en dag

public:
    Datum( int, int, int );
    Datum();
    void set_date( int, int, int ); // set year, month, day

    //OBS. funktionen "step_one_day()" bör vara PRIVATE
    void step_one_day(); // Öka datum med en dag
    static bool is_skott_aar( int ); // Är det skottår?
    bool end_of_month( int ) const; // Är dagen den sista i månaden?

    operator int() const;
    Datum operator+(int);
    Datum operator++(int) const; //Postfix
    Datum& operator++(); //Prefix
    Datum operator+=(int);
    bool operator<(Datum date);
    bool operator<=(Datum date);
    bool operator>(Datum date);
    bool operator>=(Datum date);
    bool operator==(Datum date);
    bool operator!=(Datum date);



};

#endif
