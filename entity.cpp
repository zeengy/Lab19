#include "entity.h"

Phone::Phone() : model(""), price(0.0), screen(0.0) {
    std::cout << "Default constructor called\n";
}

Phone::Phone(const std::string &model, float price, float screen) 
    : model(model), price(price), screen(screen) {
    std::cout << "Parameterized constructor called\n";
}

Phone::Phone(const Phone &other) 
    : model(other.model), price(other.price), screen(other.screen) {
    std::cout << "Copy constructor called\n";
}

Phone::~Phone() {
    std::cout << "Destructor called\n";
}

std::string Phone::getModel() const {
    return model;
}

void Phone::setModel(const std::string &model) {
    this->model = model;
}

float Phone::getPrice() const {
    return price;
}

void Phone::setPrice(float price) {
    this->price = price;
}

float Phone::getScreen() const {
    return screen;
}

void Phone::setScreen(float screen) {
    this->screen = screen;
}

std::string Phone::toString() const {
    std::stringstream ss;
    ss << "Model: " << model << ", Price: " << price << ", Screen: " << screen << "\n";
    return ss.str();
}

void Phone::fromString(const std::string &str) {
    std::stringstream ss(str);
    std::string tmp;
    ss >> tmp >> model >> tmp >> price >> tmp >> screen;
}

// Operator overloading
Phone& Phone::operator=(const Phone& other) {
    if (this != &other) {
        model = other.model;
        price = other.price;
        screen = other.screen;
    }
    return *this;
}

bool Phone::operator==(const Phone& other) const {
    return (model == other.model && price == other.price && screen == other.screen);
}

bool Phone::operator!=(const Phone& other) const {
    return !(*this == other);
}

bool Phone::operator<(const Phone& other) const {
    return price < other.price;
}

bool Phone::operator>=(const Phone& other) const {
    return !(*this < other);
}

bool Phone::operator>(const Phone& other) const {
    return price > other.price;
}

bool Phone::operator<=(const Phone& other) const {
    return !(*this > other);
}

std::ostream& operator<<(std::ostream& os, const Phone& phone) {
    os << phone.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Phone& phone) {
    std::string input;
    std::getline(is, input);
    phone.fromString(input);
    return is;
}
