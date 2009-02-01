transienttmp : transienttmp.c
	$(CC) -o $@ $?
	sudo chown root:root $@
	sudo chmod a+x $@
	sudo chmod u+s $@
