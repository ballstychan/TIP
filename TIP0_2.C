#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product_Details {
    char product_name[50];
    double product_weight;
    char weight_category[20];
    double price;
    char quantity_category[20];
    int quantity[2];
    double cost[2];
    char DateAdded[20][2];
};

typedef struct Product_Details Product_Details;

struct Categories{
    Product_Details Beverage;
    Product_Details Canned_Goods;
    Product_Details Dairy;
    Product_Details Dry_Baking_Goods;
    Product_Details Produce;
    Product_Details Cleaners;
    Product_Details Paper_Goods;
    Product_Details Personal_Care;
    Product_Details Other;
};
//Based on this category list
/*Beverages – coffee/tea, juice, soda
Bread/Bakery – sandwich loaves, dinner rolls, tortillas, bagels
Canned/Jarred Goods – vegetables, spaghetti sauce, ketchup
Dairy – cheeses, eggs, milk, yogurt, butter
Dry/Baking Goods – cereals, flour, sugar, pasta, mixes
Frozen Foods – waffles, vegetables, individual meals, ice cream
Meat – lunch meat, poultry, beef, pork
Produce – fruits, vegetables
Cleaners – all- purpose, laundry detergent, dishwashing liquid/detergent
Paper Goods – paper towels, toilet paper, aluminum foil, sandwich bags
Personal Care – shampoo, soap, hand soap, shaving cream
Other – baby items, pet items, batteries, greeting cards
*/

typedef struct Categories Categories;

/*
struct item{
    int size;
    int capacity;
    Categories *Item;
};

typedef struct item item;

void initList(item* item) {
    item->size = 0;         
    item->capacity = 10;
    item->Item = (Categories*)malloc(sizeof(Categories)*item->capacity);
}

void resizeVector(item *items, size_t newCapacity) {
    items->Item = (Categories*)realloc(items->Item, newCapacity*sizeof(Categories));
    items->capacity = newCapacity;
}

*/ //Will implement vectors later, for now, ako sa i-set ang size sa struct array


void InitializeItem(Categories *Categories){
    strcpy(Categories->Beverage.product_name, "Coke Sakto");
    Categories->Beverage.price = 20.00;
    strcpy(Categories->Beverage.weight_category, "grams");
    Categories->Beverage.product_weight = 100.00;
    strcpy(Categories->Beverage.quantity_category, "pcs");
    Categories->Beverage.quantity = 30;

    strcpy(Categories->Canned_Goods.product_name, "Century Tuna Spicy");
    Categories->Canned_Goods.price = 30.00;
    strcpy(Categories->Canned_Goods.weight_category, "grams");
    Categories->Canned_Goods.product_weight = 200.00;
    strcpy(Categories->Canned_Goods.quantity_category, "pcs");
    Categories->Canned_Goods.quantity = 30;

    strcpy(Categories->Dairy.product_name, "Eden Cheese");
    Categories->Dairy.price = 15.00;
    strcpy(Categories->Dairy.weight_category, "grams");
    Categories->Dairy.product_weight = 50.00;
    strcpy(Categories->Dairy.quantity_category, "pcs");
    Categories->Dairy.quantity = 15;

    strcpy(Categories->Dry_Baking_Goods.product_name, "All-purpose Flour");
    Categories->Dry_Baking_Goods.price = 40.00;
    strcpy(Categories->Dry_Baking_Goods.weight_category, "grams");
    Categories->Dry_Baking_Goods.product_weight = 100.00;
    strcpy(Categories->Dry_Baking_Goods.quantity_category, "pcs");
    Categories->Dry_Baking_Goods.quantity = 30;

    strcpy(Categories->Produce.product_name, "Red Onion");
    Categories->Produce.price = 25.00;
    strcpy(Categories->Produce.weight_category, "grams");
    Categories->Produce.product_weight = 0.25;
    strcpy(Categories->Beverage.quantity_category,"pcs");
    Categories->Beverage.quantity = 20;

    strcpy(Categories->Cleaners.product_name, "Tide");
    Categories->Cleaners.price = 8.00;
    strcpy(Categories->Cleaners.weight_category, "grams");
    Categories->Cleaners.product_weight = 10.00;
    strcpy(Categories->Cleaners.quantity_category, "pcs");
    Categories->Cleaners.quantity = 20;

    strcpy(Categories->Paper_Goods.product_name, "Toilet Paper");
    Categories->Paper_Goods.price = 8.00;
    strcpy(Categories->Paper_Goods.weight_category, "grams");
    Categories->Paper_Goods.product_weight = 50.00;
    strcpy(Categories->Paper_Goods.quantity_category, "pcs");
    Categories->Paper_Goods.quantity = 10;

    strcpy(Categories->Personal_Care.product_name, "Safe Guard Soap");
    Categories->Personal_Care.price = 8.00;
    strcpy(Categories->Personal_Care.weight_category, "grams");
    Categories->Personal_Care.product_weight = 10.00;
    strcpy(Categories->Personal_Care.quantity_category, "pcs");
    Categories->Personal_Care.quantity = 30;

    strcpy(Categories->Other.product_name, "Short Bondpaper");
    Categories->Other.price = 1.00;
    strcpy(Categories->Other.weight_category, "grams");
    Categories->Other.product_weight = 5.00;
    strcpy(Categories->Other.quantity_category, "pcs");
    Categories->Other.quantity = 30;    
}

void TitleScreen(){
    char String[40] = "                ";
    printf("%s////////////    ///     ////////////\n",String);
    printf("%s    ///         ///     ///      //\n",String);
    printf("%s    ///         ///     ///      //\n",String);
    printf("%s    ///         ///     /////////\n",String);
    printf("%s    ///         ///     ///      \n",String);
    printf("%s    ///         ///     ///      \n",String);
}

void header(){
    int len = strlen("  ////         //////   ///      ");
    for(int i = 0; i<2*len; i++){
        printf("-");
    }

}

void greeter(){
    for(int i = 0; i<25; i++)
        printf(" ");
    printf("WELCOME USER!");
    for(int i = 0; i<30; i++)
        printf(" ");
}

void main_interface(){
    printf("1. Display Products\n");
    printf("2. Add Products\n");
    printf("3. Input Sales\n");
    printf("4. Print Costs and Sales\n");
    printf("5. Exit\n");
    printf("Input: ");

}

void Display_Interface(){

}
int main(){
    Categories Item_Store[100], *ItemP;
    ItemP = &Item_Store;
    InitializeItem(ItemP);
    header();
    printf("\n");
    TitleScreen();
    header();
    printf("\n\n");
    greeter();
    printf("\n");
    int loop = 1;
    while(loop){
    int choice;
    printf("\n");
    main_interface();
    scanf("%i", &choice);
    switch(choice){
        case 5:
        loop = 0;
        break;
        default:
        break;
    }
    }

    return 0;
}




