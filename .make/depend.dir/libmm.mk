DEPEND_TARGETS += libmm.build
ECHO_TARGETS += libmm.echo
libmm.build:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libmodel/               >> /home/lidali/alpine/libraries/libmm/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libmodel/.make >> /home/lidali/alpine/libraries/libmm/.make/super
	cd /home/lidali/alpine/libraries/libmm/ && make && make install
	-rm /home/lidali/alpine/libraries/libmm/.make/super
libmm.echo:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libmodel/               >> /home/lidali/alpine/libraries/libmm/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libmodel/.make >> /home/lidali/alpine/libraries/libmm/.make/super
	cd /home/lidali/alpine/libraries/libmm/ && make echo
	-rm /home/lidali/alpine/libraries/libmm/.make/super
