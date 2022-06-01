#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//ZADANIE 1:
/*
Przekszta³æ
Zaimplementowaæ funkcjê int change(char * inName, char * outName, int digit), w której przepisana zostaje
zawartoœæ pliku wejœciowego (nazwa inName) do wyjœciowego (nazwa outName) z tym, ¿e:
• cyfry (w postaci znaku w pliku) podzielne przez cyfrê (zmienna digit) zmniejszane s¹ o 1, podczas wpisywania do
pliku wyjœciowego (zak³adaj¹c, ¿e 0 nie jest podzielne przez digit),
• wszystkie pozosta³e cyfry zostaj¹ pominiête w pliku wyjœciowym,
• na koñcu pliku wyjœciowego powinna byæ dopisana liczba wszystkich wielkich liter (alfabetu angielskiego) z pliku
wejœciowego,
• powinna byæ równie dopisana liczba wszystkich usuniêtych cyfr.
Dodatkowo powinna zostaæ zwrócona suma wszystkich liczb zapisanych w pliku wejœciowym (mo¿na za³o¿yæ, ¿e liczba jest
oddzielona od innych znaków spacjami lub znajdujê siê na pocz¹tku albo na koñcu linii.
*/

int change(const char* inName, const char* outName, int digit) {
    int upperLetters = 0;
    int suma = 0;

    ifstream fileIn;
    fileIn.open(inName);

    string word;

    while (fileIn >> word){
        if (isdigit(word[0])) {
            suma += stoi(word);
        }
    }

    fileIn.close(); 

    ifstream fileIn2;
    fileIn2.open(inName);
    ofstream fileOut;
    fileOut.open(outName);
    int help = 0;
    int numberOfDeleteValue = 0;

    char c = fileIn2.get();

    while (!fileIn2.eof()) {
        if (c >= 'A' && c <= 'Z') {
            upperLetters++;
            fileOut << c;
        }
        else if (c > '0' && c <= '9')
        {
            if (c % digit == 0) {
                help = (c - 48) - 1;
                fileOut << help;
            }
            else {
                numberOfDeleteValue++;
            }
        }
        else if (c == ' ') {
            fileOut << ' ';
        }
        else
        {
            fileOut << c;
        }

        c = fileIn2.get();
    }

    fileIn2.close();

    fileOut << "\nLiczba wielkich liter: " << upperLetters << "\nIloœæ pominietych wartoœci: " << numberOfDeleteValue << "\nSuma wszystkich liczb w pliku wejœciowym: " << suma << endl;

    fileOut.close();

    return suma;
}

//ZADANIE 2:
/*
Liczby
Zaimplementowaæ funkcjê void sortTable(int** data, int n), do której przekazane s¹ dane wejœciowe w postaci dwuwymiarowej tablicy liczb (data). 
Tablica ma n wierszy (drugi parametr) i dok³adnie dwie kolumny, gdzie pierwsza, to
identyfikator zapisany liczb¹, a druga, to wartoœci dla identyfikatorów (równie¿ liczbowe). W wyniku dzia³ania funkcji,
wartoœci w tabeli musz¹ byæ posortowane rosn¹co (dowolnym sposobem) wzglêdem wartoœci z drugiej kolumny. Podczas
sortowania trzeba operowaæ tylko na adresach – nie wolno przepisywaæ wartoœci tabeli, rozwi¹zanie powinno byæ pod
tym wzglêdem optymalne.
*/

void sortTable(int** data, int n) {
    int col = 2;

    cout << "BEFORE: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col; j++) {
            cout << data[i][j] << '\t';
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (data[i][1] > data[j][1])
            {
                swap(data[i], data[j]);
            }
        }
    }

    cout << "AFTER: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col; j++) {
            cout << data[i][j] << '\t';
        }
        cout << endl;
    }
}
int main() {
    //ZADANIE 1:
    cout << "***** ZADANIE 1 *****" << endl;

    int suma = change("TextFile1.txt", "TextFile1Out.txt", 3);

    cout << suma << endl;

    //ZADANIE 2:
    cout << "***** ZADANIE 2 *****" << endl;
    int n = 4;
    int** data = new int* [n];

    int array[] = { 855, 21, 1441, 6 };

    for (int i = 0; i <= n; i++) {
        data[i] = new (nothrow) int[2];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                data[i][j] = i + 1;
            }
            else
            {
                data[i][j] = array[i];
            }
        }
    }

    sortTable(data, n);

    cout << endl;

	return 0;
}