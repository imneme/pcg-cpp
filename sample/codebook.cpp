/*
 * PCG Random Number Generation for C++
 *
 * Copyright 2014 Melissa O'Neill <oneill@pcg-random.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * For additional information about the PCG random number generation scheme,
 * including its license and other licensing options, visit
 *
 *     http://www.pcg-random.org
 */

/*
 * Outputs a little spy codebook
 */

#include "pcg_random.hpp"
#include <cstdio>
#include <iostream>
#include <random>

int main()
{
    pcg32 rng(pcg_extras::seed_seq_from<std::random_device>{});
    std::clog << "RNG used: " << rng << "\n\n";
    
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
           printf("%03u ", rng(1000));
        }
        printf("\n");
    }
}

    
    