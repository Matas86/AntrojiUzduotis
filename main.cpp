#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main()
{
    int N;
    cout<<"Iveskite studentu skaiciu: \n";
    while(!(cin >> N) || N<0)
    {
        cout << "Bloga ivestis! Iveskite studentu skaiciu skaitmeniu";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"\n";
    }
    string name[N], surname[N];
    int homeworkCount[N];
    int homeworkSum[N];
    int homework[N][1000], exam[N];
    double finalGrade[N];
    for(int i=0; i<N; i++)
    {
        cout<<"Iveskite savo varda: \n";
        while(!(cin >> name[i]))
        {
            cout << "Bloga ivestis! Iveskite savo varda";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n";
        }
        cout<<"Iveskite savo pavarde: \n";
        while(!(cin >> surname[i]))
        {
            cout << "Bloga ivestis! Iveskite savo pavarde";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n";
        }
        cout<<"Iveskite savo namu darbu uzduociu skaiciu: \n";
        while(!(cin >> homeworkCount[i]) || homeworkCount[i]<0)
        {
            cout << "Bloga ivestis! Iveskite savo namu darbu uzduociu skaiciu";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n";
        }
        homeworkSum[i] = 0;
        for(int j=0; j<homeworkCount[i]; j++)
        {
            cout<<"Iveskite savo " << j+1 << " namu darbu bala: \n";

            while(!(cin >> homework[i][j]) || homework[i][j] >10 || homework[i][j]<0)
            {
                cout << "Bloga ivestis! Iveskite savo namu darbu bala skaiciumi (0-10)";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"\n";
            }
            homeworkSum[i] += homework[i][j];
        }
        cout<<"Iveskite savo egzamino bala: \n";
        while(!(cin >> exam[i]) || exam[i] >10 || exam[i]<0)
        {
            cout << "Bloga ivestis! Iveskite savo namu darbu bala skaiciumi";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n";
        }
        finalGrade[i] = ((homeworkSum[i]*1.0/homeworkCount[i]) * 0.4) + (0.6*exam[i]);
    }

    cout<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Vardas"<<setw(20)<<"Galutinis (Vid.)"<<endl;
    cout<<"-------------------------------------------------"<<endl;


    for(int i=0; i<N; i++)
    {
        cout<<setw(20)<<left<<surname[i]<<setw(10)<<left<<name[i]<<setw(10)<<left<<fixed<<setprecision(2)<<finalGrade[i]<<"\n";
    }

}

