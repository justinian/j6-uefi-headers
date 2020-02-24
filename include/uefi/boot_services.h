#pragma once
#ifndef _uefi_boot_services_h_
#define _uefi_boot_services_h_

// This Source Code Form is part of the j6-uefi-headers project and is subject
// to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was
// not distributed with this file, You can obtain one at
// http://mozilla.org/MPL/2.0/.

#include <stdint.h>
#include <uefi/tables.h>
#include <uefi/types.h>

namespace uefi {
namespace bs_impl {
	using allocate_pages = status (*)(allocate_type, memory_type, uint64_t, uintptr_t*);
	using allocate_pool = status (*)(memory_type, uint64_t, void**);
	using handle_protocol = status (*)(handle, guid *, void **);
	using create_event = status (*)(evt, tpl, event_notify, void*, event*);
	using locate_protocol = status (*)(const guid *, void *, void **);
	using set_mem = void (*)(void *, uint64_t, uint8_t);
}

struct boot_services {
	static constexpr uint64_t signature = 0x56524553544f4f42ull;

	table_header header;

	// Task Priority Level management
	void *raise_tpl;
	void *restore_tpl;

	// Memory Services
	bs_impl::allocate_pages allocate_pages;
	void *free_pages;
	void *get_memory_map;
	bs_impl::allocate_pool allocate_pool;
	void *free_pool;

	// Event & Timer Services
	bs_impl::create_event create_event;
	void *set_timer;
	void *wait_for_event;
	void *signal_event;
	void *close_event;
	void *check_event;

	// Protocol Handler Services
	void *install_protocol_interface;
	void *reinstall_protocol_interface;
	void *uninstall_protocol_interface;
	bs_impl::handle_protocol handle_protocol;
	void *_reserved;
	void *register_protocol_notify;
	void *locate_handle;
	void *locate_device_path;
	void *install_configuration_table;

	// Image Services
	void *load_image;
	void *start_image;
	void *exit;
	void *unload_image;
	void *exit_boot_services;

	// Miscellaneous Services
	void *get_next_monotonic_count;
	void *stall;
	void *set_watchdog_timer;

	// DriverSupport Services
	void *connect_controller;
	void *disconnect_controller;

	// Open and Close Protocol Services
	void *open_protocol;
	void *close_protocol;
	void *open_protocol_information;

	// Library Services
	void *protocols_per_handle;
	void *locate_handle_buffer;
	bs_impl::locate_protocol locate_protocol;
	void *install_multiple_protocol_interfaces;
	void *uninstall_multiple_protocol_interfaces;

	// 32-bit CRC Services
	void *calculate_crc32;

	// Miscellaneous Services
	void *copy_mem;
	bs_impl::set_mem set_mem;
	void *create_event_ex;
};

} // namespace uefi

#endif
