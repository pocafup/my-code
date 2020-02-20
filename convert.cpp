#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;
string BinaryStringToText(string binaryString) {
    string text = "";
    stringstream sstream(binaryString);
    while (sstream.good()){
        bitset<8> bits;
        sstream >> bits;
        text += char(bits.to_ulong());
    }
    return text;
}
int main(){
  ifstream cin ("desktop/afaf.in");
  string s; getline(cin,s);
    // getline(std::cin, line);
    // bitset<8> bs;
    // cout << char(bs.to_ulong());
  while(!cin.eof()){
    for (int i=0;i<s.size();){
      if (s[i]=='M'){
        string a = "01";

        for (int j=i+1;j<=i+6;j++){
          // cout << j-i+1 << endl;
          if (s[j]=='O') a+="1";
          else a+="0";
        }
        // cout << a << endl;
        string k = BinaryStringToText(a);
        for (int i=0;i<k.length();i+=2) cout << k[i];
        i+=7;
      }
      else {
        cout <<s[i];
        if ((s[i]=='.' && s[i+1]==' ') || (s[i]=='.'&&i==s.length()-1)){
          cout << endl;
          i++;
          while(s[i]==' '){i++;if (i>=s.length()) break;}
          if (i>=s.length()) break;
        }
        else if (s[i]==']'||s[i]=='!') {
          cout <<  endl;
          // cout << i << " " <<s.length() << endl;}
          i++;
          while(s[i]==' '){i++;if (i>=s.length()) break;}
          if (i>=s.length()) break;

        }
        i++;
      }
    }
    // if (s[0]==' ') cout << endl;
    cout << " ";
    if (s[0]==' ') cout << ' ';
    else if (s[s.length()-1]=='.')cout << endl;
    getline(cin,s);
  }
}
