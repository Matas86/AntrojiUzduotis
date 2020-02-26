#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;

const char duomenys [] = "kursiokai.txt";

struct student
{
    string name;
    string surname;
    int homeworkCount;
    int homeworkSum;
    vector<int> homework;
    int exam;
    double finalGrade;
    bool random;
};
void Skaityk(student stud[], int &N);

void Isvesk(student stud[], int N);

void FinalCounter(student stud[], int N);

bool sortStudents(student A, student B);

int main()
{
    srand(time(NULL));

    string failas;
    cout<<"Ar duomenys bus nuskaitomi is duomenu failo? (taip - y, ne - n) \n";
    while(!(cin >> failas))
    {
        cout << "Bloga ivestis! Iveskite savo varda";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"\n";
    }
    if(failas == "y")
    {

        int N = 10;
        student stud[N];
        Skaityk(stud, N);
        Isvesk(stud,N);
    }
    else
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

                    while(!(cin >> skaicius) || skaicius>10 || skaicius<0)
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
            else
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
                    cout<<"Sugeneruotas " << skc+1 << " namu darbu balas: \n";
                    skaicius = rand() %10 +1;
                    cout<<skaicius<<endl;
                    stud[i].homeworkSum += skaicius;
                    skc++;
                    stud[i].homework.push_back(skaicius);
                    cout<<"Ar norite toliau generuoti namu darbu balus? (taip - y, ne - n) \n";
                    cin>>ats;
                    if(ats == "n")
                    {
                        veda=false;
                        stud[i].homeworkCount = skc;
                    }
                }



                cout<<"Sugeneruotas egzamino balas: \n";
                stud[i].exam = rand()%10 +1;
                cout<<stud[i].exam<<endl;
                stud[i].finalGrade = ((stud[i].homeworkSum*1.0/stud[i].homework.size()) * 0.4) + (0.6*stud[i].exam);
            }


        }
    }


}

void Isvesk(student stud[], int N)
{
    FinalCounter(stud,N);
    string ats;
    cout<<"Norite isvesti atsakymus i komandine eilute ar i tekstini faila? (cmd - komandine eilute, file - tekstinis failas) \n";
    cin>>ats;
    if(ats=="cmd")
    {
        cout<<"Norite gauti vidurki ar mediana? (Vidurkis - v, Mediana - m) \n";
        string temp;

        cin>>temp;
        if(temp == "v")
        {
            cout<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Vardas"<<setw(20)<<"Galutinis (Vid.)"<<endl;
            cout<<"-------------------------------------------------"<<endl;


            for(int i=0; i<N; i++)

                cout<<setw(20)<<left<<stud[i].surname<<setw(10)<<left<<stud[i].name<<setw(10)<<left<<fixed<<setprecision(2)<<stud[i].finalGrade<<"\n";
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
    else
    {
        ofstream write("atsakymai.txt");
        cout<<"Norite gauti vidurki ar mediana? (Vidurkis - v, Mediana - m) \n";
        string temp;

        cin>>temp;
        if(temp == "v")
        {
            write<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Vardas"<<setw(20)<<"Galutinis (Vid.)"<<endl;
            write<<"-------------------------------------------------"<<endl;


            for(int i=0; i<N; i++)

                write<<setw(20)<<left<<stud[i].surname<<setw(10)<<left<<stud[i].name<<setw(10)<<left<<fixed<<setprecision(2)<<stud[i].finalGrade<<"\n";
        }

        else if( temp == "m")
        {
            write<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Vardas"<<setw(20)<<"Galutinis (Med.)"<<endl;
            write<<"-------------------------------------------------"<<endl;

            for(int i=0; i<N; i++)
            {

                sort(stud[i].homework.begin(), stud[i].homework.end());


                if(stud[i].homework.size()%2==1)
                {

                    write<<setw(20)<<left<<stud[i].surname<<setw(10)<<left<<stud[i].name<<setw(10)<<left<<fixed<<setprecision(2)<<stud[i].homework[(stud[i].homework.size())/2]*1.0<<"\n";
                }
                else
                {
                    write<<setw(20)<<left<<stud[i].surname<<setw(10)<<left<<stud[i].name<<setw(10)<<left<<fixed<<setprecision(2)<<(stud[i].homework[(stud[i].homework.size())/2 - 1] + stud[i].homework[((stud[i].homework.size())/2)])/2.0<<"\n";
                }

            }
        }
        else
        {
            cout<<"Bloga įvestis. \n";
        }
    }

}
void Skaityk(student stud[], int &N)
{
    ifstream file("kursiokai.txt");
    string line;
    vector<string> split;
    N=0;
    file.close();
    ifstream read("kursiokai.txt");
    getline(read,line);
    int pazymys;
    while(getline(read,line))
    {
        stringstream stream;
        stream<<line;
        stream>>stud[N].name>>stud[N].surname;
        while(stream>>pazymys)
        {
            stud[N].homework.push_back(pazymys);
        }
        stud[N].exam = stud[N].homework.back();
        stud[N].homework.pop_back();
        N++;
    }
}
void FinalCounter(student stud[], int N)
{
    for(int i=0; i<N; i++)
    {
        stud[i].homeworkSum = 0;

        for(int j=0; j<stud[i].homework.size(); j++)
        {
            stud[i].homeworkSum+=stud[i].homework[j];
        }
        stud[i].finalGrade = stud[i].homeworkSum*1.0/stud[i].homework.size();
    }
    sort(stud,stud+N, sortStudents);
}

bool sortStudents(student A, student B){
    if(B.name > A.name || B.surname > A.surname){
        return true;
    }
    return false;
}
