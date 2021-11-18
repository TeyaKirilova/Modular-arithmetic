#include <iostream>
#include "functions.h"
#include <windows.h>
#pragma execution_character_set( "utf-8" )

//using namespace std;

int main() {
    SetConsoleOutputCP(65001);

	int menuSelect;
    while (true) {
        std::cout << std::endl << std::endl << std::endl << std::endl;
        
        std::cout << "Въведете число от 1 до 14, за да изберете задача. :)" << std::endl
            << std::endl
            << "1. Маасив от елементите на остатъчния пръстен." << std::endl
            << "2. Събиране на елементи от остатъчния пръстен." << std::endl
            << "3. Изваждане на елементи от остатъчния пръстен." << std::endl
            << "4. Умножаване на елементи от остатъчния пръстен." << std::endl
            << "5. Намиране на двойките реципрочни елементи." << std::endl
            << "6. Намиране на реципрочния елемент ако такъв съществува." << std::endl
            << "8. Делене на елементи от остатъчния пръстен." << std::endl
            << "9. Бързо степенуване." << std::endl
            << "11. Проверка дали дадено число е примитивен корен." << std::endl
            << "12. Намиране на всички примитивни корени. " << std::endl
            << "14. Проверка дали даден остатъчен пръстен е остатъчно поле." << std::endl
            << std::endl

            << "Изберете 0, за да излезете." << std::endl;
        std::cin >> menuSelect;

        switch (menuSelect) {
        case 0:; return 0;
        case 1: populate_ring(); break;
        case 2: add_elements(); break;
        case 3: subtract_numbers(); break;
        case 4: multiply_numbers(); break;
        case 5: print_reciprocals_matrix(); break;
        case 6: print_recirocal(); break;
        case 8: divide_numbers(); break;
        case 9: fast_power_of_numbers_first(); break;
        case 11: positive_root_check(); break;
        case 12: find_primitive_roots(); break;
        case 14: ring_is_a_field(); break;
        default:std::cout << "Моля избери число от 1 до 14!" << std::endl; break;
        }
    }
	return 0;
}
