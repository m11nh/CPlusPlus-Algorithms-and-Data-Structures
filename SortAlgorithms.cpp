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

template<typename T>
auto merge(std::vector<T>& elements, int lo1, int hi1, int lo2, int hi2) 
{
    int lo = lo1; 
    auto mergedResult = std::vector<T>(); 
    while ((lo1 <= hi1) || (lo2 <= hi2)) {
        if ((lo1 <= hi1) && (lo2 <= hi2)) {
            if (elements[lo1] <= elements[lo2]) {
                mergedResult.push_back(elements[lo1++]); 
            } else {
                mergedResult.push_back(elements[lo2++]); 
            }
        } else if((lo1 <= hi1)) {
            mergedResult.push_back(elements[lo1++]); 
        } else {
            mergedResult.push_back(elements[lo2++]); 
        }
    }
    for (int i = lo, j = 0; i <= hi2; ++i, ++j) {
        elements[i] = mergedResult[j];
    }
}

template<typename T>
auto mergeSort(std::vector<T>& elements, int lo, int hi) -> void
{
    if (lo < hi) {
        int midPoint = (lo + hi)/2; 
        mergeSort(elements, lo, midPoint);
        mergeSort(elements, midPoint + 1, elements.size() - 1);
        merge(elements, lo, midPoint, midPoint + 1, elements.size() - 1); 
    }
}

template<typename T>
auto partition(std::vector<T>& elements, int lo, int hi) -> int
{
    int endPartStart = 0; 
    for (int i = 0; i < hi; ++i) {
        if (elements[i] < elements[hi]) {
            std::swap(elements[i], elements[endPartStart]);
            ++endPartStart; 
        }
    }
    std::swap(elements[endPartStart], elements[hi]); 
    return endPartStart - 1;
}

template<typename T>
auto quickSort(std::vector<T>& elements, int lo, int hi) -> void
{
    if (lo < hi) {
        int n = partition(elements, lo, hi); 
        quickSort(elements, lo, n - 1); 
        quickSort(elements, n + 1, hi); 
    }
}


int main() {
    auto v = std::vector<int>({4, 3, 2, 5, 8});
    quickSort(v, 0, v.size() - 1); 
    for (auto e : v) {
        std::cout << e; 
    }
    assert(std::vector<int>({2, 3, 4, 5, 8}) == v);
    v = std::vector<int>({}); 
    assert(std::vector<int>{} == v); 
    v = std::vector<int>({1}); 
    assert(std::vector<int>{1} == v); 
}