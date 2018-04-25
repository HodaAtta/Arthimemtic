#include <bits/stdc++.h>

#define max 10
using namespace std;

vector< pair<char,double> > source;
vector<double> intervals;
double L[max], U[max];
// this vector represents the set
// the first term is the element in the set, the second term is the P[]

string target = "ACBA";
string output = "";
double tag = 0;

int get_index(char x){
   for(int i = 0; i < source.size(); ++i){
      if(x == source[i].first){
         return i + 1;
      }
   }
   return -1;
}

void init(){
   source.push_back(make_pair('A', 0.8));
   source.push_back(make_pair('B', 0.02));
   source.push_back(make_pair('C', 0.18));
   intervals.push_back(0);
}

int main(void){
   init();
   int index = 0;
   double numberline = 0;
   while(index < source.size()){
      numberline += source[index++].second;
      intervals.push_back(numberline);
   }
   U[0] = 1;
   for(int i = 1; i <= target.size(); ++i){
      int ii = get_index(target[i - 1]);
      L[i] = L[i - 1] + (U[i - 1] - L[i - 1]) * intervals[ii - 1];
      U[i] = L[i - 1] + (U[i - 1] - L[i - 1]) * intervals[ii];
      while((L[i] >= 0.5 && U[i] >= 0.5) || (L[i] <= 0.5 && U[i] <= 0.5)){
         if(L[i] >= 0.5 && U[i] >= 0.5){
            output += '1';
            L[i] = 2 * (L[i] - 0.5);
            U[i] = 2 * (U[i] - 0.5);
            tag += pow(2, -1 * (int)output.size());
         }else if(L[i] <= 0.5 && U[i] <= 0.5){
            output += '0';
            L[i] = 2 * (L[i]);
            U[i] = 2 * (U[i]);
         }
      }
   }
   cout << output << "\n";
   cout << output + "100000000"<< "\n";
   cout << tag << "\n";
}
