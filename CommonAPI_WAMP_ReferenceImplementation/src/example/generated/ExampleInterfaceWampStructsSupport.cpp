
#include <example/generated/ExampleInterfaceWampStructsSupport.hpp>

namespace example {


// example for a struct that does NOT contain nested structs

Summands_internal transformSummands(const ExampleInterface::Summands &summands)
{
	return summands.values_;
}

ExampleInterface::Summands transformSummands(const Summands_internal &summands_internal)
{
	ExampleInterface::Summands summands;
	summands.values_ = summands_internal;
	return summands;
}


SumDiff_internal transformSumDiff(const ExampleInterface::SumDiff &sumDiff)
{
	return sumDiff.values_;
}

ExampleInterface::SumDiff transformSumDiff(const SumDiff_internal &sumDiff_internal)
{
	ExampleInterface::SumDiff sumDiff;
	sumDiff.values_ = sumDiff_internal;
	return sumDiff;
}


// example for a struct that contains nested structs

Params_internal transformParams(const ExampleInterface::Params &params)
{
	return Params_internal(
			transformSummands(params.getSs()),
			params.getX()
		);
}

ExampleInterface::Params transformParams(const Params_internal &params_internal)
{
	return ExampleInterface::Params(
			transformSummands(std::get<0>(params_internal)),
			std::get<1>(params_internal)
		);
}


} // namespace example
