#pragma once
#include "bits/stdc++.h"
#include "User.hpp"
#include "ItemRequest.hpp"
#include "Warehouse.hpp"
using namespace std;
class OrderRequest
{
  User user;
  string date;
  vector<ItemRequest> itemRequest;
  Warehouse *warehouse;
  public:
 OrderRequest(User user, string date, vector<ItemRequest> itemRequest, Warehouse *warehouse)
  {
      this->user = user;
      this->date = date;
      this->itemRequest = itemRequest;
      this->warehouse = warehouse;
    
  }
  bool validOrder()
  {
      for(auto it:itemRequest)
      {
          auto itemsForDate = warehouse->getItems(date);
          auto itemCategoryForDate = warehouse->getItemCategory(date);
          for(auto items:itemsForDate)
          {
              if(it.getItem().getName() == items.first)
              {
                  if(it.getQuantity() > items.second)
                   return false;
              }
          }
           for(auto items:itemCategoryForDate)
          {
              if(it.getItem().getCategory() == items.first)
              {
                  if(it.getQuantity() > items.second)
                   return false;
              }
          }
      }
      return true;
  }

  void placeOrder()
  {
      for(auto it:itemRequest)
      {
          auto itemsForDate = warehouse->getItems(date);
          auto itemCategoryForDate = warehouse->getItemCategory(date);

          for(auto items:itemsForDate)
          {
              if(it.getItem().getName() == items.first)
              {
                  
                   auto newquantity = items.second-it.getQuantity();
                   itemsForDate[items.first] =  newquantity;   
              }
               
          }
          warehouse->setItems(date, itemsForDate);
           for(auto items:itemCategoryForDate)
          {
              if(it.getItem().getCategory() == items.first)
              {
                  auto newquantity = items.second-it.getQuantity();
                //    items.second = newquantity; 
                   itemCategoryForDate[items.first] = newquantity;  
              }
          }
         warehouse->setItemCategory(date,  itemCategoryForDate);
      }
  }


};