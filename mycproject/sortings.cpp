#include "sortings.h"

sortings::sortings() {
}

sortings::sortings(const sortings& orig) {
}

sortings::~sortings() {
}

void sortings::execute() {
    int arr[] = {4, 10, 11, 5, 1, 13};
    int n = sizeof (arr) / sizeof (arr[0]);

    //selectionsort(arr, n);
    //insertionsort(arr, n);
    //bubblesort(arr, n);
    //shellsort(arr, n);
    //heapsort(arr, n);

    cout << "Sorted array: \n";
    comm.printArray(arr, n);
}

// <editor-fold defaultstate="collapsed" desc="selection sort">
//Массивын хамгийн эхний/хамгийн их элементтэй хамгийн бага элементийн байрыг нь солино. 
//Үүний дараа массивын хамгийн бага/хамгийн их элемент нь жинхэнэ эзлэх ѐстой байраа эзэлнэ.

void sortings::selectionsort(int arr[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        // Swap the found minimum element with the first element
        swap(&arr[min], &arr[i]);
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="insertion sort">
//Шинээр оруулах элемэнтийг массивын 2 дахь элемэнтээс эхлэн авна. 
//Эхний алхамд хамгийн эхний элемэнтийг эрэмбэлэгдсэн массив гэж үзэн 2 дахь элемэнтийг 
//    эхний элемэнттэй харьцуулан байрлалыг нь олсноор 2 элемэнттэй эрэмбэлэгдсэн массив гарган авна. 
//Удаах алхамд үүссэн 2 элемэнт бүхий эрэмбэлэгдсэн массивтаа массивын 3 дахь элемэнтийг 
//оруулах байдлаар массивын төгсгөл хүртэл бүх элемэнтийн хувьд давтан гүйцэтгэнэ.

void sortings::insertionsort(int arr[], int n) {

    int key, i, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="bubble sort">
// elementiig 2 2 oor ni bvleglej bairiin solih bdlaar sortlono
// dotor heseg i iig hasaj ogch bgan bairaa olson uchraas svvliin elemented hvrehgui bh zorilgotoi

void sortings::bubblesort(int arr[], int n) {
    int i, j;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
        comm.printArray(arr, n);
    }
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="shell sort">

void sortings::shellsort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1) {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="heap sort">
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void sortings::heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        cout << "orj bn" << i << "\n";
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void sortings::heapsort(int arr[], int n) {

    comm.printArray(arr, n);
    for (int i = n / 2 - 1; i >= 0; i--) {
        cout << i << "\n";
        heapify(arr, n, i);
        comm.printArray(arr, n);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}
// </editor-fold>

void sortings::swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}