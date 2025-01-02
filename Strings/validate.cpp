#include <iostream>
using namespace std;

bool validate(char *word){
    bool valid;
    for(int i=0; word[i] != '\0'; i++){
        if((word[i] < 'a' || word[i] > 'z') && (word[i] < 'A' || word[i] > 'Z')){
            valid = false;
            break;
        }
    }
    return valid;
}

int main(){
    char word[] = "Hello World";
    bool validation = validate(word);
    if(validation){
        cout << "The string is valid" << endl;
}else{
        cout << "The string is invalid" << endl;
    }
    return 0;
}