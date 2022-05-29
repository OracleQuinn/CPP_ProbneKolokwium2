#include <iostream>

using namespace std;

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