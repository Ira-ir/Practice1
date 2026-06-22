#include <iostream>
#include <vector>
#include <algorithm>

int sumNegativeBetweenMinMax(const std::vector<int>& arr) {
    if (arr.empty()) return 0;

    // Находим индексы первого максимума и первого минимума
    int idx_max = 0;
    int idx_min = 0;

    for (int i = 1; i < (int)arr.size(); ++i) {
        if (arr[i] > arr[idx_max]) {
            idx_max = i;
        }
        if (arr[i] < arr[idx_min]) {
            idx_min = i;
        }
    }

    // Определяем границы
    int left, right;
    if (idx_max < idx_min) {
        left = idx_max;
        right = idx_min;
    }
    else {
        left = idx_min;
        right = idx_max;
    }

    // Суммируем отрицательные элементы между ними
    int sum = 0;
    for (int i = left + 1; i < right; ++i) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }

    return sum;
}

int main() {
    int N;
    std::cout << "Enter array size N: ";
    std::cin >> N;

    std::vector<int> arr(N);
    std::cout << "Enter " << N << " array elements: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    int result = sumNegativeBetweenMinMax(arr);
    std::cout << "Sum of negative elements between max and min: " << result << std::endl;

    // Чтобы окно не закрывалось сразу
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}