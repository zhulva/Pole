#include <cstring>

#include "pole.hpp"
#include <cstdlib>
#include <ctime>

pole::pole() {
    /*Když není zadán parametr, ukazatel je nastaven na bezpečnou 
    hodnotu 0 (null)
     */
    this->ukazatel=0;
    this->pocetPrvku=0;
}

pole::pole(int n){
    //Pokud je počet prvků kladný, vytvoříme pole
    if (n>0){
        //Vytvoření pole ve volné oblasti paměti
        this->ukazatel = new int[n];
        //Testování přidělené paměti
        if (this->ukazatel!=0)
            this->pocetPrvku = n;
        else
            this->pocetPrvku = 0;
    }else{
        this->ukazatel = 0;
        this->pocetPrvku = 0;
    }
}

pole::pole(const pole& orig) {
}

pole::~pole() {
    // Pokud byla přidělena paměť, zrušíme ji v destruktoru
    if (this->ukazatel!=0){
        delete[] this->ukazatel;
        this->ukazatel = 0;
        this->pocetPrvku=0;
    }
}

bool pole::naplnPole(){
    // Pokud nějaké pole existuje, tak je naplněno z generátoru čísel
    if (this->ukazatel!=0){
        srand((unsigned)time(NULL));
        for(int i = 0;i < this->pocetPrvku;i++){
            this->ukazatel[i]=rand() % 100;
        }
    }
}

// Vrací hodnotu n-tého prvku
int pole::getPrvek(int n) const{
    // Jestliže pole existuje, tak můžeme zkontrolovat existenci prvku
    if(this->ukazatel !=0){
        // Musíme zkontrolovat jestli prvek v poli existuje
        if (n >= 0 && n <= pocetPrvku)
            return this->ukazatel[n];
        else
            return -666;
    }else
        return -666;
}

int pole::getPocet() const{
    return this->pocetPrvku;
}

bool pole::sort() {
    int pom=0;
    if(this->ukazatel ==0)
        return false;
    if(index<0 || index > this->pocetPrvku)
            return false;
    for(int j=0; j < this->pocetPrvku; j++){
    for(int i=0; i < this->pocetPrvku-1;i++){
        if(this->ukazatel[i]>this->ukazatel[i+1]){
            pom=this->ukazatel[i];
            this->ukazatel[i]=this->ukazatel[i+1];
            this->ukazatel[i+1]=pom;
        }
      }
    }
    return true;
}

bool pole::addPrvek(int hodnota){
    //Pole neexistuje, vytvoříme pole o jednom prvku
    if(this->ukazatel == 0){
        this->ukazatel = new int[1];
        if(this->ukazatel !=0){
            this->pocetPrvku = 1;
            this->ukazatel[0]=hodnota;
            return true;
    }
  }else{
      //Pole existuje
            int *pom_u = new int [this->pocetPrvku+1];
            if(pom_u !=0){
                for(int i=0; i < this->pocetPrvku; i++){
                    pom_u[i] = this->ukazatel[i]; 
                }
            pom_u[this->pocetPrvku] = hodnota;
            this->pocetPrvku++;
            free(this->ukazatel);
            this->ukazatel = pom_u;
            return true;
            
            }
        }
    return false;
}

bool pole::deletePrvek(int index){
    int *pom_u = new int [this->pocetPrvku - 1];
    if(this->ukazatel==0)
        return false==0;
    if(pom_u !=0){
        for(int i=0; i<index; i++){
            //zkopírujeme hodnoty před indexem
                pom_u[i] = this->ukazatel[i];
        }
        //vynechame a zkopirujeme zbytek
         for(int i=index+1; i<pocetPrvku; i++){
             pom_u[i-1]=this->ukazatel[i];
         }   
        this->pocetPrvku--;
    free(this->ukazatel);
    this->ukazatel = pom_u;
    return true;
    }    
    return false;
}

bool pole::insertPrvek(int index, int hodnota){
    if(this->ukazatel ==0)
        return false;
    if(index<0 || index > this->pocetPrvku)
            return false;
    int *pom_u = new int [this->pocetPrvku +1];
    if(pom_u !=0){
        for(int i=0;i<index;i++){
            pom_u[i] = this->ukazatel[i];
        }
        this->pocetPrvku++;
        free(this->ukazatel);
    this->ukazatel = pom_u;
    }
}

