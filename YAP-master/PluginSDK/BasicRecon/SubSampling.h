
#include "Implement/ProcessorImpl.h"

namespace Yap
{
	class SubSampling :
		public ProcessorImpl
	{
		IMPLEMENT_SHARED(SubSampling)
	public:
		SubSampling();
		SubSampling(const SubSampling& rhs);

	protected:
		~SubSampling();

		virtual bool Input(const wchar_t * port, IData * data) override;

		void GetSubSampledData(std::complex<float> * input_data, float * mask, std::complex<float> * output_data, unsigned int width, unsigned int height);

	private:
		SmartPtr<IData> _mask;

	};
}