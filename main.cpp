#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product {
    private:
    string name;
    int price;
    int quantity;
    public:
    Product(const string& name, int price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
    void setName(const string& name) {
        if (!name.empty()) {
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
        return name;
    }
    [[nodiscard]] double getPrice() const {
        return price;
    }
    [[nodiscard]] int getQuantity() const {
        return quantity;
    }
    void printInfo() const {
        cout << "Name: " << this->name << endl;
        cout << "Price: " << this->price << endl;
        cout << "Quantity: " << this->quantity << "\n" << endl;
    }
};
void addProduct(vector<Product>& products)
{
    string name;
    int price;
    int quantity;

    cout << "Please enter name of the product: ";
    cin >> name;

    cout << "Please enter price of the product: ";
    cin >> price;

    cout << "Please enter quantity of the product: ";
    cin >> quantity;

    Product temp_product(name, price, quantity);
    products.push_back(temp_product);

    cout << "Product has been added successfully!" << endl;
}

void deleteProduct(vector<Product>& products) {
    string name;
    cout << "Please enter name of the product: ";
    cin >> name;
    bool found = false;
    for (int i = 0; i < products.size(); i++) {
        if (products[i].getName() == name) {
            products.erase(products.begin() + i);
            cout << "Product has been deleted successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product hasn't been deleted successfully!" << endl;
    }
}

void changePrice(vector<Product>& products) {
    string name;
    cout << "Please enter name of the product: ";
    cin >> name;
    bool found = false;
    for (auto &product : products) {
        if (product.getName() == name) {
            int new_price;
            cout << "Please enter new price of the product: ";
            cin >> new_price;

            while (cin.fail() || new_price < 0)
                {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter new price of the product: ";
                cin >> new_price;
            }
            product.setPrice(new_price);
            cout << "Product has been changed successfully!" << endl;

            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product hasn't been changed successfully!" << endl;
    }

}
void printProducts(const vector<Product>& products) {
    for (int i = 0; i < products.size(); i++) {
        cout << "Product: " << "#" << i << endl;
        products[i].printInfo();
    }
}
int main() {
    vector<Product> products;
    string user_name;
    cout << "Please enter your name:";
    cin >> user_name;
    int user_choose;
    cout << "Hi , " << user_name << " choose an option you want to do: " << endl;

    do {
        cout << "1. Add product" << endl;
        cout << "2. Delete product" << endl;
        cout << "3. Change price to product" << endl;
        cout << "4. Print product" << endl;
        cout << "5. Quit" << endl;
        cin >> user_choose;

        if (cin.fail() || user_choose < 1 || user_choose > 5) {
            cin.clear();
            cout << "Please enter a valid choice!" << endl;
            continue;
        }

        switch (user_choose) {
            case 1: {
                addProduct(products);
                break;
            }
            case 2: {
                deleteProduct(products);
                break;
            }
            case 3: {
                changePrice(products);
                break;
            }
            case 4: {
                printProducts(products);
                break;
            }

            case 5: {
                cout << "Bye bye..." << endl;
                break;
            }
            default: {
                cout << "Unknown Error!" << endl;
            }

        }
    }
    while (user_choose != 5);
}


