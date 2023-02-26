#include <iostream>
#define ll long long int

using namespace std;

// Linked List
template <typename T>
class node
{
public:
    string key;
    T value;
    node *next;

    node(string key, T value) // constructor
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    node(node &obj) // copy constructor
    {
        this->key = obj.key;
        this->value = obj.value;
        this->next = NULL;
    }

    ~node() // destructor
    {
        node *head = this;
        while (head != NULL)
        {
            node *currNode = head;
            head = head->next;
            delete currNode;
        }
    }
};

// hash table
template <typename T>
class unordered_map
{
public:
    int numOfElements, capacity;
    node<T> **arr; // want a array which stores pointers to node<T> i.e. head of a Linked List

    unordered_map() // constructor
    {
        this->capacity = 1;
        this->numOfElements = 0;
        this->arr = new node<T> *[this->capacity];
        this->arr[0] = NULL;
    }

    int hashFunction(string key) // hash function for hashing a string
    {    
        int bucketIndex;
        ll sum = 0, factor = 31;
        for (int i = 0; i < key.size(); i++)
        {    
              // sum = sum + (ascii value of character * (prime number ^ x)) % total number of buckets
              // factor = factor * prime number i.e. prime number ^ x
            sum = ((sum % this->capacity) + ((int(key[i])) * factor) % this->capacity) % this->capacity;
            factor = ((factor % INT16_MAX) * (31 % INT16_MAX)) % INT16_MAX; 
        }

        bucketIndex = sum; 
        return bucketIndex;
    }

    float getLoadFactor()
    {    
          // number of elements in hash table / total numbers of buckets
        return (float)(this->numOfElements + 1) / (float)(this->capacity);
    }

    void rehashing()
    {
        int oldCapacity = this->capacity;
        node<T> **temp = this->arr; // temp is hodling current array

        this->capacity = oldCapacity * 2; // doubling the size of current capacity
        this->arr = new node<T> *[this->capacity]; // points to new array of doubled size

        for (int i = 0; i < this->capacity; i++)
        {
            arr[i] = NULL;
        }
        for (int i = 0; i < oldCapacity; i++) // copying all the previous values in new array
        {
            node<T> *currBucketHead = temp[i];
            while (currBucketHead != NULL) // copying whole linked list
            {
                this->insert(currBucketHead->key, currBucketHead->value); // insert function have now updated hash function as capacity is doubled
                currBucketHead = currBucketHead->next;
            }
        }
        delete[] temp; // deleting old array from heap memory
        return;
    }

    void insert(string key, T value)
    {
        while (this->getLoadFactor() > 0.5f) // when load factor > 0.5
        {
            this->rehashing();
        }

        int bucketIndex = this->hashFunction(key);
        if (this->arr[bucketIndex] == NULL) // when there is no linked list at bucket
        {
            node<T> *newNode = new node<T>(key, value);
            arr[bucketIndex] = newNode;
        }
        else // adding at the head of current linked list
        {
            node<T> *newNode = new node<T>(key, value);
            newNode->next = this->arr[bucketIndex];
            this->arr[bucketIndex] = newNode;
        }
        return;
    }

    int search(string key)
    {
        int bucketIndex = this->hashFunction(key); // getting bucket index
        node<T> *bucketHead = this->arr[bucketIndex];
        while (bucketHead != NULL) // searching in the linked list which is present at bucket for given key
        {
            if (bucketHead->key == key)
            {
                return bucketHead->value;
            }
            bucketHead = bucketHead->next; // moving to next node in linked list
        }
        cout << "Oops!! Data not found." << endl; // when key is not matched...
        return -1;
    }
};

int main()
{
    unordered_map<int> mp; // int is value....in our case key must be of string type
      mp.insert("Manish", 16);
      mp.insert("Vartika", 14);
      mp.insert("ITT", 5);
      mp.insert("elite_Programmer", 4);
      mp.insert("pluto14", 14);
      mp.insert("GeeksForGeeks", 11);
      
      cout << "Value of GeeksForGeeks : " << mp.search("GeeksForGeeks") << endl;
      cout << "Value of ITT : " << mp.search("ITT") << endl;
      cout << "Value of Manish : " << mp.search("Manish") << endl;
      cout << "Value of Vartika : " << mp.search("Vartika") << endl;
      cout << "Value of elite_Programmer : " << mp.search("elite_Programmer") << endl;
      cout << "Value of pluto14 : " << mp.search("pluto14") << endl;
        
        // prints Oops!! Data not found and return -1
      mp.search("GFG"); // case when there is no key present in Hash Map..
  
      return 0;
}