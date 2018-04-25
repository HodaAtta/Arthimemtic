#include <bits/stdc++.h>

#define max 10
using namespace std;

vector< pair<char,double> > source;
vector<double> intervals;
double L[max], U[max];
// this vector represents the set
// the first term is the element in the set, the second term is the P[]

string target = "1100011000000000000000000";
string output = "";
double tag;
int k = 1;

void init(){
   source.push_back(make_pair('A', 0));
   source.push_back(make_pair('B', 0));
   source.push_back(make_pair('C', 0));
   intervals.push_back(0);
   intervals.push_back(0.8);
   intervals.push_back(0.82);
   intervals.push_back(1.0);
}

double eval(string x){
   int i = 0;
   double ret = 0.0;
   while(i < x.size()){
      if(x[i] == '1'){
         ret += pow(2, -1 * (i + 1));
      }
      i++;
   }
   return ret;
}

void decipher(){
   cout << "Final : ";
   U[0] = 1;
   double small = 123923929.0;
   for(int i = 1; i < intervals.size(); ++i){
      small = min(small, intervals[i] - intervals[i - 1]);
   }
   while(pow(2, -1 * k) >= small){
      k ++;
   }
   string cur = target.substr(0, k);
   tag = eval(cur);
   for(int i = 1; i <= source.size() + 1; ++i){
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
            output += source[j].first;
            break;
         }
      }
      while((L[i] >= 0.5 && U[i] >= 0.5) || (L[i] <= 0.5 && U[i] <= 0.5)){
         if(L[i] >= 0.5 && U[i] >= 0.5){
            L[i] = 2 * (L[i] - 0.5);
            U[i] = 2 * (U[i] - 0.5);
         }else if(L[i] <= 0.5 && U[i] <= 0.5){
            L[i] = 2 * (L[i]);
            U[i] = 2 * (U[i]);
         }
         cur = cur.substr(1, (int)cur.size() - 1);
         cur += target[k ++];
         tag = eval(cur);
      }
   }
   // cout << "\n";
}

int main(void){
   init();
   decipher();
   cout << output << "\n";
}
