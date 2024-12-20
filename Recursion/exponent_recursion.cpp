#include <iostream>
using namespace std;
/*Un exponente es igual al numero de veces que se multiplica un numero*/

int exponente(int m , int n){
    if(n==0)
        return 1;
    return exponente(n,m-1)*n;

}

int main(){
    int n;
    n=exponente(3,4);
    cout<<n<<endl;
}

