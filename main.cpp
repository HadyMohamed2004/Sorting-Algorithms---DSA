#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;



template <typename T>
class SortingSystem {
private:
    T* data;
    int size;

public:
    explicit SortingSystem(int n) : size(n) {
        data = new T[size];
    }

    ~SortingSystem() {
        delete[] data;
    }

    void setData(const string& filename) {

        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "File could not be opened" << endl;
            return;
        }

        vector<T> tempdata;
        T temp;

        while (file >> temp) {
            tempdata.push_back(temp);
        }
        file.close();

        if (tempdata.empty()) {
            cerr<<"File is empty";
            return;
        }

        delete[] data;

        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = tempdata[i];
        }

    }

    void insertion_sort() {
        for (int i = 1; i < size; i++) {
            T temp = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > temp) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = temp;
        }
    }

    void selection_sort() {
        for (int i = 0; i < size - 1; i++) {
            int min = i;
            for (int j = i + 1; j < size; j++) {
                if (data[j] < data[min]) {
                    min = j;
                }
            }
            swap(data[i], data[min]);
        }
    }

    void bubble_sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = size - 1; j > i; j--) {
                if (data[j] < data[j - 1]) {
                    swap(data[j], data[j - 1]);
                }
            }
        }
    }

    void shell_sort() {
        for (int gap = size / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < size; i++) {
                T temp = data[i];
                int j;
                for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
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
        vector<T> temp(data + start, data + middle + 1);
        vector<T> temp1(data + middle + 1, data + end + 1);
        int i = 0, j = 0, k = start;

        while (i < temp.size() && j < temp1.size()) {
            if (temp[i] <= temp1[j]) {
                data[k++] = temp[i++];
            } else {
                data[k++] = temp1[j++];
            }
        }

        while (i < temp.size()) data[k++] = temp[i++];
        while (j < temp1.size()) data[k++] = temp1[j++];
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


    void showMenu() {
            cout<<"Select a sorting algorithm:\n"
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

};

int main() {


    while (true) {
        int n;
        cout<<"Enter the number of elements :";
        cin>>n;

        auto* sorting = new SortingSystem<int>(n);

        string filename;
        cout<<"Enter the file name to extract data from: ";
        cin>>filename;

        sorting->setData(filename);
        sorting->showMenu();
        int choice;
        cin>>choice;
        switch (choice) {
            case 1:
                sorting->measureSortTime(&SortingSystem<int>::insertion_sort); break;
            case 2:
                sorting->measureSortTime(&SortingSystem<int>::selection_sort); break;
            case 3:
                sorting->measureSortTime(&SortingSystem<int>::bubble_sort); break;
            case 4:
                sorting->measureSortTime(&SortingSystem<int>::shell_sort); break;
            case 5:
                sorting->measureSortTime(&SortingSystem<int>::merging_sort, 0, size - 1);
            break;
            default:
                cout<<"Wrong choice!\n"<<endl;
        }

        cout << "Sorted data: ";
        sorting->displayData();

        delete sorting;

        char repeat;
        cout<<"Do you want to sort another dataset? (y/n): ";
        cin>>repeat;
        if (tolower(repeat) != 'y') {
            break;
        }
    }

    return 0;
}
