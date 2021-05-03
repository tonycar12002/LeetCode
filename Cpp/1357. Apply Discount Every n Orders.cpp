/*
Author: Tony Hsiao
Date: 2021/04/24
Topic: 1357. Apply Discount Every n Orders
Speed: 208 ms, 120.6 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
class Cashier {
public:
  Cashier(int n, int discount, vector<int>& products, vector<int>& prices) :
      n_(n), discounts_(discount), current_customer_(0) {
    for (int i = 0; i < products.size(); ++i) {
      products_[products[i]] = prices[i];
    }
  }

  double getBill(vector<int> product, vector<int> amount) {
    current_customer_++;
    double original_bill = 0;
    for (int i = 0; i < product.size(); ++i) {
      original_bill += products_[product[i]] * amount[i];
    }
    if (current_customer_ == n_) {
      original_bill = original_bill - (discounts_ * original_bill) / 100.0;
      current_customer_ = 0;
    }
    return original_bill;
  }
private:
  std::unordered_map<int, int> products_;
  int discounts_;
  int current_customer_;
  int n_;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */