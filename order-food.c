#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура, що представляє інформацію про замовлення
typedef struct {
    int orderId;
    char itemName[100];
    float price;
    int quantity;
} Order;

// Структура, що представляє інформацію про користувача
typedef struct {
    int userId;
    char username[100];
    Order orders[10];
    int orderCount;
} User;

// Функція для створення нового користувача
User createNewUser(int userId, const char* username) {
    User newUser;
    newUser.userId = userId;
    strcpy(newUser.username, username);
    newUser.orderCount = 0;
    return newUser;
}