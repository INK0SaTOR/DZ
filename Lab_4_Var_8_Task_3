#include <iostream>
#include <vector>
using namespace std;

int main() 
{  
    int n;  
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0) 
    {
        cout << "Number of elements must be positive" << endl;
        return 1;
    }
    vector <int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
    }
    vector<int> uniqueElements; 
    vector<int> counts;
    for (int element : arr) 
    {
        bool found = false;
        for (size_t i = 0; i < uniqueElements.size(); ++i) //Перебираю уникальные элементы 
        {  
            if (uniqueElements[i] == element)
            {
                counts[i]++; 
                found = true; 
                break;
            }
        }
        if (!found) 
        {
            uniqueElements.push_back(element);
            counts.push_back(1); 
        }
    }
    cout << "\nResults: \n";
    cout << "Number of different elements: " << uniqueElements.size() << endl;
    cout << "Elements and numbers:\n";
    for (size_t i = 0; i < uniqueElements.size(); ++i) 
    {
        cout << "Element " << uniqueElements[i] << " counts " << counts[i] << " times" << endl;
    }
    return 0;
