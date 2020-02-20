# j6 UEFI headers

This is a set of headers for interacting with UEFI as a C++ EFI application. I
found the EDK2 headers seemed to be missing some definitions (or perhaps I just
hadn't found the right headers to include), and the GNU-EFI ones to be specific
to using GNU-EFI and tended to break when using clang to natively build an EFI
application.

I also hate the style of the standard headers, they should probably
come with a trigger warning for anyone who had to spend time doing Win32 COM
programming. So I've created my headers in a modern C++ style that is ABI
compatible, but doesn't attempt to be API compatible with other UEFI headers.

The UEFI protocol definition headers aren't directly included in the git repo,
but are  generated from the `protos.yaml` file via the `generate_protos.py`
script. I've started with just the protocols I'm actually using in the [jsix][]
bootloader, but new protocols should be fairly simple to add. I'll happily
accept pull requests if you find this code useful.

[jsix]: https://github.com/justinian/jsix
