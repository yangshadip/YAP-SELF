#include "DicomReader.h"

Yap::DicomReader::DicomReader(void):
	ProcessorImpl(L"DicomReader")
{
	AddInput(L"Input", 0, DataTypeUnknown);
	AddProperty<const wchar_t * const>(L"DataPath", L"D:\\", L"包含原始数据文件的文件夹。");
	AddProperty<bool>(L"IsDirectory", true, L"读取单个文件或文件夹");
	AddOutput(L"Output", 2, DataTypeAll);
}


Yap::DicomReader::DicomReader(const DicomReader & rhs):
	ProcessorImpl(rhs)
{
}

Yap::DicomReader::~DicomReader()
{

}

bool Yap::DicomReader::Input(const wchar_t * name, IData * data)
{
	assert(data == nullptr);
	if (name == nullptr)
		return false;
	USES_CONVERSION;


	std::ofstream file("test.txt");
	file << "Processor Start!" << std::endl;
	ReaderUpdate(unsigned char, 2,ImgType,ReaderType,ImgIOType,gdcmIO,reader);

	auto width = gdcmIO->GetDimensions(0);
	auto height = gdcmIO->GetDimensions(1);
	auto datalength = width*height;
	auto datatype = gdcmIO->GetComponentType();
	Dimensions dimensions;
	dimensions(DimensionReadout, 0U, width)
		(DimensionPhaseEncoding, 0U, height);
	void* temp = nullptr;
	if (datatype == ComponentType::UNKNOWNCOMPONENTTYPE)
	{
	}
	else if (datatype == ComponentType::UCHAR)
	{
		ReaderUpdate(unsigned char, 2, ImgType, ReaderType, ImgIOType, gdcmIO, reader);
		Feedout(unsigned char, datalength, temp, dimensions, reader);
	}
	else if (datatype == ComponentType::CHAR)
	{
		ReaderUpdate(char, 2, ImgType, ReaderType, ImgIOType, gdcmIO, reader);
		Feedout(char, datalength, temp, dimensions, reader);
	}
	else if (datatype == ComponentType::USHORT)
	{
		ReaderUpdate(unsigned short, 2, ImgType, ReaderType, ImgIOType, gdcmIO, reader);
		Feedout(unsigned short, datalength, temp, dimensions, reader);
	}
	else if (datatype == ComponentType::SHORT)
	{
		ReaderUpdate(short, 2, ImgType, ReaderType, ImgIOType, gdcmIO, reader);
		Feedout(short, datalength, temp, dimensions, reader);
	}
	else if (datatype == ComponentType::UINT)
	{
		ReaderUpdate(unsigned int, 2, ImgType, ReaderType, ImgIOType, gdcmIO, reader);
		Feedout(unsigned int, datalength, temp, dimensions, reader);
	}
	else if (datatype == ComponentType::INT)
	{
		ReaderUpdate(int, 2, ImgType, ReaderType, ImgIOType, gdcmIO, reader);
		Feedout(int, datalength, temp, dimensions, reader);
	}
	else if (datatype == ComponentType::ULONG)
	{
		ReaderUpdate(unsigned long, 2, ImgType, ReaderType, ImgIOType, gdcmIO, reader);
		/*Feedout(unsigned long, datalength, temp, dimensions, reader);*/
	}
	else if (datatype == ComponentType::LONG)
	{
		ReaderUpdate(long, 2, ImgType, ReaderType, ImgIOType, gdcmIO, reader);
		/*Feedout(long, datalength, temp, dimensions, reader);*/
	}
	else if (datatype == ComponentType::FLOAT)
	{
		ReaderUpdate(float, 2, ImgType, ReaderType, ImgIOType, gdcmIO, reader);
		Feedout(float, datalength, temp, dimensions, reader);
	}
	else if (datatype == ComponentType::DOUBLE)
	{
		ReaderUpdate(double, 2, ImgType, ReaderType, ImgIOType, gdcmIO, reader);
		Feedout(double, datalength, temp, dimensions, reader);
	}
	
	return true;

	//bool IsDirectory = GetProperty<bool>(L"IsDirectory");
	//if (IsDirectory)
	//{
	//	
	//}
	//else
	//{
	//	Feed(L"Output", output_data.get());
	//}
	return true;
}
