#include <iostream>
#include <string>

using namespace std;

class Category {
public:
    int id;
    std::string name;
    Category(int id, std::string name) {
        this->name = name;
        this->id = id;
    }
};

class Brand {
public:
    int id;
    std::string name;
    Brand(int id, std::string name) {
        this->name = name;
            this->id = id;

    }
};

class Seller {
public:
    int id;
    std::string name;
    Seller(int id,std::string name) {
        this->name = name;
            this->id = id;
    }

};

class Product {
public:
    int id;
    int  id_seller, brand_id, category_id;
    std::string name;
    Product(int id , int id_seller, int  brand_id, int  category_id,std::string name) {
        this->name = name;
        this->id = id;
        this->id_seller = id_seller;
        this->brand_id = brand_id;
        this->category_id =category_id;
    }
};
std::string convert(std::string res) {
    int size = res.size();

    if (size < 20) {
        for (; res.size() < 20;) {
            res += ' ';
        }
    }
    return res;
}

std::string findSeller(int id,  Seller** sellers);
std::string findCategory(int id,  Category** categories);
std::string findBrand(int id,  Brand** brands);

int main() {
    setlocale(LC_ALL, "Russian");

    Brand* brand1 = new Brand( 1, "Nike" );
    Brand* brand2 = new Brand( 2, "Apple" );
    Brand* brand3 = new Brand( 3, "Samsung" );
    Brand* brand4 = new Brand( 4, "Adidas" );
    Brand* brand5 = new Brand( 5, "Old Spice" );

    Seller* seller1 = new Seller( 1, "Amazon" );
    Seller* seller2 = new Seller( 2, "Best Buy" );
    Seller* seller3 = new Seller( 3, "Walmart" );
    Seller* seller4 = new Seller( 4, "Target" );
    Seller* seller5 = new Seller( 5, "Costco" );

    Product* product1 = new Product( 1, 1, 2, 1, "обувь" );
    Product* product2 = new Product( 2, 2, 2, 2, "iPhone" );
    Product* product3 = new Product( 3, 1, 1, 3, "холодос" );
    Product* product4 = new Product( 4, 3, 3, 4, "майка" );
    Product* product5 = new Product( 5, 1, 1, 5, "шампунь" );
    
    Seller* sellers[] = {seller5, seller4, seller3, seller2, seller1};
    Category* categories[] = {new Category ( 1, "электроника " ), new Category ( 2, "одежда" ), 
                              new Category ( 3, "дом и сад" ), new Category ( 4, "спорт" ), 
                              new Category (5, "уход за собой")};
    Brand* brands[] = {brand5, brand4, brand3, brand2, brand1};
    std::cout << convert("ID") << convert("Имя") << convert("Продавец") << convert("Бренд") << convert("Категория") << std::endl;
    Product* Array[] = { product1 ,product2 ,product3 ,product4 ,product5 };
    for (auto object : Array) {
        cout << object->id << " " << object->name << " " << findSeller(object->id_seller, sellers) << " "<< findCategory(object->category_id,  categories) << " "
    << findBrand(object->brand_id,  brands) << "\n";
    }
    
    
    
   
    return 0;
}

std::string findSeller(int id,  Seller** sellers) {
    for (int i = 0; i < 5; i++) {
        if (id == sellers[i]->id) {
            std::string  name = sellers[i]->name;
            return name;
        }
    }
    return NULL;
}

std::string findCategory(int id,  Category** categories) {
    for (int i = 0; i < 5; i++) {
        if (id == categories[i]->id) {
            std::string  name = categories[i]->name;
            return name;
        }
    }
    return NULL;
}

std::string findBrand(int id,  Brand** brands) {
    for (int i = 0; i < 5; i++) {
        if (id == brands[i]->id) {
            std::string  name = brands[i]->name;
            return name;
        }
    }
    return NULL;
}
