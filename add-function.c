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
