#ifndef LIST_H
#define LIST_H

#include "entity.h"
#include <vector>
#include <fstream>

class List {
private:
    std::vector<Phone> phones;

public:
    void addPhone(const Phone &phone);
    void removePhone(size_t index);
    Phone& getPhone(size_t index);
    void print() const;
    const Phone& findCheapestPhone(float diagonal) const;
    void readFromFile(const std::string& fileName);
    void writeToFile(const std::string& fileName) const;

    // Operator overloading
    Phone& operator[](size_t index);
    const Phone& operator[](size_t index) const;

    friend std::ostream& operator<<(std::ostream& os, const List& list);
    friend std::istream& operator>>(std::istream& is, List& list);
};

#endif // LIST_H
