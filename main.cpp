#include <iostream>
#include <cstring>

#pragma region Entrees
class Entree {
protected:
    char _entree[10];
public:
    virtual ~Entree() {}
    const char *getEntree() { return _entree; }
};

class Burger : public Entree {
public:
    Burger() {
        printf("\n Grill burger patty, add tomatoes and place them in a bun");
        strcpy(_entree, "hamburger");
    }
};

class Hotdog : public Entree {
public:
    Hotdog(){
        printf("\n Cook sausage and place it in a bun");
        strcpy(_entree, "hotdog");
    }
};
#pragma endregion Entrees

#pragma region Sides
class Side {
protected:
    char _side[10];
public:
    virtual ~Side() {}
    char *getSide() { return _side; }
};

class Fries : public Side {
public:
    Fries(){
        printf("\n Fry and season potatoes");
        strcpy(_side, "fries");
    }
};

class Salad : public Side {
public:
    Salad(){
        printf("\n Toss greens and dressing together");
        strcpy(_side, "salad");
    }
};
#pragma endregion Sides

#pragma region Drink
class Drink {
protected:
    char _drink[10];
public:
    Drink(){
        printf("\n Fill cup with soda\n");
        strcpy(_drink, "soda");
    }
    char *getDrink(){
        return _drink;
    }
};
#pragma endregion Drink

class MealCombo {
private:
    Entree* entree;
    Side* side;
    Drink* drink;
    char _bag[100];

public:
    MealCombo(const char *type){
        sprintf(_bag, "\n %s meal combo:", type);
    }
    void setEntree(Entree *e) { entree = e; }
    void setSide(Side *s) { side = s; }
    void setDrink(Drink *d) { drink = d; }
    const char *openMealBag(){
        sprintf(_bag, "%s %s, %s, %s", _bag, entree->getEntree(), side->getSide(), drink->getDrink());
        return _bag;
    }

};


#pragma region Builders
class MealBuilder {
protected:
    MealCombo * _meal;
public:
    virtual ~MealBuilder() {}
    virtual void cookEntree() {};
    virtual void cookSide() {};
    virtual void fillDrink() {};
    MealCombo* getMeal() { return _meal; }
};

class BurgerMeal : public MealBuilder {
public:
    BurgerMeal() { _meal = new MealCombo("Burger"); }
    void cookEntree() { 
        Burger *burger = new Burger; 
        _meal->setEntree(burger);
    }
    void cookSide(){
        Fries *fries = new Fries;
        _meal->setSide(fries);
    }
    void fillDrink(){
        Drink *drink = new Drink;
        _meal->setDrink(drink);
    }
};

class HotdogMeal : public MealBuilder {
public:
    HotdogMeal() { _meal = new MealCombo("Hotdog"); }
    void cookEntree(){
        Hotdog *hotdog = new Hotdog;
        _meal->setEntree(hotdog);
    }
    void cookSide(){
        Salad *caesar = new Salad;
        _meal->setSide(caesar);
    }
    void fillDrink(){
        Drink *drink = new Drink;
        _meal->setDrink(drink);
    }
};
#pragma endregion Builders

int main(){

    MealBuilder* cook = new MealBuilder;
    MealCombo* meal;

    cook = new BurgerMeal;
    cook->cookEntree();
    cook->cookSide();
    cook->fillDrink();
    meal = cook->getMeal();
    std::cout << meal->openMealBag() << std::endl;

    printf("Done\n");
    return 0;
}

// #include <iostream>
// #include <vector>

// class Product1
// {
//   public:
//   std::vector<std::string> parts_;
  
//   void ListParts() const {
//     std::cout << "Product parts: ";
//     for (size_t i = 0; i < parts_.size(); i++) {
//       if(parts_[i] == parts_.back()) {
//         std::cout << parts_[i];
//       } else {
//         std::cout << parts_[i] << ", ";
//       }
//     }
//     std::cout << "\n\n";
//   }
// };

// class Builder
// {
//   public:
//   virtual ~Builder() {}
//   virtual void ProducePartA() const = 0;
//   virtual void ProducePartB() const = 0;
//   virtual void ProducePartC() const = 0;  
// };

// class ConcreteBuilder1: public Builder
// {
//   private:
//   Product1* product;
  
//   public:
//   ConcreteBuilder1() { this->Reset(); }
//   ~ConcreteBuilder1() { delete product; }
//   void Reset() { 
//     this->product = new Product1(); 
//   }
//   void ProducePartA() const override {
//     this->product->parts_.push_back("PartA1");
//   }
  
//   void ProducePartB() const override {
//     this->product->parts_.push_back("PartB1");
//   }
  
//   void ProducePartC() const override {
//     this->product->parts_.push_back("PartC1");
//   }
  
//   Product1* GetProduct() {
//     Product1* result = this->product;
//     this->Reset();
//     return result;
//   }
// };

// class Director
// {
//   private:
//   Builder* builder;
  
//   public:
//   void set_builder(Builder* builder) {
//     this->builder = builder;
//   }
  
//   void BuildMinimalViableProduct() {
//     this->builder->ProducePartA();
//   }
  
//   void BuildFullFeaturedProduct() {
//     this->builder->ProducePartA();
//     this->builder->ProducePartB();
//     this->builder->ProducePartC();
//   }
// };

// void ClientCode(Director& director)
// {
//   ConcreteBuilder1* builder = new ConcreteBuilder1();
//   director.set_builder(builder);
//   std::cout<<"Standard basic product:\n";
//   director.BuildMinimalViableProduct();
  
//   Product1* p = builder->GetProduct();
//   p->ListParts();
//   delete p;
  
//   std::cout << "Standard full featured product:\n";
//   director.BuildFullFeaturedProduct();
  
//   p = builder->GetProduct();
//   p->ListParts();
//   delete p;
  
//   std::cout<<"Custom product:\n";
//   builder->ProducePartA();
//   builder->ProducePartB();
//   p = builder->GetProduct();
//   p->ListParts();
//   delete p;
//   delete builder;

// }


// int main()
// {
//   Director* director = new Director();
//   ClientCode(*director);
//   delete director;
  
//   return 0;
// }
