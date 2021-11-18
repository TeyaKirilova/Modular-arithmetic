#include <iostream>
#include "functions.h"
#include <string>
#pragma execution_character_set( "utf-8" )

//Функция за проверка дали числото е по-голямо или равно на нула
//използва се във всяка друга функция
int input_natural_number() {
    //std::cout << "Въведете число. " << std::endl;
    int input;
    while (true) {
        std::cin >> input;
        if (input >= 0) return input;
        std::cout << "Числото трябва да е положително!" << std::endl;
    }
}


//Функция за проверка дали числото влиза в остатъчния пръстен
int input_natural_number_less_than(int limit) {

    int number;
    while (true) {
        std::cin >> number;
        if (number >= 0 && number < limit) return number;
        std::cout << "Числото трябва да е по-голямо или равно на нула и по-малко от " << limit << std::endl;
    }
}


// Да се дефинира С++ функция, която запълва масив с елементите на остатъчния пръстен Zn.
//arr - съхранява типа, който се подава в началото
// for (начална стойност; до кога да се върти; операцията, с която се върти, как да се птомени следващата стойност) 
int* populate_ring() {
    std::cout << "Въведете модул. " << std::endl;
    int n = input_natural_number();
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cout << i << " ";
        arr[i] = i;
    }
    std::cout << std::endl;
    return arr;
}


//Да се дефинира С++ функция, която изпълнява операция събиране на елементи от остатъчния пръстен Zn. 
// цикълът - ако не е валиден импута да повтори
// % - модул, осатук от целочислено деление
int add_elements() {
    std::cout << "Въведете модул. " << std::endl;
    int num = input_natural_number();
   
    std::cout << "Въведете първото число от сбора. " << std::endl;
    int first = input_natural_number_less_than(num);
    std::cout << "Въведете второто число от сбора. " << std::endl;
    int second = input_natural_number_less_than(num);

    std::cout <<"Сборът е: "<< (first + second) % num << std::endl;
    return 0;
}


// Да се дефинира С++ функция, която изпълнява операция изваждане на елементи от остатъчния пръстен Zn.
//рекурсивна функция
int subtract_numbers() {
    std::cout << "Въведете модул. " << std::endl;
    int limit = input_natural_number();
    int first, second;
    int sub;

    std::string error_message = "Числото трябва да е между 0 и " + std::to_string(limit);
    std::cout << "Въведете първото число от разликата! " << std::endl;
    first = input_natural_number_less_than(limit);
    std::cout << "Въведете второто число от разликата! " << std::endl;
    second = input_natural_number_less_than(limit);

    sub = first - second;
    if (sub < 0) {
        sub += limit;
    }
    else sub %= limit;

    std::cout << "Разликата е:" << sub << std::endl;

    return 0;
}


// Да се дефинира С++ функция, която изпълнява операция умножение на елементи от остатъчния пръстен Zn.
int multiply_numbers() {
    std::cout << "Въведете модул. " << std::endl;
    int num = input_natural_number();
    int first, second;
    std::cout << "Въведете първото число, което да бъде умножено. " << std::endl;
    first = input_natural_number_less_than(num);
    std::cout << "Въведете второто число, което да бъде умножено. " << std::endl;
    second = input_natural_number_less_than(num);

    std::cout<< "Произведението е: " << (first * second) % num << std::endl;

    return 0;
}


// matrix - двумерен масив
//ако j e реципрочно на i
// функция за размера на матрицата
int calculate_reciprocal_matrix_size(int num) {
    int matrix_size = 0;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if ((i * j) % num == 1) matrix_size++;
        }
    }
    return matrix_size;
}


//функция за запърване на матрицата
int fill_reciprocals_matrix(int num, int* matrix[2], int row_size) {
    matrix[0] = new int[row_size];
    matrix[1] = new int[row_size];

    int count = 0;
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            if ((i * j) % num == 1) {
                matrix[0][count] = i;
                matrix[1][count] = j;
                count++;
            }
        }
    }
    return 0;
}


// Да се дефинира С++ функция, която намира двойките реципрочни елементи в Zn. Намерените елементи да се запишат в двумерен масив.
int print_reciprocals_matrix() {
    std::cout << "Въведете число. " << std::endl;
    int num = input_natural_number();
    int* matrix[2];
    int row_size = calculate_reciprocal_matrix_size(num);
    fill_reciprocals_matrix(num, matrix, row_size);

    //row - ред
    for (int j = 0; j < row_size; j++) {
        std::cout << "(" << matrix[0][j] << ", " << matrix[1][j] << ")" << std::endl;;
    }

    std::cout << std::endl;

    return 0;
}


// Да се дефинира С++ функция, която намира реципрочен (обратен) на зададен от потребителя елемент от множеството Zn, 
//ако такъв съществува. Използвайте образувания двумерен масив в горния пример.
int print_recirocal() {
    std::cout << "Въведете модул. " << std::endl;
    int num = input_natural_number();
    int size = calculate_reciprocal_matrix_size(num);
    std::cout << "Въведете число. " << std::endl;
    int** matrix = new int*[2];
    fill_reciprocals_matrix(num, matrix, size);

    int target = input_natural_number_less_than(num);



    for (int i = 0; i < size; ++i) {
        if (matrix[0][i] == target) {
            int reciprocal = matrix[1][i];
            std::cout << "Реципрочното на " << target << " е " << reciprocal << std::endl;
            return 0;
        }
    }

    std::cout << "Реципрочното на " << target << " не е намерено" << std::endl;
    return 0;
}


// Да се дефинира С++ функция, която изпълнява операция деление на елементи от остатъчния пръстен Zn и връща резултат 1, ако не е допустимо.
int divide_numbers() {
    std::cout << "Въведете модул. " << std::endl;
    int num = input_natural_number();
    int* Matrix = new int[num];
    for (int i = 0; i < num; i++) {
        Matrix[i] = 1;
    }

    for (int i = 1; i < num; i++) {
        for (int j = 1; j < num; j++) {
            if ((i * j) % num == 1) Matrix[i] = j;
        }
    }

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            std::cout << i << " / " << j << " = ";
            if (Matrix[j] == -1)std::cout << "-1" << std::endl;
            else std::cout << ((i * Matrix[j]) % num) << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}


//Да се дефинира С++ функция, която извършва бързо степенуване на база на въведени остатъчен пръстен,
//основа и степен от потребителя, използвайки първия подход.
int fast_power_of_numbers_first() {
    std::cout << "Въведете модул. " << std::endl;
    int num = input_natural_number();
    int first, second, third = 1;
    int previous;
    std::cout << "Въведете първото число, което да бъде използвано за бързото степенуване. " << std::endl;
    //std::cout << "Въведете първото число: ";
    std::cin >> first;
    std::cout << "Въведете второто число, което да бъде използвано за бързото степенуване. " << std::endl;
   // std::cout << "Въведете второто число:  ";
    std::cin >> second;
    previous = first;

    while (true) {
        if (previous % num == 1)break;
        third++;
        previous *= first;
    }

    int mod = second % third;
    previous = first;

    for (int i = 0; i < mod - 1; i++)
        previous *= first;
    std::cout << first << " ^ " << second << " = " << previous % num << std::endl;
    std::cout << std::endl;
    return 0;
}


//Да се дефинира С++ функция, която проверява дали дадено число е примитивен корен в Zn.
int positive_root_check() {
    int num, x;

    while (true) {
        std::cout << "Въведете модул. " << std::endl;
        num = input_natural_number();
        if (num >= 0 && ifnIsPrime(num) == 1) break;
        std::cout << "Невалидно!" << std::endl;
    }
    std::cout << "Въведете число. " << std::endl;
    x = input_natural_number_less_than(num);

    int* roots = get_primitive_roots(num);
    std::cout << std::endl;
    if (roots[x - 1])
        std::cout << x << " е примитивен корен." << std::endl;
    else
        std::cout << x << " не е примктивен корен." << std::endl;
    std::cout << std::endl;
    return 0;
}


// Да се дефинира С++ функция, която намира всички примитивни корени в Zn.
//find_primitive_roots
int find_primitive_roots() {
    std::cout << "Въведете модул: " << std::endl;
    int num = input_natural_number();
    int* roots = get_primitive_roots(num);
    std::cout << "Примитивните корени са:" << std::endl;

    for (int i = 0; i < num - 1; ++i)
        if (roots[i] == 1)
            std::cout << i + 1 << " ";
    std::cout << std::endl;
    return 0;
}


// Да се дефинира С++ функция, която проверява дали даден остатъчен пръстен е остатъчно поле.
int ring_is_a_field() {
    std::cout << "Въведете число. " << std::endl;
    int num = input_natural_number();
    if (ifnIsPrime(num)) {
        std::cout << "Остатъчно поле е!" << std::endl;
    }
    else {
        std::cout << "Не е остатъчно поле!" << std::endl;
    }
    return 0;
}

//проверява дали дадено число е примитивен корен
//връща масив от интове 
// int i = 12;
// int j = i++; int k = ++i; j = 12, k = 13
// и++ - инкрементира се след блока първо for(int i = 0; i <20 ; ++i) 
// ++и - инкрементира се преди блока
int* get_primitive_roots(int num) {
    int jj;
    if (num == 1 || ifnIsPrime(num) == 0) {
        std::cout << "Няма примитивни корени!" << std::endl;
        return NULL;
    }

    int* roots = new int[num - 1];
    int** M = new int* [num - 1];
    for (int i = 0; i < num - 1; ++i)
        M[i] = new int[num - 1];

    for (int i = 1; i < num; ++i) {
        jj = i;
        for (int j = 0; j < num - 1; ++j) {
            M[i - 1][j] = jj % num;
            jj *= i;
        }
    }
    
    show(M, num - 1, num - 1);
    roots = IDarr(M, num - 1, num - 1);

    for (int i = 0; i < num - 1; ++i) {
        delete[] M[i];
    }
    delete[] M;
    return roots;
}

int show(int** M, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            std::cout << M[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}

int* IDarr(int** M, int rows, int cols) {
    int ifid = 0;
    int* id = new int[rows];
    for (int i = 0; i < rows; ++i) {
        id[i] = 1;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int second;
            for (second = 0; second < j; second++) {
                if (M[i][j] == M[i][second]) {
                    id[i] = 0;
                    ifid = 1;
                    break;
                }
            }
            if (ifid == 1) {
                ifid = 0;
                break;
            }
        }
    }
    return id;
}


//проверява дали числото е просто - решето на Eратостен
//връща 1 ако е просто и 0 ако не е 
int ifnIsPrime(int num)
{
    if (num == 0) return 0;
    int i;
    bool isPrime = true;

    for (i = 2; i <= num / 2; ++i)
    {
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        return 1;

    return 0;
}