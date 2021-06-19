#pragma once
#include "bits/stdc++.h"
#include "Item.hpp"
using namespace std;
class ItemRequest
{
  Item item;
  int quantity;
  public:
  ItemRequest(const string &name, const int &id, const ItemCategory &category, const int &quantity):item(name, id, category)
  {
      this->quantity = quantity;
  }
 int getQuantity()
 {
     return quantity;
 }
 Item getItem()
 {
     return item;
 }
};