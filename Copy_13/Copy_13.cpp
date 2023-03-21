#include <stdio.h>
#include <string.h>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <iostream>
#define FNAME_B "Hands_in_Hand.dat" //��� ����� � �������� �����
#define FNAME_T "searchTown.dat" //��� ����� � ������������ ������
#define FNAME_ID "searchID.dat" //��� ����� � ������������ ������

using namespace std;

void intro();	//������� �������� ������
int proverka_file(const char*, const char*); //�������� ������� �����
void dobavka(const char* fname);

void zag1();
void zag2();
void zag3();
void prosmotrbd1(const char* fname);
void prosmotrbd3(const char* fname);
void prosmotrbd2(const char* fname);
void sort_town(const char* fname1, const char* fname2);
void sort_income(const char* fname);
void operations_rko(const char* fname1, const char* fname2); //������� �������� ���
void settings_bd();
void sort_ID(const char* fname_i, const char* fname2);		//������� ��� ����������� ���������� ������� ������, ��������������� �������������
void sort_title(const char* fname);
void deposit_withdraw(const char* fname, int, int);

void show_account();
void dep(int);							//������� ��� �������� ����� � ���������� � ����� �������
void draw(int);							//������� ��� �������� ����� � ��������� �� ����� �������

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

    char idDogovora[7];
    int birthY;
    char name[20];
    char town[25];
    char telNubmer[12];
    char placeWork[30];
    char type[12];
    double deposit;
    double income;

    
}
trip;

void show_account()
{
    trip ship;
    cout << "\n Id ��������������� ��������: " << ship.idDogovora;
    cout << "\n ��� �������: " << ship.name;
    cout << "\n ��� ��������: " << ship.birthY;
    cout << "\n ����� ����������: " << ship.town;
    cout << "\n ���������� ����� ��������: " << ship.telNubmer;
    cout << "\n ����� ������: " << ship.placeWork;
    cout << "\n ������� ����������� �����: " << ship.income;
    cout << "\n ��� ������� ������ (������ (W)/���������� (A)): " << ship.type;
    cout << "\n ������ ������� ������: " << ship.deposit;
}

void dep(int x)
{
    trip ship{};
    ship.deposit += x;
}

void draw(int x)
{
    trip ship{};
    ship.deposit -= x;
}


void intro()
{
    cout << "\n\n\n\t            DATABASE";
    cout << "\n\n\t          ���� � ����";
    cout << "\n\n\t    ������� ���������� ���";
    cout << "\n\n\n\n��������: ������� ��. ������ Z1411";
    cout << "\n\n�������� �.�.";
    cin.get();
}

int main() {
    {
        char otv;
        char fname_b[25] = FNAME_B;
        char fname_t[25] = FNAME_T;
        char fname_id[25] = FNAME_ID;

        setlocale(LC_ALL, "Russian");
        char ch;
        intro();
        do
        {
            system("cls");
            cout << "\n\n\n\t ������� ����";
            cout << "\n\n\t 01. ������� ���� ������ ���";
            cout << "\n\n\t 02. ������� ������ ��������";
            cout << "\n\n\t 03. ���������� �� �������� ������������ ������ ��������";
            cout << "\n\n\t 04. ���������� �� �������������� ��������";
            cout << "\n\n\t 05. ��������� ���������� ��������";
            cout << "\n\n\t 06. ������������� ���� ������ ���������";
            cout << "\n\n\t 07. �����" << endl;
            cout << "  1 - �������� ���� ������" << endl;
            cout << "  2 - ���������� ����� �������" << endl;
            cout << "  4 - ���������� �� �������� ���" << endl;//case3
            cout << "  3 - ���������� �� ������ ���" << endl;//case4
            cout << "  5 - ����� ��� �� ����� ���������" << endl;
            cout << "  6 - �������� ���� ������" << endl;
            cout << "  7 - �������� ���� ������ ������ ���" << endl;
            cout << "  8 - ���������� ������" << endl;
            cout << "\n\n\t ������� ����� �������� (1-7) ";
            cin >> ch;
            system("cls");
            switch (ch)
            {
            case '1':
                if (proverka_file(fname_b, PR_R)) {
                    cout << " ���� ���� ������ ��� � ������ " << fname_b;
                    cout << " ��� ������ �����." << endl;
                    cout << " ������� ���� � ����� ������? [Y/N] ";
                    while ((otv = getc(stdin)) == '\n');
                    if (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�') {
                        cout << " ����� �������� ���� ������ ��� �� �����. (���������� ����� ������� ���������� .dat): ";
                        cin >> fname_b;
                    }
                    else if (otv == 'N' || otv == 'n' || otv == '�' || otv == '�')
                    {
                        cout << "\n ��� �������� � ������� ����, ����������, ������� <Enter>.";
                        int main();
                        break;
                    }
                    else {
                        cout << "\n �� �� ������ ���������� ��� �����. ��������� ��� � ������� ����." << endl;
                        int main();
                        break;
                    }
                }
                if (!proverka_file(fname_b, PR_W)) {
                    cout << "\n ������ �������� ����� ��� ������." << endl;
                    break;
                }
                cout << " ������� ���� " << fname_b << endl;
                cout << " �� ������ ���������� ������ � ��������� ����? [Y/N]: ";
                while ((otv = getc(stdin)) == '\n');
                if (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�') {
                    dobavka(fname_b);
                    break;
                }
                else if (otv == 'N' || otv == 'n' || otv == '�' || otv == '�') {
                    cout << "\n ��� �������� � ������� ����, ����������, ������� <Enter>.";
                    int main();
                    break;
                }
                else {
                    cout << "\n �� �� ������ ���������� ��� �����. ��������� ��� � ������� ����." << endl;
                    int main();
                    break;
                }
                cout << "\n �������� ����� ���������." << endl;
                if (proverka_file(fname_b, PR_R)) {
                    cout << " ���� ������ ��� ������ � ������. ����������, ������� <Enter>" << endl;
                }
                else {
                    cout << "\n ���� �� �������." << endl;
                }
                break;

            case '2':
                if (proverka_file(fname_b, PR_R)) {
                    cout << " ���� ���� ������ ��� � ������ " << fname_b;
                    cout << " ��� ������ �����.";
                    cout << "\n ���������� ���������� �������� � ������ �����? [Y/N]: ";

                    while ((otv = getc(stdin)) == '\n');
                    if (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�') {
                        dobavka(fname_b);
                        break;
                    }
                    else if (otv == 'N' || otv == 'n' || otv == '�' || otv == '�') {
                        cout << " ������� ��� ����� ������������ ����� (���������� ����� ������� ���������� .dat): ";
                        cin >> fname_b;
                        if (!proverka_file(fname_b, PR_R)) {
                            cout << " ����� ���� ������ �� �����������." << endl;
                            cout << " \n������ ����� ���� ���� ������." << endl;
                            cout << " ����� �������� ���� ������ ��� �� �����. (���������� ����� ������� ���������� .dat): ";
                            cin >> fname_b;
                            cout << " ������ ���������� ���������� ���� ������? [Y/N]: ";

                            while ((otv = getc(stdin)) == '\n');
                            if (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�') {
                                dobavka(fname_b);
                                break;
                            }
                            else if (otv == 'N' || otv == 'n' || otv == '�' || otv == '�')
                            {
                                cout << "\n ��� �������� � ������� ����, ����������, ������� <Enter>.";
                                int main();
                                break;
                            }
                            else {
                                cout << "\n �� �� ������ ���������� ��� �����. ��������� ��� � ������� ����." << endl;
                                int main();
                                break;
                            }
                        }
                    }
                    else {
                        cout << "\n �� �� ������ ���������� ��� �����. ��������� ��� � ������� ����." << endl;
                        int main();
                        break;
                    }
                }
                cout << " ��������� ������ � ���� " << fname_b << endl;
                dobavka(fname_b);
                cout << "\n ���� ���� ������ ������� ��������.";
                break;

            case '3':
                if (!proverka_file(fname_b, PR_S)) {
                    cout << "\n ������ �������� ����� ��� ������ � ������" << endl;
                    break;
                }
                sort_income(fname_b);
                prosmotrbd1(fname_b);
                cout << "\n\n\t ���������� �� �������� ������������ ������ �������� ���������.";
                cout << "\n\n\t ��� �����������, ����������, ������� <Enter>" << endl;
                break;

            case '4':
                if (!proverka_file(fname_b, PR_R)) {
                    cout << "\n ������ �������� ����� ��� ������" << endl;
                    break;
                }
                if (!proverka_file(fname_t, PR_W)) {
                    cout << "\n ������ �������� ����� ��� ������" << endl;
                    break;
                }
                sort_town(fname_b, fname_t);
                prosmotrbd2(fname_t);
                cout << "\n\n\t ���������� �� �������������� �������� ���������.";
                cout << "\n\n\t ��� �����������, ����������, ������� <Enter>" << endl;
                break;

            case '5':
                operations_rko(fname_b, fname_id);
                break;

            case '6':
                settings_bd();
                break;

            case '11':
                if (!proverka_file(fname_b, PR_S)) {
                    cout << "\n ������ �������� ����� ��� ������ � ������" << endl;
                    break;
                }
                sort_title(fname_b);
                cout << "\n ���������� �� �������� ��� ���������.";
                break;



            case '8':
                if (!proverka_file(fname_b, PR_R)) {
                    cout << "\n ������ �������� ����� ��� ������" << endl;
                    break;
                }
                prosmotrbd1(fname_b);
                break;

            case '7':
                cout << "\n\n\t���������� ��� �� ������������� ������ ��. \n\n\t\t\t�� ����� ������!";
                break;
            default:cout << "\a";
            }
            cin.ignore();
            cin.get();
        } while (ch != '7');
        return 0;
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
        cout << "\n ������� id ��������������� �������� (6 ����, ������ ��������� � ������� ��������) : ";
        cin >> ship.idDogovora;
        cout << " ������� ��� �������: ";
        cin.ignore();
        cin.getline(ship.name, 25);
        cout << " ������� ��� �������: ";
        cin >> ship.birthY;
        cout << " ������� ����� ����������: ";
        cin.ignore();
        cin.getline(ship.town, 25);
        cout << " ������� ���������� ����� �������� (� ������� 89**): ";
        cin >> ship.telNubmer;
        cout << " ������� ����� ������ (������������ �����������): ";
        cin >> ship.placeWork;
        cout << " ������� ������� ����������� ����� ������� (���. ���.): ";
        cin >> ship.income;
        cout << " ������� ��� ������� ������ (Bring_out / Insert): ";
        cin.ignore();
        cin.getline(ship.type, 12);
        cout << " ������� �����, �������� �� �/� (���. ���.): ";
        cin >> ship.deposit;
        cout << "\n ������� ������ �������.\n" << endl;
        fwrite(&ship, sizeof(ship), 1, baza);
        cout << "\n ����������?[Y/N]";

        while ((otv = getc(stdin)) == '\n');
    } while (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�');

    cout << "\n ��� �������� � ������� ����, ����������, ������� <Enter>.";
    fclose(baza);
    return;
}


//***************************************************************
//    		������� ��� ������ ������ ���� ������
//****************************************************************

void zag1() {
    int i;
    cout << endl << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    cout << endl;
    cout << "\t| ID �������� |" << " ��� ������� |" << " ��� �������� |" << "    �����     |" << " ���������� ������� |" << "   ����� ������   |" << " ��. ����� |" << " ������ |" << " ��� ����� |" << endl;
    cout << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    return;
}

void zag2() {
    int i;
    cout << endl << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    cout << endl;
    cout << "\t|    �����     |" << " ID �������� |" << " ��� ������� |" << " ��� �������� |" << " ���������� ������� |" << "   ����� ������   |" << " ��. ����� |" << " ������ |" << " ��� ����� |" << endl;
    cout << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    return;
}

void zag3() {
    int i;
    cout << endl << "\t";
    for (i = 1; i <= 51; i++)
        cout << "-";
    cout << endl;
    cout << "\t| ID �������� |" << " ��� ������� |" << " ������ |" << " ��� ����� |" << endl;
    cout << "\t";
    for (i = 1; i <= 51; i++)
        cout << "-";
    return;
}

void prosmotrbd1(const char* fname) {
    int i;
    trip ship;
    FILE* baza;
    baza = fopen(fname, PR_R);
    cout << "\n\n\n\t ���� ������ �����-���������� ����������� '���� � ����'\n\n";
    zag1();
    while (fread(&ship, sizeof(ship), 1, baza) > 0) {
        cout << endl << "\t|";
        cout.width(13); cout << ship.idDogovora << "|";
        cout.width(14); cout << ship.name << "|";
        cout.width(14); cout << ship.birthY << "|";
        cout.width(14); cout << ship.town << "|";
        cout.width(20); cout << ship.telNubmer << "|";
        cout.width(18); cout << ship.placeWork << "|";
        cout.width(11); cout << ship.income << "|";
        cout.width(8); cout << ship.deposit << "|";
        cout.width(11); cout << ship.type << "|";
    }
    cout << endl << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    fclose(baza);
    return;
}

void prosmotrbd2(const char* fname) {
    int i;
    trip ship;
    FILE* baza;
    baza = fopen(fname, PR_R); //��������� ���� �� ������
    cout << "\n\n\n\t ���� ������ �����-���������� ����������� '���� � ����'\n\n";
    zag2();
    while (fread(&ship, sizeof(ship), 1, baza) > 0) {
        cout << endl << "\t|";
        cout.width(14); cout << ship.town << "|";
        cout.width(13); cout << ship.idDogovora << "|";
        cout.width(14); cout << ship.name << "|";
        cout.width(14); cout << ship.birthY << "|";
        cout.width(20); cout << ship.telNubmer << "|";
        cout.width(18); cout << ship.placeWork << "|";
        cout.width(11); cout << ship.income << "|";
        cout.width(8); cout << ship.deposit << "|";
        cout.width(11); cout << ship.type << "|";
    }
    cout << endl << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    fclose(baza);
    return;
}

void prosmotrbd3(const char* fname) {
    int i;
    trip ship;
    FILE* baza;
    baza = fopen(fname, PR_R); //��������� ���� �� ������
    cout << "\n\n\n\t ������ ������������\n\n";
    zag3();
    while (fread(&ship, sizeof(ship), 1, baza) > 0) {
        cout << endl << "\t|";
        cout.width(13); cout << ship.idDogovora << "|";
        cout.width(14); cout << ship.name << "|";
        cout.width(8); cout << ship.deposit << "|";
        cout.width(11); cout << ship.type << "|";
    }
    cout << endl << "\t";
    for (i = 1; i <= 51; i++)
        cout << "-";
    fclose(baza);
    return;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//���������� �� �������� ��� �� ��������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

//�������� ������� ����������� �����
int proverka_file(const char* fname, const char* pr) {//��������� ����
    if (!(fopen(fname, pr)))
        return(0);
    return(1);
}

void settings_bd()
{
    char ch;
    int num;
    char otv;
    char fname_b[25] = FNAME_B;

    do {
        system("cls");
        cout << "\n\n\n\t �������������� ���� ������ ���������";
        cout << "\n\n\t 01. ������� ������ ���� ���������.";
        cout << "\n\n\t 02. �������� �ר���� ������ ��������.";
        cout << "\n\n\t 03. �������� �ר���� ������ ��������.";//����� ������� ������
        cout << "\n\n\t 04. ������� �ר���� ������ ��������.";
        cout << "\n\n\t 05. ��������� � ����" << endl;
        cout << "\n\t ������� ����� �������� (1-5): ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            if (!proverka_file(fname_b, PR_R)) {
                cout << "\n ������ �������� ����� ��� ������" << endl;
                break;
            }
            prosmotrbd1(fname_b);
            break;
        case '2':
            if (proverka_file(fname_b, PR_R)) {
                cout << " ���� ���� ������ ��� � ������ " << fname_b;
                cout << " ��� ������ �����.";
                cout << "\n ���������� ���������� �������� � ������ �����? [Y/N]: ";

                while ((otv = getc(stdin)) == '\n');
                if (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�') {
                    dobavka(fname_b);
                    break;
                }
                else if (otv == 'N' || otv == 'n' || otv == '�' || otv == '�') {
                    cout << " ������� ��� ����� ������������ ����� (���������� ����� ������� ���������� .dat): ";
                    cin >> fname_b;
                    if (!proverka_file(fname_b, PR_R)) {
                        cout << " ����� ���� ������ �� �����������." << endl;
                        cout << " \n������ ����� ���� ���� ������." << endl;
                        cout << " ����� �������� ���� ������ ��� �� �����. (���������� ����� ������� ���������� .dat): ";
                        cin >> fname_b;
                        cout << " ������ ���������� ���������� ���� ������? [Y/N]: ";

                        while ((otv = getc(stdin)) == '\n');
                        if (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�') {
                            dobavka(fname_b);
                            break;
                        }
                        else if (otv == 'N' || otv == 'n' || otv == '�' || otv == '�')
                        {
                            cout << "\n ��� �������� � ������� ����, ����������, ������� <Enter>.";
                            int main();
                            break;
                        }
                        else {
                            cout << "\n �� �� ������ ���������� ��� �����. ��������� ��� � ������� ����." << endl;
                            int main();
                            break;
                        }
                    }
                }
                else {
                    cout << "\n �� �� ������ ���������� ��� �����. ��������� ��� � ������� ����." << endl;
                    int main();
                    break;
                }
            }
            cout << " ��������� ������ � ���� " << fname_b << endl;
            dobavka(fname_b);
            cout << "\n ���� ���� ������ ������� ��������.";
            break;
        case '3':
            cout << "\n\n\t������� id �������� : "; cin >> num;
            //modify_account(fname_b, num);
            break;
        case '4':
            cout << "\n\n\t������� id �������� : "; cin >> num;
            //delete_account(num);
            break;
        case '5':
            cout << "\n\n\t ��� �����������, ����������, ������� <Enter>" << endl;
            break;
        }
        cin.ignore();
        cin.get();
    } while (ch != '5');
    return;
}

//***************************************************************
//    		������� ��� ��������� ������ �����
//****************************************************************

//***************************************************************
//    		������� ��� ���������� ��������� ���������� ��������
//****************************************************************

void operations_rko(const char* fname_b, const char* fname_id)
{
    int num;
    char ch;
    do {
        system("cls");
        cout << "\n\n\n\t ��������� ���������� �������� ";
        cout << "\n\n\t 01. ��������� ������� �ר�";
        cout << "\n\n\t 02. ����� � �������� �ר��";
        cout << "\n\n\t 03. ������� ������ �� �����";
        cout << "\n\n\t 04. ��������� � ������� ����" << endl;
        cout << "\n\n\t ������� ����� �������� (1-4): ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            if (!proverka_file(fname_b, PR_S)) {
                cout << "\n ������ �������� ����� ��� ������ � ������" << endl;
                break;
            }
            cout << "\n\t ������� ID ������ ���������: ";
            cin >> num;
            deposit_withdraw(fname_b, num, 1);


            break;
        case '2':
            if (!proverka_file(fname_b, PR_S)) {
                cout << "\n ������ �������� ����� ��� ������ � ������" << endl;
                break;
            }
            cout << "\n\t ������� ID ������ ���������: ";
            cin >> num;
            deposit_withdraw(fname_b, num, 2);


            break;
        case '3':

            if (!proverka_file(fname_b, PR_R)) {
                cout << "\n ������ �������� ����� ��� ������" << endl;
                break;
            }
            if (!proverka_file(fname_id, PR_W)) {
                cout << "\n ������ �������� ����� ��� ������" << endl;
                break;
            }
            sort_ID(fname_b, fname_id);
            prosmotrbd3(fname_id);
            cout << "\n\n\t ��� �����������, ����������, ������� <Enter>" << endl;
            break;

            //display_sp(fname1, fname2);
            break;
        case '4':
            cout << "\n\n\t ��� �����������, ����������, ������� <Enter>" << endl;
            break;
        }
        cin.ignore();
        cin.get();
    } while (ch != '4');
    return;
}

//***************************************************************
//    		������� ��� ��������/������ ����� ��� ������� �����
//****************************************************************

void deposit_withdraw(const char* fname_b, int n, int option)
{
    int amt;
    bool found = false;
    trip ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "������ �������� ����� ��� ������! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (&ac), sizeof(trip));
        if (ac.idDogovora[6] == n)
        {
            show_account();
            if (option == 1)
            {
                cout << "\n\n\t ���������� �������� �ר�� ";
                cout << "\n\n ������� �����, ���������� ��������: ";
                cin >> amt;
                dep(amt);
            }
            if (option == 2)
            {
                cout << "\n\n\t ������ � �������� �ר�� ";
                cout << "\n\n ������� �����, ���������� ������: ";
                cin >> amt;
                double bal = ac.deposit - amt;
                if ((bal < 500 && ac.type == "Bring_out") || (bal < 1000 && ac.type == "Insert"))
                    cout << " ����������� �������� �������!";
                else
                    draw(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*> (&ac), sizeof(trip));
            cout << "\n\n\t �������� �������� ���������! ";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n ��� ����������� ������ ���������! ";
}

//*******************************************************************************************
//    		������� ��� ����������� ������� �� ID ������� ������, ��������������� �������������
//*******************************************************************************************

void sort_ID(const char* fname1, const char* fname2)
{
    char searchID[7];
    trip ship;
    FILE* in,     //�������� ����
        * out;    //���� ����������� ������
    in = fopen(fname1, PR_R);  //��������� ���� �� ������
    out = fopen(fname2, PR_W);  //��������� ���� �� ������
    cout << "\n\t ������� ID �������� ��� �������� �������: ";
    cin >> searchID;
    while (fread(&ship, sizeof(ship), 1, in) > 0)
        if (strncmp(ship.idDogovora, searchID, 7) == 0)
            fwrite(&ship, sizeof(ship), 1, out);
    fclose(out);
    fclose(in);
    return;
}

//*******************************************************************************************
//    		������� ��� ���������� �� ����������� �������� ������������ ������ 
//*******************************************************************************************
void sort_income(const char* fname) {
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
                if (ship.income > ppp.income) {
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

//����� �� ������ ����������
//*******************************************************************************************
//    		������� ��� ����������� ���� ������ �� ������ ������� ������, ��������������� �������������
//*******************************************************************************************
void sort_town(const char* fname1, const char* fname2) {
    char searchTown[25];
    trip ship;
    FILE* in,     //�������� ����
        * out;    //���� ����������� ������
    in = fopen(fname1, PR_R);  //��������� ���� �� ������
    out = fopen(fname2, PR_W);  //��������� ���� �� ������
    cout << "\n\t ������� �����, �� �������� ���������� ��������� ������: ";
    cin >> searchTown;
    while (fread(&ship, sizeof(ship), 1, in) > 0)
        if (strncmp(ship.town, searchTown, 25) == 0)
            fwrite(&ship, sizeof(ship), 1, out);
    fclose(out);
    fclose(in);
    return;
}
