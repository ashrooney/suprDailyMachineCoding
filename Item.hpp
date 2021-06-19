#pragma once
#include "bits/stdc++.h"
#include "common.hpp"
using namespace std;
class Item
{
  string itemName;
  int itemID;
  ItemCategory itemcategory;
  public:
  Item(const string &itemName, const int &itemID, const ItemCategory &itemcategory)
  {
      this->itemName = itemName;
      this->itemID = itemID;
      this->itemcategory = itemcategory;
  }
  string getName()
  {
      return itemName;
  }
  ItemCategory getCategory()
  {
      return itemcategory;
  }
};