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

// Функція для додавання замовлення для користувача
void addOrder(User* user, const char* itemName, float price, int quantity) {
    Order newOrder;
    newOrder.orderId = user->orderCount + 1;
    strcpy(newOrder.itemName, itemName);
    newOrder.price = price;
    newOrder.quantity = quantity;

    user->orders[user->orderCount] = newOrder;
    user->orderCount++;
}

// Функція для відображення історії замовлень користувача та розрахунку сумарної ціни
void displayOrderHistory(const User* user) {
    printf("Order History for User: %s\n", user->username);

    if (user->orderCount == 0) {
        printf("No orders found.\n");
        return;
    }

    float totalCost = 0.0;

    for (int i = 0; i < user->orderCount; i++) {
        Order order = user->orders[i];
        printf("Order ID: %d\n", order.orderId);
        printf("Item: %s\n", order.itemName);
        printf("Price per unit: $%.2f\n", order.price);
        printf("Quantity: %d\n", order.quantity);
        printf("---------------\n");

        totalCost += order.price * order.quantity;
    }

    printf("Total Cost: $%.2f\n", totalCost);
}

int main() {
    int userId;
    char username[100];
    int choice;
    int foodIndex;
    int quantity;

    printf("Enter User ID: ");
    scanf("%d", &userId);
    printf("Enter Username: ");
    scanf("%s", username);

    User user = createNewUser(userId, username);

    typedef struct {
        const char* name;
        float price;
    } MenuItem;

    const MenuItem mainCourseItems[] = {
        {"Steak", 15.99},
        {"Chicken", 10.99},
        {"Pasta", 8.99},
        {"Fish", 12.99},
        {"Pizza", 9.99}
    };

    const MenuItem saladItems[] = {
        {"Caesar Salad", 6.99},
        {"Greek Salad", 7.99},
        {"Cobb Salad", 8.99},
        {"Caprese Salad", 6.99},
        {"Waldorf Salad", 7.99}
    };

    const MenuItem fastFoodItems[] = {
        {"Burger", 5.99},
        {"Hot Dog", 3.99},
        {"French Fries", 2.99},
        {"Chicken Nuggets", 4.99},
        {"Taco", 4.99}
    };

    const MenuItem appetizerItems[] = {
        {"Bruschetta", 4.99},
        {"Chicken Wings", 7.99},
        {"Mozzarella Sticks", 6.99},
        {"Spinach Dip", 5.99},
        {"Nachos", 6.99}
    };

    do {
        printf("\nFood Categories:\n");
        printf("1. Main Course\n");
        printf("2. Salads\n");
        printf("3. Fast Food\n");
        printf("4. Appetizers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		
		switch (choice) {
            case 1:
                printf("\nMain Course Items:\n");
                for (int i = 0; i < sizeof(mainCourseItems) / sizeof(mainCourseItems[0]); i++) {
                    printf("%d. %s - $%.2f\n", i + 1, mainCourseItems[i].name, mainCourseItems[i].price);
                }
                printf("Enter item number: ");
                scanf("%d", &foodIndex);
                foodIndex--;  // Зменшення на 1 для відповідності індексу масиву
                if (foodIndex >= 0 && foodIndex < sizeof(mainCourseItems) / sizeof(mainCourseItems[0])) {
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    addOrder(&user, mainCourseItems[foodIndex].name, mainCourseItems[foodIndex].price, quantity);
                } else {
                    printf("Invalid item number. Try again.\n");
                }
                break;
            case 2:
                printf("\nSalad Items:\n");
                for (int i = 0; i < sizeof(saladItems) / sizeof(saladItems[0]); i++) {
                    printf("%d. %s - $%.2f\n", i + 1, saladItems[i].name, saladItems[i].price);
                }
                printf("Enter item number: ");
                scanf("%d", &foodIndex);
                foodIndex--;  // Зменшення на 1 для відповідності індексу масиву
                if (foodIndex >= 0 && foodIndex < sizeof(saladItems) / sizeof(saladItems[0])) {
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    addOrder(&user, saladItems[foodIndex].name, saladItems[foodIndex].price, quantity);
                } else {
                    printf("Invalid item number. Try again.\n");
                }
                break;
            case 3:
                printf("\nFast Food Items:\n");
                for (int i = 0; i < sizeof(fastFoodItems) / sizeof(fastFoodItems[0]); i++) {
                    printf("%d. %s - $%.2f\n", i + 1, fastFoodItems[i].name, fastFoodItems[i].price);
                }
                printf("Enter item number: ");
                scanf("%d", &foodIndex);
                foodIndex--;  // Зменшення на 1 для відповідності індексу масиву
                if (foodIndex >= 0 && foodIndex < sizeof(fastFoodItems) / sizeof(fastFoodItems[0])) {
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    addOrder(&user, fastFoodItems[foodIndex].name, fastFoodItems[foodIndex].price, quantity);
                } else {
                    printf("Invalid item number. Try again.\n");
                }
                break;
            case 4:
                printf("\nAppetizer Items:\n");
                for (int i = 0; i < sizeof(appetizerItems) / sizeof(appetizerItems[0]); i++) {
                    printf("%d. %s - $%.2f\n", i + 1, appetizerItems[i].name, appetizerItems[i].price);
                }
                printf("Enter item number: ");
                scanf("%d", &foodIndex);
                foodIndex--;  // Зменшення на 1 для відповідності індексу масиву
                if (foodIndex >= 0 && foodIndex < sizeof(appetizerItems) / sizeof(appetizerItems[0])) {
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    addOrder(&user, appetizerItems[foodIndex].name, appetizerItems[foodIndex].price, quantity);
                } else {
                    printf("Invalid item number. Try again.\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);

    displayOrderHistory(&user);

    return 0;
}
