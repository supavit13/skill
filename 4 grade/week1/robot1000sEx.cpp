#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int getLength(string p)
{
  int x=0, y=0;
  for (int i=0; i<p.length(); i++) {
    switch (p[i]) {
      case 'N':  y ++; break;
      case 'E':  x ++; break;
      case 'W':  x --; break;
      case 'S':  y --; break;
      case 'Z':  x = 0; y = 0; break;
    }
  }
  return abs(x) + abs(y);
}

void combi(string com, int l, int &max)
{
  if (com.length() > l) {
    for (int i=0; i<com.length(); i++) {
      string next = com;
      next.erase(i, 1);
      combi(next, l, max);
    }
  } else {
    int len = getLength(com);
    max = len > max ? len : max;
  }
}

int main()
{
  int l, max = 0;
  string input;
  cin >> input;
  cin >> l;
  combi(input, input.length() - l, max);
  cout << max*2 << endl;
}
