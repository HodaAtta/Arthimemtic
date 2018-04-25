#include <bits/stdc++.h>

#define max 10
using namespace std;

vector< pair<char,double> > source;
vector<double> intervals;
double L[max], U[max];
// this vector represents the set
// the first term is the element in the set, the second term is the P[]

string target;
double tag;

void read_input(){
   cout << "\n 1st step \n";
   cin >> tag;
   cout << "\n 2nd step \n";
   cout << "\n enter 0 0 to end the input \n";
   char x;
   double p;
   cin >> x >> p;
   intervals.push_back(0);
   while(p){
      source.push_back(make_pair(x, 0));
      intervals.push_back(p);
      cin >> x >> p;
   }
}

void decipher(){
   cout << "Final : ";
   U[0] = 1;
   for(int i = 1; i <= source.size(); ++i){
      vector<pair<double, double> > tmp;
      for(int j = 0; j < intervals.size(); ++j){
         double x = L[i - 1] + (U[i - 1] - L[i - 1]) * intervals[j];
         double z = L[i - 1] + (U[i - 1] - L[i - 1]) * intervals[j + 1];
         tmp.push_back(make_pair(x, z));
      }
      for(int j = 0; j < tmp.size(); ++j){
         if(tag >= tmp[j].first && tag <= tmp[j].second){
            U[i] = tmp[j].second;
            L[i] = tmp[j].first;
            cout << source[j].first;
            break;
         }
      }
   }
   cout << "\n";
}

int main(void){
   read_input();
   decipher();
}
