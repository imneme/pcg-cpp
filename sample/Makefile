# 
# PCG Random Number Generation for C++.
# 
# Copyright 2014 Melissa O'Neill <oneill@pcg-random.org>
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# 
# For additional information about the PCG random number generation scheme,
# including its license and other licensing options, visit
# 
#     http://www.pcg-random.org
#

TARGETS           = pcg-demo codebook cppref-sample make-partytrick
BINARYOUT_TARGETS = spew use-partytrick

CPPFLAGS += -I../include 
CXXFLAGS += -std=c++11 -O2
CC       = $(CXX)       # Cheat so that linking uses the C++ compiler

all: $(TARGETS)

posix-binaryoutput: spew use-partytrick

clean:
	rm -f *.o $(TARGETS) $(BINARYOUT_TARGETS)

codebook.o: codebook.cpp ../include/pcg_random.hpp \
  ../include/pcg_extras.hpp ../include/pcg_uint128.hpp
cppref-sample.o: cppref-sample.cpp ../include/pcg_random.hpp \
  ../include/pcg_extras.hpp ../include/pcg_uint128.hpp
make-partytrick.o: make-partytrick.cpp ../include/pcg_random.hpp \
  ../include/pcg_extras.hpp ../include/pcg_uint128.hpp
pcg-demo.o: pcg-demo.cpp ../include/pcg_random.hpp \
  ../include/pcg_extras.hpp ../include/pcg_uint128.hpp
spew.o: spew.cpp ../include/pcg_random.hpp ../include/pcg_extras.hpp \
  ../include/pcg_uint128.hpp
use-partytrick.o: use-partytrick.cpp ../include/pcg_random.hpp \
  ../include/pcg_extras.hpp ../include/pcg_uint128.hpp
