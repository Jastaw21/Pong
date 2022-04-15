#pragma once

#include "Ball.h"
#include "CppUnitTest.h"
#include "CppUnitTestAssert.h"
#include "Location.h"

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework {
// bounds enum to str
template <>
inline std::wstring ToString<Bounds>(const Bounds& t) {
  auto sting = static_cast<int>(t);
  RETURN_WIDE_STRING(sting);
}
}  // namespace CppUnitTestFramework
}  // namespace VisualStudio
}  // namespace Microsoft
