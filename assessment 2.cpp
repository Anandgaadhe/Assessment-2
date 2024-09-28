#include <iostream>
#include <string.h>

using namespace std;

class item {
protected:
    string n; 
    int lp; 
    int sp;
    int mp; 

public:
    item(string nn, int llp, int spp, int mmp) 
        : n(nn), lp(llp), sp(spp), mp(mmp) {}
    void d() const {
        cout << n << (n.length() < 15 ? string(15 - n.length(), ' ') : "");
    }
    void di() const {
        cout << "  1 Large   " << lp << endl;
        cout << "  2 Small " << sp << endl;
        cout << "  3 Medium " << mp << endl;
    }
    int gp(int sc) const {
        switch (sc) {
            case 1: return lp; 
            case 2: return sp; 
            case 3: return mp; 
            default: return 0; 
        }
    }
    string gn() const { return n; }
};

class food {
private:
    string cn;
    static const int ms = 5; 
    item m[ms]; 
public:
    food() : m{
        item("Pizza", 240, 100, 150),
        item("Burger", 300, 100, 200),
       item("Sandwich", 500, 250, 325),
        item("Roll", 240, 100, 150),
        item("Biryani", 240, 100, 150)
        } {}
 void sc(const string& nn) {
        cn = nn; 
    }       
void dsplmn() 
{
        cout << "\n-------- Mega Menu --------\n";
        m[0].d(); cout << "1\n"; 
        m[1].d(); cout << "2\n"; 
        m[2].d(); cout << "3\n"; 
        m[3].d(); cout << "4\n"; 
        m[4].d(); cout << "5\n";     
    }
    void dspl(int c) 
	{
        cout  << m[c].gn();
        cout << "  Option  Size     Price            \n";
        m[c].di();
    }
    void po() {
        char oa; 
        do {
            dsplmn(); 
            int c; 
            cout << "Please enter your choice ";
            cin >> c; 
            c--;

            if (c < 0 || c >= ms) {
                cout << "Invalid choice.\n"; 
                continue; 
            }
            dspl(c); 
            int ic; 
            cout << "Please enter item \n";
            cin >> ic;
            int p = m[c].gp(ic); 
            if (p == 0) {
                cout << "Invalid item choice.\n";
                continue; 
            }
            int q; 
            cout << "Please enter the quantity: ";
            cin >> q; 
            cout << "----- Your Order ---------\n\n";
            cout << "You ordered " << q << " " << (ic == 1 ? "Large" : ic == 2 ? "Small" : "Medium") 
                 << " " << m[c].gn() << "\n\n";
            cout << "\nYour total bill is = Rs. " << p * q << "\n\n";
            cout << "Your order will arrive in 20 minutes.\n\n";
            cout << "Thank you for ordering from Top Tech Fast Food!\n\n";

            cout << "Would you like to order anything else? (Y/N): ";
            cin >> oa; 

        } while (oa == 'Y' || oa == 'y'); 
    }
};
int main() {
    food fo;
    string n; 
    cout << "\n======TOPS TECH FAST FOOD======\n";
    cout << "Please enter your name: ";
    cin >> n; 
    fo.sc(n);
    fo.po();
    return 0; 
}
