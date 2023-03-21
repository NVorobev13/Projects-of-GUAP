#include <stdio.h>
#include <string.h>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <iostream>
using namespace std;
#define FNAME_I "D:\\bd15.dat\0" //��� ����� � �������� �����
#define FNAME_R "D:\\bd25.dat\0" //��� ����� � ������������ ������

int proverka_file(const char*, const char*); //�������� ������� �����
void dobavka(const char* fname);
void zag1();
void zag2();
void prosmotrbd1(const char* fname);
void prosmotrbd2(const char* fname);
void sort_owner(const char* fname1, const char* fname2);
void sort_title(const char* fname);
void sort_lenght(const char* fname);

void intro();	//������� �������� ������

const char PR_R[] = "rb"; //������� �������� ��������� ����� �� ������
const char PR_S[] = "r+b"; //������� �������� ����� �� ������ � ������
const char PR_W[] = "wb"; //������� �������� ����� �� ������
const char PR_A[] = "ab"; //������� �������� ����� �� ����������
typedef struct {
    char title[15]; //�������� ����
    char owner[15]; //��� ���������
    double lenght;   //������  (�.)
    double cost;   //��������� (���.$)
    int yearsOld; //��� ��������� 
}
trip;

void intro()
{
    cout << "\n\n\n\t     BANK";
    cout << "\n\n\tUSER MANAGEMENT";
    cout << "\n\n\t    SYSTEM";
    cout << "\n\n\n\nCREATED BY: N.A. VOROBEV";
    cout << "\n\nUNIVERSITY: GUAP";
    cin.get();
}

int main() {
    int var;
    char otv;
    char fname_i[20] = FNAME_I;
    char fname_r[20] = FNAME_R;
    setlocale(LC_ALL, "Russian");
    intro();

    for (; ;) { //����� ���� ��������
        cout << "\n    ��� ��������:" << endl;
        cout << "  1 - �������� ���� ������" << endl;
        cout << "  2 - ���������� ����� �������" << endl;
        cout << "  3 - ���������� �� �������� ���" << endl;
        cout << "  4 - ���������� �� ������ ���" << endl;
        cout << "  5 - ����� ��� �� ����� ���������" << endl;
        cout << "  6 - �������� ���� ������" << endl;
        cout << "  7 - �������� ���� ������ ������ ���" << endl;
        cout << "  8 - ���������� ������" << endl;
        cout << "  ������� ��� �������� -> (1-8): ";
        cin >> var;
        switch (var) {
        default:break;
        case 1:
            if (proverka_file(fname_i, PR_R)) {
                cout << " ���� ���� ������ ���������� ��� � ������ " << fname_i;
                cout << " ��� ������ ������." << endl;
                cout << " ������ ���� � ����� ������? [Y/N] ";
                while ((otv = getchar()) == '\n');
                if (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�') {
                    cout << " ������� ��� ������������ �����: ";
                    cin >> fname_i;
                }
                else break;
            }
            if (!proverka_file(fname_i, PR_W)) {
                cout << "\n ������ �������� ����� ��� ������" << endl;
                break;
            }
            cout << " ������� ���� " << fname_i << endl;
            getchar();
            dobavka(fname_i);
            cout << "�������� ����� ���������." << endl;
            if (proverka_file(fname_i, PR_R))
                cout << " ���� ������ ������ � ������" << endl;
            else cout << "���� �� �������" << endl;
            break;

        case 2:
            if (proverka_file(fname_i, PR_R)) {
                cout << " ���� ���� ������ ���������� ��� � ������ " << fname_i;
                cout << " ��� ������ ������.";
                cout << " ����� ��������� ����� ������ � ����? [Y/N] ";
                while ((otv = getchar()) == '\n');
                if (otv == 'N' || otv == 'n' || otv == '�' || otv == '�') {
                    cout << " ������� ��� ����� ������ ����: ";
                    cin >> fname_i;
                    if (!proverka_file(fname_i, PR_R)) {
                        cout << " ����� ���� ������ �� �����������" << endl;
                        break;
                    }
                }
            }
            cout << " ��������� ������ � ���� " << fname_i << endl;
            dobavka(fname_i);
            cout << "\n ��������� ����� ���������.";
            break;

        case 3:
            if (!proverka_file(fname_i, PR_S)) {
                cout << "\n ������ �������� ����� ��� ������ � ������" << endl;
                break;
            }
            sort_title(fname_i);
            cout << "\n ���������� �� �������� ��� ���������.";
            break;

        case 4:
            if (!proverka_file(fname_i, PR_S)) {
                cout << "\n ������ �������� ����� ��� ������ � ������" << endl;
                break;
            }
            sort_lenght(fname_i);
            cout << "\n ���������� �� ������ ��� ���������.";
            break;

        case 5:
            if (!proverka_file(fname_i, PR_R)) {
                cout << "\n ������ �������� ����� ��� ������" << endl;
                break;
            }
            if (!proverka_file(fname_r, PR_W)) {
                cout << "\n ������ �������� ����� ��� ������" << endl;
                break;
            }
            sort_owner(fname_i, fname_r);
            cout << "\n ����� �� ����� ���������� ���� ��������.";
            break;

        case 6:
            if (!proverka_file(fname_i, PR_R)) {
                cout << "\n ������ �������� ����� ��� ������" << endl;
                break;
            }
            prosmotrbd1(fname_i);
            break;

        case 7:
            if (!proverka_file(fname_r, PR_R)) {
                cout << "\n ������ �������� ����� ��� ������" << endl;
                break;
            }
            prosmotrbd2(fname_r);
            break;

        case 8:
            return 0;
        }
    }
}

//���������� ����� ��������� � ���� ������
void dobavka(const char* fname) {
    char otv;
    trip ship{};
    FILE* baza;
    baza = fopen(fname, PR_A);
    rewind(baza);
    do {
        cout << "\n �������� ����? ";
        cin >> ship.title;

        cout << " ��� ���������? ";
        cin >> ship.owner;

        cout << " ������ ����? (�.) ";
        cin >> ship.lenght;

        cout << " ���������? (���.$) ";
        cin >> ship.cost;

        cout << " ��� ���������? ";
        cin >> ship.yearsOld;

        fwrite(&ship, sizeof(ship), 1, baza);

        cout << "\n ����������?[Y/N]";
        while ((otv = getchar()) == '\n');
    } while (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�');
    fclose(baza);
    return;
}

//����� ��������� ��� ��������� ��������� �����
void zag1() {
    int i;
    cout << endl;
    for (i = 1; i <= 80; i++)
        cout << "-";
    cout << endl;
    cout << "| �������� ���� |" << " ��� ��������� |" << " ������, � |" << " ���������, ���.$ |" << " ��� ��������� |" << endl;

    for (i = 1; i <= 80; i++)
        cout << "-";
    return;
}

//����� ��������� ��� ��������� ����� ������ ����� ���������
void zag2() {
    int i;
    cout << endl;
    for (i = 1; i <= 80; i++)
        cout << "-";
    cout << endl;
    //cout("|%15s|%15s|%11s|%18s|%15s|\n", "��� ��������� ", "�������� ���� ", "�����, �", "���������, ���.$", "��� ���������");
    cout << "| �������� ���� |" << " ��� ��������� |" << " ������, � |" << " ���������, ���.$ |" << " ��� ��������� |" << endl;
    for (i = 1; i <= 80; i++)
        cout << "-";
    return;
}

//�������� ���� ������ ���������� ���
void prosmotrbd1(const char* fname) {
    int i;
    trip ship;
    FILE* baza;
    baza = fopen(fname, PR_R);
    cout << "\n     ���� ������ ���������� ���";
    zag1();
    while (fread(&ship, sizeof(ship), 1, baza) > 0) {
        cout << endl;
        cout.width(16); cout << ship.title << "|";
        cout.width(15); cout << ship.owner << "|";
        cout.width(11); cout << ship.lenght << "|";
        cout.width(18); cout << ship.cost << "|";
        cout.width(15); cout << ship.yearsOld << "|";

    }
    cout << endl;
    for (i = 1; i <= 80; i++)
        cout << "-";
    fclose(baza);
    return;
}

//�������� ���� ������ ������ �� ����� ��������� ���
void prosmotrbd2(const char* fname) {
    int i;
    trip ship;
    FILE* baza;
    baza = fopen(fname, PR_R); //��������� ���� �� ������
    cout << "\n  ���� ������ ������ ���������� ��� �� ����� ���������";
    zag2();
    while (fread(&ship, sizeof(ship), 1, baza) > 0) {
        //cout << "\n|%15s|%15s|%11i|%18i|%15s|" << ship.owner << ship.title << ship.lenght << ship.cost << ship.yearsOld;
        cout << endl;
        cout.width(16); cout << ship.owner << "|";
        cout.width(15); cout << ship.title << "|";
        cout.width(11); cout << ship.lenght << "|";
        cout.width(18); cout << ship.cost << "|";
        cout.width(15); cout << ship.yearsOld << "|";

    }
    cout << endl;
    for (i = 1; i <= 80; i++)
        cout << "-";
    fclose(baza);
    return;
}

//����� ��� �� ����� ���������
void sort_owner(const char* fname1, const char* fname2) {
    char ownerName[15];
    trip ship;
    FILE* in,     //�������� ����
        * out;    //���� ����������� ������
    in = fopen(fname1, PR_R);  //��������� ���� �� ������
    out = fopen(fname2, PR_W);  //��������� ���� �� ������
    cout << "\n ��� ��������� ���� ��� ������? ";
    cin >> ownerName;
    while (fread(&ship, sizeof(ship), 1, in) > 0)
        if (strncmp(ship.owner, ownerName, 15) == 0)
            fwrite(&ship, sizeof(ship), 1, out);
    fclose(out);
    fclose(in);
    return;
}

//���������� �� �������� ��� �� ��������
void sort_title(const char* fname) {
    int i;
    int fl;
    trip ppp, ship;
    FILE* baza;
    baza = fopen(fname, PR_S); //��������� ���� �� ������ � ������
    do {
        rewind(baza);
        fl = 0;
        for (i = 0; fread(&ship, sizeof(ship), 1, baza) > 0; i += sizeof(ship), fseek(baza, i, SEEK_SET)) {
            if (fread(&ppp, sizeof(ship), 1, baza) > 0) {
                if (strncmp(ship.title, ppp.title, 15) > 0) {
                    fseek(baza, i, SEEK_SET); //������� i �� ������ �����
                    fwrite(&ppp, sizeof(ship), 1, baza);
                    fwrite(&ship, sizeof(ship), 1, baza);
                    fl = 1;
                }
            }
        }
    } while (fl);
    fclose(baza);
    return;
}

//���������� �� �������� ������ ����
void sort_lenght(const char* fname) {
    int i;
    int fl;
    trip ppp, ship;
    FILE* baza;
    baza = fopen(fname, PR_S); //��������� ���� �� ������ � ������
    do {
        rewind(baza);
        fl = 0;
        for (i = 0; fread(&ship, sizeof(ship), 1, baza) > 0; i += sizeof(ship), fseek(baza, i, SEEK_SET)) {
            if (fread(&ppp, sizeof(ship), 1, baza) > 0) {
                if (ship.lenght > ppp.lenght) {
                    fseek(baza, i, SEEK_SET); //������� i �� ������ �����
                    fwrite(&ppp, sizeof(ship), 1, baza);
                    fwrite(&ship, sizeof(ship), 1, baza);
                    fl = 1;
                }
            }
        }
    } while (fl);
    fclose(baza);
    return;
}

//�������� ������� ����������� �����
int proverka_file(const char* fname, const char* pr) {//��������� ����
    if (!(fopen(fname, pr)))
        return(0);
    return(1);
}