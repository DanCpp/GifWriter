#include <cstdint>
#include <gif.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#define COUNTOFIMG 2

std::vector<uint8_t> GetImg(std::string filename)
{
    std::ifstream read(filename, std::ios_base::binary);
    std::vector<uint8_t> out;
    if (read.is_open())
    {
        while (!read.eof())
        {
            uint8_t byte;
            read >> byte;
            out.push_back(uint8_t(byte));
        }
    }
    else
    {
        exit(1);
    }
    return out;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int width = 104,
        height = 302,
        delay = 100;
    std::string filename = "NYTree.gif";
    const std::string extension = ".bmp";
#ifdef COUNTOFIMG
    GifWriter G_Writer;
    GifBegin(&G_Writer, filename.c_str(), width, height, delay);
    for (int i = 1; i <= COUNTOFIMG; i++)
    {
        std::vector<uint8_t> frame;
        frame = GetImg("Trees/Tree_" + std::to_string(i) + extension);
        std::reverse(frame.begin(), frame.end());
        GifWriteFrame(&G_Writer, frame.data(), width, height, delay);
    }
    GifEnd(&G_Writer);
#else //COUNTOFIMG
    std::cout << "Cannot understand how many frames there are.";
    system("sleep");
    exit(1);
#endif //COUNTOFIMG
	
	return 0;
}