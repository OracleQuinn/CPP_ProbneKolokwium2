#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//ZADANIE 1:
/*
Przekszta��
Zaimplementowa� funkcj� int change(char * inName, char * outName, int digit), w kt�rej przepisana zostaje
zawarto�� pliku wej�ciowego (nazwa inName) do wyj�ciowego (nazwa outName) z tym, �e:
� cyfry (w postaci znaku w pliku) podzielne przez cyfr� (zmienna digit) zmniejszane s� o 1, podczas wpisywania do
pliku wyj�ciowego (zak�adaj�c, �e 0 nie jest podzielne przez digit),
� wszystkie pozosta�e cyfry zostaj� pomini�te w pliku wyj�ciowym,
� na ko�cu pliku wyj�ciowego powinna by� dopisana liczba wszystkich wielkich liter (alfabetu angielskiego) z pliku
wej�ciowego,
� powinna by� r�wnie dopisana liczba wszystkich usuni�tych cyfr.
Dodatkowo powinna zosta� zwr�cona suma wszystkich liczb zapisanych w pliku wej�ciowym (mo�na za�o�y�, �e liczba jest
oddzielona od innych znak�w spacjami lub znajduj� si� na pocz�tku albo na ko�cu linii.
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

    fileOut << "\nLiczba wielkich liter: " << upperLetters << "\nIlo�� pominietych warto�ci: " << numberOfDeleteValue << "\nSuma wszystkich liczb w pliku wej�ciowym: " << suma << endl;

    fileOut.close();

    return suma;
}

//ZADANIE 2:
/*
Liczby
Zaimplementowa� funkcj� void sortTable(int** data, int n), do kt�rej przekazane s� dane wej�ciowe w postaci dwuwymiarowej tablicy liczb (data). 
Tablica ma n wierszy (drugi parametr) i dok�adnie dwie kolumny, gdzie pierwsza, to
identyfikator zapisany liczb�, a druga, to warto�ci dla identyfikator�w (r�wnie� liczbowe). W wyniku dzia�ania funkcji,
warto�ci w tabeli musz� by� posortowane rosn�co (dowolnym sposobem) wzgl�dem warto�ci z drugiej kolumny. Podczas
sortowania trzeba operowa� tylko na adresach � nie wolno przepisywa� warto�ci tabeli, rozwi�zanie powinno by� pod
tym wzgl�dem optymalne.
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