// The customer cannot buy more than 5 items.
// If the customer does not have enough credit, the product cannot be bought.


#include <iostream>
#include <string>

using namespace std;

const int N = 5; // The global constant symbol N 

class Product{
private:
    string name;
    float price;

public:
    Product(){}   // Default constructor with an empty code block
    ~Product(){}   // Destructor
    Product(string n, float p) : name(n), price(p) {} // Parameted constructor

    // Get-set for name
    string get_name(){return name;} 
    void set_name(string n){name = n;}

    // Get-set for price
    float get_price(){return price;}
    void set_price(float p){price = p;}

};

class Customer{
    private:
        string customer_name;
        float credit_card_limit = 1000; // default value for the limit
        Product list_of_ordered_products[N]; 
        int count_of_ordered_products;

    public:
        Customer(string cname, float cclimit = 1000); // Parameted constructor

        void operator+(Product P){

            cout << "Add product : " << P.get_name() << " " << P.get_price() << endl;

            
            if(count_of_ordered_products >= N){
                cout << "Count of ordered products exceeded the maximum number." << endl;
                cout << "Product add operation is not done." << endl;
                return;
            }

            if(calculate_total_debt() + P.get_price() > credit_card_limit){
                cout << "Total debt exceeded the credit card limit." << endl;
                cout << "Product add operation is not done." << endl;
                return;
            }
            
            cout << "Product is added to customer successfully." << endl;
            list_of_ordered_products[count_of_ordered_products++] = P; // Incrementing to add the product
        }

        float calculate_total_debt(){
            float total = 0;
            for(int i = 0; i < count_of_ordered_products; i++){
                total += list_of_ordered_products[i].get_price();
            }
            return total;
        }
        
        void print(){
            cout << "Customer name: " << customer_name << endl;
            cout << "Credit card Limit: " << credit_card_limit << endl;
            cout << "Count of ordered products: " << count_of_ordered_products << endl;
            cout << "List of Ordered Products: " << endl;

            for(int i = 0; i < count_of_ordered_products; i++){
                cout << i + 1 << ". Name: " << list_of_ordered_products[i].get_name() << "     " << "Price: " << list_of_ordered_products[i].get_price() << endl;
            }

            cout << "TOTAL DEBT = " << calculate_total_debt() << endl << endl;
            cout << "******************************************************************" << endl << endl;
        }
};

Customer::Customer(string cname, float cclimit) : customer_name(cname), credit_card_limit(cclimit), count_of_ordered_products(0) {}

int main(){
    cout << "PROGRAM STARTED" << endl << endl;

    Customer johnFisher("JOHN FISHER", 2000);
    Customer ronaldCraig("RONALD CRAIG"); // Using default credit card limit
    Customer thomasAustin("THOMAS AUSTIN", 750);

    // Create Product objects with given names and prices
    Product panasonicPhone("Panasonic Phone", 800);
    Product toshibaBattery("Toshiba Battery", 300);
    Product kenwoodDVD("Kenwood DVD", 400);
    Product linksysRouter("Linksys Router", 60);
    Product nintendoPortable("Nintendo Portable", 150);
    Product mitsubishiStand("Mitsubishi Stand", 50);
    Product canonBattery("Canon Battery", 500);
    Product nikonAccessory("Nikon Accessory", 600);
    Product yamahaSubwoofer("Yamaha Subwoofer", 200);
    Product whirlpoolCharger("Whirlpool Charger", 90);
    Product logitechRemote("Logitech Remote", 20);
    Product lgDryer("LG Dryer", 100);

    // Add products to customers

    // First addition
    johnFisher + panasonicPhone;
    cout << endl;
    johnFisher + toshibaBattery;
    cout << endl;
    johnFisher + kenwoodDVD;
    cout << endl;

    johnFisher.print();

    // Second addition
    ronaldCraig + canonBattery;
    cout << endl;
    ronaldCraig + nikonAccessory; // This won't be added due to credit limit
    cout << endl;
    ronaldCraig + yamahaSubwoofer;
    cout << endl;

    ronaldCraig.print();

    // Third addition
    thomasAustin + whirlpoolCharger;
    cout << endl;
    thomasAustin + logitechRemote;
    cout << endl;
    thomasAustin + lgDryer;
    cout << endl;
    thomasAustin + linksysRouter;
    cout << endl;
    thomasAustin + nintendoPortable;
    cout << endl;
    thomasAustin + mitsubishiStand; // This won't be added due to count limit
    cout << endl;

    thomasAustin.print();

    cout << "PROGRAM FINISHED" << endl;

    return 0;
}


