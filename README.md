# Welcome
A real-time visualization tool that demonstrates how the Heapsort algorithm organizes data, built with C++ and SDL2.

## About
This project is part of a series visualizing different sorting algorithms. Watching algorithms sort data in real-time helps bridge the gap between theoretical understanding and practical implementation—seeing Heapsort build and manipulate a heap structure makes the algorithm's mechanics much clearer than reading about it alone.

Through developing this visualization, I:
- Gained a deeper understanding of how Heapsort works internally
- Improved my ability to translate algorithm logic into visual representations
- Learned to use SDL2 for rendering graphics in C++

I hope this tool helps other students grasp sorting algorithms more intuitively, especially those who learn better through visual demonstrations.

## Features
- Real-time visualization of the heap sort algorithm
- Interactive display showing each step of the sorting process
- Highlighted elements to track current operations
- Smooth animations with customizable delay
- Random data generation for varied demonstrations

## 🔍 How Heapsort Works

Heapsort is a comparison-based sorting algorithm that uses a binary heap data structure. The algorithm consists of two main phases:

### Phase 1: Build Max Heap
1. Convert the unsorted array into a max heap (parent ≥ children)
2. Start from the last non-leaf node and heapify downward
3. Ensure the heap property is maintained throughout

### Phase 2: Extract Elements
1. Swap the root (maximum element) with the last element
2. Reduce heap size by one
3. Heapify the root to restore the heap property
4. Repeat until the heap is empty

### Tech Used
- **C++**
- **SDL2**

### Time Complexity

- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)


### Watch the inspiration video!
<a href="https://www.youtube.com/watch?v=kPRA0W1kECg" target="_blank">
  <img src="https://img.youtube.com/vi/kPRA0W1kECg/maxresdefault.jpg" width="400"/></a>




&copy; 2025 GitHub &bull; [Code of Conduct](https://www.contributor-covenant.org/version/2/1/code_of_conduct/code_of_conduct.md)
