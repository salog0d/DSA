#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(string word){
    bool palindrome = true;
    int j=0;
    for(int i=word.length()-1;i>=0;i--){
        if(word[i] != word[j]){
            palindrome = false;
            break;
        }
        j++;
    }
    return palindrome;
}

int main(){
    string word = "madam";
    bool palindrome = isPalindrome(word);
    if(palindrome){
        cout << "The string is a palindrome" << endl;
    }else{
        cout << "The string is not a palindrome" << endl;
    }
    return 0;
}