#include <iostream> 
#include <string.h>
#include <string>
#include <windows.h> 
#include <stdio.h>
using namespace std;


void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
    int w = 10;
    int delta = (wLine - w) / 2 - 1;
    cout.width(delta); cout << " ";
    if (day > 9) {
        cout << day;
    }
    else {
        cout << "0" << day;
    }
    cout << ".";
    if (month > 9) {
        cout << month;
    }
    else {
        cout << "0" << month;
    }
    cout << ".";
    cout << year;
    cout.width(delta); cout << " ";
}

void printZero(int num) {

    if (num < 10000) {

        cout << "0000" << num;
    }
    if (num > 9999 and num < 100000) {
        cout << "000" << num;
    }
    if (num > 99999 and num < 1000000) {
        cout << "00" << num;
    }
    if (num > 999999 and num < 1000000) {
        cout << num;
    }

}

class clDate {
private:
    unsigned short day;
    unsigned short month;
    unsigned short year;

public:
    clDate();
    clDate(unsigned short, unsigned short, unsigned short);
    clDate(const clDate&);
    clDate(const char*);
    clDate operator= (const clDate&);

    void setDate(unsigned short, unsigned short, unsigned short);
    void getDate(int);
    int getDaysInMonth();
    bool checkData(unsigned short);
    void plusFive(unsigned short);
    unsigned short getDay() { return day; }
    unsigned short getMonth() { return month; }
    unsigned short getYear() { return year; }
};
clDate::clDate() {
    day = 1;
    month = 1;
    year = 1970;
}
clDate::clDate(unsigned short day, unsigned short month, unsigned short year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

clDate::clDate(const clDate& date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;

}

int clDate::getDaysInMonth() {
    // Проверяем февраль (високосный год)
    if (month == 2) {
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    // Проверяем месяцы с 30 днями
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    // Проверяем месяцы с 31 днем
    return 31;
}

bool clDate::checkData(unsigned short plusNum) {
    unsigned short _day = day + plusNum;
    return _day <= getDaysInMonth();
}

void clDate::plusFive(unsigned short plusNum = 5) {
    if (checkData(plusNum)) {
        day += plusNum;
    }
    else cout << "выход за пределы даты!\n";
}


void clDate::getDate(int wLine) {
    int w = 10;
    int delta = (wLine - w) / 2 - 1;
    cout.width(delta); cout << " ";
    if (day > 9) {
        cout << day;
    }
    else {
        cout << "0" << day;
    }
    cout << ".";
    if (month > 9) {
        cout << month;
    }
    else {
        cout << "0" << month;
    }
    cout << ".";
    cout << year;
    cout.width(delta); cout << " ";
}


void clDate::setDate(unsigned short day, unsigned short month, unsigned short year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

clDate clDate::operator= (const clDate& date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    return *this;
}

struct Record {
    char nameCroup[10];
    char type;
    int area;
    int productivity;
    clDate date;
};

class clRecord {
    string nameCroup;
private:
    int area;
protected:
    int productivity;
    clDate date;
public:
    char type;

    clRecord();
    clRecord(string, char,int,int, clDate);
    clRecord(string, char,int,int, unsigned short, unsigned short, unsigned short);
    clRecord(const char*);
    clRecord(Record*);

    string getNameCroup() { return nameCroup; }
    char getType() { return type; }
    int getArea() { return area; }
    int getProductivity() { return productivity; }
    clDate getDate() { return date; }
    clRecord operator= (const clRecord&);

};

clRecord::clRecord() {
    nameCroup = "Croup";
    type = 't';
    area = 0;
    productivity = 0;
}
clRecord::clRecord(string nameCroup, char type, int area, int productivity, clDate date) {
    this->nameCroup = nameCroup;
    this->type = type;
    this->area = area;
    this->productivity = productivity;
    this->date = date;
}
clRecord::clRecord(string nameCroup, char type, int area, int productivity, short unsigned day, short unsigned month, short unsigned year) {
    this->nameCroup = nameCroup;
    this->type = type;
    this->area = area;
    this->productivity = productivity;
    this->date = clDate(day, month, year);
}

clRecord::clRecord(Record* rec) {
    this->nameCroup = rec->nameCroup;
    this->type = rec->type;
    this->area = rec->area;
    this->productivity = rec->productivity;
    this->date = rec->date;
}

clRecord::clRecord(const char* nameFile) {
    FILE* file;
    char split;
    fopen_s(&file, nameFile, "r");
    fscanf_s(file, "%s", &this->nameCroup, (this->nameCroup).length());
    fscanf_s(file, "%c", &split);
    fscanf_s(file, "%c", &this->type);
    fscanf_s(file, "%d", &this->area);
    fscanf_s(file, "%d", &this->productivity);
    fscanf_s(file, "%d", this->date.getDay());
    fscanf_s(file, "%d", this->date.getMonth());
    fscanf_s(file, "%d", this->date.getYear());

    fclose(file);
}
    
clRecord clRecord::operator= (const clRecord& rec) {
    this->nameCroup = rec.nameCroup;
    this->type = rec.type;
    this->area = rec.area;
    this->productivity = rec.productivity;
    this->date = rec.date;
    return *this;
}


int lenNum(int num) {
    int len = 0;
    while (num) {
        len++;
        num /= 10;
    }
    return len;
}
void drawLine(int number = 81) {
    cout.width(number); cout.fill('-'); cout << "-";
    cout.fill(' ');
}

void center(string s, int num) {
    int w = s.length();
    int delta = (num - w) / 2;
    cout << left;
    cout.width(delta); cout << " ";
    cout << s;
    cout.width(delta + 1); cout << " ";

}


void drawSpace(int number) {
    cout.width(number); cout.fill(' '); cout << ' ';
}

void drawHead() {
    drawLine(79);
    cout << "\n|Сельскохозяйственные культуры";
    drawSpace(79 - strlen("|Сельскохозяйственные культуры"));
    cout << "|\n|";
    drawLine(78);
    cout << "|\n|";
    center("Наименование", 15);
    cout << "|";
    center("Тип", 4);
    cout << "|";
    center("Посевная площадь", 20);
    cout << "|";
    center("Урожайность", 16);
    cout << "|";
    center("Дата начала", 16);
    cout << " |\n";
    cout << "|"; drawSpace(15); cout << "|";
    drawSpace(5); cout << "|";
    center("(га)", 20);
    cout << "|";
    center("(ц/га) ", 15);
    cout << "|";
    center("посевной", 16);
    cout << "|\n|";
    drawLine(78); cout << "|\n";
}
void drawFoot() {
    cout << "|Примечание: З - зерновые, Б - бобовые";
    drawSpace(41);
    cout << "|\n";
    drawLine(79);
    cout << "\n";
}


void Draw(clRecord* records, int size = 3) {
    drawHead();

    for (int i = 0; i < size; i++) {
        cout << "|" << records[i].getNameCroup(); drawSpace(15 - (records[i].getNameCroup().length()));
        cout << "|" << records[i].type << "    |";
        printZero(records[i].getArea());
        drawSpace(13);
        cout << "|" << records[i].getProductivity();
        drawSpace(14);

        cout << "|";
        records->getDate().getDate(19);
        cout << " |\n|";
        drawLine(78); cout << "|\n";
    }
    drawFoot();
}










int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    clDate date1();
    clDate date2(27,03,2023);
    date2.plusFive();
    clDate date3(date2);
    clDate* date4 = new clDate;
    delete date4;
    clDate DC(date2);

    clRecord record1("Соя", 'Б', 13000, 45, 3, 3, 2022);
    clRecord records[3];
    records[0] = clRecord("Соя", 'Б',13000,45, 03,03,2022 );
    records[1] = clRecord( "Чумиза", 'З',8000,17, 03,04,2022 );
    records[2] = clRecord( "Рис", 'З',25650, 24, 04,03,2022 );
    Draw(records);


    return 0;
}

