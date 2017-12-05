# include the machine dependent configuration
ifneq ($(MAKECMDGOALS),clean)
  -include ../../Makefile.conf
endif

all: libimd.$(SOEXT)

libimd.$(SOEXT): imd.o vmdsock.o Clock.o ActionIMD.o
	$(LDSO) -o $@ $^ # -lnsl

# copy imd-api to biuld directory, not great but workable and matches previous style.
vmdsock.c imd.c vmdsock.h imd.h: 
	cp -v vmd-imd-api/vmd-imd/$@ $@

vmdsock.o imd.o: vmdsock.h imd.h

clean:
	rm -fr *.c imd.h vmdsock.h *.$(SOEXT) *.o

obj: all

links:
	# do nothing


