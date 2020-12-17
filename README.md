# magic cp
magic_cp is a Tool to copy files between open shells on the same host.

It does shell working directory detection by analyzing /proc or read process info on a mac.

	magic_cp file_1 [file_2...]

## vars
in your .bashrc or .zshrc

	export PATH="~/mbin:$PATH"

## MacOS
install will create $HOME/mbin directory

	make

## Linux
On Linux OS you don't need the binary, just copy the script and add it to your path

Copy magic_cp to somewhere in your PATH:

	mkdir -p ~/mbin
	cp magic_cp ~/mbin/magic_cp
	export PATH="~/mbin:$PATH"

# USE it
just launch magic_cp with an argument. Like this

	magic_cp README.md 
	found shells to copy to:
	1) /Users/tketterer/gits/kit/dotfiles/mbin
	2) /tmp
	#? 1
	# cp -iv README.md /Users/tketterer/gits/kit/dotfiles/mbin/.
	README.md -> /Users/tketterer/gits/kit/dotfiles/mbin/./README.md
