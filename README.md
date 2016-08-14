# ZipTree

##Optimized binary heap for managing heap memory

ZipTree is an optimized binary heap for managing heap memory. ZipTree can keep nodes in-order for two 
parameters at the same time (address & size). First, the heap has to search for a valid memory chunk which satisfies the requested size and allocate more 
memory segment from the system if the requested chunk is not available. Second, the heap also has to free memory 
efficiently. ZipTree behaves like a binary search tree to keep its nodes in-order by chunk address. So the heap can easily find its neighbored 
chunks within amortized logN time and if the nodes are consecutive in address they can be merged easily. 
This characteristics provides additional benefit by keeping tree depth within reasonable level while 
minimizing fragmentation within heap. ZipTree also improves cache hit rate and overall memory usage efficiency.


##### Copyright © 2016 HyperCryptic Solutions, LLC. All rights reserved.
