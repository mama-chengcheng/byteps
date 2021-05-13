// Copyright 2019 Bytedance Inc. or its affiliates. All Rights Reserved.
// Copyright 2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// =============================================================================

#ifndef BYTEPS_MXNET_ADAPTER_H
#define BYTEPS_MXNET_ADAPTER_H

#include <mxnet/base.h>
#include "../common/common.h"

namespace byteps {
namespace mxnet {

using namespace byteps::common;

template <class T>
class MXTensor : public Tensor {
 public:
  MXTensor(T* tensor);
  virtual const DataType dtype() const override;
  virtual const TensorShape shape() const override;
  virtual const void* data() const override;
  virtual int64_t size() const override;
  virtual void resize(const common::TensorShape&) override;

 protected:
  T* tensor_;
};

inline void ThrowIfError(const Status& status) {
  if (!status.ok()) {
    throw dmlc::Error(status.reason());
  }
}

}  // namespace mxnet
}  // namespace byteps

#endif  // BYTEPS_MXNET_ADAPTER_H
