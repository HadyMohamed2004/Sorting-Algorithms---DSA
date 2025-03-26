#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <memory>

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
            cout << "File could not be opened" << endl;
            return;
        }

        vector<T> tempdata;
        T temp;

        while (file >> temp) {
            tempdata.push_back(temp);
        }
        file.close();

        if (tempdata.empty()) {
            cout<<"File is empty"<<endl;
            return;
        }

        delete[] data;
        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = tempdata[i];
        }
    }

    void setData(T* inputData,int n) {
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
        int left= middle-start+1;
        int right=end-middle;
        T* leftData = new T[left];
        T* rightData = new T[right];

        for (int i = 0; i < left; i++) {
            leftData[i] = data[start + i];
        }

        for (int i = 0; i < right; i++) {
            rightData[i] = data[middle + 1 + i];
        }

        int i = 0, j = 0, k = start;

        while (i < left && j < right) {
            if (leftData[i] <= rightData[j]) {
                data[k++] = leftData[i++];
            }
            else {
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

        cout<<"Do you want to:\n"
              "1) Read from file\n"
              "2) Enter data manually\n"
              "Enter your choice (1-2): ";
        cin>>choice;
        if (type == 1) {
            SortingSystem<int> sorting(n);
            if (choice == 1) {
                cout<<"Enter file name: ";
                cin>>filename;
                sorting.setData(filename);
            }
            else if (choice == 2) {
                int* data=new int[n];
                cout << "Enter " << n << " integers: ";
                for (int i = 0; i < n; i++) cin >> data[i];
                sorting.setData(data,n);
                delete [] data;
            }
            sorting.showMenu();
            cin >> choice;
            switch (choice) {
                case 1: sorting.measureSortTime(&SortingSystem<int>::insertion_sort); break;
                case 2: sorting.measureSortTime(&SortingSystem<int>::selection_sort); break;
                case 3: sorting.measureSortTime(&SortingSystem<int>::bubble_sort); break;
                case 4: sorting.measureSortTime(&SortingSystem<int>::shell_sort); break;
                case 5: sorting.measureSortTime(&SortingSystem<int>::merging_sort, 0, n - 1); break;
                default: cout << "Invalid choice!\n";
            }

            cout << "Sorted data: ";
            sorting.displayData();
        }
        else if (type == 2) {
            SortingSystem<string> sorting(n);
            if (choice == 1) {
                cout<<"Enter file name: ";
                cin>>filename;
                sorting.setData(filename);
            }
            else if (choice == 2) {
                string* data=new string[n];
                cout << "Enter " << n << " strings: ";
                for (int i = 0; i < n; i++) cin >> data[i];
                sorting.setData(data,n);
                delete [] data;
            }
            sorting.showMenu();
            cin >> choice;
            switch (choice) {
                case 1: sorting.measureSortTime(&SortingSystem<string>::insertion_sort); break;
                case 2: sorting.measureSortTime(&SortingSystem<string>::selection_sort); break;
                case 3: sorting.measureSortTime(&SortingSystem<string>::bubble_sort); break;
                case 4: sorting.measureSortTime(&SortingSystem<string>::shell_sort); break;
                case 5: sorting.measureSortTime(&SortingSystem<string>::merging_sort, 0, n - 1); break;
                default: cout << "Invalid choice!\n";
            }

            cout << "Sorted data: ";
            sorting.displayData();
        }
        else if (type == 3) {
            SortingSystem<float> sorting(n);
            if (choice == 1) {
                cout<<"Enter file name: ";
                cin>>filename;
                sorting.setData(filename);
            }
            else if (choice == 2) {
            float* data=new float[n];
            cout << "Enter " << n << " float numbers: ";
            for (int i = 0; i < n; i++) cin >> data[i];
                sorting.setData(data,n);
                delete [] data;
            }
            sorting.showMenu();
            cin >> choice;
            switch (choice) {
                case 1: sorting.measureSortTime(&SortingSystem<float>::insertion_sort); break;
                case 2: sorting.measureSortTime(&SortingSystem<float>::selection_sort); break;
                case 3: sorting.measureSortTime(&SortingSystem<float>::bubble_sort); break;
                case 4: sorting.measureSortTime(&SortingSystem<float>::shell_sort); break;
                case 5: sorting.measureSortTime(&SortingSystem<float>::merging_sort, 0, n - 1); break;
                default: cout << "Invalid choice!\n";
            }

            cout << "Sorted data: ";
            sorting.displayData();
        }
        else if (type == 4) {
            SortingSystem<char> sorting(n);
            if (choice == 1) {
                cout<<"Enter file name: ";
                cin>>filename;
                sorting.setData(filename);
            }
            else if (choice == 2) {
                char* data=new char[n];
                cout << "Enter " << n << " characters: ";
                for (int i = 0; i < n; i++) cin >> data[i];
                sorting.setData(data,n);
                delete [] data;
            }

            sorting.showMenu();
            cin >> choice;
            switch (choice) {
                case 1: sorting.measureSortTime(&SortingSystem<char>::insertion_sort); break;
                case 2: sorting.measureSortTime(&SortingSystem<char>::selection_sort); break;
                case 3: sorting.measureSortTime(&SortingSystem<char>::bubble_sort); break;
                case 4: sorting.measureSortTime(&SortingSystem<char>::shell_sort); break;
                case 5: sorting.measureSortTime(&SortingSystem<char>::merging_sort, 0, n - 1); break;
                default: cout << "Invalid choice!\n";
            }

            cout << "Sorted data: ";
            sorting.displayData();
        }
        else {
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
