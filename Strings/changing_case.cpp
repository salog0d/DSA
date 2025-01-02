#include <iostream>
using namespace std;

String changeCase(String word){
    for(int i=0; i<word.length(); i++){
        if(word[i] >= 'a' && word[i] <= 'z'){
            word[i] = word[i] - 32;
        }else if(word[i] >= 'A' && word[i] <= 'Z'){
            word[i] = word[i] + 32;
        }
    }
    return word;
}

int main(){
    String word = "Hello World";
    cout << "The string in lower case is: " << changeCase(word) << endl;
    return 0;
}