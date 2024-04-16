#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

double parse_double(char*);
int parse_int(char*);

// Structure to represent each city
typedef struct {
    int x, y; // Coordinates
    double price; // Initial price for the blimp
    bool visited; // Flag to check if the city has been visited
} City;

// Function prototypes
double distance(int x1, int y1, int x2, int y2);
double calculateProfit(double c, double price, double distance, double d, int salesCount);
int selectNextCity(City *cities, int cities_rows, double c, double d, int *salesCount);

// Main function to solve the TBS problem
void tbsp(double c, double d, int cities_rows, int cities_columns, int** cities_data) {
    City cities[cities_rows];
    int salesCount = 0;
    double totalProfit = 0;

    // Initialize cities
    for (int i = 0; i < cities_rows; i++) {
        cities[i].x = cities_data[i][0];
        cities[i].y = cities_data[i][1];
        cities[i].price = cities_data[i][2];
        cities[i].visited = false;
    }

    int currentCity = -1; // Start from the headquarters
    while ((currentCity = selectNextCity(cities, cities_rows, c, d, &salesCount)) != -1) {
        // Visit the city
        cities[currentCity].visited = true;
        double dist = distance(0, 0, cities[currentCity].x, cities[currentCity].y);
        double profit = calculateProfit(c, cities[currentCity].price, dist, d, salesCount);
        totalProfit += profit;
        printf("%d %d\n", cities[currentCity].x, cities[currentCity].y);
        salesCount++;
    }

    //printf("Total profit: %.2f\n", totalProfit);
}

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the profit from selling a blimp in a city
double calculateProfit(double c, double price, double dist, double d, int salesCount) {
    double travelCost = dist * c;
    double sellingPrice = price * pow(d, salesCount);
    return sellingPrice - travelCost;
}

// Function to select the next city to visit based on maximum profit
int selectNextCity(City *cities, int cities_rows, double c, double d, int *salesCount) {
    int selectedCity = -1;
    double maxProfit = -1;

    for (int i = 0; i < cities_rows; i++) {
        if (!cities[i].visited) {
            double dist = distance(0, 0, cities[i].x, cities[i].y);
            double profit = calculateProfit(c, cities[i].price, dist, d, *salesCount);
            if (profit > maxProfit) {
                maxProfit = profit;
                selectedCity = i;
            }
        }
    }

    return selectedCity;
}


char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

double parse_double(char* str) {
    char* endptr;
    double value = strtod(str, &endptr);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

int main()
{
    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    double c = parse_double(*(first_multiple_input + 1));

    double d = parse_double(*(first_multiple_input + 2));

    int** cities = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        *(cities + i) = malloc(3 * (sizeof(int)));

        char** cities_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            int cities_item = parse_int(*(cities_item_temp + j));

            *(*(cities + i) + j) = cities_item;
        }
    }

    tbsp(c, d, n, 3, cities);

    return 0;
}
