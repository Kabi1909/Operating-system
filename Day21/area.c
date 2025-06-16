area calculation program
circle => C
triange => T
Square => S
Rectangle =>Rectangle

enter your choice:C

Circle area calculation

enter the radius:20.9
area is :1371.58       



#include <stdio.h>
#include <math.h>

int main() {
    char choice;
    double radius, area;
    double base, height;
    double side;
    double length, width;

    printf("Choose a shape for area calculation:\n");
    printf("C => Circle\nT => Triangle\nS => Square\nR => Rectangle\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'C':
        case 'c':
            printf("Enter the radius: ");
            scanf("%lf", &radius);
            area = M_PI * radius * radius;
            printf("Area of Circle: %.2f\n", area);
            break;
        case 'T':
        case 't':
            printf("Enter the base and height: ");
            scanf("%lf %lf", &base, &height);
            area = 0.5 * base * height;
            printf("Area of Triangle: %.2f\n", area);
            break;
        case 'S':
        case 's':
            printf("Enter the side length: ");
            scanf("%lf", &side);
            area = side * side;
            printf("Area of Square: %.2f\n", area);
            break;
        case 'R':
        case 'r':
            printf("Enter the length and width: ");
            scanf("%lf %lf", &length, &width);
            area = length * width;
            printf("Area of Rectangle: %.2f\n", area);
            break;
        default:
            printf("Invalid choice! Please enter C, T, S, or R.\n");
            break;
    }

    return 0;
}
