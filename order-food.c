#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int orderId;
    char itemName[100];
    float price;
    int quantity;
} Order;

typedef struct {
    int userId;
    char username[100];
    Order orders[10];
    int orderCount;
} User;

// Створення нового користувача з заданим ідентифікатором та ім'ям користувача
User createNewUser(int userId, const char* username) {
    User newUser;
    newUser.userId = userId;
    strcpy(newUser.username, username);
    newUser.orderCount = 0;
    return newUser;
}

// Додавання нового замовлення для користувача
void addOrder(User* user, const char* itemName, float price, int quantity) {
    Order newOrder;
    newOrder.orderId = user->orderCount + 1;
    strcpy(newOrder.itemName, itemName);
    newOrder.price = price;
    newOrder.quantity = quantity;

    user->orders[user->orderCount] = newOrder;
    user->orderCount++;
}

// Виведення історії замовлень користувача
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

typedef struct {
    const char* name;
    float price;
} MenuItem;

// Вибір пункту меню з заданою категорією
void selectMenuItem(const char* category, const MenuItem* items, int itemCount, User* user);

int main() {
    int userId;
    char username[100];
    int choice;
    int quantity;

    printf("Enter User ID: ");
    scanf("%d", &userId);
    getchar(); // Видалення символу нового рядка, залишеного scanf
    printf("Enter Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // // Видалення символу нового рядка з вводу

    User user = createNewUser(userId, username);

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
                selectMenuItem("Main Course", mainCourseItems, sizeof(mainCourseItems) / sizeof(mainCourseItems[0]), &user);
                break;
            case 2:
                selectMenuItem("Salads", saladItems, sizeof(saladItems) / sizeof(saladItems[0]), &user);
                break;
            case 3:
                selectMenuItem("Fast Food", fastFoodItems, sizeof(fastFoodItems) / sizeof(fastFoodItems[0]), &user);
                break;
            case 4:
                selectMenuItem("Appetizers", appetizerItems, sizeof(appetizerItems) / sizeof(appetizerItems[0]), &user);
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

void selectMenuItem(const char* category, const MenuItem* items, int itemCount, User* user) {
    printf("\n%s Items:\n", category);
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }

    int foodIndex;
    printf("Enter item number (or 0 to go back): ");
    scanf("%d", &foodIndex);
    getchar(); // Видалення символу нового рядка, залишеного scanf

    if (foodIndex == 0) {
        printf("Going back to the main menu...\n");
        return;
    }

    foodIndex--;

    if (foodIndex >= 0 && foodIndex < itemCount) {
        printf("Enter quantity: ");
        char quantityInput[10];
        fgets(quantityInput, sizeof(quantityInput), stdin);
        int quantity = atoi(quantityInput);
        addOrder(user, items[foodIndex].name, items[foodIndex].price, quantity);
    } else {
        printf("Invalid item number. Try again.\n");
    }
}
