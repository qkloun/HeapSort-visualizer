#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <vector>

// Function to draw the state of the array
void draw_state(std::vector<int>& v, SDL_Renderer* renderer, int highlighted) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i == highlighted) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue for the highlighted bar
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black for normal bars
        }

        SDL_RenderDrawLine(renderer, index, 0, index, 99 - v[i]);
        index += 1;
    }
    SDL_RenderPresent(renderer);
}

// Function to heapify a subtree rooted at index i
void heapify(std::vector<int>& v, int n, int i, SDL_Renderer* renderer, bool& running) {
    int largest = i;   // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && v[left] > v[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && v[right] > v[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        std::swap(v[i], v[largest]);

        // Visualize the current state of the array
        draw_state(v, renderer, largest);
        SDL_Delay(50);

        // Handle SDL events to allow window closure
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
                return;
            }
        }

        // Recursively heapify the affected sub-tree
        heapify(v, n, largest, renderer, running);
    }
}

// Function to perform heap sort
void heap_sort(std::vector<int>& v, SDL_Renderer* renderer, bool& running) {
    int n = v.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i, renderer, running);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        std::swap(v[0], v[i]);

        // Visualize the current state of the array
        draw_state(v, renderer, i);
        SDL_Delay(50);

        // Handle SDL events to allow window closure
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
                return;
            }
        }

        // call max heapify on the reduced heap
        heapify(v, i, 0, renderer, running);
    }
}

int main() {
    std::random_device rd;
    std::uniform_int_distribution<> d(1, 99);

    std::vector<int> v;
    for (int i = 0; i < 100; i++) {
        v.push_back(d(rd));
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Heap Sort Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_RenderSetScale(renderer, 5, 5);

    bool running = true;
    heap_sort(v, renderer, running);

    // Keep the window open after sorting is complete
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
