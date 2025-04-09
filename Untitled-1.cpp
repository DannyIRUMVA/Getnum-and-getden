#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Fraction{
    private:
        int num;    // numerator
        int den;    // denominator

    public:
    void set(int n, int d)
        {num = n; den = d; normalize();}
    int getNum()
        {return num;}
    int getDen()
        {return den;}

    private:
        void normalize();       // converts to standard form
        int gcf(int a, int b);  // greatest common factor
        int lcm(int a, int b);  // lowest common denominator
};

int main(){
    int a, b;
    string str;
    Fraction fract;
    while (true){
        cout << "Enter numerator: ";
        cin >> a;
        cout << "Enter denominator: ";
        cin >> b;
        fract.set(a, b);
        cout << "Numerator is   " << fract.getNum() << endl;
        cout << "Denominator is " << fract.getDen() << endl;
        cout << "Do again? (Y or N): ";
        cin >> str;
        if (!(str[0] == 'Y' || str[0] == 'y'))
            break;
    }
    return 0;
}
/* normalize: put fraction into standard form, unique for each mathematically different value
*/
void  Fraction::normalize(){
    // handle cases involving 0
    if (den == 0 || num == 0){
        num = 0;
        den = 1;
    }
    // put negative sign in numerator only
    if (den < 0){
        num *= (-1);
        den *= (-1);
    }
    // factor out GCF from numerator and denominator
    int n = gcf(num, den);
    num /= n;
    den /= n;
}
/* greatest common factor
*/
// int Fraction::gcf(int a, int b){
//     if (b == 0)
//         return abs(a);
//     else
//         return gcf(b, a % b);
// }
/* lowest common multiple
*/
int Fraction::lcm(int a, int b){
    int n = gcf(a, b);
    return a / n *b;
}
