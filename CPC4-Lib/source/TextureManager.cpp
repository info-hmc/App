#include "TextureManager.h"

Texture2D TextureManager::CreateTexture(const std::string& filename, bool Critical) {
    for (auto& managedTexture : textures) {
        if (managedTexture.filename == filename) {
            return managedTexture.texture;
        }
    }
    
    if (textures.size() <= MAX_TEXTURES) {
        Texture2D newTexture = LoadTexture(filename.c_str());
        textures.push_back({filename, newTexture});
        if (newTexture.id == 0 && Critical)
        {
            exit(-1);
        }
        return newTexture;
    } else {
        // Handle max texture error
        exit(-1);  // Or any other method of handling
    }
}

void TextureManager::SetFilterForAllTextures(int filterMode) {
    for (auto& managedTexture : textures) {
        SetTextureFilter(managedTexture.texture, filterMode);
    }
}

void TextureManager::CleanupAll() {
    for (auto& managedTexture : textures) {
        UnloadTexture(managedTexture.texture);
    }
    textures.clear();
}

void TextureManager::CleanupTexture(const Texture2D& texture) {
    for (auto it = textures.begin(); it != textures.end(); ++it) {
        if (it->texture.id == texture.id) {
            UnloadTexture(it->texture);
            textures.erase(it);
            break;
        }
    }
}