#pragma once
#include<bits/stdc++.h>
#include<chrono>
#include "common.hpp"
using namespace std;
class Warehouse
{
    
    //TODO
    //Right now in this implementation the warehouse class is a singleton class
    //It would have been better to have multiple warehouses possible
    
    map<string, map<string,int>> itemLimit;
    static map<string, map<ItemCategory,int>> itemCategoryLimit;
    public:
    Warehouse()=default;
    Warehouse(map<string, map<string,int>> a )
    {
        this->itemLimit = a;
        map<string, map<ItemCategory,int>> itemCategoryLimit;
        // this->itemCategoryLimit = b;
    }
   
    // void setLists(map<string, map<string,int>> itemltd,  map<string, map<ItemCategory,int>> itemCategoryltd)
    // {
    //     itemLimit = itemltd;
    //     itemCategoryLimit = itemCategoryltd;
    // }
    map<string,int> getItems(const string &date)
    {
        return itemLimit[date];
    }
    void setItems(string date, map<string,int> mp)
    {
        itemLimit[date] = mp;
    }
    static map<ItemCategory,int> getItemCategory(const string &date)
    {
        return itemCategoryLimit[date];
    }
    static void setItemCategory(string date, map<ItemCategory,int> mp)
    {
        itemCategoryLimit[date] = mp;
    }
    static void setCategoryList(map<string, map<ItemCategory,int>> itemCategoryltd)
    {
        itemCategoryLimit = itemCategoryltd;
    }
    

};
map<string, map<ItemCategory,int>> Warehouse::itemCategoryLimit;
// Warehouse::itemCategoryLimit ;