import <iostream>;
import <string>;

using namespace std;

// Abstract Component class. Arbitrary Pizza
class Pizza {
    float price;
    string desc;
    public:
        virtual ~Pizza() {} // pure virtual destructor
        Pizza() : price{0.0f}, desc{""} {}
        // NVI idiom
        float getPrice() const {
            return theprice();
        }
        string getDesc() const {
            return thedesc();
        }
    private:
        virtual float theprice() const = 0;
        virtual string thedesc() const = 0;
};

// Concrete Component class. All Pizzas must have crust and sauce.
class CrustAndSauce : public Pizza {
    public:
        CrustAndSauce() : Pizza() {} // default ctor for initialization
    private: // NVI idiom
        float theprice() const override {
            return 5; // just having a crust and sauce shall be $5
        }
        string thedesc() const override {
            return "Pizza has crust and sauce ";
        }
};

// Decorator class inherits abstract Pizza class
class Decorator : public Pizza {
    Pizza *thepizza; // the () is the ctor i suppose.
    public:
        virtual ~Decorator() {} // abstract classness.
        Decorator(Pizza* p) : thepizza(p) {} // Decorator needs to implement Pizza constructor
        // doesn't change or implement any inherited classes
        float theprice() const override {
            return thepizza->getPrice();
        }
        string thedesc() const override {
            return thepizza->getDesc();
        }
};

// ConcreteDecoratorA allows for toppings
class Topping : public Decorator {
    string topping;
    public:
        Topping(string topping, Pizza* p) : Decorator(p), topping{topping} {}
        float theprice() const override {
            return Decorator::theprice() + 1; // each topping is additional $1
        }
        string thedesc() const override {
            return Decorator::thedesc() + " and topping " + topping;
        }
};

// ConcreteDecoratorB allows for DippingSauce
class DippingSauce : public Decorator {
    string thesauce;
    public:
        DippingSauce(string thesauce, Pizza* p) : Decorator(p), thesauce{thesauce} {}
        float theprice() const override {
            return Decorator::theprice() + 2; // $2 for sauce
        }
        string thedesc() const override {
            return Decorator::thedesc() + " and " + thesauce + " dipping sauce ";
        } 
};

// let's try this out!
int main() {
    // create a base class pointer and specify the concrete component
    Pizza* order1 = new CrustAndSauce(); // gyah
    order1 = new Topping("pepperoni", order1); // add peperoni
    order1 = new DippingSauce("BBQ", order1); // add sauce to dip
    float price = order1->getPrice();
    price *= 1.13; // tax
    int discounted_price = static_cast<int>(price);
    cout << order1->getDesc() << " with discounted price $" << discounted_price << endl;

    // another trial
    Pizza* base = new CrustAndSauce();
    Pizza* baseWithMushroom = new Topping("mushroom", base);
    Pizza* baseWithMushroomAndAnchovies = new Topping("anchovies", baseWithMushroom);

    cout << baseWithMushroomAndAnchovies->getDesc() << " with discounted price $" << baseWithMushroomAndAnchovies->getPrice() << endl;

    return 0;
}