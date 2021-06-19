#pragma once
using namespace std;
#include "OrderRequest.hpp"
class OrderFulfilmentService
{
    //  Warehouse warehouse;

    public:
    OrderFulfilmentService()
    {

    }
    bool canFulfilOrder(OrderRequest orderRequest)
    {
        if(orderRequest.validOrder())
        { 
            // cout<<"Can fulfill the order"<<endl;
            return true;
        }
        // cout<<"Can't fulfill the order"<<endl;
        return false;
    }
    void reserveOrder(OrderRequest orderRequest)
    {
        if(!canFulfilOrder(orderRequest))
        {
            cout<<"Provide Valid order"<<endl;
            return;
        }
        orderRequest.placeOrder();
        cout<<"Order placed succesfully"<<endl;
        

        
    }
};