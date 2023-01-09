#include<iostream>
#include<math.h>

using namespace std;

class MinHeap
{
    public:
      int *harr;        //pointer to array of elements in heap
      int capacity;     //maximum possible size of min heap
      int heap_size;    //Current number of elements in min heap

      MinHeap(int cap)
      {
          heap_size = 0;
          capacity =  cap;
          harr = new int[cap];
      }

      void LinearSearch(int val)
      {
          for(int i=0; i<heap_size; i++)
          {
              if(harr[i] == val)
              {
                  cout<<"\nValue Found";
                  return;
              }
          }
          cout<<"\nValue NOT Found";
      }

      void PrintArray()
      {
          cout<<"\n";
          for(int i=0; i<heap_size; i++)
            cout<<harr[i]<<" ";
      }

      int Height()
      {
          return ceil(log2(heap_size + 1)) - 1;
      }
      
      int Parent(int i)
      {
          return (i-1)/2;
      }

      void InsertElement()
      {
          cout<<"\nEnter the an element to be into Min Heap:";
          int k;
          cin>>k;

          if(heap_size == capacity)
          {
              cout<<"\nOverflow: Heap full";
              return;
          }
          heap_size++;
          int i = heap_size - 1;
          harr[i] = k;
          while (i != 0 && harr[Parent(i)] > harr[i])
          {
              swap(harr[i], harr[Parent(i)]);
              i = Parent(i);
          }

          cout<<"\nThe Min Heap is:";
          PrintArray();
      }

      void MinHeapifY(int i)
      {
          int l = 2*i+1;
          int r = 2*i+2;
          int smallest = i;
          if(l < heap_size && harr[l] < harr[i])
            smallest = l;
          if(r < heap_size && harr[r] < harr[i])
            smallest = r;
          if(smallest != i)
          {
              swap(harr[i], harr[smallest]);        //When the value being checked is not the smallest, then swap with smallest child
              MinHeapifY(smallest);     //Checking if the children of the swapped element are also in Min Heap
          }
        
      }

      int ExtractMin()
      {
          if(heap_size <= 0)
            return INT8_MAX;
          
          if(heap_size == 1) 
          {
              heap_size--;
              return harr[0];
          }

          int root = harr[0];
          harr[0] = harr[heap_size - 1];
          heap_size--;
          MinHeapifY(0);
          return root;
      }

      void DecreaseKey(int i, int new_val)
      {
          harr[i] = new_val;
          while(i != 0 && harr[Parent(i)] > harr[i])
          {
              swap(harr[i], harr[Parent(i)]);
              i = Parent(i);
          }
      }

      void DeleteKey(int i)
      {
          DecreaseKey(i, INT16_MIN);
          ExtractMin();
      }
      
};

int main()
{
    int s;
    cout<<"\nEnter size of Min Heap:";
    cin>>s;
    MinHeap obj(s);

    obj.InsertElement();
    obj.InsertElement();
    obj.InsertElement();
    // obj.InsertElement();
    // obj.InsertElement();

    cout<<"\nExtracted Minimum from Heap is:"<<obj.ExtractMin();
    cout<<"\nResulting Heap:";
    obj.PrintArray();

    return 0;
}