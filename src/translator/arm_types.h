#pragma once
#include <array>
#include <variant>

#include <types.h>
namespace nuclear::translator {
    using RegisterInt = u64;
    using Vector = std::array<f64, 2>;

    using Scalar = std::variant<f32, f64, Vector>;
}