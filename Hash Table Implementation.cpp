#include<bits/stdc++.h>
using namespace std;
//---------------- It's just a Class 'Item' with Constructor for taking key and value ---------------
class Item{
public:
    int key;
    string name;
    Item(int aKey, string aName){
        key = aKey;
        name = aName;
    }
};

vector<Item> hashTable[11];

//------------------- Hash Function -------------------------

int hashFunction(int key){
    int hashValue = 0;
    while(key != 0){
        hashValue += key % 10; // Adding all the the digits one by one.
        key = key / 10;
    }
    return hashValue % 11; //return index after modulo by 11(Cause hashValue can be a large value)
}

//-------------- Inserts an item in the hashTable ----------------

void insertItem(int key, string name){
    int index = hashFunction(key); // The HashFunction has return a value as index.
    hashTable[index].push_back(Item(key, name));
}

//-------------- Inserts a key in the hashTable whether is exists in it or not ----------------

bool searchItem(int key){
    int index = hashFunction(key);
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < hashTable[index].size(); j++){
            if(key == hashTable[index][j].key){
                return true;
            }
        }
    }
    return false;
}

//-------------- Delete an item in the hashTable ----------------

bool deleteItem(int key){
    int index = hashFunction(key);
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < hashTable[index].size(); j++){
            if(key == hashTable[index][j].key){
                hashTable[index].erase(hashTable[index].begin()+i);
                return true;
            }
        }
    }
    return false;
}


//-------------- Printing the hashTable ----------------

void printHashTable(){ // Let's consider the HashTable as 2d vector. So we have to traverse it.
    for(int i = 0; i < 11; i++){ // First we are going the index i
        cout<<i<<"->";
        for(int j = 0; j < hashTable[i].size(); j++){ // Then we are travering the size of every i.
            cout<<hashTable[i][j].name;
            if(j < hashTable[i].size() - 1){
                cout<<"->";
            }
        }
        cout<<endl;
    }
}

int main(){

    insertItem(123456789,"Rahim");
    insertItem(123456789,"Alal");
    insertItem(123456789,"Ashiq");
    insertItem(198797779,"Manik");
    insertItem(123424234,"Mursalin");
    insertItem(121534535,"Harun");
    insertItem(123454129,"Sazzad");

    cout<<"### Print Hash Table : "<<endl<<endl;
    printHashTable();

    cout<<endl;
    cout<<"### The Result of Finding an Item : ";

    if(searchItem(123424234)){
        cout<<"Found!!"<<endl<<endl;
    }else{
        cout<<"Not Found!!"<<endl<<endl;
    }

    bool result = deleteItem(121534535);

    if(!result){
        cout<<"Item not Found"<<endl<<endl;
        return 0;
    }

    cout<<"### Printing Hash Table after deleting An item : "<<endl<<endl;

    printHashTable();

    return 0;
}

