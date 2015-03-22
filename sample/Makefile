# 
# PCG Random Number Generation for C++.
# 
# Copyright 2014 Melissa O'Neill <oneill@pcg-random.org>
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
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
