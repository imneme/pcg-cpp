/*
 * Random Number Generation Example
 *
 * Copyright 2012-2014 cppreference.com Contributors
 * Copyright 2014 Melissa O'Neill <oneill@pcg-random.org>
 *
 * Code in this file is based on code from cppreference.com, specifically 
 * the sample code at http://en.cppreference.com/w/cpp/numeric/random
 * which is distributed under the Creative Commons Attribution-Share Alike
 * license.  You may distribute this file (and only this file) under
 * that license, see http://creativecommons.org/licenses/by-sa/3.0/.
 *
 * Also licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with a valid License.
 * You may obtain a copy of the Apache License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
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
 */
 
/*
 * Produce a histogram of a normal distribution.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

#include "pcg_random.hpp"
 
int main()
{
    // Seed with a real random value, if available
    pcg_extras::seed_seq_from<std::random_device> seed_source;
  
    // Make a random number engine 
    pcg32 rng(seed_source);

    // Choose a random mean between 1 and 6
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(rng);
    std::cout << "Randomly-chosen mean: " << mean << '\n';
 
    // Generate a normal distribution around that mean
    std::normal_distribution<> normal_dist(mean, 2);
    
    // Make a copy of the RNG state to use later
    pcg32 rng_checkpoint = rng;
 
    std::map<int, int> hist;
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::round(normal_dist(rng))];
    }
    std::cout << "Normal distribution around " << mean << ":\n";
    for (auto p : hist) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/30, '*')
                  << '\n';
    }
    
    std::cout << "Required " << (rng - rng_checkpoint) << " random numbers.\n";
}
