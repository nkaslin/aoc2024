#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <vector>
#include <cstdint> // For uint8_t
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>


void saveGridToPNG(const std::vector<std::vector<int>>& grid, const std::string& filename) {
    int height = grid.size();
    int width = height > 0 ? grid[0].size() : 0;

    // Create a flat array for the image data (1 channel, grayscale)
    std::vector<uint8_t> imageData(height * width);

    // Convert grid values to grayscale image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            imageData[y * width + x] = grid[y][x] == 0 ? 255 : 0;
        }
    }

    // Write the PNG file
    if (!stbi_write_png(filename.c_str(), width, height, 1, imageData.data(), width)) {
        throw std::runtime_error("Failed to write PNG file");
    }
}

int main() {
    std::vector<std::vector<int>> grid = {{1, 2}, {0, 1}};

    try {
        saveGridToPNG(grid, "grid.png");
        std::cout << "PNG saved as 'grid.png'." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
