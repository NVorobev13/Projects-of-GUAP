#include<iostream>
#include<locale.h>
using namespace std;
typedef int telem;		//����������� ���� ��������� �������
typedef telem* tstr;		//����������� ���� "��������� �� telem"
typedef tstr* tmatr;		//��� "��������� �� ��������� �� telem"
void fillArray(tmatr, int);
void showArray(tmatr, int);
double zona_pr(tmatr arr, int n);
double zona_tr(tmatr arr, int n);

int main() 
{
    int n;				//����� ����� (��������) �������
    double pr, tr, sr;
    tmatr arr;				//����������-��������� �� ��������� �� telem
    setlocale(LC_ALL, "Russian");
    cout << " � �������� ���������� ������� ������� 2n*2n \n";
    cout << " ����� ������� �������������� �������� \n";
    cout << " ������������� ��������� ������� [5+6+7+8+1]. \n";
    cout << " ������� �������� ������� �������: n = ";
    cin >> n;
    arr = new tstr[2 * n];		/*��������� ������������ ������ ��� ������ ���������� �� ������ �������*/
    for (int i = 0; i < 2 * n; i++)	//��������� ������ ��� ������ ������:
        *(arr + i) = new telem[2 * n];	/*������� �������� ������� ���������� �� ������ ������������� ����� ������ ������� ������, ���������� ��� ������*/
    fillArray(arr, 2 * n);
    cout << " �������� �������:\n";
    showArray(arr, 2 * n);
    pr = zona_pr(arr, n);
    tr = zona_tr(arr, n);
    sr = (pr + tr) / 2;

    cout << " ������� �������������� �������� ������������� ���������: " << sr << endl;
    cout << endl << " ��� ���������� ������� <Enter>" << endl; //������������ ������������ ������
    for (int i = 0; i < n * 2; i++)
        delete* (arr + i);
    delete[]arr;
    return 0;
}

void fillArray(tmatr arr, int n)
{
    cout << " �������� ���������";
    cout << " ������� ������� " << n << "x" << n;
    cout << "\n ��� ������������ �������� �������������:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(*(arr + i) + j) = -(10 * i + j);
        }
    }
        
}

void showArray(tmatr arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(3);	//������ ���� ���������� ���������
            cout << *(*(arr + i) + j) << ' ';
        }
        cout << '\n';
    }
}

double zona_pr(tmatr arr, int n)
{
    telem sum = 0;
    double avg;
    int count = 0;
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < n; j++) {
            if (*(*(arr + i) + j) < 0) {
                count++;    //������� ����������� �� 1
                sum += *(*(arr + i) + j);    //����� ����������� �� �������� ��������
            }
        }
    } 
    avg = sum * 1. / count;
    return avg;
}

double zona_tr(tmatr arr, int n)
{
    telem sum = 0;
    double avg;
    int count = 0;

    for (int i = n; i < n * 2; i++) {
        for (int j = (n * 2) - i; j < n * 2; j++) {
            if (*(*(arr + i) + j) < 0) {
                count++;    //������� ����������� �� 1
                sum += *(*(arr + i) + j);    //����� ����������� �� �������� ��������
            }
        }
    }
    avg = sum * 1. / count;
    return avg;
}