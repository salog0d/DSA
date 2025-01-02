#include <iostream>
using namespace std;

int stringLength(string word){
    int length = 0;
    for(int i=0; word[i] != '\0'; i++){
        length++;
    }
    return length;
}

int main(){
    string word = "Hello World";
    cout << "The length of the string is: " << stringLength(word) << endl;
    return 0;
}