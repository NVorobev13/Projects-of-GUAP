#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#define FNAME_I "D:\\bd15.dat\0" //��� ����� � �������� �����
#define FNAME_R "D:\\bd25.dat\0" //��� ����� � ������������ ������
using namespace std;

class account
{
	int idDogovora;
	char name[25];
	int birthY;
	char town[25];
	char telNubmer[11];
	char placeWork[30];
	double income;
	int deposit;
	char type;
	public:
		void create_account();		//������� ��� ��������� ������ �� ������������
		void show_account() const;	//������� ��� ����������� ������ �� ������
		void modify();				//������� ��� ���������� ����� ������
		void dep(int);				//������� ��� ������ ����� � ���������� � ����� �������
		void draw(int);				//������� ��� ������ ����� � ��������� �� ����� �������
		void report() const;		//������� ��� ����������� ������ � ��������� �������

		int retacno() const;		//������� ��� �������� id ��������
		int retdeposit() const;		//������� ��� �������� ����� �������
		char rettype() const;		//������� ��� �������� ���� ������� ������
		int retbirthY () const;		//������� ��� �������� ���� ��������
		double retincome () const;  //������� ��� �������� �������� ��������� 

};



void intro();							//������� �������� ������
int create_bd(const char*, const char*);//������� �������� ��
void create_user();						//������� ��� ������ ������ � �������� ����
void display_sp(int);					//������� ��� ����������� ���������� ������� ������, ��������������� �������������
void modify_account(int);				//������� ��� ��������� ������ �����
void delete_account(int);				//������� ��� �������� ������ �����
void display_all();						//������� ��� ����������� ���� �������� �� ������� ������
void deposit_withdraw(int, int);		//������� ��� ����������/������ ����� � ������� �����
void operations_rko();					//������� �������� ���
void settings_bd();						//������� ��������� ��
void sort_income();						//������� ���������� �� �� �� ������
void sort_town();						//������� ���������� �� �� ������


const char PR_R[] = "rb";				//������� �������� ��������� ����� �� ������
const char PR_S[] = "r+b";				//������� �������� ����� �� ������ � ������
const char PR_W[] = "wb";				//������� �������� ����� �� ������
const char PR_A[] = "ab";				//������� �������� ����� �� ����������

int main()
{
	char ch;
	char city;
	char otv;
	char fname_i[20] = FNAME_I;
	char fname_r[20] = FNAME_R;
	setlocale(LC_ALL, "Russian");
	intro();
	do
	{
		system("cls");
		cout << "\n\n\n\t������� ����";
		cout << "\n\n\t01. ������� ���� ������ ���";
		cout << "\n\n\t02. �������� ������� � ���� ������";
		cout << "\n\n\t03. ����������� ���� ������ �� �������� ��-�� ������";
		cout << "\n\n\t04. ����������� ���� ������ �� ������������� ��������";
		cout << "\n\n\t05. �������� ���";
		cout << "\n\n\t06. ������������� ���� ������";
		cout << "\n\n\t07. ����� �� ���������";


		cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";//������ ���� ���������� ������� �������";

		cout << "\n\n\t������� ����� �������� (1-7) ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1': //�������� ���� ������
			if (create_bd(fname_i, PR_R)) {
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
			if (!create_bd(fname_i, PR_W)) {
				cout << "\n ������ �������� ����� ��� ������" << endl;
				break;
			}
			cout << " ������� ���� " << fname_i << endl;
			getchar();
			create_user();
			cout << "�������� ����� ���������." << endl;
			if (create_bd(fname_i, PR_R))
				cout << " ���� ������ ������ � ������" << endl;
			else cout << "���� �� �������" << endl;
			break;

		case '2': //���������� ������� � ��
			create_user();
			break;
		case '3':
			if (!create_bd(fname_i, PR_S)) {
				cout << "\n ������ �������� ����� ��� ������ � ������" << endl;
				break;
			}
			sort_income();
			break;
		case '4':
			if (!create_bd(fname_i, PR_S)) {
				cout << "\n ������ �������� ����� ��� ������ � ������" << endl;
				break;
			}
			cout << "\n\n\t������� �������� ������, �� �������� ��������� ���������� ���������� : "; cin >> city;
			sort_town();
			break;
		case '5':
			operations_rko();
			break;
		case '6':
			settings_bd();
			break;
		case '7':
			cout << "\n\n\t���������� ��� �� ������������� ������ ��. �� ����� ������!";//������� �� ������������� ������� ���������� ������
			break;
		default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (ch != '7');
	return 0;
}

//������� �������� ������
void intro()
{
	cout << "\n\n\n\t            DATABASE";
	cout << "\n\n\t          ���� � ����";
	cout << "\n\n\t    ������� ���������� ���";
	cout << "\n\n\n\n��������: ������� ��. ������ Z1411";
	cout << "\n\n�������� �.�.";
	cin.get();
}

//������� ���������� �� �� ������
void sort_town() {

}

//������� ���������� �� �� �� ������
void sort_income() {

}

//������� ��� ������ ������ � �������� ����
void create_user()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
	outFile.close();
}

//������� ��� ����������� ���������� ������� ������, ��������������� �������������
void display_sp(int n)
{
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "���� �� ����� ���� ������! ������� ����� �������...";
		return;
	}
	cout << "\n�������� � �������\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		if (ac.retacno() == n)
		{
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\n��������� id ��������������� �������� - �� ����������.";
}

//������� ��� ��������� ������ �����
void modify_account(int n)
{
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "���� �� ����� ���� ������! ������� ����� �������...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			cout << "\n\n������� ���������� ������ ������� ������" << endl;//������� ����� ������ ������� ������
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t ������� ������ ���������.";//������ ���������
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n ������� ������ �� �������.";//������ �� �������
}

//������� ��� �������� ������ �����
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";//���� �� ������� ������� !! ������� ����� �������...
		return;
	}
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		if (ac.retacno() != n)
		{
			outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\n\n\tRecord Deleted .."; //������ �������
}

//������� ��� ����������� ���� �������� �� ������� ������
void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";//���� �� ������� ������� !! ������� ����� �������...
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";//������ ���������� ������� �������
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";//�����             ���              ��� �������
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//������� ��� ����������/������ ����� � ������� �����
void deposit_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";//���� �� ������� ������� !! ������� ����� �������...
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << "\n\n\tTO DEPOSITE AMOUNT ";//�� ����� ��������
				cout << "\n\nEnter The amount to be deposited";//�����, ���������� ��������
				cin >> amt;
				ac.dep(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\tTO WITHDRAW AMOUNT ";//��� ������ ����� 
				cout << "\n\nEnter The amount to be withdraw";//������� ����� ��� ������
				cin >> amt;
				int bal = ac.retdeposit() - amt;
				if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
					cout << "Insufficience balance";//������������� ������
				else
					ac.draw(amt);
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t Record Updated";//������ ��������� 
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";//������ �� ������� 
}

//������� �������� ���
void operations_rko()
{
	char ch;
	int num;
	do {
		system("cls");
		cout << "\n\n\n\t�������� ��������-��������� ������������";//������� ����
		cout << "\n\n\t01. ������ �������� ��������";
		cout << "\n\n\t02. ������� �������� ��������";//����� ������� ������
		cout << "\n\n\t03. ��������� ������";
		cout << "\n\n\t04. ��������� � ����";
		cout << "\n\n\t������� ����� �������� (1-4): ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			cout << "\n\n\t������� id �������� : "; cin >> num;//������� ����� ������� ������. :
			deposit_withdraw(num, 1);
			break;
		case '2':
			cout << "\n\n\t������� id �������� : "; cin >> num;//������� ����� ������� ������. :
			deposit_withdraw(num, 2);
			break;
		case '3':
			cout << "\n\n\t������� id �������� : "; cin >> num;//������� ����� ������� ������. : 
			display_sp(num);
			break;
		case '4':
			main();
			break;
		}
		cin.ignore();
		cin.get();
	} while (ch != '4');
	return;
}

//������� ��������� ��
void settings_bd()
{
	char ch;
	int num;
	do {
		system("cls");
		cout << "\n\n\n\t�������������� ���� ������";//������� ����
		cout << "\n\n\t01. �������� ������� ������";
		cout << "\n\n\t02. �������� ������� ������";//����� ������� ������
		cout << "\n\n\t03. ������� ������� ������";
		cout << "\n\n\t04. ��������� � ����";
		cout << "\n\n\t������� ����� �������� (1-4): ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			create_user();
			break;
		case '2':
			cout << "\n\n\t������� id �������� : "; cin >> num;//������� ����� ������� ������. :
			modify_account(num);
			break;
		case '3':
			cout << "\n\n\t������� id �������� : "; cin >> num;//������� ����� ������� ������. : 
			delete_account(num);
			break;
		case '4':
			main();
			break;
		}
		cin.ignore();
		cin.get();
	} while (ch != '4');
	return;
}

//������� �������� ��
int create_bd(const char* fname, const char* pr) {//��������� ����
	if (!(fopen(fname, pr)))
		return(0);
	return(1);


	/*create_bd(fname_i, PR_S) {
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
	outFile.close();*/

}


















//������� ��� ��������� ������ �� ������������
void account::create_account()
{
	cout << "\n������� id ��������������� �������� (6 ����, ������ ��������� � ������� ��������) :";
	cin >> idDogovora;
	cout << "\n\n������� ��� ������� : ";
	cin.ignore();
	cin.getline(name, 25);
	cout << "\n������� ��� ������� : ";
	cin >> birthY;
	cout << "\n������� ����� ���������� : ";
	cin.ignore();
	cin.getline(town, 25);
	cout << "\n������� ���������� ����� �������� (� ������� 89**) : ";
	cin.ignore();
	cin.getline(telNubmer, 11);
	cout << "\n\n������� ����� ������ (������������ �����������): ";
	cin.ignore();
	cin.getline(placeWork, 30);
	cout << "\n������� ������� ����������� ����� ������� (���. ���.) : ";
	cin >> income;
	cout << "\n������� ��� ������� ������ (������ (W)/���������� (A)) : "; //������� ��� ������� ������ (C/S) 
	cin >> type;
	type = toupper(type);
	cout << "\n������� �����, �������� �� �/� (���. ���.) : ";
	cin >> deposit;
	cout << "\n\n\n������� ������ �������.";
}

//������� ��� ����������� ������ �� ������
void account::show_account() const
{
	cout << "\nAccount No. : " << idDogovora;//����� ������� ������.
	cout << "\nAccount Holder Name : "; //��� ��������� ������� ������ : 
	cout << name; 	//���
	cout << "\nType of Account : " << type;	//��� ������� ������ : 
	cout << "\nBalance amount : " << deposit;	//����� ������� :
}

//������� ��� ���������� ����� ������
void account::modify()
{
	cout << "\n������� id ��������������� �������� (6 ����, ������ ��������� � ������� ��������) :";
	cin >> idDogovora;
	cout << "\n\n������� ���������� ��� ������� : ";
	cin.ignore();
	cin.getline(name, 25);
	cout << "\n������� ���������� ��� ������� : ";
	cin >> birthY;
	cout << "\n������� ���������� ����� ���������� : ";
	cin.ignore();
	cin.getline(town, 25);
	cout << "\n������� ���������� ���������� ����� �������� (� ������� 89**) : ";
	cin.ignore();
	cin.getline(telNubmer, 11);
	cout << "\n\n������� ���������� ����� ������ (������������ �����������): ";
	cin.ignore();
	cin.getline(placeWork, 30);
	cout << "\n������� ������� ����������� ����� ������� (���. ���.) : ";
	cin >> income;
	cout << "\n������� ��� ������� ������ (������ (W)/���������� (A)) : "; //������� ��� ������� ������ (C/S) 
	cin >> type;
	type = toupper(type);
	cout << "\n������� �����, �������� �� �/� (���. ���.) : ";
	cin >> deposit;
}

//������� ��� ������ ����� � ���������� � ����� �������
void account::dep(int x)
{
	deposit += x;
}

//������� ��� ������ ����� � ��������� �� ����� �������
void account::draw(int x)
{
	deposit -= x;
}

//������� ��� ����������� ������ � ��������� �������
void account::report() const
{
	cout << idDogovora << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}

//������� ��� �������� ������ �����
int account::retacno() const
{
	return idDogovora;
}

//������� ��� �������� ����� �������
int account::retdeposit() const
{
	return deposit;
}

//������� ��� �������� ���� ������� ������
char account::rettype() const
{
	return type;
}

//������� ��� �������� ���� ��������
int account::retbirthY() const
{
	return birthY;
}

//������� ��� �������� �������� ��������� 
double account::retincome() const
{
	return income;
}

