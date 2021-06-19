#include "OrderFulfilmentService.hpp"
#include "Warehouse.hpp"
using namespace std;
int main()
{
    OrderFulfilmentService orderFulfilmentService;
    
    /*
    *****WAREHOUSE INITIALIZATION******
    */
    vector<ItemRequest> itemRequestList;
    
    ItemRequest itemRequest1("mango",1,ItemCategory::FNV, 14);
    ItemRequest itemRequest2("milk",1,ItemCategory::MLK, 10);
    ItemRequest itemRequest3("spinach",1,ItemCategory::FNV, 5);

    itemRequestList.push_back(itemRequest1);
    itemRequestList.push_back(itemRequest2);
    itemRequestList.push_back(itemRequest3);

    User a("Ashish",1,"bhattashish192@gmail.com","7675824625");
    map<string, int> item;
    map<ItemCategory, int> itemcat;
    map<string, map<string,int>> items;
    map<string,map<ItemCategory,int>> itemcategory;

    item["mango"] = 15;
    item["milk"] = 20;
    item["spinach"] = 50;
    item["paneer"] = 10;

    items["17-6-2021"] = item;
    items["18-6-2021"] = item;
    items["19-6-2021"] = item;
    items["20-6-2021"] = item;
    
    itemcat[ItemCategory::FNV] = 15;
    itemcat[ItemCategory::MLK] = 10;
    itemcat[ItemCategory::XYZ] = 12;
    itemcategory["17-6-2021"] = itemcat;
    itemcategory["18-6-2021"] = itemcat;
    itemcategory["19-6-2021"] = itemcat;
    itemcategory["20-6-2021"] = itemcat;

    
    //TODO: Keep lists in warehouse static so that multiple instances of warehouse is possible in future
//     Warehouse::GetInstance().setLists(items, itemcategory);
    
    Warehouse *wa = new Warehouse(items);
     wa->setCategoryList( itemcategory ) ;
    item["mango"] = 20;
    item["milk"] = 10;
    item["spinach"] = 15;
    item["paneer"] = 20;

    items["17-6-2021"] = item;
    items["18-6-2021"] = item;
    items["19-6-2021"] = item;
    items["20-6-2021"] = item;
    
    

    Warehouse *wb = new Warehouse(items); 
    //TODO: use chrono header for dateTime


    /*
    *ORDER SERVICE UTILITY IN ACTION
    */
    OrderRequest orderRequest(a,"17-6-2021", itemRequestList,wa);
    
    if(orderFulfilmentService.canFulfilOrder(orderRequest)) //Return 1 if true and 0 if false
         cout<<"Order is possible"<<endl;
    else
         cout<<"Order not possible"<<endl;

    
    //TODO:Insted of using cout as output we can create a separate output class to provide output
    
    /*
    ********Reserving the order*******
    */
    orderFulfilmentService.reserveOrder(orderRequest); //Place order

    if(orderFulfilmentService.canFulfilOrder(orderRequest)) //Return 1 if true and 0 if false
         cout<<"Order is possible"<<endl;
    else
         cout<<"Order not possible"<<endl;

    orderFulfilmentService.reserveOrder(orderRequest); //Place order

    /******
    ****2nd ORDER REQUEST****
    *******/
    
    OrderRequest orderRequest2(a,"18-6-2021", itemRequestList,wb);

    if(orderFulfilmentService.canFulfilOrder(orderRequest2)) //Return 1 if true and 0 if false
         cout<<"Order is possible"<<endl;
    else
         cout<<"Order not possible"<<endl;

     orderFulfilmentService.reserveOrder(orderRequest2);
     // orderFulfilmentService.reserveOrder(orderRequest2);
}