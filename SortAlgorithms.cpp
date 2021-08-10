#include <iostream>
#include <assert.h>
#include <vector>

template<typename T>
auto selectionSort(std::vector<T>& elements) -> void
{
    for (int i = 0; i < elements.size(); ++i) {
        int max_elm_idx = i; 
        for (int j = i; j < elements.size(); ++j) {
            if (elements[j] < elements[max_elm_idx]) {
                max_elm_idx = j; 
            }
        }
        std::swap(elements[i], elements[max_elm_idx]); 
    }
}

template<typename T>
auto bubbleSort(std::vector<T>& elements) -> void
{
    for (int i = elements.size() - 1; i > 0; --i) {
        int swaps = 0; 
        for (int j = 0; j < i; ++j) {
            if (elements[j] > elements[j+1]) {
                int tmp = elements[j]; 
                std::swap(elements[j], elements[j+1]);
                ++swaps;
            }
        }
        if (swaps == 0) {
            break;
        }
    }
}

template<typename T>
auto insertionSort(std::vector<T>& elements) -> void 
{
    for (int i = 0; i < elements.size(); ++i) {
        for (int j = i; j >= 1 ; --j) {
            if (elements[j] < elements[j-1]) {
                std::swap(elements[j], elements[j-1]);
            } else {
                break;
            }
        }
    }
}

int main() {
    auto v = std::vector<int>({4, 3, 2, 5, 8});
    insertionSort(v); 
    for (auto e : v) {
        std::cout << e << "\n"; 
    }
    assert(std::vector<int>({2, 3, 4, 5, 8}) == v);
    v = std::vector<int>({}); 
    assert(std::vector<int>{} == v); 
    v = std::vector<int>({1}); 
    assert(std::vector<int>{1} == v); 
}