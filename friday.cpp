/*
ID:dx424391
PROG: friday
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int a;
int year = 1900;
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int days[7] = {0,0,0,0,0,0,0};
int day_count = 0;
bool leap = false;
int main(){
  ofstream fout("friday.out");
  ifstream fin("friday.in");
  fin >> a;

  for (int i=0;i<a;i++){
    if (year % 100 == 0 && year % 400 != 0){

    }else if(year % 4 == 0){
      leap = true;
    }
  if (leap){
    month[1] ++;
    leap = false;
  }
  for (int i=0;i<12;i++){
    for (int j=0;j<month[i];j++){
      day_count ++;
      if (day_count >6){
        day_count = 0;
      }
      if (j==12){
        days[day_count]++;
      }
    }
  }
    year ++;
    if (month[1] == 29){
      month[1] = 28;
    }
  }
  fout << days[6] << " ";
  for(int i=0;i<5;i++){
    fout << days[i] << " ";
  }
  fout << days[5] << endl;
}
