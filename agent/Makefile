#
# pg_statsinfo: Makefile
#
#    Copyright (c) 2009-2025, NTT, Inc.
#
SUBDIRS = bin lib

all install installdirs uninstall distprep clean distclean maintainer-clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $@ || exit; \
	done
