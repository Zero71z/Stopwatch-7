#include <iostream>
#include <time.h>
#include <vector>
#include <Windows.h> 

using namespace std;

class Stopwatch {
public:
    vector <double>measurings;      //замеры
    clock_t start;
    double seconds;

    Stopwatch() {
        measurings;
        start = 0;
    }

    void Start() {
        start = clock();            //старт замера
    }

    int End() {
        clock_t end;
        end = clock();              //конец замера
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        return seconds;
    }

    void Save() {
        measurings.push_back(seconds);        //сохранение секунд в замеры
    }

    void Reset() {                                  //сброс значений
        measurings.clear();
    }

    friend ostream& operator << (ostream& stream, const Stopwatch& a) {
        int symbol = 0;
        while (a.measurings.size() != symbol) {
            stream << symbol + 1 << " " << a.measurings[symbol] << endl;
            symbol++;
        }

        return stream;
    }


};

int main()
{
    setlocale(LC_ALL, "ru");

    Stopwatch a;
    a.Start();
    Sleep(1640);
    a.End();
    a.Save();
    a.Start();
    Sleep(700);
    a.End();
    a.Save();



    cout << a << endl;

    return 0;
}