#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> myvector;
	for (int i=1; i<10; ++i) myvector.push_back(i);
	reverse(myvector.begin()+1,myvector.begin()+3);
	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
