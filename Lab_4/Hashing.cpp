#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HashTable
{
private:
    static const int table_size = 10;
    struct KeyValue
    {
        string key;
        int value;
    };
    vector<KeyValue> table[table_size];

    int hashFunction(const string &key)
    {
        int hash = 0;
        for (size_t i = 0; i < key.length(); ++i)
        {
            hash += key[i];
        }
        return hash % table_size;
    }

public:
    void insert(const string &key, int value)
    {
        int index = hashFunction(key);
        KeyValue kv = {key, value};
        table[index].push_back(kv);
    }

    bool search(const string &key)
    {
        int index = hashFunction(key);
        for (int i = 0; i < table[index].size(); i++)
        {
            if (table[index][i].key == key)
            {
                cout << "Found key '" << key << "' with value: " << table[index][i].value << endl;
                return true;
            }
        }
        cout << "Key '" << key << "' not found." << endl;
        return false;
    }

    void remove(const string &key)
    {
        int index = hashFunction(key);
        vector<KeyValue> &bucket = table[index];

        for (size_t i = 0; i < bucket.size(); ++i)
        {
            if (bucket[i].key == key)
            {
                bucket.erase(bucket.begin() + i);
                cout << "Removed key '" << key << "' from the table." << endl;
                return;
            }
        }
        cout << "Key '" << key << "' not found to remove." << endl;
    }
};

int main()
{
    HashTable ht;

    ht.insert("a", 5);
    ht.insert("b", 34);
    ht.insert("o", 7);

    ht.search("b");

    ht.remove("a");
    ht.search("a");

    return 0;
}