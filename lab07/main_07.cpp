#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <vector>
#include <string>

using namespace std;

map<char,int> shuffled_abc;

int main() {
    /*vector<string> fruits {"melon", "raspberry", "cherry", "apple"};
    auto it=find_if(fruits.begin(),fruits.end(),
                                                [](const string &e) {
                                                    return e.contains("berry");
                                                });
    cout<<*it;*/

    vector<int> numbers{2, 4, 6};
    /*cout << ((all_of(numbers.begin(), numbers.end(),
                    [](const int &number) {
                        return number % 2 == 0;
                    }))?
          ("Az összes páros")
        : ("Nem mindegyik páros"));*/


    /*for_each(numbers.begin(),numbers.end(),
        [](int &number) {
            number*=2;
        });
    cout<<numbers[2];*/

    vector<string> months{
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    /*cout<<count_if(months.begin(),months.end(),
        [](const string &s) {
        return s.length()==5;
    });*/

    vector<double> real_numbers{-11.2, 1.5, 2.8, 0.5};
    /*sort(real_numbers.begin(),real_numbers.end(),
        [](const double &f, const double &s) {
            return f>s;
        });*/
    /*sort(real_numbers.begin(), real_numbers.end(), greater<double>());
    cout<<real_numbers[0];*/

    /*vector<pair<string, double> > avg_months{
        {"Február", 0.0},
        {"Január", -1.5},
        {"Március", 5.0},
        {"Április", 10.5},
        {"Május", 15.5},
        {"Június", 19.5},
        {"Július", 21.5},
        {"Augusztus", 21.0},
        {"Szeptember", 16.5},
        {"Október", 10.0},
        {"November", 4.0},
        {"December", 0.0}
    };

    sort(avg_months.begin(),avg_months.end(),
        [](const pair<string,double> &p1, const pair<string,double> &p2) {
            return p1.second<p2.second;
        });
    cout<<avg_months[0].first;*/

    /*sort(real_numbers.begin(),real_numbers.end(),
        [](const double &n1, const double &n2) {
            return abs(n1)<abs(n2);
        });
    cout<<real_numbers[0]<<" "<<real_numbers[3];*/

    for_each(months.begin(),months.end(),
        [](string &s) {
            s[0]=s[0]+('a'-'A');
        });

    /*cout<<months[0]<<" "<<months[1];*/

    string abc {"abcdefghijklmnopqrstuvwxyz"};
    shuffle(abc.begin(),abc.end(),random_device());

    cout<<abc<<endl<<endl;



    for (int i=0; i<abc.length(); i++) {
        shuffled_abc[abc[i]]=i;
    }

    //Kérdés: Hogyan lehetne a shuffled_abc-t átadni a függvénynek, ha nem tehetjük globális változóba?

    sort(months.begin(),months.end(),
        [](const string &s1, const string &s2) {
            for (int i=0; i<s1.length() || i<s2.length(); i++) {
                if (s1[i]!=s2[i]) {
                    return shuffled_abc[s1[i]]<shuffled_abc[s2[i]];
                }
            }
            return s1.length()<s2.length();
        });

    for (int i=0; i<months.size(); i++) {
        cout<<months[i]<<" ";
    }

    return 0;
}