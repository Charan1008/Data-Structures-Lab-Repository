#include<cstdio>
#include<cstdlib>

class Shape {
public:
    virtual void calculate_area() = 0;
};

class Square : public Shape {
private:
    int *side;
public:
    Square(int s) {
        side = (int*)malloc(sizeof(int));
        *side = s;
    }
    void calculate_area() {
        printf("\tArea of Square: %d\n", (*side) * (*side));
    }
    ~Square() {
        free(side);
    }
};

class Cube : public Shape {
private:
    int *side;
public:
    Cube(int s) {
        side = (int*)malloc(sizeof(int));
        *side = s;
    }
    void calculate_area() {
        printf("\tSurface Area of Cube: %d\n", 6 * (*side) * (*side));
    }
    ~Cube() {
        free(side);
    }
};

class Rectangle : public Shape {
private:
    int *length, *breadth;
public:
    Rectangle(int l, int b) {
        length = (int*)malloc(sizeof(int));
        breadth = (int*)malloc(sizeof(int));
        *length = l;
        *breadth = b;
    }
    void calculate_area() {
        printf("\tArea of Rectangle: %d\n", (*length) * (*breadth));
    }
    ~Rectangle() {
        free(length);
        free(breadth);
    }
};

class Cuboid : public Shape {
private:
    int *length, *breadth, *height;
public:
    Cuboid(int l, int b, int h) {
        length = (int*)malloc(sizeof(int));
        breadth = (int*)malloc(sizeof(int));
        height = (int*)malloc(sizeof(int));
        *length = l;
        *breadth = b;
        *height = h;
    }
    void calculate_area() {
        printf("\tSurface Area of Cuboid: %d\n", 2 * ((*length * *breadth) + (*breadth * *height) + (*height * *length)));
    }
    ~Cuboid() {
        free(length);
        free(breadth);
        free(height);
    }
};

void Display()
{
    printf("\n");
    printf("\t\t\t              MENU                \n");
    printf("\t\t\t----------------------------------\n");
    printf("\t\t\t       Choose Your Choice\n");
    printf("\t\t\t----------------------------------\n");
    printf("\t\t\t1.Area of square \n");
    printf("\t\t\t2.Area of cube \n");
    printf("\t\t\t3.Area of rectangle \n");
    printf("\t\t\t4.Area of cuboid \n");
    printf("\t\t\t5.Exit \n");
    printf("\t\t\t----------------------------------\n");
}

int main()
{
    int choice;
    Display();
    while(1)
    {
        printf("\tEnter your choice: ");
        scanf("%d",&choice);
        if(choice>=1&&choice<=5)
        {
            break;
        }
        else
        {
            printf("INVALID INPUT\n");
            printf("Please enter a number from 1 to 5: \n");
        }
    }
    switch(choice)
    {
        case 1:
            {
                int side;
                printf("\tEnter side length: ");
                scanf("%d", &side);
                Square obj(side);
                obj.calculate_area();
                break;
            }
        case 2:
            {
                int side;
                printf("\tEnter side length: ");
                scanf("%d", &side);
                Cube obj(side);
                obj.calculate_area();
                break;
            }
        case 3:
            {
                int length, breadth;
                printf("\tEnter length and breadth: ");
                scanf("%d %d", &length, &breadth);
                Rectangle obj(length, breadth);
                obj.calculate_area();
                break;
            }
        case 4:
            {
                int length, breadth, height;
                printf("\tEnter length, breadth, and height: ");
                scanf("%d %d %d", &length, &breadth, &height);
                Cuboid obj(length, breadth, height);
                obj.calculate_area();
                break;
            }
        case 5:
            printf("\n\tYou have chosen to exit the code.....\n\n");
            printf("\t\t\t----EXITING THE CODE----\n");
            printf("\t\t\t------CODE EXITED------\n");
            break;
    }
}