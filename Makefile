T=${PREFIX}/usr/bin/transienttmp

transienttmp : transienttmp.c
	$(CC) -o $@ $?

install :
	cp transienttmp $T
	chown root:root $T
	chmod a+x $T
	chmod u+s $T

clean :
	-rm transienttmp
