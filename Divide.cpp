

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


int partition(vector<int>& arr, int left, int right, int pivot) {
    int pivotValue = arr[pivot];
    swap(arr[pivot], arr[right]);
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}


int medianOfFive(vector<int>& arr, int left, int right) {
    sort(arr.begin() + left, arr.begin() + right + 1);
    return (left + right) / 2;
}


int selectMedianOfMedians(vector<int>& arr, int left, int right, int k) {
    if (left == right) return arr[left];

    
    vector<int> medians;
    for (int i = left; i <= right; i += 5) {
        int subRight = min(i + 4, right);
        int median = medianOfFive(arr, i, subRight);
        medians.push_back(arr[median]);
    }

    int pivot;
    if (medians.size() == 1) {
        pivot = left + (right - left) / 2;
    } else {
        vector<int> mediansCopy = medians;
        int mom = selectMedianOfMedians(mediansCopy, 0, mediansCopy.size() - 1, mediansCopy.size() / 2);
        
        pivot = left;
        while (pivot <= right && arr[pivot] != mom) pivot++;
    }

    int pivotIndex = partition(arr, left, right, pivot);
    int length = pivotIndex - left + 1;

    if (length == k) return arr[pivotIndex];
    else if (k < length) return selectMedianOfMedians(arr, left, pivotIndex - 1, k);
    else return selectMedianOfMedians(arr, pivotIndex + 1, right, k - length);
}


int getMedian(vector<int>& arr) {
    int n = arr.size();
    if (n % 2 == 1) {
        return selectMedianOfMedians(arr, 0, n - 1, n / 2 + 1);
    } else {
        int m1 = selectMedianOfMedians(arr, 0, n - 1, n / 2);
        int m2 = selectMedianOfMedians(arr, 0, n - 1, n / 2 + 1);
        return (m1 + m2) / 2;
    }
}


pair<double,double> stats(const vector<double>& times) {
    double sum = 0;
    for (double t : times) sum += t;
    double mean = sum / times.size();
    double var = 0;
    for (double t : times) var += (t - mean) * (t - mean);
    var /= times.size();
    return {mean, sqrt(var)};
}

int main() {
    vector<int> sizes = {1<<20, 1<<21, 1<<22, 1<<23, 1<<24};
    random_device rd;
    mt19937 g(rd());

    for (int N : sizes) {
        cout << "N = " << N << endl;
        vector<double> times;
        for (int r = 0; r < 5; r++) {
            vector<int> arr(N);
            iota(arr.begin(), arr.end(), 0);
            shuffle(arr.begin(), arr.end(), g);

            auto start = high_resolution_clock::now();
            int mediana = getMedian(arr);
            auto end = high_resolution_clock::now();

            double elapsed = duration<double, milli>(end - start).count();
            times.push_back(elapsed);
            cout << "  Run " << r+1 << ": Mediana = " << mediana 
                << ", Tiempo = " << elapsed << " ms" << endl;
        }
        auto [mean, stddev] = stats(times);
        cout << "  Promedio: " << mean << " ms, Desviacion: " << stddev << " ms\n\n";
    }
}
