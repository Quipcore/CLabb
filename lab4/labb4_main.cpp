//
// Felix Lidö feli8145
//

//  labb4_main.cpp
//  labb4_tree

#include <iostream>
#include "Trad.h"


// Denna block-kommentar måste tas bort när programmet skall VPL-evalueras!

// Funktionen nedan används för test/evaluering av din lösning.
// Denna funktion anropas från både "print_eval_short" och
// "print_eval_double", du behöver därmed revidera funktionen,
// så att den kan anropas av båda funktionerna.
// Tänk på att inte ändra utskrift instruktionerna då dessa används vid VPL-evalueringen.

template<class Trad>
void inmatning(Trad& t )
{
  int i;
  std::cout << "Mata in tal: "; std::cin >> i; //2
  if ( t.sok( i ) )
    std::cout << "Finns redan i trädet!" << std::endl;
  else
    t.satt_in( i );
}


// Funktionen nedan används för test/evaluering av din lösning.
// Ändra inte denna!
void print_eval_short( Trad<short>& t )
{
  t.satt_in( short(5) );
  t.satt_in( short(4) );
  t.satt_in( short(7) );
  t.satt_in( short(1) );
  t.satt_in( short(3) );
  t.satt_in( short(6) );
  t.satt_in( short(8) );
  t.satt_in( short(9) );

  std::cout << "t1: ";
  t.skriv_ut();
  std::cout << std::endl;

  inmatning( t ); //2
  inmatning( t ); //7

  std::cout << "t2: ";
  t.skriv_ut();
  std::cout << std::endl;
}

// Funktionen nedan används för test/evaluering av din lösning.
// Ändra inte denna!
void print_eval_double( Trad<double> & tf, Trad<double> & tf2 )
{
  tf.satt_in( double(5.01) );
  tf.satt_in( double(4.12) );
  tf.satt_in( double(7.23) );
  tf.satt_in( double(1.34) );
  tf.satt_in( double(3.45) );
  tf.satt_in( double(6.56) );
  tf.satt_in( double(8.67) );
  tf.satt_in( double(9.78) );

  std::cout << "tf1: ";
  tf.skriv_ut();
  std::cout << std::endl;

  tf2 = tf;

  std::cout << "tf2: ";
  tf.skriv_ut();
  std::cout << std::endl;

  if ( tf == tf2 )
    std::cout << "LIKA" << std::endl;
  else
    std::cout << "OLIKA" << std::endl;

  inmatning( tf2 ); //3.52

  if ( tf == tf2 )
    std::cout << "LIKA" << std::endl;
  else
    std::cout << "OLIKA" << std::endl;

  std::cout << "tf2: ";
  tf2.skriv_ut();
  std::cout << std::endl;
}


int main() {
    // Heltal, short
    Trad<short> t;
    print_eval_short( t );

    // Flyttal, double
    Trad<double> tf, tf2;
    print_eval_double( tf, tf2 );

    return 0;
}
