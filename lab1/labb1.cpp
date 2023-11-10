//Felix Lidö feli8145

#include <iostream>
#include <vector>

struct Person {
    std::string fnamn;
    std::string enamn;
    std::string nummer;
};

void visa_person(std::vector<Person> people, std::string fnamn) {
    // Denna funktion tar emot ett telefonregister och ett förnamn på den person-post som skall visas.

    // Om det finns en eller flera person-poster med detta förnamn i registret,
    // så skall telefonnumret till dessa visas, på formen: "förnamn efternamn: telefonnummer".
    bool personFound = false;
    for(const Person& person : people){
        if(person.fnamn == fnamn){
            std::cout << person.fnamn << " " << person.enamn << ": " << person.nummer << std::endl;
            personFound = true;
        }
    }

    // Om ingen person-post hittas med det sökta förnamnet, så skall följande skrivas ut.
    if(!personFound){
        std::cout << "Hittade inget nummer!" << std::endl;
    }
}

void skriv_hela_telefonreg(const std::vector<Person>& people) {
    // Denna funktion tar emot ett telefonregister och visar samtliga poster i
    // telefonregistret på formen: "förnamn efternamn: telefonnummer".
    for(const Person& person : people){
        std::cout << person.fnamn << " " << person.enamn << ": " << person.nummer << std::endl;
    }
}

void ny_person(std::vector<Person> &people, std::string fnamn, std::string enamn, std::string nummer) {
    // Denna funktion tar emot ett telefonregister och ett förnamn, ett efternamn och
    // ett telefonnummer till den nya person-post som skall skapas och läggas till i telefonboken,
    // därefter läggs person-posten till registret.
    people.push_back({std::move(fnamn), std::move(enamn), std::move(nummer)});
}

void ta_bort_person(std::vector<Person> &people, std::string fnamn) {
    // Denna funktion tar emot ett telefonregister och ett förnamn på den person-post
    // som skall tas bort ur registret.
    // Om det finns fler person-poster med samma förnamn, så tas alla dessa bort.

    // När en person-post tas bort så skrivs namnet på person-posten ut på skärmen (förnamn efternamn),
    // men ingen användardialog skall finnas, dvs. användaren skall inte bekräfta borttag.


    for(int i = 0; i < people.size(); i++){
        Person person = people.at(i);
        if(person.fnamn == fnamn){
            std::cout << person.fnamn << " " << person.enamn << " tas nu bort." << std::endl;
            people.erase(people.begin()+i);
            --i;
        }
    }
}

int main() {
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
            {"Christina", "Nyberg",     "0707423653"},
            {"Josefin",   "Danielsson", "0705463245"},
            {"Ellen",     "Lindgren",   "0705643229"},
            {"Stig", "Ek", "0705673247"},
            {"Linus",     "Jonasson",   "0703457923"},
            {"Adam",      "Nordin",     "0203456297"}
    };


    // Här skall en liten kommandostyrd huvudmeny skrivas. Observera att vissa kommandon
    // behöver fler värden som skall matas in. I menyn skall följande val
    // av Kommandon finnas:
    //  Ny person               - 'n' förnamn efternamn telefonnummer
    //  Visa en person          - 'v' förnamn
    //  Skriv hela telefonboken - 's'
    //  Ta bort en person       - 'd' förnamn
    //  Avsluta                 – 'q'
    
    for(char command = 0; command != 'q';){
        std::cout << "Kommando: ";
        std::cin >> command;
        std::string fnamn, enamn, nummer;
        switch (command) {
            case 'n':
                std::cin >> fnamn >> enamn >> nummer;
                ny_person(people, fnamn, enamn, nummer);
                break;
            case 'v':
                std::cin >> fnamn;
                visa_person(people, fnamn);
                break;
            case 's':
                skriv_hela_telefonreg(people);
                break;
            case 'd':
                std::cin >> fnamn;
                ta_bort_person(people, fnamn);
                break;
            default:
                break;
        }
    }

    std::cout << "Hejdå!" << std::endl;
    return 0;
}
