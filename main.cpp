#include <cstdlib>
#include <iostream>

#include "pole.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    pole  p1(5);
    pole  p2;
    int novaHodnota;
    int index;
    p1.naplnPole();
    cout << "Objekt pole vytvoreny konstruktorem s parametru" <<endl;
    for (int i=0;i<p1.getPocet();i++){
        cout<<p1.getPrvek(i)<<endl;
    }
    cout<< "Setrideni vypis pole" << endl;
    p1.sort();
    for (int i=0;i<p1.getPocet();i++){
    cout<<p1.getPrvek(i)<<endl;
    }
    
    
    p2.naplnPole();
    cout<< "Objekt pole vytvoreny konstruktorem bez parametru" <<endl;
    cout << p2.getPrvek(0)<<endl;
    p2.sort();
    
    cout << "Jakou hodnotu pole chces pridat:"<< endl;
    cin >> novaHodnota;
    
    if(p2.addPrvek(novaHodnota)){
        for (int i=0;i<p2.getPocet();i++){
            cout<<p2.getPrvek(i)<<endl;
        }
    }
     if(p1.addPrvek(novaHodnota)){
        for (int i=0;i<p1.getPocet();i++){
            cout<<p1.getPrvek(i)<<endl;
        }    
    }
    return 0;
}

