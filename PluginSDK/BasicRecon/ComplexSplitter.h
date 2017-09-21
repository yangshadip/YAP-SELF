#pragma once

#ifndef ComplexSplitter_h__20160813
#define ComplexSplitter_h__20160813

#include "Implement/ProcessorImpl.h"
#include "Client/DataHelper.h"

namespace Yap
{
	class ComplexSplitter :public ProcessorImpl
	{
		IMPLEMENT_SHARED(ComplexSplitter)
	public:
		ComplexSplitter();
		ComplexSplitter(const ComplexSplitter& rhs);

	protected:
		~ComplexSplitter();

		virtual bool Input(const wchar_t * port, IData * data) override;

		void Split(std::complex<double> * data, double * real, double * imaginary, size_t size);
		void ExtractReal(std::complex<double> * data, double * real, size_t size);
		void ExtractImaginary(std::complex<double> * data, double * imaginary, size_t size);
	};
}
#endif // ComplexSplitter_h__
