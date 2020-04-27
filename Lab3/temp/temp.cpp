#include <iostream>
#include "../includes/types/UserTable.h"
#include "../includes/UserFiles.h"

int main(int argc, char const *argv[])
{
    Table tab(1, 1);
    read("../data/data.dat", tab);

    int *arr, size = tab.width;
    arr = new int[size];

    for (int i = 0; i < tab.width; i ++){
        arr[i] = tab.data[0][i];
    }

    for (int i = 0; i < size; i ++){
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';

    std::cout << isSorted(arr, size) << endl;

    return 0;
}

