#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Product {
    private:
    string name;
    int price;
    int quantity;
    public:
    Product(string name, int price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
    void setName(string name) {
        if (name != "") {
            this->name = name;
        }
        else
            cout << "Product name is empty" << endl;
    }
    void setPrice(int price) {
        if (price >= 0) {
            this->price = price;
        }
        else
            cout << "Product price is empty" << endl;
    }
    void setQuantity(int quantity) {
        if (quantity >= 0) {
            this->quantity = quantity;
        }
        else
            cout << "Product quantity is empty" << endl;
    }
    string getName() {
        return this->name;
    }
    int getPrice() {
        return this->price;
    }
    int getQuantity() {
        return this->quantity;
    }
    void printInfo() {
        cout << "Name: " << this->name << endl;
        cout << "Price: " << this->price << endl;
        cout << "Quantity: " << this->quantity << endl;
    }
};
int main() {
    Product product("noname", 0, 0);
    vector<Product> products;
    string user_name;
    cout << "Please enter your name:";
    cin >> user_name;
    int user_choose;
    cout << "Hi , " << user_name << " choose an option you want to do: " << endl;
    do {
        cout << "1. Add product" << endl;
        cout << "2. Delete product" << endl;
        cout << "3. Buy product" << endl;
        cout << "4. Print product" << endl;
        cout << "5. Quit" << endl;
        cin >> user_choose;

        if (!cin.fail() && user_choose < 1  || user_choose > 5) {
            cin.clear();
            cout << "Please enter a valid choice!" << endl;
            continue;
        }

        switch (user_choose) {
            case 1:
                //11
                break;
            case 2:
                //22
                break;
            case 3:
                //33
                break;
            case 4:
                //44
                break;
            case 5:
                cout << 'Bye bye...' << endl;
                break;
        }
    }
    while (user_choose < 1 || user_choose > 5);
}


