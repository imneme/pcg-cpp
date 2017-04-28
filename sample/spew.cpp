/*
 * PCG Random Number Generation for C++
 *
 * Copyright 2014 Melissa O'Neill <oneill@pcg-random.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * For additional information about the PCG random number generation scheme,
 * including its license and other licensing options, visit
 *
 *     http://www.pcg-random.org
 */

/*
 * This program outputs 215 GB of random bits (binary data).  This is
 * about the same as the total output of random.org in its 15 year history.
 * The code uses 1.25e-8 of the period, and chooses an arbitrary stream from 
 * 2^64 streams.
 *
 * Typical usage:
 *      ./spew | hexdump -C | less
 */

#include <cstdio>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <random>

#include <unistd.h>             // We use POSIX read/write for binary I/O

#include "pcg_random.hpp"

int main()
{
    pcg32_fast rng(pcg_extras::seed_seq_from<std::random_device>{});
    std::clog << rng << "\n\n";
    
    constexpr size_t BUFFER_SIZE = 1024ull * 128ull;
    uint32_t buffer[BUFFER_SIZE];
    constexpr size_t ROUNDS      = 215 * 1073741824ull / sizeof(buffer);
    
    for (size_t i = 0; i < ROUNDS; ++i) {
        for (auto& v : buffer)
            v = rng();
        write(1, (void*) buffer, sizeof(buffer));
    }
    return 0;
}

    
    