obj-m:= driver.o
default:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd)
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
