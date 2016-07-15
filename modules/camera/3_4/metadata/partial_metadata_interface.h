/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef V4L2_CAMERA_HAL_METADATA_PARTIAL_METADATA_INTERFACE_H_
#define V4L2_CAMERA_HAL_METADATA_PARTIAL_METADATA_INTERFACE_H_

#include <vector>

#include <hardware/camera3.h>

namespace v4l2_camera_hal {

// A subset of metadata.
class PartialMetadataInterface {
 public:
  virtual ~PartialMetadataInterface(){};

  // The metadata tags this partial metadata is responsible for.
  // See system/media/camera/docs/docs.html for descriptions of each tag.
  virtual const std::vector<int32_t>& StaticTags() = 0;
  virtual const std::vector<int32_t>& ControlTags() = 0;
  virtual const std::vector<int32_t>& DynamicTags() = 0;

  // Add all the static properties this partial metadata
  // is responsible for to |metadata|.
  virtual int PopulateStaticFields(camera_metadata_t** metadata) = 0;
  // Add all the dynamic states this partial metadata
  // is responsible for to |metadata|.
  virtual int PopulateDynamicFields(camera_metadata_t** metadata) = 0;
  // Check if the requested control values from |metadata| (for controls
  // this partial metadata owns) are supported.
  virtual bool SupportsRequestValues(const camera_metadata_t* metadata) = 0;
  // Set all the controls this partial metadata
  // is responsible for from |metadata|.
  virtual int SetRequestValues(const camera_metadata_t* metadata) = 0;
};

}  // namespace v4l2_camera_hal

#endif  // V4L2_CAMERA_HAL_METADATA_PARTIAL_METADATA_INTERFACE_H_
