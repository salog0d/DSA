#include <iostream>
using namespace std;

void recursive(int n){
    if(n>0){
        cout<<n<<endl;
        recursive(n-1);
    }
}
int main()
{
        int x = 7;
        recursive(x);
}