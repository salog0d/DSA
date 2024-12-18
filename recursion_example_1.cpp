#include <iostream>
using namespace std;

void recursive(int n){
    if(n>0){
        cout<<n<<endl;
        recursive(n-1);
    }
}

void recursive2(int n){
    if(n>0){
        recursive2(n-1);
        cout<<n<<endl;
    }
}

/*Loop only ascending phase, and recursion has ascending and descending
return tuime, making it more moldeable to resolve probelms such as the Finobasi
seccunce wich is a piramid wich both ascends and descends.
*/


int main()
{
        int x = 3;
        recursive2(x);
}