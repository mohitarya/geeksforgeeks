// Compile using 
// gcc vectorIterators.cpp -std=c++11 -lstdc++

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;

    for(int i=0; i<10; i++)
    {
        vec.push_back(i);
    }
    // Output begin to end
    for(vector<int>::iterator p = vec.begin(); p < vec.end(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;
    for(vector<int>::const_iterator cp = vec.begin(); cp < vec.end(); cp++)
    {
        cout << " " << *cp;
    }

    cout << endl;

    for(vector<int>::reverse_iterator rp = vec.rbegin(); rp != vec.rend(); rp++)
    {
        cout << " " << *rp;
    }
    cout << endl;
    for(vector<int>::const_reverse_iterator crp = vec.rbegin(); crp < vec.rend(); crp++)
    {
        cout << " " << *crp;
    }
    cout << endl;

    cout << "Size = " << vec.size() << endl;

    cout << "max Size = " << vec.max_size() << endl;
    
    cout << "Capacity = " << vec.capacity() << endl;

    vec.resize(12);

    cout << "Capacity = " << vec.capacity() << endl;

    cout << "Empty = " << vec.empty() << endl;

    // If we resize then it keep the changed size and do not shrink
    vec.shrink_to_fit();
    cout << "Capacity = " << vec.capacity() << endl;

    vec.reserve(10);

    cout << "Capacity = " << vec.capacity() << endl;

    cout << "Data[3] = " << vec[3] << endl;

    cout << "Data[3] = " << vec.at(3) << endl;
    cout << "Data[Front] = " << vec.front() << endl;
    cout << "Data[back] = " << vec.back() << endl;

    // Returns the pointer to first element
    int *ptr = vec.data();

    // Modifires
    //assign() – It assigns new value to the vector elements by replacing old ones
    //push_back() – It push the elements into a vector from the back
    //pop_back() – It is used to pop or remove elements from a vector from the back.
    //insert() – It inserts new elements before the element at the specified position
    //erase() – It is used to remove elements from a container from the specified position or range.
    //swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
    //clear() – It is used to remove all the elements of the vector container
    //emplace() – It extends the container by inserting new element at position
    //emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector

    vec.assign(2, 5);
    cout << "Capacity = " << vec.capacity() << endl;
    for(vector<int>::iterator p = vec.begin(); p < vec.end(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;

    vec.push_back(20);
    vec.push_back(30);
    for(vector<int>::iterator p = vec.begin(); p < vec.end(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;
    vec.pop_back();
    for(vector<int>::iterator p = vec.begin(); p < vec.end(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;
    vec.insert(vec.begin()+2, 10);
    for(vector<int>::iterator p = vec.begin(); p < vec.end(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;
    vec.erase(vec.begin()+2);
    for(vector<int>::iterator p = vec.begin(); p < vec.end(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;
    vec.emplace(vec.begin()+2, 100);
    for(vector<int>::iterator p = vec.begin(); p < vec.end(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;
    vec.emplace_back(200);
    for(vector<int>::iterator p = vec.begin(); p < vec.end(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;
    /*
    vec.clear();
    for(vector<int>::iterator p = vec.begin(); p < vec.end(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;
    */
    //vector<int> vec2(vec);
    //vec2 = vec;
    vector<int> vec2;
    //copy(vec.begin(), vec.end(), back_inserter((vec2)));
    vec2.assign(vec.begin(), vec.end());
    for(vector<int>::iterator p = vec2.begin(); p < vec2.end(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;


    return 0;
}
