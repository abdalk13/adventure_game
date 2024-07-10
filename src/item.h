// item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name, const std::string& description, double weight);

    std::string getName() const; 
    std::string getDescription() const;
    double getWeight() const;

    bool operator==(const Item& other) const;

private:
    std::string name;
    std::string description;
    double weight;
};

#endif 
