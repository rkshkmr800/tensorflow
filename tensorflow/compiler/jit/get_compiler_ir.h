/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_COMPILER_JIT_GET_COMPILER_IR_H_
#define TENSORFLOW_COMPILER_JIT_GET_COMPILER_IR_H_

#include "absl/strings/string_view.h"
#include "absl/types/span.h"
#include "tensorflow/compiler/xla/statusor.h"

namespace tensorflow {

class ProcessFunctionLibraryRuntime;
class Device;
class Tensor;

enum class IrExportStage { HLO, OPTIMIZED_HLO, OPTIMIZED_HLO_DOT };

// Returns HLO text for a given function `func_name` using library runtime
// `runtime` on a device `dev` with given `inputs`.
xla::StatusOr<std::string> GetCompilerIr(
    IrExportStage stage, ProcessFunctionLibraryRuntime* pflr,
    absl::string_view func_name, Device* dev,
    absl::Span<const Tensor* const> inputs);

}  // namespace tensorflow

#endif  // TENSORFLOW_COMPILER_JIT_GET_COMPILER_IR_H_