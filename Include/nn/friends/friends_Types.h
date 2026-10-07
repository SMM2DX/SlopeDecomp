#pragma once

namespace nn::friends {
struct Url {
    char m_Buffer[0xA0];
};

enum ImageSize {
    ImageSize_64x64 = 64,
    ImageSize_128x128 = 128,
    ImageSize_256x256 = 256,
    ImageSize_Standard = ImageSize_256x256,
};
}  // namespace nn::friends
