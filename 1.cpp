#include <iostream>
#include <string>

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
    int  id_seller;
    std::string  brand_id;
    std::string category_id;
    std::string name;
    Product(int id , int id_seller, Brand*  brand_id, Category*  category_id,std::string name) {
        this->name = name;
        this->id = id;
        this->id_seller = id_seller;
        this->brand_id = brand_id->name;
        this->category_id =category_id->name;
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

std::string findName(int id,  Seller** sellers);

int main() {
    setlocale(LC_ALL, "Russian");

    Category* category1 = new Category ( 1, "электроника " );
    Category* category2 = new Category ( 2, "одежда" );
    Category* category3 = new Category ( 3, "дом и сад" );
    Category* category4 = new Category ( 4, "спорт" );
    Category* category5 = new Category (5, "уход за собой");

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

    Product* product1 = new Product( 1, 1, brand1, category4, "обувь" );
    Product* product2 = new Product( 2, 2, brand2, category1, "iPhone" );
    Product* product3 = new Product( 3, 1, brand3, category3, "холодос" );
    Product* product4 = new Product( 4, 3, brand4, category2, "майка" );
    Product* product5 = new Product( 5, 1, brand5, category5, "шампунь" );
    
    Seller* sellers[] = {seller5, seller4, seller3, seller2, seller1};
    std::cout << convert("ID") << convert("Имя") << convert("Продавец") << convert("Бренд") << convert("Категория") << std::endl;
    Product* Array[] = { product1 ,product2 ,product3 ,product4 ,product5 };
    // for (auto i : Array) {
    //     std::cout << convert(std::to_string(i->id))<<convert(i->name) << convert(i->seller_id)<< convert(i->brand_id)<< convert(i->category_id) << '\n';
    // }
    
    std::cout << findName(product5->id_seller, sellers);
    
    
   
    return 0;
}

std::string findName(int id,  Seller** sellers) {
    for (int i = 0; i < 5; i++) {
        if (id == sellers[i]->id) {
            std::string  name = sellers[i]->name;
            return name;
    }
    }
    return NULL;
}
