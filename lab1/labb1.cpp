//
// Created by felix on 2023-11-01.
//



#include <iostream>
#include <vector>

struct Person
{
    std::string fnamn;
    std::string enamn;
    std::string nummer;
};



//Create a macro for length of array
#define ARRAY_LENGTH_PERSON(array) (sizeof(array)/sizeof(Person))

void visa_person ()
{
    // Denna funktion tar emot ett telefonregister och ett förnamn på den person-post som skall visas.

    // Om det finns en eller flera person-poster med detta förnamn i registret,
    // så skall telefonnumret till dessa visas, på formen: "förnamn efternamn: telefonnummer".
//    std::cout << fnamn << " " << enamn << ": " << nummer << std::endl;

    // Om ingen person-post hittas med det sökta förnamnet, så skall följande skrivas ut.
//    std::cout << "Hittade inget nummer!" << std::endl;
}

void skriv_hela_telefonreg ()
{
    // Denna funktion tar emot ett telefonregister och visar samtliga poster i
    // telefonregistret på formen: "förnamn efternamn: telefonnummer".

//    std::cout << fnamn << " " << enamn << ": " << nummer << std::endl;

}

void ny_person (std::vector<Person> people, std::string fnamn, std::string enamn, std::string nummer)
{
    people.push_back({fnamn, enamn, nummer});
    // Denna funktion tar emot ett telefonregister och ett förnamn, ett efternamn och
    // ett telefonnummer till den nya person-post som skall skapas och läggas till i telefonboken,
    // därefter läggs person-posten till registret.

}

void ta_bort_person ()
{
    // Denna funktion tar emot ett telefonregister och ett förnamn på den person-post
    // som skall tas bort ur registret.
    // Om det finns fler person-poster med samma förnamn, så tas alla dessa bort.

    // När en person-post tas bort så skrivs namnet på person-posten ut på skärmen (förnamn efternamn),
    // men ingen användardialog skall finnas, dvs. användaren skall inte bekräfta borttag.

    //std::cout << fnamn << " " << enamn << " tas nu bort." << std::endl;

}

void print(std::vector<Person> people){
    for(const auto & i : people){
        std::cout << i.fnamn << " " << i.enamn << ": " << i.nummer << std::endl;
    }
}

int main ()
{

    // Dessa personer skall finnas med som person-poster i telefonregistret.
    /*
    "Christina", "Nyberg","0707423653"
    "Josefin", "Danielsson", "0705463245"
    "Ellen", "Lindgren", "0705643229"
    "Ellen", "Lindgren", "0705643229"
    "Linus", "Jonasson", "0703457923"
    "Adam", "Nordin", "0203456297"
    */

    // Här ska du deklarera den variabel som skall innehålla ditt register!
    std::vector<Person> people = {
            {"Christina", "Nyberg","0707423653"},
            {"Josefin", "Danielsson", "0705463245"},
            {"Ellen", "Lindgren", "0705643229"},
            {"Ellen", "Lindgren", "0705643229"},
            {"Linus", "Jonasson", "0703457923"},
            {"Adam", "Nordin", "0203456297"},
    };

    print(people);

    // Här skall en liten kommandostyrd huvudmeny skrivas. Observera att vissa kommandon
    // behöver fler värden som skall matas in. I menyn skall följande val
    // av Kommandon finnas:
    //  Ny person               - 'n' förnamn efternamn telefonnummer
    //  Visa en person          - 'v' förnamn
    //  Skriv hela telefonboken - 's'
    //  Ta bort en person       - 'd' förnamn
    //  Avsluta                 – 'q'



    std::string command;

    while(command != "q") {
        std::cout << "Kommando: ";
        std::cin >> command;

        if(command == "n"){
            std::string fnamn, enamn, nummer;

            std::cout << "Name: ";
            std::cin >> fnamn;

            std::cout << "Last name: ";
            std::cin >> enamn;

            std::cout << "Number: ";
            std::cin >> nummer;
            ny_person(people, fnamn, enamn, nummer);
        }

    }
    return 0;
}
