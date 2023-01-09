cout<<order<<"\n";
    printV(inventory);
    long profit = 0;
    
    make_heap(inventory.begin(), inventory.end());
    for(int i = 0; i < order; i++)
    {
        long maxNow = inventory.front();
        profit += maxNow;
        
        pop_heap(inventory.begin(), inventory.end());
        inventory.pop_back();
        
        inventory.push_back(maxNow-1);
        push_heap(inventory.begin(), inventory.end());
    }
    return profit;