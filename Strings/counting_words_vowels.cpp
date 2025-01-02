#include <iostream>
using namespace std;

int countWordsAndVowels(String word){
    int vowels = 0;
    int words = 1;

    for(i=0; i!= "\0" ;i++){
        if(word[i] == ' '&& word[i-1] != ' '){
            words++;
        }
        if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
            vowels++;
        }
    }
    return words,vowels;
}

int main(){
    String word = "Hello World";
    cout << "The number of words in the string is: " << countWordsAndVowels(word) << endl;
    return 0;
}