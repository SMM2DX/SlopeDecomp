#pragma once

#include <cstdint>

namespace nn::util::neon {

struct MatrixRowMajor4x3fType {
    float m[4][3];
};

struct MatrixColumnMajor4x3fType {
    float m[3][4];
};

struct MatrixRowMajor4x4fType {
    float m[4][4];
};

struct MatrixColumnMajor4x4fType {
    float m[4][4];
};

}  // namespace nn::util::neon

namespace nn::util {

typedef uint32_t AngleIndex;

struct Float2 {
    union {
        float v[2];
        struct {
            float x;
            float y;
        };
    };
};

struct Float3 {
    union {
        float v[3];
        struct {
            float x;
            float y;
            float z;
        };
    };
};

struct Float4 {
    union {
        float v[4];
        struct {
            float x;
            float y;
            float z;
            float w;
        };
    };
};

struct FloatColumnMajor4x3 {
    float m[3][4];
};

struct Unorm8x4 {
    union {
        uint8_t v[4];
    };
};

typedef Unorm8x4 Color4u8Type;

typedef neon::MatrixRowMajor4x3fType Matrix4x3fType;
typedef neon::MatrixRowMajor4x4fType Matrix4x4fType;
typedef neon::MatrixColumnMajor4x3fType MatrixT4x3fType;
typedef neon::MatrixColumnMajor4x4fType MatrixT4x4fType;

}  // namespace nn::util
