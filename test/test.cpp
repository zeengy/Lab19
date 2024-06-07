#include "gtest/gtest.h"
#include "../list.h"
#include "../entity.h"
#include <iostream> 

TEST(PhoneTest, DefaultConstructor) {
    Phone p;
    EXPECT_EQ(p.getModel(), "");
    EXPECT_EQ(p.getPrice(), 0.0);
    EXPECT_EQ(p.getScreen(), 0.0);  
}

TEST(PhoneTest, ParameterizedConstructor) {
    std::cerr << "Test PhoneTest.ParameterizedConstructor passed successfully!" << std::endl; 
    Phone p("ModelX", 999.99, 5.5);
    EXPECT_EQ(p.getModel(), "ModelX");
    EXPECT_EQ(p.getPrice(), 999.99);
    EXPECT_EQ(p.getScreen(), 5.5);
    
}

TEST(ListTest, AddPhone) {
    List list;
    Phone p("ModelX", 999.99, 5.5);
    list.addPhone(p);
    EXPECT_EQ(list.getPhone(0).getModel(), "ModelX");
    std::cerr << "Test ListTest.AddPhone passed successfully!" << std::endl; 
}

TEST(ListTest, RemovePhone) {
    List list;
    Phone p("ModelX", 999.99, 5.5);
    list.addPhone(p);
    list.removePhone(0);
    EXPECT_THROW(list.getPhone(0), std::out_of_range);
    std::cerr << "Test ListTest.RemovePhone passed successfully!" << std::endl; 
}

TEST(ListTest, FindCheapestPhone) {
    List list;
    Phone p1("ModelX", 999.99, 5.5);
    Phone p2("ModelY", 499.99, 5.5);
    list.addPhone(p1);
    list.addPhone(p2); 
    EXPECT_EQ(list.findCheapestPhone(5.5).getModel(), "ModelY"); 
    std::cerr << "Test ListTest.FindCheapestPhone passed successfully!" << std::endl; 
}
