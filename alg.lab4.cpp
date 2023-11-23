#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

// Объявление функции customPartition
int customPartition(std::vector<int>& arr, int low, int high);

// Функция для создания динамического массива с заполнением случайными числами в заданном диапазоне
std::vector<int> createRandomArray(int n, int min, int max) {
    std::vector<int> arr;
    arr.reserve(n); // Резервируем память для увеличения производительности
    srand(time(nullptr));

    for (int i = 0; i < n; ++i) {
        arr.push_back(rand() % (max - min + 1) + min);
    }

    return arr;
}

// Функция для проверки массива на упорядоченность
bool isOrdered(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}

// Реализация алгоритма Хоара (быстрой сортировки)
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Разделение и получение индекса опорного элемента
        int pivotIndex = customPartition(arr, low, high);

        // Рекурсивно сортируем две части массива
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Вспомогательная функция для разделения массива
int customPartition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Опорный элемент
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; ++j) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int main() {
    int N;
    std::cout << "Input count of elements: ";
    std::cin >> N;

    // Создаем динамический массив с случайными числами
    std::vector<int> arr = createRandomArray(N, 1, 1000);

    // Замеряем время выполнения сортировки
    clock_t start = clock();
    quickSort(arr, 0, N - 1);
    clock_t end = clock();

    // Выводим время сортировки
    std::cout << "Quick sort: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " sec\n";

    // Проверяем упорядоченность массива
    if (isOrdered(arr)) {
        std::cout << "Array is ordered\n";
    } else {
        std::cout << "Array is not ordered\n";
    }

    return 0;
}

