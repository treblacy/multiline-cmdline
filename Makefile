mlcl: mlcl.c
	gcc -O2 $< -o $@
	strip $@

.PHONY: clean
clean:
	rm mlcl
