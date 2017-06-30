#ifndef EXAMPLE_Example_Interface_WAMP_StructsSupport_HPP_
#define EXAMPLE_Example_Interface_WAMP_StructsSupport_HPP_

#include <example/generated/ExampleInterface.hpp>


namespace example {


// example for a struct that does NOT contain nested structs

typedef std::tuple<uint64_t, uint64_t> Summands_internal;

extern Summands_internal transformSummands(const ExampleInterface::Summands &summands);

extern ExampleInterface::Summands transformSummands(const Summands_internal &summands_internal);


typedef std::tuple<uint64_t, uint64_t> SumDiff_internal;

extern SumDiff_internal transformSumDiff(const ExampleInterface::SumDiff &sumDiff);

extern ExampleInterface::SumDiff transformSumDiff(const SumDiff_internal &sumDiff_internal);


// example for a struct that contains nested structs

typedef std::tuple<Summands_internal, uint64_t> Params_internal;

extern Params_internal transformParams(const ExampleInterface::Params &params);

extern ExampleInterface::Params transformParams(const Params_internal &params_internal);


} // namespace example

#endif // EXAMPLE_Example_Interface_WAMP_StructsSupport_HPP_
