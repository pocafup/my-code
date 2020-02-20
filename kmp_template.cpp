// Find pat part
int cM = 0;
for (int i=1;i<=T;i++){
  while(cM>=0 && pat[cM+1]!=text[i]){
    cM = nextB[cM]; // always decrease
  }
  cM++;
  if (cM==P){
    //we found a cMatch
    cM = nextB[cM];
  }

}
//nextB[i] = longest suffix of prefix[1...i] that is also a prefix of pat
//text[i+1] != pat[j+1]
//j = nextB[j]
/*
consider case:
  pat: ananacat
  string: banananacat
  nextB[0] = -1;
  nextB[1] = 0;
  nextB[2] = 0;
  nextB[3] = 1;
  nextB[4] = 2;
  nextB[5] = 3;
  nextB[6] = 0;
*/


//actual KMP part
nextB[0] = -1;
int cM = -1;
for (int i=1;i<=P;i++){
  while(cM>=0 && pat[cM+1]!=pat[i]){
    cM = nextB[cM];
  }
  cM++;
  nextB[i] = cM;
}
