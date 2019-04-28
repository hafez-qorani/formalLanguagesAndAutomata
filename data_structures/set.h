#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>

template <class T>
class Set{

    protected:
	// members of this set
	std::vector<T> members;


    public:
	Set(std::vector<T> members);

	// add item to this set
	void addMember(T);

	// does the intersection operation with another set
	/* Set intersect(Set); */

	// does the union opration with another set
	/* Set union(Set); */

	// multiply this set with the specified one
	/* Set multiply(Set); */	

	/* bool isMember(T); */
}

template <class T>
Set::Set(std::vector<T> items){
      
    bool item_found;


    // adding items to set members
    for(int i = 0; i < items.size(); i++){
	
	item_found = false;
	for(int j = 0; j < this->members.size(); j++){
	    // item[i] is already in the member of this set
	    if (members[j] == items[i]) item_found = true;
	}
	// making this item a member of this set
	if (!item_found) this->members.push_back(items[i]); 

    }

}

template <class T>
void Set::addMember(T item){
    
    bool item_found = false;
    for(int i = 0; i < this->members.size(); i++){
	if (members[i] == item) item_found = true;	 
    }
    if (!item_found) this->members.push_back(item);
}

#endif // SET_H
