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

#ifndef SIXEL_WINDOW_H
#define SIXEL_WINDOW_H

#include "window.hpp"

#include <memory>
#include <mutex>
#include <vector>
#include <thread>
#include <atomic>

#include <sixel.h>

class Image;

class Sixel : public Window
{
public:
    Sixel(std::unique_ptr<Image> new_image, std::shared_ptr<std::mutex> stdout_mutex);
    ~Sixel() override;

    void draw() override;
    void generate_frame() override;

private:
    std::unique_ptr<Image> image;
    std::shared_ptr<std::mutex> stdout_mutex;

    std::string str;
    std::thread draw_thread;
    std::atomic<bool> can_draw {true};
    
    int x;
    int y;
    int horizontal_cells = 0;
    int vertical_cells = 0;

    sixel_dither_t *dither = nullptr;
    sixel_output_t *output = nullptr;
};

#endif

