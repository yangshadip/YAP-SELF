#pragma once
#include "Implement/ProcessorImpl.h"
#include "Implement/DataObject.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImageFileReader.h"
#include "itkImageIOBase.h"
#include "itkImage.h"
#include "Implement/LogUserImpl.h"
#include <string>
#include <iostream>
#include <atlconv.h>
#include <fstream>

#define ReaderUpdate(type_s,dim,type_img,type_reader,type_io,io_pointer,reader_pointer)\
typedef itk::Image< type_s, dim > type_img;\
typedef itk::ImageFileReader< type_img > type_reader;\
typedef itk::GDCMImageIO type_io;\
type_reader::Pointer reader_pointer = type_reader::New();\
type_io::Pointer io_pointer = type_io::New();\
reader_pointer->SetImageIO(io_pointer);\
reader_pointer->SetFileName(W2A(GetProperty<const wchar_t * const>(L"DataPath")));\
reader_pointer->Update();
#define Feedout(type_s,datalength,temp_pointer,dims,reader_pointer)\
temp_pointer = new type_s[datalength];\
memcpy(temp_pointer, reader_pointer->GetOutput()->GetBufferPointer(), datalength * sizeof(type_s));\
auto outputdata = CreateData<type_s>(nullptr, (type_s*)temp_pointer, dims, nullptr, true);\
Feed(L"Output", outputdata.get()); 
//
typedef itk::ImageIOBase::IOComponentType ComponentType;
namespace Yap
{
	class DicomReader : public  ProcessorImpl
	{
		IMPLEMENT_SHARED(DicomReader)
	public:
		DicomReader();
		DicomReader(const DicomReader& rhs);
	protected:
		~DicomReader();
		virtual bool Input(const wchar_t * name, IData * data) override;
	};
}
