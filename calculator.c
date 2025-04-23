#include <stdio.h>
#include <math.h>

// Function Prototypes
float area_circle(float radius);
float circumference_circle(float radius);
float area_rectangle(float length, float width);
float perimeter_rectangle(float length, float width);
float area_triangle(float a, float b, float c);
float perimeter_triangle(float a, float b, float c);
int is_valid_triangle(float a, float b, float c);

int main() {
    int choice;
    float r, l, w, a, b, c;

    do {
        printf("\n===== Shape Calculator =====\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter radius of the circle: ");
                scanf("%f", &r);
                if (r <= 0) {
                    printf("Invalid radius. Please enter a positive number.\n");
                } else {
                    printf("Area of Circle = %.2f\n", area_circle(r));
                    printf("Circumference of Circle = %.2f\n", circumference_circle(r));
                }
                break;

            case 2:
                printf("Enter length and width of the rectangle: ");
                scanf("%f %f", &l, &w);
                if (l <= 0 || w <= 0) {
                    printf("Invalid dimensions. Length and width must be positive.\n");
                } else {
                    printf("Area of Rectangle = %.2f\n", area_rectangle(l, w));
                    printf("Perimeter of Rectangle = %.2f\n", perimeter_rectangle(l, w));
                }
                break;

            case 3:
                printf("Enter the three sides of the triangle: ");
                scanf("%f %f %f", &a, &b, &c);
                if (!is_valid_triangle(a, b, c)) {
                    printf("Invalid triangle sides. The sum of any two sides must be greater than the third.\n");
                } else {
                    printf("Area of Triangle = %.2f\n", area_triangle(a, b, c));
                    printf("Perimeter of Triangle = %.2f\n", perimeter_triangle(a, b, c));
                }
                break;

            case 0:
                printf("Exiting program. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please select from the menu.\n");
        }
    } while (choice != 0);

    return 0;
}
#define M_PI 3.14159265358979323846

// Circle functions
float area_circle(float radius) {
    return M_PI * radius * radius;
}

float circumference_circle(float radius) {
    return 2 * M_PI * radius;
}

// Rectangle functions
float area_rectangle(float length, float width) {
    return length * width;
}

float perimeter_rectangle(float length, float width) {
    return 2 * (length + width);
}

// Triangle functions
float area_triangle(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
}

float perimeter_triangle(float a, float b, float c) {
    return a + b + c;
}

int is_valid_triangle(float a, float b, float c) {
    return (a + b > c && b + c > a && a + c > b);
}
