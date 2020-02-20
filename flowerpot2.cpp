#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
multiset<int> y_set;
int n,d;
struct node{
  int x,y;
}flower[100005];
int findMax(multiset<int> my_set)
{

    int max_element;
    if (!my_set.empty())
        max_element = *my_set.rbegin();

    // return the maximum element
    return max_element;
}

int findMin(multiset<int> my_set)
{

    // Get the minimum element
    int min_element;
    if (!my_set.empty())
        min_element = *(--my_set.rend());

    return min_element;
}

bool sorted(node a, node b){
  return a.x<b.x;
}

int main(){
  cin >> n >> d;
  for (int i=0;i<n;i++) cin >> flower[i].x >> flower[i].y;
  sort(flower,flower+n,sorted);
  int curr = 0;
  int ans = 1e9;
  for (int i=0;i<n;i++){
    if (y_set.empty()) {y_set.insert(flower[curr].y);curr++;}
    while((*y_set.rend())-(*y_set).rbegin()<d && curr<n){
      y_set.insert(flower[curr].y);
      curr++;
    }

    if (findMax(y_set)-findMin(y_set)>=d) ans = min(ans,abs(flower[curr-1].x-flower[i].x));
    y_set.erase(y_set.find(flower[i].y));
  }
  if (ans==1e9) cout << -1;
  else cout << ans;
}
