/* 
    File: my_allocator.h

    Original Author: R.Bettati
            Department of Computer Science
            Texas A&M University
    Date  : 08/02/08

    Modified:

*/

#ifndef _BuddyAllocator_h_                   // include file only once
#define _BuddyAllocator_h_
#include <iostream>
using namespace std;
typedef unsigned int uint;

/* declare types as you need */

class BlockHeader{
	bool isFree;
	int size;
	BlockHeader* next;


	// decide what goes here
	// hint: obviously block size will go here
};

class LinkedList{
	// this is a special linked list that is made out of BlockHeader s. 
		// you need a head of the list
public:
	BlockHeader* head;

	
	void insert (BlockHeader* b){	// adds a block to the list
		if(head== nullptr)
		{
			head=b;
		}
		else
		{
	
			while(head->next != nullptr)
			{
				head=head->next;
			}
			head->next=b;
			b->next=nullptr;
		}

	}

	void remove (BlockHeader* b){  // removes a block from the list
		if(head == nullptr)
			cerr << "Error"
		else if(head == b)
		{
			head=b->next;
			b->next=nullptrl
		}
		else
		{
			while(head->next !=b)
			{
				head=head-> next;
			}
			head->next=head->next->next;
			b->next=nullptr;

		}

		
	}
};


class BuddyAllocator{
private:
	/* declare member variables as necessary */
    char* memPtr;
    uint bbs; //basic block size
    unit tml; //Totaly memory
    vector<LinkedList> memList;



private:
	/* private function you are required to implement
	 this will allow you and us to do unit test */
	
	char* getbuddy (char * addr)
	{
		return ((addr-memPtr)^(((BlockHeader*) addr)->size) + memPtr;
	}
	// given a block address, this function returns the address of its buddy 
	
	bool isvalid (char *addr);
	// Is the memory starting at addr is a valid block
	// This is used to verify whether the a computed block address is actually correct 

	bool arebuddies (char* block1, char* block2);
	// checks whether the two blocks are buddies are not
	

	char* merge (char* block1, char* block2)
	{
		BlockHeader* blk1;
		BlockHeader* blk2;
		if(block1<block2)
		{
			blk1=(BlockHeader*) block2;
			blk2=(BlockHeader*) block1;
		}
		else
		{
			blk1=(BlockHeader*) block1;
			blk2=(BlockHeader*) block2;
		}
		int loc = log2(_total_memory_length)-log2(blk2->size;

		memList.at(loc).remove(blk1);
		memList.at(loc).remove(blk2);
		blk1->size=blk1->size*2;
		blk1->free=true;
		memList.at(loc).insert(blk1);
	}
	// this function merges the two blocks returns the beginning address of the merged block
	// note that either block1 can be to the left of block2, or the other way around

	char* split (char* block)
	{
		
		block->size = (block->size/2);

		BlockHeader* blk2=(block+block->size);
		blk2->size=block->size;
		int pos=log2(_total_memory_length)-log2(block->size*2)
		memList.at(pos).remove(block);
		memList.at(pos+1).insert(block);
		memList.at(pos+1).insert(blk2);

		return block;

	}
	// splits the given block by putting a new header halfway through the block
	// also, the original header needs to be corrected


public:
	BuddyAllocator (uint _basic_block_size, uint _total_memory_length); 
	/* This initializes the memory allocator and makes a portion of 
	   ’_total_memory_length’ bytes available. The allocator uses a ’_basic_block_size’ as 
	   its minimal unit of allocation. The function returns the amount of 
	   memory made available to the allocator. If an error occurred, 
	   it returns 0. 
	*/ 

	~BuddyAllocator(); 
	/* Destructor that returns any allocated memory back to the operating system. 
	   There should not be any memory leakage (i.e., memory staying allocated).
	*/ 

	char* Myalloc(uint _length); 
	/* Allocate _length number of bytes of free memory and returns the 
		address of the allocated portion. Returns 0 when out of memory. */ 

	int Myfree(char* _a); 
	/* Frees the section of physical memory previously allocated 
	   using ’my_malloc’. Returns 0 if everything ok. */ 
   
	void debug ();
	/* Mainly used for debugging purposes and running short test cases */
	/* This function should print how many free blocks of each size belong to the allocator
	at that point. The output format should be the following (assuming basic block size = 128 bytes):

	128: 5
	256: 0
	512: 3
	1024: 0
	....
	....
	 which means that at point, the allocator has 5 128 byte blocks, 3 512 byte blocks and so on.*/
};

#endif 
