all: magic_cp mac_pid_path mbin copy

mac_pid_path:mac_pid_path.c
	@gcc -o mac_pid_path mac_pid_path.c

mbin:
	@mkdir -p $(HOME)/mbin

copy:$(HOME)/mbin/mac_pid_path $(HOME)/mbin/magic_cp

$(HOME)/mbin/mac_pid_path: mac_pid_path
	@cp -vf mac_pid_path $(HOME)/mbin/mac_pid_path

$(HOME)/mbin/magic_cp: magic_cp
	@cp -vf magic_cp $(HOME)/mbin/magic_cp

clean:
	rm -f mac_pid_path

uninstall:
	rm -f $(HOME)/mbin/mac_pid_path $(HOME)/mbin/magic_cp
