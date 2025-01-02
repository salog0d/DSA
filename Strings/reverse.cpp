#include <iostream>
#include <string>
using namespace std;

char* reverse(string word){
    int j=0;
    char* reversed = new char[word.length()];
    for(int i=word.length()-1;i>=0;i--){
        reversed[j]=word[i];
        j++;
    }
    return reversed;
}

int main(){
    string word = "Hello";
    string reversed = reverse(word);
    cout << "The reversed string is: " << reversed << endl;
}