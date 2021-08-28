/* 
    File: my_allocator.cpp
*/
#include "BuddyAllocator.h"
#include <iostream>
using namespace std;


BuddyAllocator::BuddyAllocator (uint basic_block_size, uint total_memory_length)
{
  bbs=basic_block_size;
  tml=total_memory_length;
  memPtr=(char*) malloc(total_memory_length);


  Blockheader* firstBlock = (Blockheader*) startPtr;
  firstBlock->size=(total_memory_length);
  firstBlock->isFree=true;
  firstBlock->next=nullPtr;
  memList = new vector<LinkedList>();
  memList[0].insert(block_ptr);




}

BuddyAllocator::~BuddyAllocator ()
{
  	delete[] memList;
    free memPtr; 
}



char* BuddyAllocator::Myalloc(uint _length) 
{
  _length+= sizeof(Blockheader);

  uint allocSize=basic_block_size;

  while(allocSize<_length)
  {
    allocSize=allocSize*2;
  }
  uint pos= log2(total_memory_length)-log2(allocSize);

  if(memList.at(pos)->head==nullPtr)
  {
    while(memList.at(pos)->head==nullPtr)
    {
      if(pos==0)
        return nullPtr
      pos--;
    }
  }

  blocAlloc = (BlockHeader*) memList.at(loc)->head;
  if(blocAlloc->size==_length)
  {
    
  }
  else
  {
    while(blocAlloc=>size!=_length)
    {
     blocAlloc=(Blockheader*) split(blocAlloc); 
    }
  }

  memList.at(loc).remove(blocAlloc);

  return (char*) blocAlloc


  /* This preliminary implementation simply hands the call over the 
     the C standard library! 
     Of course this needs to be replaced by your implementation.
  */
  return new char [_length];
}

int BuddyAllocator::Myfree(char* _a) {
  /* Same here! */
  delete _a;
  return 0;
}

void BuddyAllocator::debug (){
  
}


char* getbuddy (char * addr)
{

}
  // given a block address, this function returns the address of its buddy 
  

char* merge (char* block1, char* block2)
{

}
  // this function merges the two blocks returns the beginning address of the merged block
  // note that either block1 can be to the left of block2, or the other way around
char* split (char* block)
{

}
// splits the given block by putting a new header halfway through the block
// also, the original header needs to be corrected
