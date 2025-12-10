#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;

enum class Razmesheniye {
    lukshery,
    solo_room,
    two_person,
    three_person,
    apartments,
};

enum class Eda {
    utrennee,
    trehrazovoe,
    allin
};

struct gostinica {
    string FIO;               // ФИО гостя
    string data_priezda;     // Дата приезда
    string data_otezda;      // Дата отъезда
    string nomer;             // Номер комнаты
    Razmesheniye komnata;    // Тип размещения
    Eda pitaniye;            // Тип питания
};

gostinica* readHotelsFromFile(const string& filename, int& n) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return nullptr;
    }

    vector<gostinica> hotels; // Вектор для хранения гостиниц
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        gostinica hotel;
        string komnata_str, pitaniye_str;
        getline(ss, hotel.FIO, ',');
        getline(ss, hotel.data_priezda, ',');
        getline(ss, hotel.data_otezda, ',');
        getline(ss, hotel.nomer, ',');
        getline(ss, komnata_str, ',');
        getline(ss, pitaniye_str); // Последнее значение до конца строки

        // Присваиваем значения в зависимости от строковых представлений
        if (komnata_str == "lukshery") hotel.komnata = Razmesheniye::lukshery;
        else if (komnata_str == "solo_room") hotel.komnata = Razmesheniye::solo_room;
        else if (komnata_str == "two_person") hotel.komnata = Razmesheniye::two_person;
        else if (komnata_str == "three_person") hotel.komnata = Razmesheniye::three_person;
        else if (komnata_str == "apartments") hotel.komnata = Razmesheniye::apartments;

        if (pitaniye_str == "utrennee") hotel.pitaniye = Eda::utrennee;
        else if (pitaniye_str == "trehrazovoe") hotel.pitaniye = Eda::trehrazovoe;
        else if (pitaniye_str == "allin") hotel.pitaniye = Eda::allin;

        hotels.push_back(hotel); // Добавляем гостиницу в вектор
    }

    n = hotels.size(); // Обновляем количество гостиниц

    // Проверка на количество строк
    if (n < 11) {
        cerr << "Ошибка: в файле должно быть не менее 11 строк!" << endl;
        return nullptr; // Возвращаем nullptr при недостаточном количестве строк
    }

    gostinica* hotels_array = new gostinica[n]; // Создаем массив гостиниц
    for (int i = 0; i < n; i++) {
        hotels_array[i] = hotels[i]; // Копируем данные из вектора в массив
    }
    return hotels_array; // Возвращаем указатель на массив гостиниц
}

int main() {
    setlocale(LC_ALL, "RU");
    int n = 0; // Количество гостиниц
    gostinica* hotels = readHotelsFromFile("hotels.txt", n); // Читаем данные из файла

    if (hotels == nullptr) {
        return -1; // Если произошла ошибка, завершаем программу
    }

    int ch;
    while (true) {
        cout << "Что вы хотите вывести? \n1. Вывести по определенным датам \n2. Вывести по типу размещения \n3. Вывести все \n0. Выход" << endl;
        cin >> ch;

        switch(ch){
            case 1: {
                string kakoytovvod;
                cout << "Введите дату, которая вас интересует: ";
                cin >> kakoytovvod;
                for (int i = 0; i < n; i++) {
                    if (kakoytovvod == hotels[i].data_priezda) {
                        cout << "Гость: " << hotels[i].FIO
                             << ", Дата приезда: " << hotels[i].data_priezda
                             << ", Дата отъезда: " << hotels[i].data_otezda
                             << ", Номер: " << hotels[i].nomer
                             << ", Размещение: " << static_cast<int>(hotels[i].komnata) + 1
                             << ", Питание: " << static_cast<int>(hotels[i].pitaniye) + 1 << endl;
                    }
                }
                break;
            }
            case 2: {
                int kakoytovvod2;
                cout << "Введите интересуемое размещение (1 - Люкс, 2 - Одноместный, 3 - Двухместный, 4 - Трехместный, 5 - Апартаменты): ";
                cin >> kakoytovvod2;

                // Проверка корректности ввода
                if (kakoytovvod2 < 1 || kakoytovvod2 > 5) {
                    cout << "Некорректный ввод типа размещения." << endl;
                    break;
                }

                for (int i = 0; i < n; i++) {
                    if (kakoytovvod2 == static_cast<int>(hotels[i].komnata) + 1) {
                        cout << "Гость: " << hotels[i].FIO
                             << ", Дата приезда: " << hotels[i].data_priezda
                             << ", Дата отъезда: " << hotels[i].data_otezda
                             << ", Номер: " << hotels[i].nomer
                             << ", Размещение: " << static_cast<int>(hotels[i].komnata) +1
                             << ", Питание: " << static_cast<int>(hotels[i].pitaniye) +1<< endl;
                    }
                }
                break;
            }
            case 3: {
                for (int i = 0; i < n; i++) {
                    cout << "Гость: " << hotels[i].FIO
                         << ", Дата приезда: " << hotels[i].data_priezda
                         << ", Дата отъезда: " << hotels[i].data_otezda
                         << ", Номер: " << hotels[i].nomer
                         << ", Размещение: " << static_cast<int>(hotels[i].komnata) + 1
                         << ", Питание: " << static_cast<int>(hotels[i].pitaniye) + 1 << endl;
                }
                break;
            }
            case 251: {
                cout << "Папка system32 будет удалена через..."<< endl;
                for (int i = 10; i > 0; i--) {
                    cout << i << endl;
                    Sleep(750);
                }
                cout << "Я шучу (наверное)" << endl;
                break;
                return 0;
            }
            case 0: {
                delete[] hotels;
                return 0;
            }
            default: {
                cout << "Некорректный ввод. Пожалуйста, выберите вариант из списка." << endl;
                break;
            }
        }
    }

    delete[] hotels;
    return 0;
}
