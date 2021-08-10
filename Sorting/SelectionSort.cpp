#include <iostream>
#include <assert.h>
#include <vector>

template<typename T>
auto selectionSort(std::vector<T>& elements) -> void
{
    for (int i = 0; i < elements.size(); ++i) {
        int max_elm_val = elements[i]; 
        int max_elm_idx = i; 
        for (int j = i; j < elements.size(); ++j) {
            if (elements[j] < max_elm_val) {
                max_elm_val = elements[j]; 
                max_elm_idx = j; 
            }
        }
        int tmp = elements[i]; 
        elements[i] = elements[max_elm_idx]; 
        elements[max_elm_idx] = tmp; 
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
                elements[j] = elements[j+1]; 
                elements[j+1] = tmp; 
                ++swaps;
            }
        }
        if (swaps == 0) {
            break;
        }
    }
}

int main() {
    auto v = std::vector<int>({4, 3, 2, 5, 8});
    bubbleSort(v); 
    for (auto e : v) {
        std::cout << e << "\n"; 
    }
    assert(std::vector<int>({2, 3, 4, 5, 8}) == v);
}