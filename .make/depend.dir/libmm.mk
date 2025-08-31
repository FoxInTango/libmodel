DEPEND_TARGETS += libmm.build
ECHO_TARGETS += libmm.echo
libmm.build:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmm/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmm/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmm/ && make && make install
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmm/.make/super
libmm.echo:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmm/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmm/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmm/ && make echo
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmm/.make/super
