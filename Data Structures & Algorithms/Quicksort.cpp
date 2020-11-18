/***************************************************************
Problem: Quicksort
Question: just quicksort code done in class
Name: Alyssa and Wenjie
ID: 1662110
Date: 10/22/2018
Status: complete
****************************************************************/

/* Partition the array list[first..last] */
int partition(int list[], int first, int last)
{
            int f=list[first];
            int l=list[last];
            int middle=first+(last-first)/2;
            int m=list[middle];
            int pivotpos=((m-f)*(m-l)<=0)*middle+((l-m)*(l-f)<0)*last+((f-l)*(f-m)<0)*first;
            int pivot=list[pivotpos];
            int high = last;

                        for (int low = first; high > low; low+=(list[low]<=pivot), high-=(list[high]>pivot))
                             {
                                 if(list[low] > pivot && list[high] < pivot) {
                                     int temp = list[high];
                                     list[high] = list[low];
                                     list[low] = temp;
                             }
                        }
    return high;
}

void quickSort(int list[], int first, int last)
{
    if (last > first)
    {
        int pivotIndex = partition(list, first, last);
        quickSort(list, first, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, last);
    }
}

//==== entry point ===
void quickSort(int list[], int arraySize)
{
    quickSort(list, 0, arraySize - 1);
}
