#pragma once
using namespace std;
#include <array>
#include <list>
#include <utility>
#include <string.h>

class associative_array
{
private:
    array<list<pair<string,int> >, 1000> A;
    int find(string);
    bool insert(string, int);
    void deletePair(string);
    int hashingFunc(string);
    int sizeIndex;
    bool userExists(string);
public:
	associative_array();
    void userInteractionForInsert();
    void userInteractionForFind();
    void userInteractionForDelete();
	void printList();
    int size();
    bool is_empty();
	~associative_array();
};

