//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Copyright (c) 2018 NVIDIA Corporation. All rights reserved.



#ifndef PX_STREAM_FROM_FILE_BUF_H
#define PX_STREAM_FROM_FILE_BUF_H

/*!
\file
\brief Conversion utilities between PhysX 2.8 and 3.0 data types
*/

#include "ApexDefs.h"
#include "foundation/PxIO.h"
#include "filebuf/PxFileBuf.h"

namespace nvidia
{
namespace apex
{

PX_PUSH_PACK_DEFAULT

/**
\brief A wrapper class that provides an NvStream API for a PxFileBuf
*/
class PxStreamFromFileBuf : 
	public physx::PxInputStream, public physx::PxOutputStream
{
private:
	physx::PxFileBuf& mFileBuf;
	PxStreamFromFileBuf& operator=(const PxStreamFromFileBuf&)
	{
		return *this;
	}

public:
	//! \brief Constructor that takes a PxFileBuf
	PxStreamFromFileBuf(physx::PxFileBuf& fb) : mFileBuf(fb) {}

	//! \brief Read data from the stream
	uint32_t	read(void* dest, uint32_t count)
	{
		return mFileBuf.read(dest, count);
	}

	//! \brief Read data to the stream
	uint32_t write(const void* src, uint32_t count)
	{
		return mFileBuf.write(src, count);
	}
};

PX_POP_PACK

}
} // end namespace nvidia::apex

#endif // PX_STREAM_FROM_FILE_BUF_H
