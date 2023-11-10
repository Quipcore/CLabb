# Labbuppgift 2, En IntVektor
## Problem
Implementera klassen IntVector, som ska bete sig som en utökningsbar array för heltalsvärden (ungefär som Javas 
ArrayList<integer>, eller C++:s vector<int>).

## Detaljerad beskrivning
Denna uppgift utgör en övning på skapande av klasser som allokerar utrymme dynamiskt och beter sig med värdesemantik. 
Det finns även lite operatoröverlagring. Vid lösning av uppgiften får inte standardbibliotekets mall vector<> 
användas – uppgiften ska ju illustrera mekanismer som används för skapande av sådana klasser. Implementera klassen 
IntVector som ska bete sig som en utökningsbar array för heltalsvärden (ungefär som Javas ArrayList<Integer> eller C++:s 
vector<int>). Lägg klassdefinitionen på en headerfil och definitioner av icke-triviala medlemsfunktioner på en .cpp-fil. 
Testprogram och tillämpningar ska ligga på en tredje fil. Använd bifogade tre filer för detta, tillämpningsprogrammet 
med funktionen main och funktionen för test av move-konstruktorn finns redan med i filen "labb2_main.cpp. 

IntVector ska ha värdesemantik, dvs den (och alla dess element) ska kopieras vid tilldelning, då den skickas som 
värdeargument till funktioner och då den returneras från funktioner. Ett IntVector-objekt ska kunna konstrueras utan 
argument (en tom IntVector), med ett annat IntVector-objekt (en kopiera-konstruktor, den nya IntVector blir en kopia av 
argumentet), med ett temporärt IntVector-objekt (en move-konstruktor, det temporära objektet nollställs), samt med 
värden från en initieringslista.

Tänk på att du behöver också kunna skriva ut ett IntVector-objekt med utskriftoperatorn <<, exempelvis:
```c++
std::cout << "vek4: " << vek4 << std::endl;   // Exempel på utskrift: vek4: 43 43 53 73
```

`exempel på hur utskriftsoperatorn kan användas för anpassad utskrift av egna objekt presenteras i föreläsningsbilderna till föreläsning 7-8`

Fundera också på om default-konstruktorn räcker för IntVector, eller om en egenskriven destruktor, måste skrivas, om så är fallet, skriv denna.

Exempel på konstruktion:
```c++
IntVector vek1;             // Tom IntVector
IntVector vek3(vek1);       // IntVector med lika element som vek1
IntVector vek4{ 10,11,16 };  // IntVector med de angivna värdena
```

Man ska kunna tilldela ett IntVector -objekt från ett annat:
```c++
vek3 = vek4;
```
varvid vek3 blir en kopia av vek4 (värdesemantik, ändrar man senare i vek4 så ändras inte vek3).
Åtkomst till element i en IntVector skall ske med indexering:
```c++
vek4[1] = 53;
if ( vek4[i] == 6)
{ … }
```

Om ett IntVector-objekt deklarerats som const ska man kunna avläsa elementvärden med indexering och avläsa IntVector:ns 
storlek, men man ska inte kunna ändra elementvärdena eller lägga till nya element till detta objekt. Att lägga till nya 
element till ett IntVector-objekt ska göras med medlemsfunktionen push_back, som tar det nya värdet som argument och 
lägger detta värde sist i IntVector: 
```c++
vek4.push_back( 23 );
```
Dessutom ska IntVector ha en medlemsfunktion size() som returnerar antalet element som har adderats till objektet.

## 

När du öppnar VPL-modulen och väljer "Edit", så får du tre arbetsfiler "labb2_main.cpp", "IntVector.h" och "IntVector.cpp",
spara dessa genom meny-ikonen "Spara". Därefter, kan du komplettera koden med din egen.Komplettera befintlig kod i de 
tre utgångsfilerna, så att IntVector fungerar som beskrivet ovan.

I funktionerna main och func skall du inte skriva till, ta bort eller ändra någonting, det är dessa funktioner som testkör programmet.
Det är viktigt att dessa anvisningar för uppgiften följs, då uppgiften kommer att automatevalueras.
Denna uppgift kan du spara, kompilera, och evaluera så ofta du vill.

**För att bli godkänd** på denna uppgift:

* Programmet måste gå att kompilera och köra i VPL(g++, C++17)
* Det enda testfall som finns i denna uppgift måste passera när koden evalueras (med meny-ikonen för evaluering). 
Testfallet undersöker output av programmet när det körs. Förväntad output, finns redan med som kommentar till main-funktionen. 
* Anvisningarna för uppgiften måste ha följts.
* **Viktigt**. Om det visar sig i efterhand att lösningen fokuserar mer på att kringgå uppgiftens anvisningar för att 
kunna passera evalueringen, än att faktiskt lösa problemet, så kan uppgiftens bedömning komma att ändras från Godkänt till Underkänt.

## Tips
Exempel på hur utskriftsoperatorn kan användas för anpassad utskrift av egna objekt presenteras i föreläsningsbilderna till föreläsning 7-8

I denna uppgift är användningen av const relevant. Tänk på att alltid ta för vana att const - ange detta för objekt eller värden som inte skall ändras.

Tänk också på att det kan behövas städa upp, frigöra minne, när ett dynamiskt skapat objekt destrueras, dvs. du kan behöva skapa en egen destruktor i vissa fall, där default konstruktorn inte räcker.

## Input format
* Ingenting. Tillämpningsrogrammet kör de instruktioner som finns i main-funktionen.

## Constraints
* Skriv ditt namn som kommentar högst upp i filerna.
* Uppgiften skall utföras individuellt. Plagieringskontroll kan komma att utföras.
* Skriv all kod i de tre bifogade dokumenten.
* Kommentera relevant del av koden.
* Använd befintlig klassdefinition och befintlig definition av medlemsfunktion som utgångspunkt, ändra och komplettera kod, som du finner lämpligt.
* Ändra ingenting i main-funktionen, dessa instruktioner används för utvärdering.
* Ändra ingenting i func-funktionen, denna funktion används för utvärdering.

## Output när tillämpningsprogrammet exekverar
```c++
vek4: 43 43 53 73
vek3[3]: 20
vek3: 10 11 16 20 23
vek4: 10 11 16 75 23
vek5, size: 6
vek5[5]: 46
vek5: 10 11 16 75 23 46
```
