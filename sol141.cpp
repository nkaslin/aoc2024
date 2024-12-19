#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "template.h"

int N = 101; // 101 11
int M = 103; // 103 7

int steps = 100;

void saveGridToPNG(const std::vector<std::vector<int>>& grid, const std::string& filename) {
    int height = grid.size();
    int width = height > 0 ? grid[0].size() : 0;

    // Create a flat array for the image data (1 channel, grayscale)
    std::vector<uint8_t> imageData(height * width);

    // Convert grid values to grayscale image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            imageData[y * width + x] = grid[y][x] == 0 ? 0 : 255;
        }
    }

    // Write the PNG file
    if (!stbi_write_png(filename.c_str(), width, height, 1, imageData.data(), width)) {
        throw std::runtime_error("Failed to write PNG file");
    }
}

void vvprint(vvi& grid) {
    for (int i=0; i<grid.size(); i++) {
        vprint(grid[i]);
    }
    cout << "\n";
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("140.in");
    ofstream fout ("out.txt");
    
    string s;
    vi px, py, vx, vy;

    while (getline(fin, s)) {
        int pxVal, pyVal, vxVal, vyVal;

        istringstream lineStream(s);
        lineStream >> pxVal >> pyVal >> vxVal >> vyVal;

        px.pb(pxVal);
        py.pb(pyVal);
        vx.pb((vxVal + N) % N);
        vy.pb((vyVal + M) % M);
    }

    vvi grid(M, vi(N, 0));
    

    for (int step=0; step<10; step++) {
        for (int i=0; i<px.size(); i++) {
            grid[(py[i]+(step * vy[i])) % M][(px[i]+(step * vx[i])) % N]++;
        }

        try {
            ostringstream oss;
            oss << "141_plots/" << std::setfill('0') << std::setw(5) << step << ".png";
            string filename = oss.str();
            saveGridToPNG(grid, filename);
            filename.clear();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        for (int i=0; i<px.size(); i++) {
            grid[(py[i]+(step * vy[i])) % M][(px[i]+(step * vx[i])) % N]--;
        }
        

    }

    return 0;
}
