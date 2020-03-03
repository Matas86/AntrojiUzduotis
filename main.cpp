#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>
using namespace std;

struct student
{
    std::string name;
    std::string surname;
    int homeworkSum;
    std::vector<int> homework;
    int exam;
    double finalGrade;
    bool random;
    student()
    {
        homeworkSum = 0;
    }
};

int main()
{
    srand(time(NULL));
    int N;

    cout<<"Iveskite studentu skaiciu: \n";
    while(!(cin >> N) || N<0)
    {
        cout << "Bloga ivestis! Iveskite studentu skaiciu skaitmeniu";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"\n";
    }

    std::vector<student> stud;
    stud.reserve(N);
    string randomas;
    for(int i=0; i<N; i++)
    {
        cout<<"Ar norite, kad studento pazymiai butu generuojami atsitiktinai? (taip - y, ne - n)"<<endl;
        while(!(cin >> randomas))
        {
            cout << "Bloga ivestis! Iveskite savo varda";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n";
        }
        if(randomas == "y")
            stud[i].random = true;
        else
            stud[i].random = false;

        if(!stud[i].random)
        {
            student currentStud;
            cout<<"Iveskite savo varda: \n";
            while(!(cin >> currentStud.name))
            {
                cout << "Bloga ivestis! Iveskite savo varda";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"\n";
            }

            cout<<"Iveskite savo pavarde: \n";
            while(!(cin >> currentStud.surname))
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
                currentStud.homeworkSum += skaicius;
                skc++;
                currentStud.homework.push_back(skaicius);
                cout<<"Ar norite toliau vesti namu darbu balus? (taip - y, ne - n) \n";
                cin>>ats;
                if(ats == "n")
                {
                    veda=false;
                }
                
            }




            cout<<"Iveskite savo egzamino bala: \n";
            while(!(cin >> currentStud.exam) || currentStud.exam >10 || currentStud.exam<0)
            {
                cout << "Bloga ivestis! Iveskite savo namu darbu bala skaiciumi";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"\n";
            }
            currentStud.finalGrade = ((currentStud.homeworkSum*1.0/currentStud.homework.size()) * 0.4) + (0.6*currentStud.exam);
            stud.push_back(currentStud);
        }
        else
        {
            student currentStud;
            cout<<"Iveskite savo varda: \n";
        while(!(cin >> currentStud.name))
        {
            cout << "Bloga ivestis! Iveskite savo varda";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n";
        }

        cout<<"Iveskite savo pavarde: \n";
        while(!(cin >> currentStud.surname))
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
        while(veda)
        {
            cout<<"Sugeneruotas " << skc+1 << " namu darbu balas: \n";
            skaicius = rand() %10 +1;
            cout<<skaicius<<endl;
            currentStud.homeworkSum += skaicius;
            skc++;
            currentStud.homework.push_back(skaicius);
            cout<<"Ar norite toliau generuoti namu darbu balus? (taip - y, ne - n) \n";
            cin>>ats;
            if(ats == "n")
            {
                veda=false;
            }
        }



        cout<<"Sugeneruotas egzamino balas: \n";
        currentStud.exam = rand()%10 +1;
        cout<<currentStud.exam<<endl;
        currentStud.finalGrade = ((currentStud.homeworkSum*1.0/currentStud.homework.size()) * 0.4) + (0.6*currentStud.exam);
        stud.push_back(currentStud);
        }


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

            sort(stud[i].homework.begin(), stud[i].homework.end());


            if(stud[i].homework.size()%2==1)
            {

                cout<<setw(20)<<left<<stud[i].surname<<setw(10)<<left<<stud[i].name<<setw(10)<<left<<fixed<<setprecision(2)<<stud[i].homework[(stud[i].homework.size())/2]*1.0<<"\n";
            }
            else
            {
                cout<<setw(20)<<left<<stud[i].surname<<setw(10)<<left<<stud[i].name<<setw(10)<<left<<fixed<<setprecision(2)<<(stud[i].homework[(stud[i].homework.size())/2 - 1] + stud[i].homework[((stud[i].homework.size())/2)])/2.0<<"\n";
            }

        }
    }


    else
    {
        cout<<"Bloga įvestis. \n";
    }


}

