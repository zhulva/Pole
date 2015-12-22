#ifndef POLE_HPP
#define	POLE_HPP

class pole {
public:
    pole();
    pole(int);
    pole(const pole& orig);
    virtual ~pole();
    int getPocet() const;
    bool insertPrvek(int, int);
    bool deletePrvek(int);
    bool addPrvek(int);
    bool rewritePrvek(int,int);
    bool sort();
    int getPrvek(int) const;
    bool naplnPole();
    bool reverse();
private:
    int *ukazatel;
    int pocetPrvku;
};


#endif	/* POLE_HPP */

