#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

struct student
{
    string name;
    string surname;
    int homeworkCount;
    int homeworkSum;
    vector<int> homework;
    int exam;
    double finalGrade;
};

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

    student stud[N];

    for(int i=0; i<N; i++)
    {
        cout<<"Iveskite savo varda: \n";
        while(!(cin >> stud[i].name))
        {
            cout << "Bloga ivestis! Iveskite savo varda";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n";
        }

        cout<<"Iveskite savo pavarde: \n";
        while(!(cin >> stud[i].surname))
        {
            cout << "Bloga ivestis! Iveskite savo pavarde";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n";
        }

        int skc;
        bool veda;
        string ats;
        skc = 0;
        veda = true;
        int skaicius;
        stud[i].homeworkSum = 0;
        while(veda)
        {
            cout<<"Iveskite savo " << skc+1 << " namu darbu bala: \n";

            while(!(cin >> skaicius || skaicius>10 || skaicius<0))
            {
                cout << "Bloga ivestis! Iveskite savo namu darbu bala skaiciumi (0-10)";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"\n";
            }
            stud[i].homeworkSum += skaicius;
            skc++;
            stud[i].homework.push_back(skaicius);
            cout<<"Ar norite toliau vesti namu darbu balus? (taip - y, ne - n) \n";
            cin>>ats;
            if(ats == "n")
            {
                veda=false;
                stud[i].homeworkCount = skc;
            }
        }



        cout<<"Iveskite savo egzamino bala: \n";
        while(!(cin >> stud[i].exam) || stud[i].exam >10 || stud[i].exam<0)
        {
            cout << "Bloga ivestis! Iveskite savo namu darbu bala skaiciumi";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n";
        }
        stud[i].finalGrade = ((stud[i].homeworkSum*1.0/stud[i].homeworkCount) * 0.4) + (0.6*stud[i].exam);

    }

    cout<<"Norite gauti vidurki ar mediana? (Vidurkis - v, Mediana - m \n";
    string temp;

    cin>>temp;
    if(temp == "v")
    {
        cout<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Vardas"<<setw(20)<<"Galutinis (Vid.)"<<endl;
        cout<<"-------------------------------------------------"<<endl;


        for(int i=0; i<N; i++)
        {
            cout<<setw(20)<<left<<stud[i].surname<<setw(10)<<left<<stud[i].name<<setw(10)<<left<<fixed<<setprecision(2)<<stud[i].finalGrade<<"\n";
        }
    }
    else if( temp == "m")
    {
        cout<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Vardas"<<setw(20)<<"Galutinis (Med.)"<<endl;
        cout<<"-------------------------------------------------"<<endl;

        for(int i=0; i<N; i++)
        {

            /*for(int j = 0; j<homeworkCount[i]-1; j++)
            {
                for(int k = j+1; k<homeworkCount[i]; k++)
                {
                    if(homework[i][j]>homework[i][k])
                    {
                        int tempas;
                        tempas= homework[i][j];
                        homework[i][j] = homework[i][k];
                        homework[i][k] = tempas;
                    }
                }
            }*/

            sort(stud[i].homework.begin(), stud[i].homework.end());


            if(stud[i].homeworkCount%2==1)
            {

                cout<<setw(20)<<left<<stud[i].surname<<setw(10)<<left<<stud[i].name<<setw(10)<<left<<fixed<<setprecision(2)<<stud[i].homework[(stud[i].homeworkCount)/2]<<"\n";
            }
            else
            {
                cout<<setw(20)<<left<<stud[i].surname<<setw(10)<<left<<stud[i].name<<setw(10)<<left<<fixed<<setprecision(2)<<(stud[i].homework[(stud[i].homeworkCount)/2 - 1] + stud[i].homework[((stud[i].homeworkCount)/2)])/2.0<<"\n";
            }

        }
    }


    else
    {
        cout<<"Bloga įvestis. \n";
    }


}

