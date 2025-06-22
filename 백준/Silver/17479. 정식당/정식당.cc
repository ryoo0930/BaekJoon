#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{   
    unordered_map<string, int> normal_menu;
    unordered_map<string, int> special_menu;
    vector<string> service_menu;
    int normal_menu_size = 0, special_menu_size = 0, service_menu_size = 0;
    cin >> normal_menu_size >> special_menu_size >> service_menu_size;

    for (int i = 0; i < normal_menu_size; i++) {
        string menu_name; int menu_cost;
        cin >> menu_name >> menu_cost;
        normal_menu.insert({ menu_name, menu_cost });
    }
    for (int i = 0; i < special_menu_size; i++) {
        string menu_name; int menu_cost;
        cin >> menu_name >> menu_cost;
        special_menu.insert({ menu_name, menu_cost });
    }
    for (int i = 0; i < service_menu_size; i++) {
        string menu_name;
        cin >> menu_name;
        service_menu.push_back(menu_name);
    }

    long long normal_menu_total_price = 0;
    long long special_menu_total_price = 0;
    int service_menu_order_count = 0;

    int order_count = 0; cin >> order_count;
    for (int i = 0; i < order_count; i++) {
        string menu; cin >> menu;
        if (normal_menu.count(menu)) normal_menu_total_price += normal_menu[menu];
        else if (special_menu.count(menu)) special_menu_total_price += special_menu[menu];
        else service_menu_order_count++;
    }

    bool is_Okay = true;
    if (special_menu_total_price > 0) if (normal_menu_total_price < 20000) is_Okay = false;
    if (service_menu_order_count >= 1) if (normal_menu_total_price + special_menu_total_price < 50000) is_Okay = false;
    if (!(service_menu_order_count == 0 || service_menu_order_count == 1)) is_Okay = false;

    if (is_Okay) cout << "Okay" << endl;
    else cout << "No" << endl;

    return 0;
}