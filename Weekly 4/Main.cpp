#include <iostream>
#include <conio.h>


void clearCin();
void task1();
void task2();
void task3();
void task4();

float Calculate(float n1, float n2, char operation) {

    switch (operation) {
    case 'a':
        return n1 + n2;
        break;
    case 's':
        return n1 - n2;
        break;
    case 'm':
        return n1 * n2;
        break;
    case 'd':
        return n1 / n2;
        break;
    default:
        std::cout << "Invalid input.\n";
        clearCin();
        break;
    }

}

void clearCin()
{
    std::cin.clear();
    std::cin.ignore(32767, '\n');
}

int main()
{
    char input{};

    std::cout << "What do you want to access?\n"
        << "a: Task 1 (Calculator)\n"
        << "b: Task 2 (Board game)\n"
        << "c: Task 3 (Phone number catalouge)\n"
        << "d: Task 4 (Dice task)\n"
        << "Your choice : ";

    std::cin >> input;

    switch (input)
    {
    case 'a':
        task1();
        break;
    case 'b':
        task2();
        break;
    case 'c':
        task3();
        break;
    case 'd':
        task4();
        break;
    default:
        std::cout << "Invalid input\n";
        clearCin();
        break;
    }
}


void task1() {
    std::cout << std::endl;
    char operation{};
    float n1{};
    float n2{}
    ;
    std::cout << "CALCULATOR\n"
        << "Press a to choose addition, s to choose subtraction,\n"
        << "m for multiplication, or d for division : ";
    
    std::cin >> operation;
    
    std::cout << "Now enter two numbers to perform the selected operation on.\n"
        << "One : ";
    std::cin >> n1;
    std::cout << "Two : ";
    std::cin >> n2;
    std::cout << "The result is " << Calculate(n1, n2, operation);
}

void task2()
{
    const int row = 10;
    const int col = 10;

    int x = 1;
    int y = 1;

    int level = 1;

    char table[row][col] = {};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            table[i][j] = ' ';
        }
    }

    table[9][0] = '/';
    table[9][9] = '\\';
    table[4][4] = 'G';

    do {
        if (table[x][y] == 'G') {
            exit(0);
        }
        else if (table[x][y] == '\\') {
            x = 0;
            y = 0;
            level = level + 1;
        }
        else if (table[x][y] == '/') {
            x = 0;
            y = 0;
            level = level - 1;
        }

        std::cout << "Press WASD to move\n"
            << "You are at level " << level << "\n";

        table[x][y] = '*';

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                std::cout << "|" << table[i][j];
            }
            std::cout << "|";
            std::cout << std::endl;
        }

        char input = _getch();



        switch (input) {
        case 'w':
            table[x][y] = ' ';
            x = x - 1;
            break;
        case 'a':
            table[x][y] = ' ';
            y = y - 1;
            break;
        case 's':
            table[x][y] = ' ';
            x = x + 1;
            break;
        case 'd':
            table[x][y] = ' ';
            y = y + 1;
            break;
        default:
            break;
        }

        system("cls");

    } while (true);

}

void task3()
{
    struct People {
        std::string name{};
        long phone{};
    };

    int amount{};

    std::string names[10] = {};
    long phonenumbers[10] = {};

    std::cout << "How many people would you like to input info for? (max 10) : ";
    std::cin >> amount;

    for (int i = 0; i < amount; i++) {
        std::cout << "The name of person " << amount << " is : ";
        std::cin >> names[i];
        std::cout << "The phone number of person " << amount << " is : ";
        std::cin >> phonenumbers[i];
    }

    for (int j = 0; j < amount; j++) {
        People joe = { names[j], phonenumbers[j] };
    }

    
}

void task4()
{

}

