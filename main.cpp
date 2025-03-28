#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

template<typename T>
string to_string(const T &value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}

template <typename T>
string print_arr(const T* data, int size) {
    string result = "[";
    for (int i = 0; i < size; ++i) {
        result += to_string(data[i]);
        if (i < size - 1) {
            result += ", ";
        }
    }
    return result + "]";
}


template<typename T>
class SortingSystem {
private:
    T *data;
    int size;

public:
    explicit SortingSystem(int n) : size(n) {
        data = new T[size];
    }

    ~SortingSystem() {
        delete[] data;
    }

    void setData(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "File could not be opened" << endl;
            return;
        }

        T temp;

        for (int i = 0; i < size && file >> temp; i++) {
            data[i] = temp;
        }
        file.close();

    }

    void setData(T *inputData, int n) {
        delete[] data;
        size = n;
        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = inputData[i];
        }
    }


    void insertion_sort() {
        for (int i = 1; i < size; i++) {
            T temp = data[i];
            cout << "Current Element: " << temp << endl;
            int j = i - 1;
            while (j >= 0 && data[j] > temp) {
                cout << "   Swapping " << data[j + 1] << " with " << data[j] << endl;
                data[j + 1] = data[j];
                j--;
            }
            cout << "   Putting " << temp << " In place of " << data[j + 1] << endl;
            data[j + 1] = temp;

            cout << "Current Array: " << print_arr(data, size) << endl;
        }
    }

    void selection_sort() {
        for (int i = 0; i < size - 1; i++) {
            int min = i;
            cout << "Current Minimum: " << data[i] << endl;
            for (int j = i + 1; j < size; j++) {
                cout << "   Comparing " << data[min] << " and " << data[j] << " -> ";
                if (data[j] < data[min]) {
                    min = j;
                    cout << "Changing Minimum to: " << data[min] << endl;
                } else {
                    cout << "No Changing Minimum" << endl;
                }
            }

            cout << "   Swapping " << data[i] << " and " << data[min] << endl;
            swap(data[i], data[min]);

            cout << "Iteration " << i + 1 << ": " << print_arr(data, size) << endl;
        }
    }

    void bubble_sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    cout << "Element getting swapped -> " << data[j] << ": ";
                    for (int k = 0; k < size; k++) {
                        if (k == j || k == j + 1) cout << "[" << data[k] << "] ";
                        else cout << data[k] << ' ';
                    }
                    cout << endl;
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }


    void shell_sort() {
        for (int gap = size / 2; gap > 0; gap /= 2) {
            cout<<"Gap: "<<gap<<endl;
            for (int i = gap; i < size; i++) {
                T temp = data[i];
                int j;
                for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                    for (int k=0;k<size;k++) {
                        if (k==j||k==j-gap) {
                            cout<<"["<<data[k]<<"] ";
                        }
                        else cout<<data[k]<<' ';
                    }
                    cout<<endl;
                    data[j] = data[j - gap];
                }

                data[j] = temp;
            }
        }
    }


    void merging_sort(int start, int end) {
        if (start >= end)
            return;
        int mid = (start + end) / 2;

        merging_sort(start, mid);
        merging_sort(mid + 1, end);
        merge(start, mid, end);
    }


    void merge(int start, int middle, int end) {
        int left = middle - start + 1;
        int right = end - middle;
        T *leftData = new T[left];
        T *rightData = new T[right];

        cout << "Mid = " << data[middle] << endl;


        for (int i = 0; i < left; i++) {
            leftData[i] = data[start + i];
        }

        for (int i = 0; i < right; i++) {
            rightData[i] = data[middle + 1 + i];
        }

        cout << "Left: " << print_arr(leftData, left) << "| Right: " << print_arr(rightData, right) << endl;


        int i = 0, j = 0, k = start;

        while (i < left && j < right) {
            if (leftData[i] <= rightData[j]) {
                data[k++] = leftData[i++];
            } else {
                data[k++] = rightData[j++];
            }
        }
        while (i < left) {
            data[k++] = leftData[i++];
        }
        while (j < right) {
            data[k++] = rightData[j++];
        }
        delete[] leftData;
        delete[] rightData;
    }


    void quick_sort(int left, int right) {
        if (left >= right) {
            return;
        }
        int p = partition(left, right);
        cout << "Left Part: " << print_arr(data, left) << " | Right Part: " << print_arr(data, right) << endl;

        quick_sort(left, p - 1);
        quick_sort(p + 1, right);
    }

    int partition(int left, int right) {
        T pivot = data[left];

        cout << "Pivot: " << pivot << endl;
        int i = left;
        for (int j = left + 1; j <= right; j++) {
            cout << "Comparing: " << pivot << " and " << data[j] << endl;
            if (data[j] < pivot) {
                i++;
                swap(data[i], data[j]);
                cout << "After swap: " << print_arr(data, right) << endl;
            }
            cout << print_arr(data, size) << endl;
        }
        swap(data[i], data[left]);
        cout << "After pivot swap: " << print_arr(data, right) << endl;

        return i;
    }


    void count_sort() {
        int k = INT_MIN; // max

        cout << "Current Array: ";

        for (int i = 0; i < size; i++) {
            if (data[i] > k) {
                k = data[i];
            }
        }
        cout << print_arr(data, size) << endl;


        cout << "Count Array: ";
        int c[k + 1];

        for (int i = 0; i < k; i++) {
            c[i] = 0;
        }

        cout << "Greatest Element (k): " << k << endl;


        cout << "Loop 0:" << print_arr(c, k + 1) << endl;

        for (int j = 0; j < size; j++) {
            c[data[j]]++;
            cout << "Loop " << j + 1 << ":" << print_arr(c, k + 1) << endl;
        }

        cout << "Cumulative count array:";
        for (int i = 1; i < k + 1; i++) {
            c[i] += c[i - 1];
            cout << "Loop " << i - 1 << ":" << print_arr(c, k + 1) << endl;
        }

        int b[size];
        for (int i = 0; i < size; i++) {
            b[i] = 0;
        }

        cout << "Sorted Array: " << print_arr(b, size) << " Cumulative count array:" << print_arr(c, k + 1) << endl;
        for (int j = size - 1; j >= 0; j--) {
            b[c[data[j]] - 1] = data[j];
            c[data[j]]--;
            cout << "Loop" << j - size << ": " << endl;
            cout << "Sorted Array: " << print_arr(b, size) << " Cumulative count array:" << print_arr(c, k + 1) << endl;
        }

        for (int i = 0; i < size; i++) {
            data[i] = b[i];
        }
    }

    void bucket_sort() {
        T min = data[0], max = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < min) {
                min = data[i];
            }
            if (data[i] > max) {
                max = data[i];
            }
        }
        int range = max - min + 1;

        int n_buckets=size/4;
        T **buckets=new T*[n_buckets];
        int *buckets_size=new int[n_buckets]{0};

        for (int i = 0; i < n_buckets; i++) {
            buckets[i] = new T[size];
        }

        for (int i = 0; i < size; i++) {
            int index = (n_buckets * (data[i] - min)) / range;
            buckets[index][buckets_size[index]++] = data[i];
        }
        cout<<"Buckets before sorting :"<<endl;
        for (int i = 0; i < n_buckets; i++) {
            cout<<"Bucket "<<i+1<<": ";
            for (int j = 0; j < buckets_size[i]; j++) {
                cout<<buckets[i][j]<<" ";
            }
            cout<<endl;
        }

        for (int i = 0; i < n_buckets; i++) {
            for (int j = 1; j < buckets_size[i]; j++) {
                T temp = buckets[i][j];
                int k = j - 1;
                while (k >= 0 && buckets[i][k] > temp) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = temp;
            }
        }
        cout<<"Buckets after sorting :"<<endl;;
        for (int i = 0; i < n_buckets; i++) {
            cout<<"Bucket "<<i+1<<": ";
            for (int j = 0; j < buckets_size[i]; j++) {
                cout<<buckets[i][j]<<" ";
            }
            cout<<endl;
        }
        int index=0;
        for (int i=0;i<n_buckets;i++) {
            for (int j=0;j<buckets_size[i];j++) {
                data[index++] = buckets[i][j];
            }
            delete[] buckets[i];
        }

        delete[] buckets;
        delete[] buckets_size;
    }


    void count_radix(int exp) {
        int c[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (int j = 0; j < size; j++) {
            int n = (data[j] / exp) % 10;
            c[n]++;
        }

        for (int i = 1; i < 10; i++) {
            c[i] += c[i - 1];
        }
        cout << "Cumulative Count Array: " << print_arr(c, 10) << endl;


        cout << "Building Sorted Array:" << endl;
        cout << "Before Sorting Array: " << print_arr(data, size) << " - Cumulative Array: " << print_arr(c, 10) <<
                endl;
        int b[size];
        for (int i = 0; i < size; i++) {
            b[i] = 0;
        }

        for (int j = size - 1; j >= 0; j--) {
            int n = (data[j] / exp) % 10;
            b[c[n] - 1] = data[j];
            c[n]--;
            cout << "Loop " << size - j << " Sorted Array: " << print_arr(b, size) << endl;
        }

        for (int i = 0; i < size; i++) {
            data[i] = b[i];
        }
    }

    void radix_sort() {
        cout << "Current Array: " << print_arr(data, size) << endl;

        int max = INT_MIN;
        for (int i = 0; i < size; i++) {
            if (data[i] > max) {
                max = data[i];
            }
        }

        int exp = 1;
        while (exp < max) {
            cout << endl << "Exponent: " << exp << endl;
            count_radix(exp);
            cout << "Final Array: " << print_arr(data, size) << endl;
            exp *= 10;
        }
    }

    void displayData() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void measureSortTime(void (SortingSystem::*sortFunc)()) {
        auto start = chrono::high_resolution_clock::now();
        (this->*sortFunc)();
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> duration = end - start;
        cout << "Sorting took " << duration.count() << " milliseconds." << endl;
    }

    void measureSortTime(void (SortingSystem::*sortFunc)(int, int), int start, int end) {
        auto t1 = chrono::high_resolution_clock::now();
        (this->*sortFunc)(start, end);
        auto t2 = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> duration = t2 - t1;
        cout << "Sorting took " << duration.count() << " milliseconds." << endl;
    }


    void static showMenu() {
        cout << "Select a sorting algorithm:\n"
                "1. Insertion Sort\n"
                "2. Selection Sort\n"
                "3. Bubble Sort\n"
                "4. Shell Sort\n"
                "5. Merge Sort\n"
                "6. Quick Sort\n"
                "7. Count Sort (int only)\n"
                "8. Radix Sort (int only)\n"
                "9. Bucket Sort\n"
                "Enter your choice (1-9): ";
    }

    template<typename Te>
    friend string print_arr(Te data, int size);
};


int main() {
    while (true) {
        int n, choice, type;
        string filename;

        cout << "Enter the number of elements: ";
        cin >> n;

        cout << "Select the data type:\n"
                "1) Integer\n"
                "2) String\n"
                "3) Float\n"
                "4) Character\n"
                "Enter your choice (1-4): ";
        cin >> type;

        cout << "Do you want to:\n"
                "1) Read from file\n"
                "2) Enter data manually\n"
                "Enter your choice (1-2): ";
        cin >> choice;
        if (type == 1) {
            SortingSystem<int> sorting(n);
            if (choice == 1) {
                cout << "Enter file name: ";
                cin >> filename;
                sorting.setData(filename);
            } else if (choice == 2) {
                int *data = new int[n];
                cout << "Enter " << n << " integers: ";
                for (int i = 0; i < n; i++) cin >> data[i];
                sorting.setData(data, n);
                delete [] data;
            }
            sorting.showMenu();
            cin >> choice;
            switch (choice) {
                case 1: sorting.measureSortTime(&SortingSystem<int>::insertion_sort);
                    break;
                case 2: sorting.measureSortTime(&SortingSystem<int>::selection_sort);
                    break;
                case 3: sorting.measureSortTime(&SortingSystem<int>::bubble_sort);
                    break;
                case 4: sorting.measureSortTime(&SortingSystem<int>::shell_sort);
                    break;
                case 5: sorting.measureSortTime(&SortingSystem<int>::merging_sort, 0, n - 1);
                    break;
                case 6: sorting.measureSortTime(&SortingSystem<int>::quick_sort, 0, n - 1);
                    break;
                case 7: sorting.measureSortTime(&SortingSystem<int>::count_sort);
                    break;
                case 8:
                    cout << "Radix" << endl;
                    sorting.measureSortTime(&SortingSystem<int>::radix_sort);
                    break;
                case 9: sorting.measureSortTime(&SortingSystem<int>::bucket_sort);
                    break;

                default: cout << "Invalid choice!\n";
            }

            cout << "Sorted data: ";
            sorting.displayData();
        } else if (type == 2) {
            SortingSystem<string> sorting(n);
            if (choice == 1) {
                cout << "Enter file name: ";
                cin >> filename;
                sorting.setData(filename);
            } else if (choice == 2) {
                string *data = new string[n];
                cout << "Enter " << n << " strings: ";
                for (int i = 0; i < n; i++) cin >> data[i];
                sorting.setData(data, n);
                delete [] data;
            }
            sorting.showMenu();
            cin >> choice;
            switch (choice) {
                case 1: sorting.measureSortTime(&SortingSystem<string>::insertion_sort);
                    break;
                case 2: sorting.measureSortTime(&SortingSystem<string>::selection_sort);
                    break;
                case 3: sorting.measureSortTime(&SortingSystem<string>::bubble_sort);
                    break;
                case 4: sorting.measureSortTime(&SortingSystem<string>::shell_sort);
                    break;
                case 5: sorting.measureSortTime(&SortingSystem<string>::merging_sort, 0, n - 1);
                    break;
                case 6: sorting.measureSortTime(&SortingSystem<string>::quick_sort, 0, n - 1);
                    break;
                default: cout << "Invalid choice!\n";
            }

            cout << "Sorted data: ";
            sorting.displayData();
        } else if (type == 3) {
            SortingSystem<float> sorting(n);
            if (choice == 1) {
                cout << "Enter file name: ";
                cin >> filename;
                sorting.setData(filename);
            } else if (choice == 2) {
                float *data = new float[n];
                cout << "Enter " << n << " float numbers: ";
                for (int i = 0; i < n; i++) cin >> data[i];
                sorting.setData(data, n);
                delete [] data;
            }
            sorting.showMenu();
            cin >> choice;
            switch (choice) {
                case 1: sorting.measureSortTime(&SortingSystem<float>::insertion_sort);
                    break;
                case 2: sorting.measureSortTime(&SortingSystem<float>::selection_sort);
                    break;
                case 3: sorting.measureSortTime(&SortingSystem<float>::bubble_sort);
                    break;
                case 4: sorting.measureSortTime(&SortingSystem<float>::shell_sort);
                    break;
                case 5: sorting.measureSortTime(&SortingSystem<float>::merging_sort, 0, n - 1);
                    break;
                case 6: sorting.measureSortTime(&SortingSystem<float>::quick_sort, 0, n - 1);
                    break;
                case 9: sorting.measureSortTime(&SortingSystem<float>::bucket_sort);
                default: cout << "Invalid choice!\n";
            }

            cout << "Sorted data: ";
            sorting.displayData();
        } else if (type == 4) {
            SortingSystem<char> sorting(n);
            if (choice == 1) {
                cout << "Enter file name: ";
                cin >> filename;
                sorting.setData(filename);
            } else if (choice == 2) {
                char *data = new char[n];
                cout << "Enter " << n << " characters: ";
                for (int i = 0; i < n; i++) cin >> data[i];
                sorting.setData(data, n);
                delete [] data;
            }

            sorting.showMenu();
            cin >> choice;
            switch (choice) {
                case 1: sorting.measureSortTime(&SortingSystem<char>::insertion_sort);
                    break;
                case 2: sorting.measureSortTime(&SortingSystem<char>::selection_sort);
                    break;
                case 3: sorting.measureSortTime(&SortingSystem<char>::bubble_sort);
                    break;
                case 4: sorting.measureSortTime(&SortingSystem<char>::shell_sort);
                    break;
                case 5: sorting.measureSortTime(&SortingSystem<char>::merging_sort, 0, n - 1);
                    break;
                case 6: sorting.measureSortTime(&SortingSystem<char>::quick_sort, 0, n - 1);
                    break;
                case 9: sorting.measureSortTime(&SortingSystem<char>::bucket_sort);
                    break;
                default: cout << "Invalid choice!\n";
            }

            cout << "Sorted data: ";
            sorting.displayData();
        } else {
            cout << "Invalid type selection!\n";
            continue;
        }

        char repeat;
        cout << "Do you want to sort another dataset? (y/n): ";
        cin >> repeat;
        if (tolower(repeat) != 'y') {
            break;
        }
    }
    return 0;
}