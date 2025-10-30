#include <iostream>
using namespace std;

void changeLocation(char *Array, int b1, int b2) {
    if (b1 >= b2){
        return;
    }
    else{
    char temp = Array[b1];
    Array[b1] = Array[b2];
    Array[b2] = temp;
    }
    changeLocation(Array, b1 + 1, b2 - 1);
}

int main() {
    char arr[8] = {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'};
    int b1 = 2, b2 = 6;

    changeLocation(arr, b1, b2);

    cout<<"After Changing the Location: "<<endl;    
    for (int i = 0; i < 8; i++){
        cout<< arr[i]<<" "<<endl;
    }

    return 0;
}
