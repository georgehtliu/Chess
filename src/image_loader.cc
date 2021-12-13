//
// Created by david on 12/12/21.
//

#include "image_loader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

XImage *load_image(std::string path, Xwindow *w) {
    int width, height, bpp;
    unsigned char* rgb_image = stbi_load(path.c_str(), &width, &height, &bpp, 4);

    XImage *img = XCreateImage(w->get_display(), w->get_visual(), DefaultDepth(w->get_display(), 0), ZPixmap, 0, reinterpret_cast<char *>(rgb_image), width, height, 16, 0);
    return img;
}

