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

#ifndef UTIL_PTR_H
#define UTIL_PTR_H

#include <memory>

template <auto fn>
struct deleter_from_fn {
    template <typename T>
    constexpr void operator()(T* arg) const {
        fn(const_cast<std::remove_const_t<T>*>(arg));
    }
};

template <auto fn>
struct deleter_from_fn_null {
    template <typename T>
    constexpr void operator()(T* arg) const {
        if (arg != nullptr) {
            fn(const_cast<std::remove_const_t<T>*>(arg));
        }
    }
};

// custom unique pointer
template <typename T, auto fn>
using c_unique_ptr = std::unique_ptr<T, deleter_from_fn<fn>>;

// custom unique pointer that checks for null before deleting
template <typename T, auto fn>
using cn_unique_ptr = std::unique_ptr<T, deleter_from_fn_null<fn>>;


template <typename T>
using unique_C_ptr = std::unique_ptr<T, deleter_from_fn<std::free>>;

#endif
