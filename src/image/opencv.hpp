// Display images inside a terminal
// Copyright (C) 2023  JustKidding
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef __OPENCV_IMAGE__
#define __OPENCV_IMAGE__

#include "image.hpp"

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

class OpencvImage : public Image
{
public:
    OpencvImage(const std::string& filename, int max_width, int max_height);

    auto width() const -> int override;
    auto height() const -> int override;
    auto size() const -> unsigned long override;
    auto data() const -> const unsigned char* override;

    auto framerate() const -> int override;
    auto next_frame() -> void override;

private:
    cv::Mat image;
    cv::VideoCapture video;

    std::string filename;

    int _width;
    int _height;
    unsigned long _size;
    int max_width;
    int max_height;

    auto process_image() -> void;
};

#endif
