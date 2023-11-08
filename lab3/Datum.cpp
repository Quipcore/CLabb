//
// Felix Lidö feli8145
//

// Labb3, Datum.cpp – definitioner av icke-triviala medlemsfunktioner

#include <iostream>
#include <string>
#include "Datum.h"

std::string month_names[13] = {"","January","February", "March", "April","May", "June", "July", "August", "September", "October", "November", "December"};

// Initialisera statisk medlem
// (första elementet används inte i denna lösning!)
const std::array< unsigned int, 13 > Datum::ANT_DAGAR_PER_MAANAD = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };


// Konstruktor
Datum::Datum( int year, int month, int day  )
{
    set_date( year, month, day);
}

Datum::Datum(const Datum &other) {
    set_date(other.year, other.month, other.day);
}

Datum::Datum() {
    set_date(2000, 1, 1);
}


void Datum::set_date( int yy, int mm, int dd )
{
    // Glöm inte att kontrollera inmatade värden, annars "exception"
    year = yy;
    month = mm;
    day = dd;
}

// Denna medlemsfunktion är tänkt att lägga till 1 dag till befintligt datum.
// Om sista dagen i månaden, så byt månad.
//     Om skottår, så ta hänsyn till att februari(månad 2) har 29 dagar.
// Om sista dagen på året, så byt år.
void Datum::step_one_day()
{
    // Dagen är inte sista dagen i månaden!
    if ( !end_of_month( day ) )
        ++day;
    else
    if ( month < 12 )
    {
        ++month;
        day = 1;
    }
    else
    {
        ++year;
        month = 1;
        day = 1;
    }
}

// Returnera true om yy(year) är skottår!
bool Datum::is_skott_aar( int yy )
{
    if ( yy % 400 == 0 ||
         ( yy % 100 != 0 && yy % 4 == 0 ) )
        return true;
    else
        return false;
}

// Är det sista dagen (dd) i månaden?
bool Datum::end_of_month( int dd ) const
{
    if ( month == 2 && is_skott_aar( year ) )
        return dd == 29;
    else
        return dd == ANT_DAGAR_PER_MAANAD[ month ];
}



// operator<<
std::ostream &operator<<( std::ostream &output, const Datum &d ) {
    // OBS. Glöm inte att modifiera vad som skrivs ut!
    output << d.day << ' ' << month_names[d.month] << ' ' << d.year;
    return output;
}

Datum operator+(const int left, const Datum& right) {
    Datum temp(right);
    temp = temp + left;
    return temp;
}

Datum Datum::operator+(int count) const {
    Datum tmp(year, month, day);
    for(int i = 0; i < count; i++){
        tmp.step_one_day();
    }
    return tmp;
}

//Postfix
Datum Datum::operator++(int) {
    Datum tmp(*this);
    *this += 1;
    return tmp;
}

//Prefix
Datum &Datum::operator++() {
    step_one_day();
    return *this;
}

Datum Datum::operator+=(int count) {
    for (int i = 0; i < count; i++){
        step_one_day();
    }
    return *this;
}

bool Datum::operator<(Datum date) {
    if(year < date.year){
        return true;
    }
    if(month < date.month){
        return true;
    }
    if(day < date.day){
        return true;
    }
    return false;
}

bool Datum::operator<=(Datum date) {
    return date == *this || *this < date;
}

bool Datum::operator>(Datum date) {
    return !(*this <= date);
}

bool Datum::operator>=(Datum date) {
    return !(*this < date);
}

bool Datum::operator==(Datum date) {
    return (date.day == day) && (date.month == month) && (date.year == year);
}

bool Datum::operator!=(Datum date) {
    return !(date == *this);
}