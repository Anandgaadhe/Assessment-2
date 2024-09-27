#include <iostream>
#include <string>

using namespace std;

// Class menu item
class MenuItem {
protected:
    string name; 
    int largePrice; 
    int smallPrice;
    int mediumPrice; 

public:
    // Constructor to initialize a menu item 
    MenuItem(string n, int lp, int sp, int mp) 
        : name(n), largePrice(lp), smallPrice(sp), mediumPrice(mp) {}

    // Display themenu item name
    void display() const {
        cout << "| " << name << (name.length() < 15 ? string(15 - name.length(), ' ') : "") 
             << "| " <<"\n";
    }

   
  void displaySizes() const {
        cout << "|   1    | Large  | " << largePrice << "                   |" << endl;
        cout << "|   2    | Small  | " << smallPrice << "                   |" << endl;
        cout << "|   3    | Medium | " << mediumPrice << "                  |" << endl;
    }
 int getPrice(int sizeChoice) const {
        switch (sizeChoice) {
            case 1: return largePrice; 
            case 2: return smallPrice; 
            case 3: return mediumPrice; 
            default: return 0; 
        }
    }
    string getName() const { return name; }
};
// Derived class for managing ordr
class FastFoodOrder {
private:
    string customerName;
    static const int menuSize = 5; // Fixed size for menu
    MenuItem menu[menuSize]; // Array of menu items
public:
    FastFoodOrder() 
        : menu {
            MenuItem("Pizza", 240, 100, 150),
            MenuItem("Burger", 300, 100, 200),
            MenuItem("Sandwich", 500, 250, 325),
            MenuItem("Roll", 240, 100, 150),
            MenuItem("Biryani", 240, 100, 150)
        }   
    {
    }
void setCustomerName(const string& name) {
        customerName = name; // Assigns the name to customerName
    }
 // Display the main menu
      void displayMenu() {
        cout << "\n-------- Mega Menu --------\n";
        cout << "-----------------------------\n";
        cout << "| Option | Item            |\n";
        cout << "-----------------------------\n";
        for (int i = 0; i < menuSize; ++i) {
            cout << "|   " << (i + 1) << "    "; 
            menu[i].display(); 
        }
        cout << "-----------------------------" << "\n";
    }
void displayItemMenu(int choice) {
        cout << "\n---- " << menu[choice].getName() << " Sizes and Prices ----" << "\n";
        cout << "----------------------------------------------" << "\n";
        cout << "| Option | Size   | Price (Rs.)            |" << "\n";
        cout << "----------------------------------------------" << "\n";
        menu[choice].displaySizes(); // Call displaySizes method of MenuItem
        cout << "----------------------------------------------" << "\n";
    }

    
void placeOrder() {
        char orderAgain; 
        do {
            displayMenu(); 
            int choice; 
            cout << "Please enter your choice 1 to 5: ";
            cin >> choice; 
            choice--; // Convert to zero-based index

    if (choice < 0 || choice >= menuSize) {
                cout << "Invalid choice.\n"; 
                continue; 
            }
displayItemMenu(choice); 

            int itemChoice; 
            cout << "Please enter which item would you like to have 1 to 3: \n";
            cin >> itemChoice;

            int price = menu[choice].getPrice(itemChoice); // Get the price for the selected size
            if (price == 0) {
                cout << "Invalid item choice.\n";
                continue; // Skip to the next itertion
            }
 int quantity; 
            cout << "Please enter the quantity: ";
            cin >> quantity; 
            cout << "----- Your Order ---------"<< "\n\n";
            cout << "You ordered " << quantity << " " << (itemChoice == 1 ? "Large" : itemChoice == 2 ? "Small" : "Medium") 
                 << " " << menu[choice].getName() << "\n\n";

            cout << "\nYour total bill is = Rs. " << price * quantity << "\n\n";
            cout << "Your order will arrive in 20 minutes." << "\n\n";
            cout << "Thank you for ordering from Top Tech Fast Food!" << "\n\n";

            cout << "Would you like to order anything else? (Y/N): ";
            cin >> orderAgain; 

        } while (orderAgain == 'Y' || orderAgain == 'y'); 
    }
};

int main() {
    FastFoodOrder order; 
    string name; 
    cout << "\n======TOPS TECH FAST FOOD======\n";
    cout << "Please enter your name: ";
    cin >> name; 
    order.setCustomerName(name); 
    order.placeOrder(); // Call method to place the order

    return 0; 
}



