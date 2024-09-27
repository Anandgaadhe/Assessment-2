#include <iostream>
#include <string>

using namespace std;

class Menu {
public:
    void displayMainMenu() {
        cout << "\n.................... Tops Menu ..................... : " << "\n";
        cout << "1. Pizzas" << "\n";
        cout << "2. Burgers" << "\n";
        cout << "3. Sandwiches" << "\n";
        cout << "4. Rolls" << "\n";
        cout << "5. Biryani" << "\n";
        cout << "ENTER YOUR CHOICE: " << "\n";
    }

   void displaySubMenu(int mainChoice) {
        switch (mainChoice) {
            case 1:
                cout << "\nPIZZA MENU :" << "\n";
                cout << "1. Small Pizza  = RS. 100" << "\n";
                cout << "2. Medium Pizza = RS. 150" << "\n";
                cout << "3. Large Pizza  = RS. 200" << "\n";
                break;
            case 2:
                cout << "\nBURGER MENU :" << "\n";
                cout << "1. Small Burger     = RS. 100" << "\n";
                cout << "2. Medium Burger    = RS. 120" << "\n";
                cout << "3. Large Burger     = RS. 150" << "\n";
                break;
            case 3:
                cout << "\nSANDWICH MENU :" << "\n";
                cout << "1. Small Grill Sandwich = RS. 90" << "\n";
                cout << "2. Medium Sandwich      = RS. 125" << "\n";
                cout << "3. Large Sandwich       = RS. 180" << "\n";
                break;
            case 4:
                cout << "\nROLLS MENU :" << "\n";
                cout << "1. Small Rolls   = RS. 80" << "\n";
                cout << "2. Medium Rolls  = RS. 90" << "\n";
                cout << "3. Large Rolls   = RS. 120" << "\n";
                break;
            case 5:
                cout << "\nBIRYANI MENU :" << "\n";
                cout << "1. Veggie Biryani         = RS. 100" << "\n";
                cout << "2. Double Cheese Biryani  = RS. 110" << "\n";
                cout << "3. Paneer Biryani        = RS. 190" << "\n";
                break;
            default:
                cout << "Invalid choice" << "\n";
         }
        cout << "ENTER YOUR CHOICE: " << "\n";
    }
    int getPrice(int mainChoice, int subChoice) {
        const int prices[5][3] = {
            {100, 150, 200}, 
            {100, 120, 150}, 
            {90, 125, 180},  
            {80, 90, 120},   
            {100, 110, 190}  
        };

        if (mainChoice < 1 || mainChoice > 5 || subChoice < 1 || subChoice > 3) {
            return 0; 
        }

        return prices[mainChoice - 1][subChoice - 1];
     }
};
class Order {
private:
    string name;
    double totalBill;

public:
    Order() : totalBill(0) {}
    void askName() {
        cout << "\n.........................Tops Fast Food........................." << "\n";
        cout << "ENter your Name   " << "\n";
        cin >> name;
        cout << "\nHello, " << name << "\n";
    }

    void takeOrder(Menu& menu) {
        int mainChoice, subChoice, quantity;

        menu.displayMainMenu();
        cin >> mainChoice;

        if (mainChoice < 1 || mainChoice > 5) {
            cout << "Invalid main choice" << "\n";
            return;
  }

        menu.displaySubMenu(mainChoice);
        cin >> subChoice;

        if (subChoice < 1 || subChoice > 3) {
            cout << "Invalid sub choice" << "\n";
            return;
      }

        cout << "\nEnter your quatity: " << "\n";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quanity" << "\n";
            return;
           }
        totalBill = totalBill+  menu.getPrice(mainChoice, subChoice) * quantity;
}
  void genBill() {
        cout << "YOUR TOTAL BILL IS: RS. " << totalBill << "\n";
}
    bool continueOrdering() {
        char choice;
        cout << "\nWould you like to order anything else? (Y/N): " << "\n";
        cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }
};
int main() {
    Order order;
    Menu menu;
    order.askName();

    do {
        order.takeOrder(menu);
        order.genBill();
    } while (order.continueOrdering());
    cout << "\nTHANK YOU for your order. Your order will be delivered in just 10 minutes only..." << "\n";
    return 0;
}
