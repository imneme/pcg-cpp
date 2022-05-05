/*
 * This file is demonstrates how the non-extended PCG family can be reversed.
 */

#include <cstdint>
#include <iostream>
#include <random>

#include "pcg_random.hpp"

#define MULTIPLIER_CONSTANT(type,multiplier,constant)       \
        template <> struct Inverse<type,multiplier<type>> { \
          static constexpr type value = constant;           \
        };

template <typename itype, typename multiplier> struct Inverse {};

// Precomputed multiplicative inverses of the PCG multiplier constants
MULTIPLIER_CONSTANT(std::uint8_t, pcg_detail::default_multiplier, 69U)
MULTIPLIER_CONSTANT(std::uint16_t, pcg_detail::default_multiplier, 8245U)
MULTIPLIER_CONSTANT(std::uint32_t, pcg_detail::default_multiplier,
    3425435293U)
MULTIPLIER_CONSTANT(std::uint64_t, pcg_detail::default_multiplier,
    13877824140714322085ULL)
MULTIPLIER_CONSTANT(pcg_extras::pcg128_t, pcg_detail::default_multiplier,
    PCG_128BIT_CONSTANT(566787436162029664ULL, 11001107174925446285ULL))
MULTIPLIER_CONSTANT(pcg_extras::pcg128_t, pcg_detail::cheap_multiplier,
    PCG_128BIT_CONSTANT(924194304566127212ULL, 10053033838670173597ULL))

/// Wrapper class that implements the reverse of the PCG function-call operator
/// (`previous`). This is done by subclassing a PCG configuration which gives
/// access to the protected internal `state_` and `output` permutation. The PCG
/// random number generator is then reversed by inverting ("unbumping") the LCG
/// transformation on its internal state and reapplying the output function.
template <typename EngineType = pcg64>
class ReversiblePCG : public EngineType {
 public:
  using typename EngineType::result_type;

  // Inherit constructors
  using EngineType::EngineType;

  // Equivalent to `(*this)()`
  result_type next() { return EngineType::operator()(); }

  // Inverse of `next`
  result_type previous() {
    if constexpr (ExtractPCG<EngineType>::output_previous) {
      return EngineType::output(base_ungenerate0());
    }

    return EngineType::output(base_ungenerate());
  }
 protected:
  using typename EngineType::state_type;

  // Inverse of the PCG `engine::bump` state transition function (LCG)
  state_type unbump(state_type state) const {
    constexpr state_type inverse = ExtractPCG<EngineType>::multiplier_inverse;
    return (state - EngineType::increment()) * inverse;
  }

  // Inverse of the PCG `engine::base_generate` function
  state_type base_ungenerate() {
    const state_type old_state = EngineType::state_;
    EngineType::state_ = unbump(old_state);
    return old_state;
  }

  // Inverse of the PCG `engine::base_generate0` function
  state_type base_ungenerate0() {
    return EngineType::state_ = unbump(EngineType::state_);
  }
 private:
  template <typename T>
  struct ExtractPCG;

  /// Gives access to the the `engine` template parameter that determines if
  /// the LCG state value is updated before the output permutation, and the
  /// precomputed multiplier inverses.
  template <typename xtype, typename itype, typename output,
            bool previous, typename stream, typename multiplier>
  struct ExtractPCG<pcg_detail::engine<xtype, itype, output, previous, stream, multiplier>> {
    static constexpr bool output_previous = previous;
    static constexpr itype multiplier_inverse = Inverse<itype, multiplier>::value;
  };
};

int main() {
  ReversiblePCG<pcg32> rng(pcg_extras::seed_seq_from<std::random_device>{});

  const int n = 8;
  for (int i = 0; i < n; ++i) {
    std::cout << rng.next() << ' ';
  }
  std::cout << std::endl;

  for (int i = 0; i < n; ++i) {
    std::cout << rng.previous() << ' ';
  }
  std::cout << std::endl;
}
