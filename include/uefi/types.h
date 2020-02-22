#pragma once
#ifndef _uefi_types_h_
#define _uefi_types_h_

// This Source Code Form is part of the j6-uefi-headers project and is subject
// to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was
// not distributed with this file, You can obtain one at
// http://mozilla.org/MPL/2.0/.

#include <stdint.h>

namespace uefi {

using handle = void *;

constexpr uint64_t error_bit = 0x8000000000000000ull; 
constexpr uint64_t make_error(uint64_t e) { return e|error_bit; }

enum class status : uint64_t
{
	success = 0,

#define STATUS_WARNING(name, num) name = num,
#define STATUS_ERROR(name, num) name = make_error(num),
#include "uefi/errors.inc"
#undef STATUS_WARNING
#undef STATUS_ERROR
};

inline bool is_error(status s) { return static_cast<uint64_t>(s) & error_bit; }
inline bool is_warning(status s) { return !is_error(s) && s != status::success; }

enum class memory_type : uint32_t
{
	reserved_memory_type,
	loader_code,
	loader_data,
	boot_services_code,
	boot_services_data,
	runtime_services_code,
	runtime_services_data,
	conventional_memory,
	unusable_memory,
	acpi_reclaim_memory,
	acpi_memory_nvs,
	memory_mapped_io,
	memory_mapped_io_port_space,
	pal_code,
	persistent_memory,
	max_memory_type
};

enum class allocate_type : uint32_t
{
	any_pages,
	max_address,
	address
};

} // namespace uefi

#endif
