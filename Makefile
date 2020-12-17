all: mac_pid_path copy

mac_pid_path:mac_pid_path.c
	gcc -o mac_pid_path mac_pid_path.c

copy:$(HOME)/mbin/mac_pid_path $(HOME)/mbin/magic_cp

$(HOME)/mbin/mac_pid_path: mac_pid_path
	cp -vf mac_pid_path $(HOME)/mbin/mac_pid_path

$(HOME)/mbin/magic_cp: magic_cp
	cp -vf magic_cp $(HOME)/mbin/magic_cp
