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

class clData {
private:
    unsigned short day;
    unsigned short month;
    unsigned short years;

public:
    clData();
    clData(unsigned short, unsigned short, unsigned short);
};
clData::clData() {
    day = 1;
    month = 1;
    years = 1970;
}
clData::clData(unsigned short day, unsigned short month, unsigned short years) {
    this->day = day;
    this->month = month;
    this->years = years;
}
struct Date
{
    unsigned short day;
    unsigned short month;
    unsigned short years;
};

struct Record {
    char nameCroup[10];
    char type;
    int area;
    int productivity;
    Date date;
};

class List {
public:
    Record data;

    List* next;


    void addElem(Record);
    void removeElem(int);
    void editElem(int, Record);
    void insertElem(int, Record);
    void Draw();


};
int lengthList = 0;
List* myList;
void List::addElem(Record newRec) {
    List* newList = new List();
    newList->data = newRec;
    if (lengthList == 0) {
        newList->next = NULL;
    }
    else {
        newList->next = myList;
    }
    myList = newList;
    lengthList++;
}
void List::removeElem(int index) {
    if (index >= 0 && index < lengthList && lengthList > 0) {
        List* current = myList;
        List* old;
        if (index == 0) {
            old = myList;
            myList = current->next;
            delete old;
            lengthList--;
        }
        else {
            int i = 0;
            while (current) {
                if (i == index - 1) {
                    old = current->next->next;
                    delete current->next;
                    current->next = old;
                    lengthList--;
                    break;
                }
                i++;
                current = current->next;
            }
        }
    }
    else cout << endl << "Ошибка индекс не в диапазоне";
}
void List::editElem(int index, Record editRec) {
    if (index > 0 && index < lengthList && lengthList > 0) {
        List* current = new List();
        for (int i = 0; i < index; i++) {
            current = myList->next;
        }
        current->data = editRec;

    }
    else cout << endl << "Ошибка индекс не в диапазоне";
}
void List::insertElem(int index, Record newRec) {
    if (index > 0 && index < lengthList + 1 && lengthList > 0) {
        List* current = new List();
        List* newList = new List();
        newList->data = newRec;
        for (int i = 0; i < index - 1; i++) {
            current = myList->next;
        }
        newList->next = current->next;
        current->next = newList;
        lengthList++;
    }
    else cout << endl << "Ошибка индекс не в диапазоне";
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

void List::Draw() {
    drawHead();
    List* currents = new List();
    currents = myList;

    for (int i = 0; i < lengthList; i++) {
        cout << "|" << currents->data.nameCroup; drawSpace(15 - strlen(currents->data.nameCroup));
        cout << "|" << currents->data.type << "    |";
        printZero(currents->data.area);
        drawSpace(13);
        cout << "|" << currents->data.productivity;
        drawSpace(14);
        cout << "|";
        printDate(currents->data.date.day, currents->data.date.month, currents->data.date.years, 19);
        cout << " |\n|";
        drawLine(78); cout << "|\n";
        currents = currents->next;
    }
    drawFoot();
}
void Draw(Record* records, int size = 3) {
    drawHead();

    for (int i = 0; i < size; i++) {
        cout << "|" << records[i].nameCroup; drawSpace(15 - strlen(records[i].nameCroup));
        cout << "|" << records[i].type << "    |";
        printZero(records[i].area);
        drawSpace(13);
        cout << "|" << records[i].productivity;
        drawSpace(14);
        cout << "|";
        printDate(records[i].date.day, records[i].date.month, records[i].date.years, 19);
        cout << " |\n|";
        drawLine(78); cout << "|\n";
    }
    drawFoot();
}

void freeList() {
    List* current;
    for (int i = 0; i < lengthList; i++) {
        current = myList->next;
        delete myList;
        myList = current;
    }
    lengthList = 0;
}









int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Record records[3];
    records[0] = { "Соя", 'Б',13000,45, {03,03,2022} };
    records[1] = { "Чумиза", 'З',8000,17, {03,04,2022} };
    records[2] = { "Рис", 'З',25650, 24, {04,03,2022} };
    Draw(records);

    cout << "Данные из текстового файла:\n";
    FILE* file;
    fopen_s(&file, "file.txt", "w+");
    for (int i = 0; i < 3; i++) {
        fprintf(file, "%s %c %d %d %d %d %d \n", \
            records[i].nameCroup, records[i].type, \
            records[i].area, records[i].productivity, \
            records[i].date.day, records[i].date.month, records[i].date.years);
    }
    fclose(file);

    fopen_s(&file, "file.txt", "r");
    Record newRecordsTXT[3];
    char split;
    for (int i = 0; i < 3; i++) {
        fscanf_s(file, "%s", newRecordsTXT[i].nameCroup, _countof(newRecordsTXT[i].nameCroup));
        fscanf_s(file, "%c", &split);
        fscanf_s(file, "%c", &newRecordsTXT[i].type);
        fscanf_s(file, "%d", &newRecordsTXT[i].area);
        fscanf_s(file, "%d", &newRecordsTXT[i].productivity);
        fscanf_s(file, "%hu", &newRecordsTXT[i].date.day);
        fscanf_s(file, "%hu", &newRecordsTXT[i].date.month);
        fscanf_s(file, "%hu", &newRecordsTXT[i].date.years);
    }
    fclose(file);
    Draw(newRecordsTXT);
    cout << "Данные из бинарного файла:\n";
    FILE* binfile;
    Record newRecordsBIN[3];

    fopen_s(&binfile, "file.bin", "w+");
    fwrite(records, sizeof(records), 1, binfile);
    fclose(binfile);

    fopen_s(&binfile, "file.bin", "rb");
    fread(newRecordsBIN, sizeof(newRecordsBIN), 1, binfile);
    fclose(binfile);
    Draw(newRecordsBIN);
    return 0;
}

clData::clData()
{
}
