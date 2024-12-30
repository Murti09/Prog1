#include <iostream>
#include <conio.h>

#define STANDARTGROESSE 3

class NumberBox {
    private:
        int capacity;
        double* storedNumbers;
        unsigned int n = 0;

    public:
        NumberBox(int capacity) {
            std::cout << "Constructor of class NumberBox was called" << std::endl;
            printf("I created a number box which can store up to %d numbers.\n\n", capacity);
            storedNumbers = new double[capacity];
            this->capacity = capacity;
        }
        NumberBox() {
            std::cout << "Constructor of class NumberBox was called" << std::endl;
            printf("I created a number box which can store up to %d numbers.\n\n", STANDARTGROESSE);
            storedNumbers = new double[STANDARTGROESSE];
            this->capacity = STANDARTGROESSE;
        }
        void add_a_number(double number) {
            if (n < capacity) {
                storedNumbers[n] = number;
                printf("added number %.1f to your number box\n", storedNumbers[n]);
                n++;
            }
            else {
                printf("Sorry! Cannot add another number to your box! The box is full!\n");
            }
        }
        void show_all_numbers_in_box() {
            std::cout << "Numbers currently in the box: "; 
            for (int i = 0; i < n; i++) {
                //std::cout << storedNumbers[i] << " ";
                printf("%.1f ", storedNumbers[i]);
            }
            std::cout << std::endl << std::endl;
        }
        void get_min_max(double* min, double* max) {
            *min = storedNumbers[0], *max = storedNumbers[0];
            for (int i = 0; i < n; i++) {
                if (storedNumbers[i] < *min) {
                    *min = storedNumbers[i];
                }   
                if (storedNumbers[i] > *max) {
                    *max = storedNumbers[i];
                }
            }
        }
        double get_arithmetic_mean() {
            double sum = 0;
            for (int i = 0; i < n; i++) {
                sum += storedNumbers[i];
            }
            return sum / n;
        }
        ~NumberBox() {
            delete[] storedNumbers;
            storedNumbers = nullptr;
            std::cout << "Destruktor wurde aufgerufen" << std::endl;
        }
};

int main() {
    NumberBox myBox(10);

    myBox.add_a_number(1.0);
    myBox.add_a_number(4.0);
    myBox.add_a_number(7.0);
    myBox.show_all_numbers_in_box();

    myBox.add_a_number(11.0);
    myBox.add_a_number(44.0);
    myBox.add_a_number(77.0);
    myBox.show_all_numbers_in_box();
        

    double minval, maxval;
    myBox.get_min_max(&minval,&maxval);
    printf("Minimum value of all numbers in box is: %.1f\n", minval);
    printf("Maximum value of all numbers in box is: %.1f\n", maxval);

    printf("Arithmetic mean of all numbers in box is: %.1f\n", myBox.get_arithmetic_mean());
    

    myBox.add_a_number(100.0);
    myBox.add_a_number(200.0);
    myBox.add_a_number(300.0);
    myBox.add_a_number(400.0);
    myBox.add_a_number(500.0);
    myBox.add_a_number(600.0);

    _getch();
}