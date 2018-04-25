#include <bits/stdc++.h>

#define max 10
using namespace std;

vector< pair<char,double> > source;
vector<double> intervals;
double L[max], U[max];
// this vector represents the set
// the first term is the element in the set, the second term is the P[]

string target;

void calculate_intervals(){
   int i = 0;
   double c = 0;
   intervals.push_back(c);
   while(i < source.size()){
      c += source[i++].second;
      intervals.push_back(c);
   }
}

void calculate_tag_intervals(){
   U[0] = 1.0;
   for(int i = 1; i <= target.size(); ++i){
      int x = 1;
      while(target[i - 1] != source[x - 1].first) x++;
      L[i] = L[i - 1] + (U[i - 1] - L[i - 1]) * intervals[x - 1];
      U[i] = L[i - 1] + (U[i - 1] - L[i - 1]) * intervals[x];
      cout << L[i] << " " << U[i] << "\n";
   }
}

void read_input(){
   cout << "\n 1st step \n";
   cout << "\n enter 0 0 to end the input \n";
   char x;
   double p;
   cin >> x >> p;
   while(p){
      source.push_back(make_pair(x, p));
      cin >> x >> p;
   }
   calculate_intervals();
   cout << "\n 2nd step \n";
   cin >> target;
}

int main(void){
   read_input();
   calculate_tag_intervals();
   cout << "\n Final Tag \n" << (L[source.size()] + U[source.size()]) / 2.0 << "\n";
}
