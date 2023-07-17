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
