
#include <iostream>
#include <array>
#include <list>
#include <utility>
#include <string.h>
#include "associative_array.h"


associative_array::associative_array()
{
    sizeIndex = 0;
}

bool associative_array::userExists(string name)
{
    if(A.at(hashingFunc(name)).empty()){
        return 0;
    }else{
        return 1;
    }
}

int associative_array::find(string name)
{
    int grade;
    int hashKey = hashingFunc(name);
    if(!A.at(hashKey).empty()){
        grade = A.at(hashKey).back().second;
        return grade;
    }else{
        return -1;
    }
}

bool associative_array::insert(string name, int grade)
{
    A.at(hashingFunc(name)).push_back(make_pair(name, grade));
    
    return 1;
}

void associative_array::userInteractionForInsert()
{
    cout << "Insertion:" << endl << endl;
    string name;
    int grade;
    cout << "Please enter the name of the student you want to enter " << endl;
    cin >> name;
    if(userExists(name)){
        cout << "The user already exists!" << endl;
    }else{
        cout << "Please enter the grade of the student" << endl;
        cin >> grade;
        while(grade < 0 || grade > 100){
            cout << "Please enter the grade of the student again, it must be between 0-100 " << endl;
            cin >> grade;
        }
        cout << endl;
        insert(name, grade);
        sizeIndex++;
    }
}

void associative_array::userInteractionForFind()
{
    cout << "Finding:" << endl << endl;
    string name;
    cout << "Please enter the name of the student you want to find " << endl;
    cin >> name;
    if(find(name) == -1){
        cout << "ERROR! Student does not exist on the system!" << endl;
    }else{
        cout << name << ": " << find(name) << endl;
    }
    cout << endl;
}

int associative_array::hashingFunc(string name)
{
    int hashNum = 0;
    for(int i = 0; i < name.length(); i++){
        hashNum += ((int)name[i]);
    }
    hashNum = hashNum%1000;
    
    return hashNum;
}

void associative_array::printList()
{
        if(!A.empty()){
            cout << endl << endl << "Name and Grade List: " << endl << endl;
            for(int i = 0; i < 1000; i++){
            if(!A.at(i).empty()){
                cout << "Name: " << A.at(i).back().first << "  Grade: " << A.at(i).back().second << endl;
                }
            }
            cout << endl << "The size of the list is " << sizeIndex << " Student/s" << endl << endl;
        }else{
            cout << "There is no students in the list, please insert student!" << endl;
    }
}

void associative_array::deletePair(string name)
{
    A.at(hashingFunc(name)).pop_back();
    sizeIndex--;
}

void associative_array::userInteractionForDelete()
{
    cout << "Deletion:" << endl << endl;
    string name;
    cout << "Please enter tha name of the student you want to delete " << endl;
    cin >> name;
    if(!userExists(name)){
        cout << endl << "Cannot delete the student because the student is not on the system!" << endl;
    }else{
        deletePair(name);
        cout << endl << "The student " << name << " has been deleted!" << endl;
    }
}

int associative_array::size()
{
    return sizeIndex;
}

bool associative_array::is_empty()
{
    if (sizeIndex == 0){
        return 1;
    }else{
        return 0;
    }
}

associative_array::~associative_array()
{
}
