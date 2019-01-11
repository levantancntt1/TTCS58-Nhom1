#include <iostream>
#include <fstream>

using namespace std;

class Cauhoi
{
    public:
         virtual void Docfile(ifstream &f) = 0;
         virtual void Xuat() = 0;
         virtual bool KTKQ() = 0;
};

class DScauhoi: public Cauhoi
{
    public:
        string cauhoi, luachon[4];
        char dapandung;

    public:
        void Docfile(ifstream &f);
        void Xuat();
        bool KTKQ();
};
void  DScauhoi::Docfile(ifstream &f)
        {
            getline(f, cauhoi);
            for (int i = 0; i < 4; i ++)
                getline(f, luachon[i]);
            f >> dapandung;
        }

void DScauhoi::Xuat()
        {
            cout << cauhoi << '\n';
            for (int i = 0; i < 4; i ++)
            {
                char label = 'A' + i; // 'A' + 1 = 'B'
                cout << label << ": " << luachon[i] << '\n';
            }
        }

bool DScauhoi:: KTKQ()
        {
            char traloi; cin >> traloi;
            if (traloi == dapandung)
            {
                cout << "Cau tra loi dung!\n";
                return true;
            }
            else
            {
                cout << "Cau tra loi sai! Cau tra loi dung la " << dapandung << '\n';
                return false;
            }
        }


char Tenfile[100];
int n, diem = 0;
Cauhoi *Cauhois[1000];

int main()
{
    cout << "Hay nhap file cau hoi (vd: inputquiz.txt): ";
    cin >> Tenfile;
    ifstream f; f.open(Tenfile);
    f >> n;
    for (int i = 1; i <= n; i ++)
    {
       string dong; 
	   getline(f, dong); 
       Cauhois[i] = new DScauhoi;
       Cauhois[i]->Docfile(f);
    }

    for (int i = 1; i <= n; i ++)
    {
        Cauhois[i]->Xuat();
        if (Cauhois[i]->KTKQ())
            diem++;
    }

    cout << "So diem cua ban: " <<diem;
    return 0;
}
