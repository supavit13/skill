#include<iostream>

using namespace std;

bool isNonDecreasing(unsigned long long number) {
    int remainder = 10;
    while( number > 0 ) {
        if( number % 10 <= remainder ) {
            remainder = number % 10;
            number /= 10;
        } else {
            return false;
        }
    }
    return true;
}

unsigned long long lastTidyNumber(unsigned long long number) {
    unsigned long long subtrahend = ( number % 10 ) + 1;
    cout<<"subtrahend : "<<subtrahend<<endl;
    number -= subtrahend;
    subtrahend = 10;
    cout<<"number : "<<number<<endl;
    while( !isNonDecreasing(number) ) {
    	cout<<"number22 : "<<number<<endl;
        if( number % (subtrahend * 10) == (subtrahend * 10) - 1 ) {
        	cout<<"number     33 : "<<number<<endl;
            subtrahend *= 10;
        }
        
        number -= subtrahend;
    }
    return number;
}

int main() {
    int t;
    cin >> t;
    unsigned long long n;

    for( int i = 0; i < t; i++ ) {
        cin >> n;
        if( isNonDecreasing(n) ) {
            cout << "Case #" << i + 1 << ": " << n << "\n";
        } else {
            cout << "Case #" << i + 1 << ": " << lastTidyNumber(n) << "\n";
        }
    }

    return 0;
}
