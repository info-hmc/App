#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "raylib.h"
#include <string>
#include <vector>

#define MAX_TEXTURES 256

class TextureManager {
public:
    struct ManagedTexture {
        std::string filename;
        Texture2D texture;
    };

    // Checks if texture exsists and returnes else it creates new texture
    Texture2D CreateTexture(const std::string& filename, bool Critical = false);

    // Sets the filtering mode for all loaded textures
    void SetFilterForAllTextures(int filterMode);

    // Cleans up all loaded textures
    void CleanupAll();

    // Cleans up a specific texture
    void CleanupTexture(const Texture2D& texture);

private:
    std::vector<ManagedTexture> textures;
};

#endif  // TEXTURE_MANAGER_H
