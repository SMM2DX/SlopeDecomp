/**
 * @brief JPEG decoding library.
 */

#pragma once

#include <cstdint>

namespace nn::image {
// there's probably more
enum JpegStatus {
    OK = 0,
    INVALID_FORMAT = -32,
    UNSUPPORTED_FORMAT = -33,
    OUT_OF_MEMORY = -64,
};

enum PixelFormat { RGBA32, RGB24 };

enum ProcessStage { UNREGISTERED = 0, REGISTERED = 1, ANALYZED = 2 };

struct Dimension {
    float width;
    float height;
};

class JpegDecoder {
public:
    JpegDecoder();
    virtual ~JpegDecoder();

    void SetImageData(void const* source, uint64_t size);
    nn::image::JpegStatus Analyze();
    nn::image::Dimension GetAnalyzedDimension() const;
    int64_t GetAnalyzedWorkBufferSize() const;
    JpegStatus Decode(void* out, uint64_t, int32_t alignment, void*, uint64_t);

    nn::image::ProcessStage mProcessStage;  // _8
    void* mData;                            // _C
    int64_t mSize;                          // _14
    int32_t _18;
    nn::image::PixelFormat mFormat;  // _1C
    Dimension mImgDimensions;        // _20
    int64_t _28;
    // rest is related to EXIF processing
};
}  // namespace nn::image
