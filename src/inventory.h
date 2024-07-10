#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>

template <typename T>
class Inventory {
private:
    std::vector<T> items;
public:
    void addItem(const T& item);
    void removeItem(const T& item);
    void listItems() const;
};

template <typename T>
void Inventory<T>::addItem(const T& item) {
    items.push_back(item);
}

template <typename T>
void Inventory<T>::removeItem(const T& item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
    }
}

template <typename T>
void Inventory<T>::listItems() const {
    std::cout << "Inventory of " << typeid(T).name() << "s:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.getName() << "\n";
    }
}

#endif
