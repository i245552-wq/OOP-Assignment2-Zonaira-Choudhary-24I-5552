#include <iostream>
using namespace std;

void PrintPatternHelper(int n, int row) {
    if (row > n){
        return;
    }
    else{
        int temp = n - row + 1; // controls starting number

        for (int i = 1; i <= row; i++) {
            cout<<temp<<" ";
            if (temp < n){
                 temp++;
            } 
        }
        cout<<endl;
    }
    PrintPatternHelper(n, row + 1);
}

// function from GPT
void PrintPattern(int n) {
    for (int row = 1; row <= n; row++) {
        int value = n - row + 1;  
        for (int col = 1; col <= row; col++) {
            cout << value << " ";
            if (value < n) value++;  
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    PrintPattern(n);
    return 0;
}
