// item.cpp
#include "item.h"

Item::Item(const std::string& name, const std::string& description, double weight)
    : name(name), description(description), weight(weight) {}

std::string Item::getName() const {
    return name;
}

std::string Item::getDescription() const {
    return description;
}

double Item::getWeight() const {
    return weight;
}

bool Item::operator==(const Item& other) const {
    return name == other.name; 
}
